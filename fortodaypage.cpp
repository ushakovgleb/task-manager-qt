#include "fortodaypage.h"
#include "ui_fortodaypage.h"

ForTodayPage::ForTodayPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ForTodayPage)
{
    ui->setupUi(this);
}

ForTodayPage::~ForTodayPage()
{
    delete ui;
}
