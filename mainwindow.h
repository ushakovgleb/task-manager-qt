#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void clicked_on_date();

    void on_createnewtaskButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_removetaskButton_clicked();

    void on_tasksButton_clicked();

    void on_fortodayButton_clicked();

    void on_calendarButton_clicked();

    void on_unsortedButton_clicked();

    void on_TableView_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QWidget *tasksPage;
    QWidget *fortodayPage;
    QWidget *calendarPage;
    QWidget *unsortedPage;

    int row;
};
#endif // MAINWINDOW_H
