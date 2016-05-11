#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QVector>

namespace Ui{class GameWindow;}

class GameWindow:
public QMainWindow
{

    Q_OBJECT

    public:

        explicit GameWindow(QWidget *parent = 0);
        ~GameWindow();

    private:

        Ui::GameWindow *ui;
        QGraphicsScene *anime;

        void newGame();

};

#endif // GAMEWINDOW_H
