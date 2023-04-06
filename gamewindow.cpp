#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <QLabel>
#include <QFont>
#include <string>

using namespace std;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    update();
    ui->setupUi(this);

    ifstream ifs;
    ifs.open("./config.ini");
    ifs >> difficulty;
    ifs >> gamemode;
    ifs.close();

    //init values
    playerOneScore = 0;
    playerTwoScore = 0;
    time = 0;
    x = 400;
    y = 20;
    speed = 20;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen outlinePen(Qt::black);
    QPen whiteoutline(Qt::white);
    outlinePen.setWidth(2);

    //Load player snake and play area border
    snakeHead = scene->addRect(x, y, 20, 20, outlinePen, blueBrush);
    snakeHead->setPos(-360, -60);
    x = -360;
    y = -60;
    bodyX.push_back(x);
    bodyY.push_back(y);
    previousX.push_back(x);
    previousY.push_back(y);
    snakeHead->setFlag(QGraphicsItem::ItemIsMovable);
    body.push_back(snakeHead);
    border = scene->addRect(40, -40, 780, 560, whiteoutline);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
//    ui->label->setHidden(true);
//    ui->label_2->setHidden(true);
//    ui->label_3->setHidden(true);


    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    spawnApple();
    //create a timer
    timer = new QTimer(this);

    //setup signal and slot
    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
    ui->pushButton->setHidden(true);

    //msec
//    timer->start(100);
    if(difficulty == 0)
    {
        timer->start(150);
    }
    else if(difficulty == 1)
    {
        timer->start(100);
    }
    else if(difficulty == 2)
    {
        timer->start(50);
    }
    else {
        timer->start(150);
    }
    if(gamemode == 1)
    {
        ui->singlePlayerScoreLabel->setHidden(true);
        ui->lcdNumber->setHidden(true);
        p2x = 400;
        p2y = 20;
        p2speed = 20;
        p2snakeHead = scene->addRect(p2x, p2y, 20, 20, outlinePen, greenBrush);
        //p2snakeHead->setPos(-360, -60);
        p2snakeHead->setPos(400, -60);
        p2x = 400;
        p2y = -60;
        p2bodyX.push_back(p2x);
        p2bodyY.push_back(p2y);
        p2previousX.push_back(p2x);
        p2previousY.push_back(p2y);
        p2snakeHead->setFlag(QGraphicsItem::ItemIsMovable);
        p2body.push_back(p2snakeHead);

        increaseSnake(1);
        increaseSnake(1);
        increaseSnake(1);
        increaseSnake(1);
        increaseSnake(1);
        increaseSnake(1);
        increaseSnake(2);
        increaseSnake(2);
        increaseSnake(2);
        increaseSnake(2);
        increaseSnake(2);
        increaseSnake(2);
    }
//    ui->setupUi(this);
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

    if(event->key() == Qt::Key_I)
    {
        if(player2 != DOWN)
        {
            player2 = UP;
        }
    }
    else if(event->key() == Qt::Key_K)
    {
        if(player2 != UP)
        {
            player2 = DOWN;
        }
    }
    else if(event->key() == Qt::Key_J)
    {
        if(player2 != RIGHT)
        {
            player2 = LEFT;
        }
    }
    else if(event->key() == Qt::Key_L)
    {
        if(player2 != LEFT)
        {
            player2 = RIGHT;
        }
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
            qDebug() << "Snake left the left side";
            endGame();
            if(gamemode == 0)
            {
                this->ui->lcdNumber->setVisible(true);
                this->ui->singlePlayerScoreLabel->setVisible(true);
            }
            else
            {
                this->ui->label_3->setVisible(true);
            }
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
            qDebug() << "Snake left the right side";
            endGame();
            if(gamemode == 0)
            {
                this->ui->lcdNumber->setVisible(true);
                this->ui->singlePlayerScoreLabel->setVisible(true);
            }
            else
            {
                this->ui->label_3->setVisible(true);
            }
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
            qDebug() << "Snake left the top side";

            endGame();
            if(gamemode == 0)
            {
                this->ui->lcdNumber->setVisible(true);
                this->ui->singlePlayerScoreLabel->setVisible(true);
            }
            else
            {
                this->ui->label_3->setVisible(true);
            }
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
            qDebug() << "Snake left the bottom side";
            endGame();
            if(gamemode == 0)
            {
                this->ui->lcdNumber->setVisible(true);
                this->ui->singlePlayerScoreLabel->setVisible(true);
            }
            else
            {
                this->ui->label_3->setVisible(true);
            }
        }

    }
    if(gamemode == 1)
    {
        if(player2 == LEFT)
        {
            for (int i = 0; i < (int)(p2bodyX.size()); i++)
            {
                p2previousX.at(i) = p2bodyX.at(i);
                p2previousY.at(i) = p2bodyY.at(i);
            }
            p2x -= p2speed;
            if(p2x > -380)
            {
                for(int i = 0; i < p2body.size(); i++)
                {
                    if(i == 0)
                    {
                        p2snakeHead->setPos(p2x, p2y);
                        p2bodyX.at(i) = p2x;
                        p2bodyY.at(i) = p2y;
                    }
                    else
                    {
                        p2body.at(i)->setPos(p2previousX.at(i-1), p2previousY.at(i-1));
                        p2bodyX.at(i) = p2previousX.at(i-1);
                        p2bodyY.at(i) = p2previousY.at(i-1);

                    }
                }
            }
            else
            {
                endGame();
                this->ui->label_2->setVisible(true);
            }
        }
        else if(player2 == RIGHT)
        {
            for (int i = 0; i < (int)(p2bodyX.size()); i++)
            {
                p2previousX.at(i) = p2bodyX.at(i);
                p2previousY.at(i) = p2bodyY.at(i);
            }
            p2x += p2speed;
            if(p2x < 420)
            {
                for(int i = 0; i < p2body.size(); i++)
                {
                    if(i == 0)
                    {
                        p2snakeHead->setPos(p2x, p2y);
                        p2bodyX.at(i) = p2x;
                        p2bodyY.at(i) = p2y;
                    }
                    else
                    {
                        p2body.at(i)->setPos(p2previousX.at(i-1), p2previousY.at(i-1));
                        p2bodyX.at(i) = p2previousX.at(i-1);
                        p2bodyY.at(i) = p2previousY.at(i-1);
                    }
                }
            }
            else
            {
                endGame();
                this->ui->label_2->setVisible(true);
            }
        }
        else if(player2 == UP)
        {
            for (int i = 0; i < (int)(p2bodyX.size()); i++)
            {
                p2previousX.at(i) = p2bodyX.at(i);
                p2previousY.at(i) = p2bodyY.at(i);
            }
            p2y -= p2speed;
            if(p2y > -80)
            {
                for(int i = 0; i < p2body.size(); i++)
                {
                    if(i == 0)
                    {
                        p2snakeHead->setPos(p2x, p2y);
                        p2bodyX.at(i) = p2x;
                        p2bodyY.at(i) = p2y;
                    }
                    else
                    {
                        p2body.at(i)->setPos(p2previousX.at(i-1), p2previousY.at(i-1));
                        p2bodyX.at(i) = p2previousX.at(i-1);
                        p2bodyY.at(i) = p2previousY.at(i-1);
                    }
                }
            }
            else
            {
                endGame();
                this->ui->label_2->setVisible(true);
            }
        }
        else if(player2 == DOWN)
        {
            for (int i = 0; i < (int)(p2bodyX.size()); i++)
            {
                p2previousX.at(i) = p2bodyX.at(i);
                p2previousY.at(i) = p2bodyY.at(i);
            }
            p2y += p2speed;
            if(p2y < 500)
            {
                for(int i = 0; i < p2body.size(); i++)
                {
                    if(i == 0)
                    {
                        p2snakeHead->setPos(p2x, p2y);
                        p2bodyX.at(i) = p2x;
                        p2bodyY.at(i) = p2y;
                    }
                    else
                    {
                        p2body.at(i)->setPos(p2previousX.at(i-1), p2previousY.at(i-1));
                        p2bodyX.at(i) = p2previousX.at(i-1);
                        p2bodyY.at(i) = p2previousY.at(i-1);
                    }
                }
            }
            //snakeHead->setPos(x, y);
            else
            {
                endGame();
                this->ui->label_2->setVisible(true);
            }

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

void GameWindow::increaseSnake(int player)
{
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    if(player == 1)
    {
        QGraphicsRectItem *bodyPart = new QGraphicsRectItem;
        bodyPart = scene->addRect(400, 20, 20, 20, outlinePen, blueBrush);
        bodyPart->setPos(previousX.at(previousX.size()-1), previousY.at(previousY.size()-1));
        body.push_back(bodyPart);
        bodyX.push_back(x);
        bodyY.push_back(y);
        previousX.push_back(x);
        previousY.push_back(y);
        if(gamemode == 0)
        {
            playerOneScore ++;
            this->ui->lcdNumber->display(playerOneScore);
        }
    }
    else if(player == 2)
    {
        QGraphicsRectItem *bodyPart = new QGraphicsRectItem;
        bodyPart = scene->addRect(400, 20, 20, 20, outlinePen, greenBrush);
        bodyPart->setPos(p2previousX.at(p2previousX.size()-1), p2previousY.at(p2previousY.size()-1));
        p2body.push_back(bodyPart);
        p2bodyX.push_back(p2x);
        p2bodyY.push_back(p2y);
        p2previousX.push_back(p2x);
        p2previousY.push_back(p2y);
    }

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
        applePosX = rand()%38+1;
        applePosY = rand()%27+1;
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
        for(int i = 0; i < p2bodyX.size(); i++)
        {
            if(applePosX != p2bodyX.at(i) || applePosY != p2bodyY.at(i))
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
        for(int i = 0; i < p2bodyX.size(); i++)
        {
            if(applePosX*20-360 != p2bodyX.at(i) || applePosY*20-60 != p2bodyY.at(i))
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
        increaseSnake(1);
        moveApple();
    }
    else if(appleX-360 == p2x && appleY-60 == p2y)
    {
        increaseSnake(2);
        moveApple();
    }
}

void GameWindow::checkCollision()
{
    for(int i = 0; i < (int) body.size(); i++)
    {
        if(i != 0)
        {
            //qDebug() << x << " " << bodyX.at(i);
            if(x == bodyX.at(i) && y == bodyY.at(i))
            {
                qDebug() << "Collision Detected";
                endGame();
                if(gamemode == 0)
                {
                    this->ui->lcdNumber->setVisible(true);
                    this->ui->singlePlayerScoreLabel->setVisible(true);
                    //player 1 score

                }
                else{
                    //player 2 wins
                    this->ui->label_3->setVisible(true);
                }

            }
            if(gamemode == 1)
            {
                if(p2x == bodyX.at(i) && p2y == bodyY.at(i))
                {
                    endGame();
                    //player 1 wins
                    this->ui->label_2->setVisible(true);

                }
            }
        }
    }
    if(gamemode == 1)
    {
        for(int i = 0; i < p2body.size(); i++)
        {
            if(i != 0)
            {
                //qDebug() << x << " " << bodyX.at(i);
                if(p2x == p2bodyX.at(i) && p2y == p2bodyY.at(i))
                {
                    endGame();
                    //player one wins
                    this->ui->label_2->setVisible(true);
                }

                if(x == p2bodyX.at(i) && y == p2bodyY.at(i))
                {
                    endGame();
                    //player 2 wins
                    this->ui->label_3->setVisible(true);

                }
            }
        }
    }
//    GameOver *wdg = new GameOver;
//    wdg->show();
//    timer->stop();
//    close();
}

void GameWindow::endGame()
{
    timer->stop();
    for(int q = 0; q < body.size(); q++)
    {
        body.at(q)->setVisible(false);
    }
    if(gamemode == 1)
    {
        for(int q = 0; q < p2body.size(); q++)
        {
            p2body.at(q)->setVisible(false);
        }
    }
    apple->setVisible(false);
    border->setVisible(false);
    this->ui->lcdNumber->setVisible(false);
    this->ui->singlePlayerScoreLabel->setVisible(false);
    this->ui->label->setVisible(true);
}

