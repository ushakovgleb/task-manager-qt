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
    query->exec("CREATE TABLE Tasks(Задачи TEXT);");

    //инициализация модели
    model = new QSqlTableModel(this, db);
    model->setTable("Tasks");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setStyleSheet(
            "QTableView::item {"
            "    border: 1px solid #000000;"
            "    padding: 5px;"
            "}"
            "QHeaderView::section {"
            "    background-color: #f0f0f0;"
            "    padding: 4px;"
            "    border: 1px solid #dcdcdc;"
            "}"
        );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());
}


void MainWindow::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount());
}

