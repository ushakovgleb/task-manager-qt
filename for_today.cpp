#include "for_today.h"
#include "ui_for_today.h"

for_today::for_today(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::for_today)
{
    ui->setupUi(this);
}

for_today::~for_today()
{
    delete ui;
}
