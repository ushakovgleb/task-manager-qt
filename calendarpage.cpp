#include "calendarpage.h"
#include "ui_calendarpage.h"

CalendarPage::CalendarPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalendarPage)
{
    ui->setupUi(this);
}

CalendarPage::~CalendarPage()
{
    delete ui;
}
