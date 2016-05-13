#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "note.h"

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
        int combo;
        ull score;
        QVector<Note*> save;
        Note *gen;
        QTimer *timer;
        ull curTime;
        QVector<Note*>::iterator unadded;
        QVector<Note*>::iterator curNote;

        void newGame();
        void hitJudge(int);

    public slots:

        void removeNote();
        void removeNote(Note*);

    private slots:

        void realTimer();
        void addNote();
        void keyPressEvent(QKeyEvent *k);
        void detectPos();

};

#endif // GAMEWINDOW_H
