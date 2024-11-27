#include "feedbackwindow.h"
#include "ui_feedbackwindow.h"
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>
#include <QButtonGroup>
#include "thankyouwindow.h"

feedbackwindow::feedbackwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::feedbackwindow)
{
    ui->setupUi(this);
    setupDropdown();

    // Connect the dropdown signal to the slot
    connect(ui->destinations, &QComboBox::currentTextChanged,
            this, &feedbackwindow::onDestinationChanged);
}

void feedbackwindow::setupDropdown() {
    // Add items to the dropdown programmatically
    ui->destinations->addItem("Dehradun");
    ui->destinations->addItem("Rishikesh");
    ui->destinations->addItem("Mussoorie");
    ui->destinations->addItem("Haridwar");
    ui->destinations->addItem("Chakrata");
    ui->destinations->addItem("Dhanaulti");
    ui->destinations->addItem("Tehri");
}

void feedbackwindow::onDestinationChanged(const QString &destination) {
    // Log the selected destination to the console
    qDebug() << "Selected destination:" << destination;
}


feedbackwindow::~feedbackwindow()
{
    delete ui;
}

void feedbackwindow::on_ExploreBtn_clicked()
{
    thankyouwindow *thankyouWindow = new thankyouwindow();
    this->hide();

    thankyouWindow->show();
}

