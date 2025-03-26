#ifndef CREATE_TASK_H
#define CREATE_TASK_H

#include <QWidget>

namespace Ui {
class MiniWindow;
}

class MiniWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MiniWindow(QWidget *parent = nullptr);
    ~MiniWindow();

private:
    Ui::MiniWindow *ui;
};

#endif // CREATE_TASK_H
