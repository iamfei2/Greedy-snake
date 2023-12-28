#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QPainter>

#define xlen 40
#define ylen 40
#define xysize 15

//包含每一个节点的横纵坐标和类型
struct Node {
    int x;
    int y;
    int type;//结点类型
};
//Label包含空、障碍物、蛇、果实信息
enum Label {
    empty_lable,
    border_lable,
    snake_label,
    food_label
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class paintWidget : public QWidget
{
    Q_OBJECT;

public:
    friend class MainWindow;
    paintWidget(QMainWindow* parent = 0);
    Node map[xlen+10][ylen+10]; //游戏地图
    bool gamestart;
    QTimer *timer;

private:
    void paintEvent(QPaintEvent*);
    QPainter* paint;
    QList<Node*> snake; //snake
    QList<Node*> border;//border
    QList<Node*> food;  //food

    int dx, dy;
    int moveSpeed;
    int level;
    int bonus;
    int score;
    int roadLen;

    Node* head;//蛇头
    Node* tail;//蛇尾

signals:
    void restared();
    void paused();
    void moved();

public slots:
    void startGameSlot();
    void continueGameSlot();
    void restartGameSlot();
    void pauseGameSlot();
    void snakeMoveSlot();
    void saveGameSlot();
    void loadGameSlot();

public:
    void gameOver();
    void init();
    void drawSnake(int x, int y);
    void drawBorder(int x, int y);
    void drawFood(int x, int y);
    void moveSnake();
    void getHeadTail();
    void createFood();
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent* event);
    bool notinSnake(int x, int y);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    paintWidget* gamewidget;
    void keyPressEvent(QKeyEvent *event);
    QTimer* time;
    QString viewText;

private:
    Ui::MainWindow *ui;
    QLabel* mlabel;



public slots:
    void startGameSlot();
    void continueGameSlot();
    void restartGameSlot();
    void pauseGameSlot();
    void quitGameSlot();
    void snakeMoveSlot();
//    void saveGameSlot();
//    void loadGameSlot();
};
#endif // MAINWINDOW_H
