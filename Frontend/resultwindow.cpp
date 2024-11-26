#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "feedbackwindow.h"

resultwindow::resultwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::resultwindow)
{
    ui->setupUi(this);
}

resultwindow::~resultwindow()
{
    delete ui;
}

void resultwindow::on_pushButton_clicked()
{
    feedbackwindow *feedbackWindow = new feedbackwindow();

    this->hide();

    feedbackWindow->show();
}

