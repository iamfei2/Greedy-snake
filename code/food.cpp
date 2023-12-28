#include "food.h"

QList<Node*> food;

bool notinSnake(int x, int y){//判断是否在蛇内

    for (int i = 0; i < food.length(); i++) {
    if (food.at(i)->x == x && food.at(i)->y == y)
      return false;
  }
        return true;

}

void createFood(){//产生食物算法
        int foodx;
        int foody;
        srand((unsigned)time(0));
        do {
    foodx = rand()%xlen;
    foody = rand()%ylen;
        }while(((foodx == 0)||(foody == 0)||(foodx==xlen-1)||(foody==ylen-1)) || !notinSnake(foodx, foody));
}


void drawFood(int x, int y){
        paint->setBrush(QBrush(Qt::green, Qt::SolidPattern));
        for(int i = 0; i < food.length(); i++)
    paint->drawRect(food[i]->x*xysize, food[i]->y*xysize, xysize, xysize);

        paint->setBrush(QBrush(Qt::green, Qt::SolidPattern));
        paint->drawRect(x*xysize, y*xysize, xysize, xysize);
        paint->end();
}

void init(){//初始化函数，构造器调用
        //数值初始化
        int bonus = 0;
        int dx = 1;
        int dy = 0;
        int score = 0;

        int snakelen= 2;
        int roadLen = 0;

        for(int i = 0; i < snakelen; i++) {
    food.append(0);//设置snake的坐标
        }
}



Food::Food()
{    paint->setBrush((QBrush(Qt::red, Qt::SolidPattern)));
        for(int i = 0; i < food.length(); i++)
    paint->drawEllipse(food[i]->x*xysize, food[i]->y*xysize, xysize, xysize);
}
