/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resultwindow
{
public:
    QLabel *AppName;
    QLabel *Background;
    QLabel *Heading1;
    QLabel *Heading2;
    QFrame *ExpChoice_2;
    QPushButton *pushButton;
    QLabel *ExpChoice;

    void setupUi(QWidget *resultwindow)
    {
        if (resultwindow->objectName().isEmpty())
            resultwindow->setObjectName("resultwindow");
        resultwindow->resize(761, 536);
        resultwindow->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"\n"
"\n"
""));
        AppName = new QLabel(resultwindow);
        AppName->setObjectName("AppName");
        AppName->setGeometry(QRect(260, 0, 241, 91));
        AppName->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 36px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    margin: 20px 0;\n"
"}\n"
""));
        AppName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Background = new QLabel(resultwindow);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(10, 80, 741, 431));
        Background->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: lightgray; /* Light gray background */\n"
"    border: 2px ; /* Border color */\n"
"    border-radius: 10px; /* Curved corners */\n"
"    padding: 5px; /* Padding around the text */\n"
"}\n"
""));
        Heading1 = new QLabel(resultwindow);
        Heading1->setObjectName("Heading1");
        Heading1->setGeometry(QRect(40, 110, 239, 47));
        Heading1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px; /* Larger font size for the heading */\n"
"    font-weight: bold; /* Make the heading bold */\n"
"    color: black; /* Set text color to black */\n"
"    padding: 10px; /* Add some padding around the text */\n"
"   border-radius: 15px;\n"
"}\n"
""));
        Heading2 = new QLabel(resultwindow);
        Heading2->setObjectName("Heading2");
        Heading2->setGeometry(QRect(40, 240, 239, 47));
        Heading2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px; /* Larger font size for the heading */\n"
"    font-weight: bold; /* Make the heading bold */\n"
"    color: black; /* Set text color to black */\n"
"    padding: 10px; /* Add some padding around the text */\n"
"   border-radius: 15px;\n"
"}\n"
""));
        ExpChoice_2 = new QFrame(resultwindow);
        ExpChoice_2->setObjectName("ExpChoice_2");
        ExpChoice_2->setGeometry(QRect(40, 290, 681, 171));
        ExpChoice_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 2px dashed #333; /* Dashed border */\n"
"    border-radius: 8px; /* Rounded corners */\n"
"    height: 200px; /* Set height for the block */\n"
"    margin: 10px; /* Space around the block */\n"
"    padding: 10px; /* Padding inside the block */\n"
"}\n"
""));
        ExpChoice_2->setFrameShape(QFrame::Shape::StyledPanel);
        ExpChoice_2->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(resultwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 460, 161, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ExpChoice = new QLabel(resultwindow);
        ExpChoice->setObjectName("ExpChoice");
        ExpChoice->setGeometry(QRect(40, 160, 681, 71));
        ExpChoice->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 2px dashed #333; /* Dashed border */\n"
"    border-radius: 8px; /* Rounded corners */\n"
"    height: 200px; /* Set height for the block */\n"
"    margin: 5px; /* Space around the block */\n"
"    padding: 5px; /* Padding inside the block */\n"
"	padding-right:5px;\n"
"	color:black;\n"
"	font-size:13px;\n"
"	font-weight:bold;\n"
"}\n"
"\n"
""));
        ExpChoice->setWordWrap(true);

        retranslateUi(resultwindow);

        QMetaObject::connectSlotsByName(resultwindow);
    } // setupUi

    void retranslateUi(QWidget *resultwindow)
    {
        resultwindow->setWindowTitle(QCoreApplication::translate("resultwindow", "Form", nullptr));
        AppName->setText(QCoreApplication::translate("resultwindow", "ExploreMate", nullptr));
        Background->setText(QString());
        Heading1->setText(QCoreApplication::translate("resultwindow", "ExploreMate's Choice", nullptr));
        Heading2->setText(QCoreApplication::translate("resultwindow", "Other Choices", nullptr));
        pushButton->setText(QCoreApplication::translate("resultwindow", "Next", nullptr));
        ExpChoice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class resultwindow: public Ui_resultwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
