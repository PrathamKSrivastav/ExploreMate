#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "feedbackwindow.h"

#include <QVBoxLayout>

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

void resultwindow::setPathString(const QString& pathString) {
    m_pathString = pathString;
    ui->ExpChoice->setText(pathString);
}

void resultwindow::setAlterRoute1(const QString& route1String){
    m_route1String = route1String;
    ui->alternate1->setText(route1String);
}

void resultwindow::setAlterRoute2(const QString& route2String){
    m_route1String = route2String;
    ui->alternate2->setText(route2String);
}

void resultwindow::setAlterRoute3(const QString& route3String){
    m_route1String = route3String;
    ui->alternate3->setText(route3String);
}

void resultwindow::on_pushButton_clicked()
{
    feedbackwindow *feedbackWindow = new feedbackwindow();

    this->hide();

    feedbackWindow->show();
}

