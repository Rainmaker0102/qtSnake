#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gameover.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    update();
    ui->setupUi(this);

    playerOneScore = 0;
    time = 0;
    x = 400;
    y = 20;
    speed = 20;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    QPen whiteoutline(Qt::white);
    outlinePen.setWidth(2);


    snakeHead = scene->addRect(x, y, 20, 20, outlinePen, blueBrush);
    bodyX.push_back(x);
    bodyY.push_back(y);
    previousX.push_back(x);
    previousY.push_back(y);
    snakeHead->setFlag(QGraphicsItem::ItemIsMovable);
    body.push_back(snakeHead);
    border = scene->addRect(40, -40, 780, 560, whiteoutline);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    spawnApple();
    //create a timer
    timer = new QTimer(this);

    //setup signal and slot
    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
    ui->pushButton->setHidden(true);

    //msec
    //timer->start(100);
    timer->start(50);


}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        if(player != DOWN)
        {
            player = UP;
        }
    }
    else if(event->key() == Qt::Key_S)
    {
        if(player != UP)
        {
            player = DOWN;
        }
    }
    else if(event->key() == Qt::Key_A)
    {
        if(player != RIGHT)
        {
            player = LEFT;
        }
    }
    else if(event->key() == Qt::Key_D)
    {
        if(player != LEFT)
        {
            player = RIGHT;
        }
    }
    else if(event->key() == Qt::Key_Escape)
    {
        close();
    }
}

void GameWindow::MyTimerSlot()
{
    //qDebug() << x << " " << y;
    time++;
    if(player == LEFT)
    {
        for (int i = 0; i < (int)(bodyX.size()); i++)
        {
            previousX.at(i) = bodyX.at(i);
            previousY.at(i) = bodyY.at(i);
        }
        x -= speed;
        if(x > -380)
        {
            for(int i = 0; i < body.size(); i++)
            {
                if(i == 0)
                {
                    snakeHead->setPos(x, y);
                    bodyX.at(i) = x;
                    bodyY.at(i) = y;
                }
                else
                {
                    body.at(i)->setPos(previousX.at(i-1), previousY.at(i-1));
                    bodyX.at(i) = previousX.at(i-1);
                    bodyY.at(i) = previousY.at(i-1);

                }
            }
        }
        else
        {
            GameOver *wdg = new GameOver;
            wdg->show();
            timer->stop();
            close();
        }
    }
    else if(player == RIGHT)
    {
        for (int i = 0; i < (int)(bodyX.size()); i++)
        {
            previousX.at(i) = bodyX.at(i);
            previousY.at(i) = bodyY.at(i);
        }
        x += speed;
        if(x < 420)
        {
            for(int i = 0; i < body.size(); i++)
            {
                if(i == 0)
                {
                    snakeHead->setPos(x, y);
                    bodyX.at(i) = x;
                    bodyY.at(i) = y;
                }
                else
                {
                    body.at(i)->setPos(previousX.at(i-1), previousY.at(i-1));
                    bodyX.at(i) = previousX.at(i-1);
                    bodyY.at(i) = previousY.at(i-1);
                }
            }
        }
        else
        {
            GameOver *wdg = new GameOver;
            wdg->show();
            timer->stop();
            close();
        }
    }
    else if(player == UP)
    {
        for (int i = 0; i < (int)(bodyX.size()); i++)
        {
            previousX.at(i) = bodyX.at(i);
            previousY.at(i) = bodyY.at(i);
        }
        y -= speed;
        if(y > -80)
        {
            for(int i = 0; i < body.size(); i++)
            {
                if(i == 0)
                {
                    snakeHead->setPos(x, y);
                    bodyX.at(i) = x;
                    bodyY.at(i) = y;
                }
                else
                {
                    body.at(i)->setPos(previousX.at(i-1), previousY.at(i-1));
                    bodyX.at(i) = previousX.at(i-1);
                    bodyY.at(i) = previousY.at(i-1);
                }
            }
        }
        else
        {
            GameOver *wdg = new GameOver;
            wdg->show();
            timer->stop();
            close();
        }
    }
    else if(player == DOWN)
    {
        for (int i = 0; i < (int)(bodyX.size()); i++)
        {
            previousX.at(i) = bodyX.at(i);
            previousY.at(i) = bodyY.at(i);
        }
        y += speed;
        if(y < 500)
        {
            for(int i = 0; i < body.size(); i++)
            {
                if(i == 0)
                {
                    snakeHead->setPos(x, y);
                    bodyX.at(i) = x;
                    bodyY.at(i) = y;
                }
                else
                {
                    body.at(i)->setPos(previousX.at(i-1), previousY.at(i-1));
                    bodyX.at(i) = previousX.at(i-1);
                    bodyY.at(i) = previousY.at(i-1);
                }
            }
        }
        //snakeHead->setPos(x, y);
        else
        {
            GameOver *wdg = new GameOver;
            wdg->show();
            timer->stop();
            close();
        }

    }
    checkCollision();
    checkApple();

}

void GameWindow::on_pushButton_clicked()
{
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    QGraphicsRectItem *bodyPart = new QGraphicsRectItem;
    bodyPart = scene->addRect(400, 20, 20, 20, outlinePen, blueBrush);
    body.push_back(bodyPart);
    bodyX.push_back(x);
    bodyY.push_back(y);
    previousX.push_back(x);
    previousY.push_back(y);
    moveApple();
}

void GameWindow::increaseSnake()
{
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    QGraphicsRectItem *bodyPart = new QGraphicsRectItem;
    bodyPart = scene->addRect(400, 20, 20, 20, outlinePen, blueBrush);
    bodyPart->setPos(previousX.at(previousX.size()-1), previousY.at(previousY.size()-1));
    body.push_back(bodyPart);
    bodyX.push_back(x);
    bodyY.push_back(y);
    previousX.push_back(x);
    previousY.push_back(y);
    playerOneScore ++;
    this->ui->lcdNumber->display(playerOneScore);
}

void GameWindow::spawnApple()
{
    int applePosX;
    int applePosY;
    QPen outlinePen(Qt::black);
    QBrush brush(Qt::red);
    bool available = false;
    while(true)
    {
        applePosX = rand()%39+1;
        applePosY = rand()%28+1;
        for(int i = 0; i < bodyX.size(); i++)
        {
            if(applePosX != bodyX.at(i) || applePosY != bodyY.at(i))
            {
                available = true;
            }
            else
            {
                available = false;
                break;
            }
        }
        if(available == true)
        {
            apple = scene->addRect(40, -40, 20, 20, outlinePen, brush);
            apple->setPos(applePosX*20, applePosY*20);
            appleX = applePosX*20;
            appleY = applePosY*20;
            break;
        }
    }
}

void GameWindow::moveApple()
{
    int applePosX;
    int applePosY;
    QPen outlinePen(Qt::black);
    QBrush brush(Qt::red);
    bool available = false;
    while(true)
    {
        applePosX = rand()%38+1;
        applePosY = rand()%27+1;
        for(int i = 0; i < bodyX.size(); i++)
        {
            if(applePosX*20-360 != bodyX.at(i) || applePosY*20-60 != bodyY.at(i))
            {
                available = true;
            }
            else
            {
                available = false;
                break;
            }
        }
        if(available == true && applePosX )
        {
            //apple->setPos(applePosX*20, applePosY*20);
            apple->setPos(applePosX*20, applePosY*20);
            appleX = applePosX*20;
            appleY = applePosY*20;
            break;
        }
    }
}

void GameWindow::checkApple()
{
    if(appleX-360 == x && appleY-60 == y)
    {
        increaseSnake();
        moveApple();
    }
}

void GameWindow::checkCollision()
{
    for(int i = 0; i < body.size(); i++)
    {
        if(i != 0)
        {
            qDebug() << x << " " << bodyX.at(i);
            if(x == bodyX.at(i) && y == bodyY.at(i))
            {
                GameOver *wdg = new GameOver;
                wdg->show();
                timer->stop();
                close();
            }
        }
    }
//    GameOver *wdg = new GameOver;
//    wdg->show();
//    timer->stop();
//    close();
}
