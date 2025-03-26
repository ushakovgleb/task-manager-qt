#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include "create_task.h"

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

    //инициализация модели бд для задачи
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

void MainWindow::clicked_on_date()
{
    MiniWindow* miniWindow = new MiniWindow(this);

    QSize mainWindowSize = this->size();

    // Вычисление размеров и положения выпадающего виджета
    QSize dropdownSize = QSize(800, 450); // Установите желаемый размер
    int x = (mainWindowSize.width() - dropdownSize.width()) / 2;
    int y = (mainWindowSize.height() - dropdownSize.height()) / 2;

    // Установка положения выпадающего виджета
    miniWindow->move(x, y);

    miniWindow->show();
}

