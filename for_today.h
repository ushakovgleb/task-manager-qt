#ifndef FOR_TODAY_H
#define FOR_TODAY_H

#include <QWidget>

namespace Ui {
class for_today;
}

class for_today : public QWidget
{
    Q_OBJECT

public:
    explicit for_today(QWidget *parent = nullptr);
    ~for_today();

private:
    Ui::for_today *ui;
};

#endif // FOR_TODAY_H
