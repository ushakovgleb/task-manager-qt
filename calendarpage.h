#ifndef CALENDARPAGE_H
#define CALENDARPAGE_H

#include <QWidget>

namespace Ui {
class CalendarPage;
}

class CalendarPage : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarPage(QWidget *parent = nullptr);
    ~CalendarPage();

private:
    Ui::CalendarPage *ui;
};

#endif // CALENDARPAGE_H
