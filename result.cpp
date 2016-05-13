#include "result.h"
#include "ui_result.h"

Result::Result(int score , int combo , QWidget *parent):
QDialog(parent) , ui(new Ui::Result)
{

    ui->setupUi(this);

    ui->ScoreLCD->display(score);
    ui->ComboLCD->display(combo);

}

Result::~Result(){delete ui;}
