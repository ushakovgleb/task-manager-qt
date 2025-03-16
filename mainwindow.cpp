#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./DB.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
        qDebug("no open");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE UsersTasks(Задача TEXT, Заметка TEXT);");

    //инициализация модели
    model = new QSqlTableModel(this, db);
    model->setTable("UsersTasks");
    model->select();

}

MainWindow::~MainWindow()
{
    delete ui;
}
