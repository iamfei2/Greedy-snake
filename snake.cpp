#include "snake.h"
#include "qevent.h"

bool gamestart;
QTimer *timer;
Node* head;//蛇头
Node* tail;//蛇尾
//上下左右控件贪吃蛇移动
void keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        // 同方向或者反方向不做任何操作


    case Qt::Key_Left:
        if(dx == 0){
            dx = -1;
            dy = 0;

        }
        break;
    case Qt::Key_Right:
        if(dx == 0){
            dx = 1;
            dy = 0;

        }
        break;
    case Qt::Key_Up:
        if(dy == 0){
            dx = 0;
            dy = -1;

        }
        break;
    case Qt::Key_Down:
        if(dy == 0){
            dx = 0;
            dy = 1;

        }
        break;

    default:
        break;
    }
}


