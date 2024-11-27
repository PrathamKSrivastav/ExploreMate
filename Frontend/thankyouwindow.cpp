#include "thankyouwindow.h"
#include "ui_thankyouwindow.h"
#include "mainwindow.h"

thankyouwindow::thankyouwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::thankyouwindow)
{
    ui->setupUi(this);
}

thankyouwindow::~thankyouwindow()
{
    delete ui;
}

void thankyouwindow::on_ExploreBtn_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    this->hide();

    mainWindow->show();
}

