#include "plans.h"
#include "ui_plans.h"

plans::plans(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::plans)
{
    ui->setupUi(this);
}

plans::~plans()
{
    delete ui;
}
