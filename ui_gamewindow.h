/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *singlePlayerScoreLabel;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(960, 760);
        GameWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52)\n"
""));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 960, 760));
        graphicsView->setFocusPolicy(Qt::WheelFocus);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setInteractive(true);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 400, 80, 24));
        singlePlayerScoreLabel = new QLabel(centralwidget);
        singlePlayerScoreLabel->setObjectName(QString::fromUtf8("singlePlayerScoreLabel"));
        singlePlayerScoreLabel->setGeometry(QRect(350, 50, 91, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        singlePlayerScoreLabel->setFont(font);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(510, 50, 91, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, 210, 231, 121));
        QFont font1;
        font1.setPointSize(29);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 320, 271, 121));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 320, 271, 121));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        GameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 21));
        GameWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GameWindow->setStatusBar(statusbar);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("GameWindow", "add snake tail", nullptr));
        singlePlayerScoreLabel->setText(QCoreApplication::translate("GameWindow", "Score:", nullptr));
        label->setText(QCoreApplication::translate("GameWindow", "Game Over!", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "Player 1 Wins!", nullptr));
        label_3->setText(QCoreApplication::translate("GameWindow", "Player 2 Wins!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
