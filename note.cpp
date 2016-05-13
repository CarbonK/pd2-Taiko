#include "note.h"

#include <new>

Note::Note(int ty , ull ti , double sp){

    noteType = ty , genTime = ti , moveSpeed = sp;

    switch (noteType){

        case 1:

            img = new QPixmap(":/Resource/Image/Don.png");
            setPos(804 , 64);
            break;

        case 2:

            img = new QPixmap(":/Resource/Image/Daidon.png");
            setPos(800 , 60);
            break;

        case 3:

            img = new QPixmap(":/Resource/Image/Katsu.png");
            setPos(804 , 64);
            break;

        case 4:

            img = new QPixmap(":/Resource/Image/Daikatsu.png");
            setPos(800 , 60);
            break;

    }

    setPixmap(*img);

}

Note::~Note(){delete img;}

ull Note::getGenTime(){return genTime;}

int Note::getNoteType(){return noteType;}

void Note::moveNote(){setX(x() - moveSpeed);}

void Note::detectPos(){if(x() < 120) emit deleteNote(this);}
