#ifndef UNSORTED_H
#define UNSORTED_H

#include <QWidget>

namespace Ui {
class unsorted;
}

class unsorted : public QWidget
{
    Q_OBJECT

public:
    explicit unsorted(QWidget *parent = nullptr);
    ~unsorted();

private:
    Ui::unsorted *ui;
};

#endif // UNSORTED_H
