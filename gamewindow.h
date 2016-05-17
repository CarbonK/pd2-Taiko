#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "note.h"
#include "result.h"

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
        int maxCombo;
        ull score;
        QVector<Note*> save;
        Note *gen;
        QTimer *timer;
        ull curTime;
        QVector<Note*>::iterator unadded;
        QVector<Note*>::iterator curNote;
        Result *re;

        void hitJudge(int);
        void hitImg(int);

    public slots:

        void removeNote();
        void removeNote(Note*);
        void newGame();

    private slots:

        void realTimer();
        void addNote();
        void keyPressEvent(QKeyEvent*);
        void detectPos();

};

#endif // GAMEWINDOW_H
