#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include <vector>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    QTimer *timer;
    int time;
    int x;
    int y;
    int speed;
    int difficulty;
    int gamemode;
    int appleX;
    int appleY;
    int playerOneScore;
    int playerTwoScore;

    enum direction {
        LEFT, RIGHT, UP, DOWN
    }player=DOWN, player2=DOWN;


    std::vector<QGraphicsRectItem*> body;
    std::vector<int> bodyX;
    std::vector<int> bodyY;
    std::vector<int> previousX;
    std::vector<int> previousY;
    void keyPressEvent(QKeyEvent *event);

    void increaseSnake(int player);
    void spawnApple();
    void moveApple();
    void checkApple();
    void checkCollision();
    void endGame();

    int p2x;
    int p2y;
    int p2speed;
    std::vector<QGraphicsRectItem*> p2body;
    std::vector<int> p2bodyX;
    std::vector<int> p2bodyY;
    std::vector<int> p2previousX;
    std::vector<int> p2previousY;
public slots:
    void MyTimerSlot();

private slots:

    void on_pushButton_clicked();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *snakeHead;
    QGraphicsRectItem *p2snakeHead;
    QGraphicsRectItem *border;
    QGraphicsRectItem *apple;


private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
