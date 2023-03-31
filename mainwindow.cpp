#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include <iostream>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

enum Difficulty {
    EASY, NORMAL, HARD
}gameDifficulty=EASY;

enum GamemodeChoice {
    SINGLEPLAYER, MULTIPLAYER
}gameMode=SINGLEPLAYER;



void MainWindow::on_pushButton_clicked()
{
    cout << "Difficulty set to " << gameDifficulty << endl;
    ofstream ofs;
    ofs.open("./config.ini");
    if(ofs.fail())
    {
        throw("Failed to write to config");
    }
    ofs << gameDifficulty;
    ofs << " ";
    ofs << gameMode;
    ofs.close();
    GameWindow *wdg = new GameWindow;
    wdg->show();
    hide();

}


void MainWindow::on_easyRadioButton_clicked()
{
    this->ui->easyRadioButton->setChecked(true);
    this->ui->normalRadioButton->setChecked(false);
    this->ui->hardRadioButton->setChecked(false);
    gameDifficulty = EASY;
    cout << "Difficulty set to " << gameDifficulty << endl;
}


void MainWindow::on_normalRadioButton_clicked()
{
    this->ui->easyRadioButton->setChecked(false);
    this->ui->normalRadioButton->setChecked(true);
    this->ui->hardRadioButton->setChecked(false);
    gameDifficulty = NORMAL;
    cout << "Difficulty set to " << gameDifficulty << endl;
}


void MainWindow::on_hardRadioButton_clicked()
{
    this->ui->easyRadioButton->setChecked(false);
    this->ui->normalRadioButton->setChecked(false);
    this->ui->hardRadioButton->setChecked(true);
    gameDifficulty = HARD;
    cout << "Difficulty set to " << gameDifficulty << endl;
}


void MainWindow::on_singleplayerRadioButton_clicked()
{
    this->ui->singleplayerRadioButton->setChecked(true);
    this->ui->multiplayerRadioButton->setChecked(false);
    gameMode = SINGLEPLAYER;
}


void MainWindow::on_multiplayerRadioButton_clicked()
{
    this->ui->singleplayerRadioButton->setChecked(false);
    this->ui->multiplayerRadioButton->setChecked(true);
    gameMode = MULTIPLAYER;
}

