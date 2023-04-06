#include "gameover.h"
#include "ui_gameover.h"
#include <fstream>
#include <string>
#include <QLabel>
#include <QString>
#include <QFont>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    std::this_thread::sleep_for(std::chrono::microseconds{500});
    std::ifstream ifs;
    ifs.open("../snakeGame/result.ini");
    std::string data;
    ifs >> data;
    QString text = QString::fromStdString(data);
    QLabel *lbl;
    lbl=new QLabel(this);
    lbl->setText(text);
    QFont font1;
    font1.setPointSize(35);
    lbl->setFont(font1);
    lbl->show();
    ifs.close();
    if(text == "")
    {
        GameOver *wdg = new GameOver;
        wdg->show();
        close();
    }
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    close();
}

