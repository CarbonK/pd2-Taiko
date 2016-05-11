#include "gamewindow.h"
#include "ui_gamewindow.h"

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

    newGame();

}

GameWindow::~GameWindow(){delete ui;}

void GameWindow::newGame(){
}
