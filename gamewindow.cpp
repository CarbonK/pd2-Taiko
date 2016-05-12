#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <cstdlib>
#include <new>
#include <ctime>

GameWindow::GameWindow(QWidget *parent):
QMainWindow(parent) , ui(new Ui::GameWindow)
{

    ui->setupUi(this);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    anime = new QGraphicsScene(0 , 0 , 800 , 160);
    QPixmap hantei(":/Resource/Image/Hantei.png");
    QGraphicsPixmapItem *hanteiItem = new QGraphicsPixmapItem(hantei);
    hanteiItem->setPos(160 , 60);
    anime->addItem(hanteiItem);;
    ui->graphicsView->setScene(anime);

    timer = new QTimer;
    connect(timer , SIGNAL(timeout()) , this , SLOT(realTimer()));
    connect(timer , SIGNAL(timeout()) , this , SLOT(addNote()));

    newGame();

}

GameWindow::~GameWindow(){delete ui;}

void GameWindow::newGame(){

    srand(time(NULL));
    combo = 0 , score = 0 , curTime = 0;
    save.clear();

    ui->ScoreLCD_basic->display((int)score);
    ui->TimeLCD_basic->display(30 - (int)curTime / 1000);

    ull ti = 0;

    //vvvvv basic vvvv
    int interval = 1000;
    while(ti < 28000){

        ti += interval;
        gen = new Note(rand() % 4 + 1 , ti , 6.4);
        save.push_back(gen);

    }
    //^^^^^ basic ^^^^^

    timer->start(20);
    unadded = save.begin();

}

void GameWindow::judge(int k){



}

void GameWindow::realTimer(){

    curTime += 20;
    ui->TimeLCD_basic->display(30 - (int)curTime / 1000);
    if(curTime / 1000 == 30) timer->stop();

}

void GameWindow::addNote(){

    //unadded != save.end() first or crash
    if(unadded != save.end() && curTime == (*unadded)->getGenTime()){

        anime->addItem(*unadded);
        connect(timer , SIGNAL(timeout()) , *unadded , SLOT(moveNote()));
        unadded++;

    }

}

void GameWindow::keyPressEvent(QKeyEvent *k){

    switch (k->key()){

        case Qt::Key_F:

            judge(Qt::Key_F);
            break;

        case Qt::Key_G:

            judge(Qt::Key_G);
            break;

        case Qt::Key_H:

            judge(Qt::Key_H);
            break;

        case Qt::Key_J:

            judge(Qt::Key_J);
            break;

    }

}
