#ifndef SNAKE_H
#define SNAKE_H

#include <QList>
#include <QPainter>

#define xlen 40
#define ylen 40
#define xysize 15


struct Node {
    int x;
    int y;
    int type;
};

QPainter* paint;

//Label包含空、障碍物、蛇、果实信息
enum Label {
    empty_lable,
    border_lable,
    snake_label,
    food_label
};

Node map[xlen+10][ylen+10]; //游戏地图

class Snake
{
public:
    Snake();

    void init();

    void drawSnake(int, int);

    void moveSnake();//蛇移动算法

    void getHeadTail();//获取头尾坐标

private:

    QList<Node*> snake;

    int dx, dy;//控制蛇的方向

    Node* head;//蛇头
    Node* tail;//蛇尾

    int moveSpeed;
};

#endif // SNAKE_H
