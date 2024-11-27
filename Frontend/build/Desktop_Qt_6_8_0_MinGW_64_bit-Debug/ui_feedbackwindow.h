/********************************************************************************
** Form generated from reading UI file 'feedbackwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACKWINDOW_H
#define UI_FEEDBACKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_feedbackwindow
{
public:
    QLabel *Background;
    QLabel *AppName;
    QComboBox *destinations;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton1_1;
    QRadioButton *radioButton1_2;
    QRadioButton *radioButton1_3;
    QRadioButton *radioButton1_4;
    QRadioButton *radioButton1_5;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *radioButton2_4;
    QRadioButton *radioButton2_3;
    QRadioButton *radioButton2_1;
    QRadioButton *radioButton2_5;
    QLabel *label_5;
    QRadioButton *radioButton2_2;
    QLabel *label_6;
    QRadioButton *radioButton4_2;
    QRadioButton *radioButton3_4;
    QLabel *label_7;
    QRadioButton *radioButton4_4;
    QRadioButton *radioButton4_1;
    QRadioButton *radioButton3_3;
    QRadioButton *radioButton3_1;
    QRadioButton *radioButton3_5;
    QLabel *label_8;
    QLabel *label_9;
    QRadioButton *radioButton4_5;
    QRadioButton *radioButton4_3;
    QRadioButton *radioButton3_2;
    QPushButton *ExploreBtn;

    void setupUi(QWidget *feedbackwindow)
    {
        if (feedbackwindow->objectName().isEmpty())
            feedbackwindow->setObjectName("feedbackwindow");
        feedbackwindow->resize(761, 536);
        feedbackwindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        Background = new QLabel(feedbackwindow);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(10, 80, 741, 431));
        Background->setStyleSheet(QString::fromUtf8("background-color: lightgrey;\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"border-radius: 10px;"));
        AppName = new QLabel(feedbackwindow);
        AppName->setObjectName("AppName");
        AppName->setGeometry(QRect(260, -10, 241, 91));
        AppName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    margin: 20px 0;\n"
"}\n"
""));
        AppName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        destinations = new QComboBox(feedbackwindow);
        destinations->setObjectName("destinations");
        destinations->setGeometry(QRect(330, 110, 301, 47));
        destinations->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Arial\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0; /* Subtle light-gray border */\n"
"    border-radius: 3px; /* Slightly rounded corners */\n"
"    padding: 5px 10px; /* Spacing between text and edges */\n"
"    min-height: 35px; /* Matches height in the design */\n"
"    text-align: left;\n"
"	padding-right:10px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none; /* Removes dropdown arrow divider */\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: center right; /* Positions the arrow on the far right */\n"
"    width: 30px; /* Size of the dropdown button */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/down-arrow.png); /* Use a custom simple arrow icon */\n"
"    width: 12px; /* Size of the arrow icon */\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView  {\n"
"    background-color: white; /* Dropdown menu background */\n"
"    border: 1px sol"
                        "id #e0e0e0; /* Matches box border */\n"
"    selection-background-color: #f7f7f7; /* Subtle hover effect */\n"
"    selection-color: black;\n"
"	color:black;\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"}\n"
""));
        label = new QLabel(feedbackwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 110, 609, 52));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	padding-left:10px;\n"
"	background:transparent;\n"
"    font-family: \"Arial\";\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    text-align: left;\n"
"}\n"
""));
        label_2 = new QLabel(feedbackwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 180, 351, 51));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 14px Arial;  /* Adjust font family and size */\n"
"    color: #333;  /* Text color */\n"
"    padding: 10px;  /* Padding around the label */\n"
"    background-color: #f4f4f4;  /* Background color for the label */\n"
"    border-radius: 5px;  /* Rounded corners for the label */\n"
"    margin-bottom: 5px;  /* Space below the label */\n"
"}"));
        radioButton1_1 = new QRadioButton(feedbackwindow);
        radioButton1_1->setObjectName("radioButton1_1");
        radioButton1_1->setGeometry(QRect(430, 190, 41, 26));
        radioButton1_1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	border-radius:10px;\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton1_2 = new QRadioButton(feedbackwindow);
        radioButton1_2->setObjectName("radioButton1_2");
        radioButton1_2->setGeometry(QRect(490, 190, 41, 26));
        radioButton1_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton1_3 = new QRadioButton(feedbackwindow);
        radioButton1_3->setObjectName("radioButton1_3");
        radioButton1_3->setGeometry(QRect(550, 190, 41, 26));
        radioButton1_3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton1_4 = new QRadioButton(feedbackwindow);
        radioButton1_4->setObjectName("radioButton1_4");
        radioButton1_4->setGeometry(QRect(610, 190, 41, 26));
        radioButton1_4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton1_5 = new QRadioButton(feedbackwindow);
        radioButton1_5->setObjectName("radioButton1_5");
        radioButton1_5->setGeometry(QRect(670, 190, 41, 26));
        radioButton1_5->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        label_3 = new QLabel(feedbackwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(412, 180, 321, 41));
        label_3->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius:10px;"));
        label_4 = new QLabel(feedbackwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 240, 351, 51));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 14px Arial;  /* Adjust font family and size */\n"
"    color: #333;  /* Text color */\n"
"    padding: 10px;  /* Padding around the label */\n"
"    background-color: #f4f4f4;  /* Background color for the label */\n"
"    border-radius: 5px;  /* Rounded corners for the label */\n"
"    margin-bottom: 5px;  /* Space below the label */\n"
"}"));
        radioButton2_4 = new QRadioButton(feedbackwindow);
        radioButton2_4->setObjectName("radioButton2_4");
        radioButton2_4->setGeometry(QRect(610, 250, 41, 26));
        radioButton2_4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton2_3 = new QRadioButton(feedbackwindow);
        radioButton2_3->setObjectName("radioButton2_3");
        radioButton2_3->setGeometry(QRect(550, 250, 41, 26));
        radioButton2_3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton2_1 = new QRadioButton(feedbackwindow);
        radioButton2_1->setObjectName("radioButton2_1");
        radioButton2_1->setGeometry(QRect(430, 250, 41, 26));
        radioButton2_1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	border-radius:10px;\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton2_5 = new QRadioButton(feedbackwindow);
        radioButton2_5->setObjectName("radioButton2_5");
        radioButton2_5->setGeometry(QRect(670, 250, 41, 26));
        radioButton2_5->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        label_5 = new QLabel(feedbackwindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(412, 240, 321, 41));
        label_5->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius:10px;"));
        radioButton2_2 = new QRadioButton(feedbackwindow);
        radioButton2_2->setObjectName("radioButton2_2");
        radioButton2_2->setGeometry(QRect(490, 250, 41, 26));
        radioButton2_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        label_6 = new QLabel(feedbackwindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 310, 351, 51));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 14px Arial;  /* Adjust font family and size */\n"
"    color: #333;  /* Text color */\n"
"    padding: 10px;  /* Padding around the label */\n"
"    background-color: #f4f4f4;  /* Background color for the label */\n"
"    border-radius: 5px;  /* Rounded corners for the label */\n"
"    margin-bottom: 5px;  /* Space below the label */\n"
"}"));
        radioButton4_2 = new QRadioButton(feedbackwindow);
        radioButton4_2->setObjectName("radioButton4_2");
        radioButton4_2->setGeometry(QRect(490, 380, 41, 26));
        radioButton4_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton3_4 = new QRadioButton(feedbackwindow);
        radioButton3_4->setObjectName("radioButton3_4");
        radioButton3_4->setGeometry(QRect(610, 320, 41, 26));
        radioButton3_4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        label_7 = new QLabel(feedbackwindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 370, 351, 51));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 14px Arial;  /* Adjust font family and size */\n"
"    color: #333;  /* Text color */\n"
"    padding: 10px;  /* Padding around the label */\n"
"    background-color: #f4f4f4;  /* Background color for the label */\n"
"    border-radius: 5px;  /* Rounded corners for the label */\n"
"    margin-bottom: 5px;  /* Space below the label */\n"
"}"));
        radioButton4_4 = new QRadioButton(feedbackwindow);
        radioButton4_4->setObjectName("radioButton4_4");
        radioButton4_4->setGeometry(QRect(610, 380, 41, 26));
        radioButton4_4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton4_1 = new QRadioButton(feedbackwindow);
        radioButton4_1->setObjectName("radioButton4_1");
        radioButton4_1->setGeometry(QRect(430, 380, 41, 26));
        radioButton4_1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	border-radius:10px;\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton3_3 = new QRadioButton(feedbackwindow);
        radioButton3_3->setObjectName("radioButton3_3");
        radioButton3_3->setGeometry(QRect(550, 320, 41, 26));
        radioButton3_3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton3_1 = new QRadioButton(feedbackwindow);
        radioButton3_1->setObjectName("radioButton3_1");
        radioButton3_1->setGeometry(QRect(430, 320, 41, 26));
        radioButton3_1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	border-radius:10px;\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton3_5 = new QRadioButton(feedbackwindow);
        radioButton3_5->setObjectName("radioButton3_5");
        radioButton3_5->setGeometry(QRect(670, 320, 41, 26));
        radioButton3_5->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        label_8 = new QLabel(feedbackwindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(412, 310, 321, 41));
        label_8->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius:10px;"));
        label_9 = new QLabel(feedbackwindow);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(412, 370, 321, 41));
        label_9->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius:10px;"));
        radioButton4_5 = new QRadioButton(feedbackwindow);
        radioButton4_5->setObjectName("radioButton4_5");
        radioButton4_5->setGeometry(QRect(670, 380, 41, 26));
        radioButton4_5->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton4_3 = new QRadioButton(feedbackwindow);
        radioButton4_3->setObjectName("radioButton4_3");
        radioButton4_3->setGeometry(QRect(550, 380, 41, 26));
        radioButton4_3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        radioButton3_2 = new QRadioButton(feedbackwindow);
        radioButton3_2->setObjectName("radioButton3_2");
        radioButton3_2->setGeometry(QRect(490, 320, 41, 26));
        radioButton3_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    font: 12px Arial;  /* Adjust font size */\n"
"    color: #333;  /* Text color */\n"
"    spacing: 10px;  /* Space between the radio button and the text */\n"
"\n"
"}"));
        ExploreBtn = new QPushButton(feedbackwindow);
        ExploreBtn->setObjectName("ExploreBtn");
        ExploreBtn->setGeometry(QRect(480, 460, 251, 41));
        ExploreBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ExploreBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: black;\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    font-weight: bold;\n"
"}\n"
"exploreButton->setStyleSheet(\n"
"    \"background-color: black;\"\n"
"    \"color: white;\"\n"
"    \"font-size: 16px;\"\n"
"    \"padding: 10px 20px;\"\n"
"    \"border-radius: 5px;\"\n"
"    \"border: none;\"\n"
"    \"hover { background-color: #444; }\"\n"
");\n"
"\n"
""));
        Background->raise();
        AppName->raise();
        destinations->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        radioButton1_1->raise();
        radioButton1_2->raise();
        radioButton1_3->raise();
        radioButton1_4->raise();
        radioButton1_5->raise();
        label_4->raise();
        label_5->raise();
        radioButton2_2->raise();
        radioButton2_4->raise();
        radioButton2_3->raise();
        radioButton2_1->raise();
        radioButton2_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        radioButton3_2->raise();
        radioButton3_4->raise();
        radioButton3_3->raise();
        radioButton4_4->raise();
        radioButton4_1->raise();
        radioButton4_3->raise();
        radioButton4_2->raise();
        radioButton4_5->raise();
        radioButton3_1->raise();
        radioButton3_5->raise();
        ExploreBtn->raise();

        retranslateUi(feedbackwindow);

        QMetaObject::connectSlotsByName(feedbackwindow);
    } // setupUi

    void retranslateUi(QWidget *feedbackwindow)
    {
        feedbackwindow->setWindowTitle(QCoreApplication::translate("feedbackwindow", "Form", nullptr));
        Background->setText(QString());
        AppName->setText(QCoreApplication::translate("feedbackwindow", "ExploreMate", nullptr));
        label->setText(QCoreApplication::translate("feedbackwindow", "Destination Visited", nullptr));
        label_2->setText(QCoreApplication::translate("feedbackwindow", "Question 1", nullptr));
        radioButton1_1->setText(QCoreApplication::translate("feedbackwindow", "1", nullptr));
        radioButton1_2->setText(QCoreApplication::translate("feedbackwindow", "2", nullptr));
        radioButton1_3->setText(QCoreApplication::translate("feedbackwindow", "3", nullptr));
        radioButton1_4->setText(QCoreApplication::translate("feedbackwindow", "4", nullptr));
        radioButton1_5->setText(QCoreApplication::translate("feedbackwindow", "5", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("feedbackwindow", "Question 2", nullptr));
        radioButton2_4->setText(QCoreApplication::translate("feedbackwindow", "4", nullptr));
        radioButton2_3->setText(QCoreApplication::translate("feedbackwindow", "3", nullptr));
        radioButton2_1->setText(QCoreApplication::translate("feedbackwindow", "1", nullptr));
        radioButton2_5->setText(QCoreApplication::translate("feedbackwindow", "5", nullptr));
        label_5->setText(QString());
        radioButton2_2->setText(QCoreApplication::translate("feedbackwindow", "2", nullptr));
        label_6->setText(QCoreApplication::translate("feedbackwindow", "Question 3", nullptr));
        radioButton4_2->setText(QCoreApplication::translate("feedbackwindow", "2", nullptr));
        radioButton3_4->setText(QCoreApplication::translate("feedbackwindow", "4", nullptr));
        label_7->setText(QCoreApplication::translate("feedbackwindow", "Question 4", nullptr));
        radioButton4_4->setText(QCoreApplication::translate("feedbackwindow", "4", nullptr));
        radioButton4_1->setText(QCoreApplication::translate("feedbackwindow", "1", nullptr));
        radioButton3_3->setText(QCoreApplication::translate("feedbackwindow", "3", nullptr));
        radioButton3_1->setText(QCoreApplication::translate("feedbackwindow", "1", nullptr));
        radioButton3_5->setText(QCoreApplication::translate("feedbackwindow", "5", nullptr));
        label_8->setText(QString());
        label_9->setText(QString());
        radioButton4_5->setText(QCoreApplication::translate("feedbackwindow", "5", nullptr));
        radioButton4_3->setText(QCoreApplication::translate("feedbackwindow", "3", nullptr));
        radioButton3_2->setText(QCoreApplication::translate("feedbackwindow", "2", nullptr));
        ExploreBtn->setText(QCoreApplication::translate("feedbackwindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class feedbackwindow: public Ui_feedbackwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACKWINDOW_H
