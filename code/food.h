#ifndef FOOD_H
#define FOOD_H

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

class Food
{
public:
    Food();

    bool notinSnake(int x, int y);//判断是否在蛇内

    void createFood();//产生食物算法

    void drawFood(int, int);

    void init();//初始化函数，构造器调用

private:
    QList<Node*> food;
};

#endif // FOOD_H
