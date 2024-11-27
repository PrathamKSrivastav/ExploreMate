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
    , groupQ1(new QButtonGroup(this))  // Initialize button groups
    , groupQ2(new QButtonGroup(this))
    , groupQ3(new QButtonGroup(this))
    , groupQ4(new QButtonGroup(this))
{
    ui->setupUi(this);
    setupDropdown();
    setupRadiobutton();

    // Connect the dropdown signal to the slot
    connect(ui->destinations, &QComboBox::currentTextChanged,
            this, &feedbackwindow::onDestinationChanged);
}

void feedbackwindow::setupDropdown() {
    ui->destinations->addItem("Dehradun");
    ui->destinations->addItem("Rishikesh");
    ui->destinations->addItem("Mussoorie");
    ui->destinations->addItem("Haridwar");
    ui->destinations->addItem("Chakrata");
    ui->destinations->addItem("Dhanaulti");
    ui->destinations->addItem("Tehri");

    ui->destinations->setCurrentIndex(0);  // Default to the first item
}

void feedbackwindow::onDestinationChanged(const QString &destination) {
    qDebug() << "Selected destination:" << destination;
}

void feedbackwindow::setupRadiobutton() {
    // Add buttons to groups
    groupQ1->addButton(ui->radioButton1_1);
    groupQ1->addButton(ui->radioButton1_2);
    groupQ1->addButton(ui->radioButton1_3);
    groupQ1->addButton(ui->radioButton1_4);
    groupQ1->addButton(ui->radioButton1_5);

    groupQ2->addButton(ui->radioButton2_1);
    groupQ2->addButton(ui->radioButton2_2);
    groupQ2->addButton(ui->radioButton2_3);
    groupQ2->addButton(ui->radioButton2_4);
    groupQ2->addButton(ui->radioButton2_5);

    groupQ3->addButton(ui->radioButton3_1);
    groupQ3->addButton(ui->radioButton3_2);
    groupQ3->addButton(ui->radioButton3_3);
    groupQ3->addButton(ui->radioButton3_4);
    groupQ3->addButton(ui->radioButton3_5);

    groupQ4->addButton(ui->radioButton4_1);
    groupQ4->addButton(ui->radioButton4_2);
    groupQ4->addButton(ui->radioButton4_3);
    groupQ4->addButton(ui->radioButton4_4);
    groupQ4->addButton(ui->radioButton4_5);
}

bool feedbackwindow::areAllGroupsSelected() const {
    return groupQ1->checkedButton() != nullptr &&
           groupQ2->checkedButton() != nullptr &&
           groupQ3->checkedButton() != nullptr &&
           groupQ4->checkedButton() != nullptr;
}

feedbackwindow::~feedbackwindow()
{
    delete ui;
}

void feedbackwindow::on_ExploreBtn_clicked()
{
    if (!areAllGroupsSelected()) {
        ui->statusBox->setText("*please fill all the questions ");
        return;
    }

    thankyouwindow *thankyouWindow = new thankyouwindow();
    this->hide();
    thankyouWindow->show();
}
