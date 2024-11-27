/********************************************************************************
** Form generated from reading UI file 'thankyouwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THANKYOUWINDOW_H
#define UI_THANKYOUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thankyouwindow
{
public:
    QLabel *Background;
    QLabel *AppName;
    QLabel *label;
    QPushButton *ExploreBtn;

    void setupUi(QWidget *thankyouwindow)
    {
        if (thankyouwindow->objectName().isEmpty())
            thankyouwindow->setObjectName("thankyouwindow");
        thankyouwindow->resize(761, 536);
        thankyouwindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        Background = new QLabel(thankyouwindow);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(10, 70, 741, 431));
        Background->setStyleSheet(QString::fromUtf8("background-image: url(:/images/BG.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"border-radius: 10px;"));
        AppName = new QLabel(thankyouwindow);
        AppName->setObjectName("AppName");
        AppName->setGeometry(QRect(260, -20, 241, 91));
        AppName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    margin: 20px 0;\n"
"}\n"
""));
        AppName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(thankyouwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 190, 611, 141));
        label->setStyleSheet(QString::fromUtf8("/* Styling for the Thank You QLabel */\n"
"QLabel {\n"
"    font: bold 40px Arial;  /* Adjusted font size to fit screen */\n"
"    color: #ffffff;  /* White text color for high contrast */\n"
"    background:transparent;\n"
"    padding: 20px;  /* Padding around the text */\n"
"    border-radius: 10px;  /* Rounded corners for a smoother appearance */\n"
"    text-align: center;  /* Center-align the text */\n"
"    margin: 20px;  /* Add space around the label */\n"
"    box-shadow: 0px 6px 12px rgba(0, 0, 0, 0.2);  /* Light shadow for depth */\n"
"    width: 90%;  /* Set width to 90% of screen size */\n"
"    height: auto;  /* Allow the height to adjust based on text size */\n"
"    word-wrap: break-word;  /* Ensure long text wraps properly */\n"
"    display: block;  /* Ensure it behaves like a block-level element */\n"
"    margin-left: auto;\n"
"    margin-right: auto;  /* Center the label horizontally */\n"
"}\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ExploreBtn = new QPushButton(thankyouwindow);
        ExploreBtn->setObjectName("ExploreBtn");
        ExploreBtn->setGeometry(QRect(480, 440, 251, 41));
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

        retranslateUi(thankyouwindow);

        QMetaObject::connectSlotsByName(thankyouwindow);
    } // setupUi

    void retranslateUi(QWidget *thankyouwindow)
    {
        thankyouwindow->setWindowTitle(QCoreApplication::translate("thankyouwindow", "Form", nullptr));
        Background->setText(QString());
        AppName->setText(QCoreApplication::translate("thankyouwindow", "ExploreMate", nullptr));
        label->setText(QCoreApplication::translate("thankyouwindow", "Thank you for visitng!", nullptr));
        ExploreBtn->setText(QCoreApplication::translate("thankyouwindow", "Explore More", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thankyouwindow: public Ui_thankyouwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THANKYOUWINDOW_H
