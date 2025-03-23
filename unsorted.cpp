#include "unsorted.h"
#include "ui_unsorted.h"

unsorted::unsorted(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::unsorted)
{
    ui->setupUi(this);
}

unsorted::~unsorted()
{
    delete ui;
}
