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

    QString pathString;
    for (size_t i = 0; i < suggestedPath.size(); ++i) {
        pathString.append(QString::fromStdString(suggestedPath[i]));
        if (i < suggestedPath.size() - 1) {
            pathString.append(" -> ");
        }
    }

    // Step 2: Validate inputs
    if (locationText.isEmpty() || daysText.isEmpty()) {
        ui->statusLabel->setText("*please fill all the details ");
        return;
    }

    resultwindow *resultWindow = new resultwindow();
    resultWindow->setPathString(pathString);
    this->hide();
    resultWindow->show();
}

