#include "snake.h"

Snake::Snake()
{

}


void Snake::init(){
    //数值初始化
    head = tail = NULL;
    int bonus = 0;
    int dx = 1;
    int dy = 0;
    int score = 0;

    int snakelen= 2;
    int roadLen = 0;

    for(int i = 0; i < snakelen; i++) {
        snake.append(0);
        map[i][i+5].type = snake_label;//设置snake的坐标
    }
}



void Snake::drawSnake(int x, int y){
    //画蛇
    paint->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    for(int i = 0; i < snake.length(); i++)
        paint->drawRect(snake[i]->x*xysize, snake[i]->y*xysize, xysize, xysize);

    //用画笔画
    paint->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    paint->drawRect(x*xysize, y*xysize, xysize, xysize);
    paint->end();
}



void Snake::moveSnake(){//蛇移动算法
    int roadLen;
    int bonus;
    Node temp;
    bool game_over;

    int score;

    roadLen++;

    getHeadTail();//获取🐍的头尾
    if(bonus == 0) {
        snake.removeFirst();
        tail->type = empty_lable;
    }
    else
        bonus--;
    //判断死亡
    if(temp.type == border_lable || temp.type == snake_label)
        game_over = true;
    //判断是移动还是吃食物得分
    else {
        snake.append(0);
        if(temp.type == food_label) {
            temp.type = empty_lable;
            score++;
            //food.removeFirst();
            bonus += 3;
        }
        else {
            temp.type = snake_label;
        }
    }
}

void Snake::getHeadTail();//获取头尾坐标
