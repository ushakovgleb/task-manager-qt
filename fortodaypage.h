#ifndef FORTODAYPAGE_H
#define FORTODAYPAGE_H

#include <QWidget>

namespace Ui {
class ForTodayPage;
}

class ForTodayPage : public QWidget
{
    Q_OBJECT

public:
    explicit ForTodayPage(QWidget *parent = nullptr);
    ~ForTodayPage();

private:
    Ui::ForTodayPage *ui;
};

#endif // FORTODAYPAGE_H
