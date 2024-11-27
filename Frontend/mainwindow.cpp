#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include "resultwindow.h"
#include <qmessagebox.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the background image
    ui->Background->setPixmap(QPixmap(":/images/background.png"));
    ui->Background->setScaledContents(true);

    // Apply style to the transparent box (Menu)
    ui->Menu->setStyleSheet("background-color: rgba(255, 255, 255, 0.8); border-radius: 15px; padding: 10px;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ExploreBtn_clicked()
{
    QString locationText = ui->Location->text();
    //QMessageBox::information(this, "locationText","You Entered" + locationText);
    std::string locationString = locationText.toStdString();

    QString daysText = ui->Duration->text();
    int daysNum = daysText.toInt();

    graph.initializeEdges();

    vector<string> suggestedPath = graph.suggestPath(locationString, daysNum);

    vector<string> route1, route2, route3;

    graph.suggestAlternativeRoutes(locationString, daysNum, route1, route2, route3);

    QString pathString, route1String, route2String, route3String;

    auto convertRouteToString = [](const std::vector<std::string> &route) -> QString {
        QString pathString;
        for (size_t i = 0; i < route.size(); ++i) {
            pathString.append(QString::fromStdString(route[i]));
            if (i < route.size() - 1) {
                pathString.append(" -> ");
            }
        }
        return pathString;
    };

    pathString = convertRouteToString(suggestedPath);
    route1String = convertRouteToString(route1);
    route2String = convertRouteToString(route2);
    route3String = convertRouteToString(route3);


    // Step 2: Validate inputs
    if (locationText.isEmpty() || daysText.isEmpty()) {
        ui->statusLabel->setText("*please fill all the details ");
        return;
    }

    resultwindow *resultWindow = new resultwindow();
    resultWindow->setPathString(pathString);
    resultWindow->setAlterRoute1(route1String);
    resultWindow->setAlterRoute2(route2String);
    resultWindow->setAlterRoute3(route3String);
    this->hide();
    resultWindow->show();
}

