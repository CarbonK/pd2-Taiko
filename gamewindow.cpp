#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <new>

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

    ui->lka->hide();
    ui->ldon->hide();
    ui->rdon->hide();
    ui->rka->hide();

    timer = new QTimer;
    connect(timer , SIGNAL(timeout()) , this , SLOT(realTimer()));
    connect(timer , SIGNAL(timeout()) , this , SLOT(addNote()));
    connect(timer , SIGNAL(timeout()) , this , SLOT(detectPos()));

    newGame();

}

GameWindow::~GameWindow(){

    delete re;
    delete gen;
    delete timer;
    delete anime;
    delete ui;

}

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
    curNote = save.begin();

}

void GameWindow::hitJudge(int k){

    if(140 <= (*curNote)->x() && (*curNote)->x() <= 180){

        if((*curNote)->getNoteType() <= 2){

            if(k == Qt::Key_G || k == Qt::Key_H){

                if(150 <= (*curNote)->x() && (*curNote)->x() <= 170){

                    ++combo;
                    score += 300;

                }
                else if((140 <= (*curNote)->x() && (*curNote)->x() < 150) && (170 < (*curNote)->x() && (*curNote)->x() < 180)){

                    ++combo;
                    score += 100;

                }

            }
            else{

                combo = 0;

            }

        }
        else{

            if(k == Qt::Key_F || k == Qt::Key_J){

                if(150 <= (*curNote)->x() && (*curNote)->x() <= 170){

                    ++combo;
                    score += 300;

                }
                else if((140 <= (*curNote)->x() && (*curNote)->x() < 150) && (170 < (*curNote)->x() && (*curNote)->x() < 180)){

                    ++combo;
                    score += 100;

                }

            }
            else{

                combo = 0;

            }

        }

        removeNote();

    }

    ui->ScoreLCD_basic->display((int)score);

}

void GameWindow::hitImg(int k){

    switch (k){

        case Qt::Key_F:

            ui->lka->show();
            QTimer::singleShot(200 , ui->lka , SLOT(hide()));
            break;

        case Qt::Key_G:

            ui->ldon->show();
            QTimer::singleShot(200 , ui->ldon , SLOT(hide()));
            break;

        case Qt::Key_H:

            ui->rdon->show();
            QTimer::singleShot(200 , ui->rdon , SLOT(hide()));
            break;

        case Qt::Key_J:

            ui->rka->show();
            QTimer::singleShot(200 , ui->rka , SLOT(hide()));
            break;

    }

}

void GameWindow::removeNote(){

    anime->removeItem(*curNote);
    (*curNote)->~Note();
    ++curNote;

}

void GameWindow::removeNote(Note *n){

    anime->removeItem(n);
    n->~Note();

}


void GameWindow::realTimer(){

    curTime += 20;
    ui->TimeLCD_basic->display(30 - (int)curTime / 1000);
    if(curTime / 1000 == 30){

        timer->stop();

        re = new Result(score , combo);
        re->show();
        connect(re , SIGNAL(accepted()) , this , SLOT(newGame()));
        connect(re , SIGNAL(rejected()) , this , SLOT(close()));

    }

}

void GameWindow::addNote(){

    //unadded != save.end() first or crash
    if(unadded != save.end() && curTime == (*unadded)->getGenTime()){

        anime->addItem(*unadded);
        connect(timer , SIGNAL(timeout()) , *unadded , SLOT(moveNote()));
        connect(timer , SIGNAL(timeout()) , *unadded , SLOT(detectPos()));
        connect(*unadded , SIGNAL(deleteNote(Note*)) , this , SLOT(removeNote(Note*)));
        unadded++;

    }

}

void GameWindow::keyPressEvent(QKeyEvent *k){

    switch (k->key()){

        case Qt::Key_F:

            hitJudge(Qt::Key_F);
            hitImg(Qt::Key_F);
            break;

        case Qt::Key_G:

            hitJudge(Qt::Key_G);
            hitImg(Qt::Key_G);
            break;

        case Qt::Key_H:

            hitJudge(Qt::Key_H);
            hitImg(Qt::Key_H);
            break;

        case Qt::Key_J:

            hitJudge(Qt::Key_J);
            hitImg(Qt::Key_J);
            break;

    }

}

void GameWindow::detectPos(){if((*curNote)->x() < 140) ++curNote;}
