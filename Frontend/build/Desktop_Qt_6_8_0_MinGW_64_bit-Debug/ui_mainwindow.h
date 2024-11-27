/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Background;
    QLabel *Menu;
    QLineEdit *amenu;
    QLineEdit *Location;
    QLineEdit *Duration;
    QPushButton *ExploreBtn;
    QLabel *AppName;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(761, 536);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("/* Base styles for the QLabel (icon) */\n"
"QLabel#locationIcon, QLabel#durationIcon {\n"
"    padding: 5px; /* Optional for spacing */\n"
"}\n"
"\n"
"/* When the QLineEdit is focused, hide the QLabel (icon) */\n"
"QLineEdit:focus + QLabel {\n"
"    visibility: hidden; /* Makes the icon invisible */\n"
"}\n"
""));
        Background = new QLabel(centralwidget);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(10, 80, 741, 431));
        Background->setStyleSheet(QString::fromUtf8("background-image: url(:/images/BG.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"border-radius: 10px;"));
        Menu = new QLabel(centralwidget);
        Menu->setObjectName("Menu");
        Menu->setGeometry(QRect(450, 180, 281, 211));
        Menu->setMinimumSize(QSize(281, 0));
        Menu->setMaximumSize(QSize(281, 211));
        Menu->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        Menu->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.8);\n"
"border-radius: 15px; /* Optional: adds rounded corners */\n"
"padding: 10px; /* Optional: adds inner spacing */\n"
""));
        Menu->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Menu->setWordWrap(true);
        amenu = new QLineEdit(centralwidget);
        amenu->setObjectName("amenu");
        amenu->setGeometry(QRect(480, 190, 231, 42));
        amenu->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        amenu->setMouseTracking(false);
        amenu->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        amenu->setAutoFillBackground(false);
        amenu->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.8);\n"
"border-radius: 15px; \n"
"padding: 10px; \n"
"background: transparent;\n"
"color: black;\n"
"font-weight: bold;\n"
"pointer-events: none;\n"
" \n"
""));
        amenu->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Location = new QLineEdit(centralwidget);
        Location->setObjectName("Location");
        Location->setGeometry(QRect(470, 240, 251, 51));
        Location->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: rgba(255, 255, 255, 0.8);  /* Semi-transparent white background */\n"
"    border: 2px solid #ccc;               /* Light gray border */\n"
"    border-radius: 10px;                  /* Rounded corners */\n"
"    padding: 10px;                        /* Internal padding for better appearance */\n"
"    font-size: 16px;                      /* Font size */\n"
"    color: black;                         /* Text color */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #007bff;                /* Highlighted border color when focused */\n"
"    background: rgba(255, 255, 255, 1);  /* Fully opaque background when focused */\n"
"}\n"
"\n"
"\n"
""));
        Duration = new QLineEdit(centralwidget);
        Duration->setObjectName("Duration");
        Duration->setGeometry(QRect(470, 300, 251, 51));
        Duration->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: rgba(255, 255, 255, 0.8);  /* Semi-transparent white background */\n"
"    border: 2px solid #ccc;               /* Light gray border */\n"
"    border-radius: 10px;                  /* Rounded corners */\n"
"    padding: 10px;                        /* Internal padding for better appearance */\n"
"    font-size: 16px;                      /* Font size */\n"
"    color: black;                         /* Text color */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #007bff;                /* Highlighted border color when focused */\n"
"    background: rgba(255, 255, 255, 1);  /* Fully opaque background when focused */\n"
"}\n"
"\n"
"\n"
""));
        ExploreBtn = new QPushButton(centralwidget);
        ExploreBtn->setObjectName("ExploreBtn");
        ExploreBtn->setGeometry(QRect(470, 400, 251, 41));
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
        AppName = new QLabel(centralwidget);
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
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Background->setText(QString());
        Menu->setText(QString());
        amenu->setPlaceholderText(QCoreApplication::translate("MainWindow", "   Explore like never before!", nullptr));
        Location->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Current Location", nullptr));
        Duration->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Duration", nullptr));
        ExploreBtn->setText(QCoreApplication::translate("MainWindow", "Start Exploring", nullptr));
        AppName->setText(QCoreApplication::translate("MainWindow", "ExploreMate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
