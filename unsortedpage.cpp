#include "unsortedpage.h"
#include "ui_unsortedpage.h"

UnsortedPage::UnsortedPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnsortedPage)
{
    ui->setupUi(this);
}

UnsortedPage::~UnsortedPage()
{
    delete ui;
}
