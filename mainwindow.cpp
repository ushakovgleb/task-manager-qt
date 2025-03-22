#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include "miniwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //кнопки дат(вызов функции при нажатии)
    connect(ui->monday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->monday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->monday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->monday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->monday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->monday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->tuesday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->tuesday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->tuesday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->tuesday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->tuesday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->tuesday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->wednesday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->wednesday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->wednesday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->wednesday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->wednesday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->wednesday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->thursday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->thursday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->thursday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->thursday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->thursday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->thursday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->friday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->friday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->friday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->friday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->friday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->friday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->saturday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->saturday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->saturday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->saturday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->saturday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->saturday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->sunday1,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->sunday2,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->sunday3,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->sunday4,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->sunday5,SIGNAL(clicked()), this, SLOT(clicked_on_date()));
    connect(ui->sunday6,SIGNAL(clicked()), this, SLOT(clicked_on_date()));





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

