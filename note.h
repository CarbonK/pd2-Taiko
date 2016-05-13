#ifndef NOTE_H
#define NOTE_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QPixmap>

typedef unsigned long long ull;

class Note:
public QObject , public QGraphicsPixmapItem
{

    Q_OBJECT

    public:

        explicit Note(int , ull , double);
        ~Note();

        ull getGenTime();
        int getNoteType();

    private:

        int noteType;
        ull genTime;
        double moveSpeed;
        QPixmap *img;

    signals:

        void deleteNote(Note*);

    public slots:

        void moveNote();
        void detectPos();

};

#endif // NOTE_H
