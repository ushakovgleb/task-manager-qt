#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_fortodaypage.h"
#include "ui_calendarpage.h"
#include "ui_unsortedpage.h"
#include <QtSql/QSqlDatabase>
#include "create_task.h"
#include "QSqlError"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fortodayPage(new QWidget)
    , calendarPage(new QWidget)
    , unsortedPage(new QWidget)
{
    ui->setupUi(this);

    Ui::ForTodayPage uiForToday;
    uiForToday.setupUi(fortodayPage);
    Ui::CalendarPage uiCalendar;
    uiCalendar.setupUi(calendarPage);
    Ui::UnsortedPage uiUnsorted;
    uiUnsorted.setupUi(unsortedPage);

    ui->stackedWidget->addWidget(fortodayPage);
    ui->stackedWidget->addWidget(calendarPage);
    ui->stackedWidget->addWidget(unsortedPage);

    ui->stackedWidget->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./DB.db");
    if(db.open())
    {
        qDebug("open db");
    }
    else
    {
        qDebug("no open db");
    }

    //создание БД
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Tasks(Задачи TEXT);");

    //инициализация модели бд для задачи
    model = new QSqlTableModel(this, db);
    model->setTable("Tasks");
    model->select();

    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);

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

MainWindow::~MainWindow()
{
    delete ui;
}



//кнопка для добавления задачи
void MainWindow::on_createnewtaskButton_clicked()
{
    model->insertRows(model->rowCount(), 1);
}
//кнопка для удаления задачи
void MainWindow::on_removetaskButton_clicked()
{
    //удаление задачи
    if (model->removeRow(row)) {
        //изминение в бд
        if (model->submitAll()) {
            //обновление бд
            model->select();
        } else {
            qDebug() << "Ошибка при сохранении изменений:" << model->lastError().text();
        }
    } else {
        qDebug() << "Ошибка при удалении строки!";
    }


}
//отслеживание выбора стркои пользователем
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();

    if (!index.isValid()) return;

    // Получаем данные из модели
    int id = model->data(model->index(row, 0)).toInt();
    QString title = model->data(model->index(row, 1)).toString();
    QString description = model->data(model->index(row, 2)).toString();

    // Показываем всплывающее окно
    QMessageBox::information(this,
                             "Информация о задаче",
                             QString("ID: %1\nНазвание: %2\nОписание: %3")
                                 .arg(id)
                                 .arg(title)
                                 .arg(description));
}

void MainWindow::on_tasksButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(tasksPage);
}

void MainWindow::on_fortodayButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(fortodayPage);

}


void MainWindow::on_calendarButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(calendarPage);

}


void MainWindow::on_unsortedButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(unsortedPage);

}
