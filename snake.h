#ifndef SNAKE_H
#define SNAKE_H


#include "qevent.h"
#endif // SNAKE_H

void paintEvent(QPaintEvent*);
QPainter* paint;


int dx, dy;
int moveSpeed;
int level;
int bonus;
int score;
int roadLen;

//包含每一个节点的横纵坐标和类型
struct Node {
    int x;
    int y;
    int type;
};

//Label包含空、障碍物、蛇、果实信息
    enum Label {
        empty_lable,
        border_lable,
        snake_label,
        food_label
    };

void keyPressEvent(QKeyEvent *event);

