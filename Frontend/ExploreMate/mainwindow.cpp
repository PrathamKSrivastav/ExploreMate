#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

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



