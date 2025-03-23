#include "create_task.h"
#include "ui_create_task.h"

MiniWindow::MiniWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MiniWindow)
{
    ui->setupUi(this);
}

MiniWindow::~MiniWindow()
{
    delete ui;
}
