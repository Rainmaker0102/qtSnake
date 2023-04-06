/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QRadioButton *easyRadioButton;
    QRadioButton *normalRadioButton;
    QRadioButton *hardRadioButton;
    QLabel *label_2;
    QLabel *label_3;
	QLabel *controls;
	QLabel *player1;
	QLabel *player2;
	
    QRadioButton *singleplayerRadioButton;
    QRadioButton *multiplayerRadioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(440, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 420, 80, 21));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 165);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(115, 10, 211, 81));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 248)"));
        easyRadioButton = new QRadioButton(centralwidget);
        easyRadioButton->setObjectName(QString::fromUtf8("easyRadioButton"));
        easyRadioButton->setGeometry(QRect(102, 160, 91, 22));
        easyRadioButton->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        easyRadioButton->setChecked(true);
        easyRadioButton->setAutoExclusive(false);
        normalRadioButton = new QRadioButton(centralwidget);
        normalRadioButton->setObjectName(QString::fromUtf8("normalRadioButton"));
        normalRadioButton->setGeometry(QRect(102, 200, 111, 22));
        normalRadioButton->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        normalRadioButton->setChecked(false);
        normalRadioButton->setAutoExclusive(false);
        hardRadioButton = new QRadioButton(centralwidget);
        hardRadioButton->setObjectName(QString::fromUtf8("hardRadioButton"));
        hardRadioButton->setGeometry(QRect(102, 240, 111, 22));
        hardRadioButton->setStyleSheet(QString::fromUtf8("color: white;"));
        hardRadioButton->setAutoExclusive(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(102, 120, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(233, 120, 121, 31));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
		QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
		controls = new QLabel(centralwidget);
        controls->setObjectName(QString::fromUtf8("controls"));
        controls->setGeometry(QRect(200, 480, 49, 16));
        controls->setFont(font2);
        controls->setStyleSheet(QString::fromUtf8("color: white;"));
		QFont font3;
        font2.setPointSize(9);
		player1 = new QLabel(centralwidget);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(92, 510, 91, 20));
        player1->setFont(font3);
        player1->setStyleSheet(QString::fromUtf8("color: white;"));
		player2 = new QLabel(centralwidget);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(260, 510, 91, 20));
        player2->setFont(font3);
        player2->setStyleSheet(QString::fromUtf8("color: white;"));
		
		
        singleplayerRadioButton = new QRadioButton(centralwidget);
        singleplayerRadioButton->setObjectName(QString::fromUtf8("singleplayerRadioButton"));
        singleplayerRadioButton->setGeometry(QRect(248, 160, 91, 22));
        singleplayerRadioButton->setStyleSheet(QString::fromUtf8("color: white;"));
        singleplayerRadioButton->setChecked(true);
        singleplayerRadioButton->setAutoExclusive(false);
        multiplayerRadioButton = new QRadioButton(centralwidget);
        multiplayerRadioButton->setObjectName(QString::fromUtf8("multiplayerRadioButton"));
        multiplayerRadioButton->setGeometry(QRect(248, 200, 91, 22));
        multiplayerRadioButton->setStyleSheet(QString::fromUtf8("color: white;"));
        multiplayerRadioButton->setAutoExclusive(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 440, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Snake Game", nullptr));
        easyRadioButton->setText(QCoreApplication::translate("MainWindow", "Slug(Easiest)", nullptr));
        normalRadioButton->setText(QCoreApplication::translate("MainWindow", "Worm (Normal)", nullptr));
        hardRadioButton->setText(QCoreApplication::translate("MainWindow", "Python (Hardest)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Difficulty", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Game Mode", nullptr));
		controls->setText(QCoreApplication::translate("MainWindow", "Controls", nullptr));
		player1->setText(QCoreApplication::translate("MainWindow", "Player 1: (WASD)", nullptr));
		player2->setText(QCoreApplication::translate("MainWindow", "Player 2: (IJKL)", nullptr));
        singleplayerRadioButton->setText(QCoreApplication::translate("MainWindow", "Single Player", nullptr));
        multiplayerRadioButton->setText(QCoreApplication::translate("MainWindow", "Multiplayer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
