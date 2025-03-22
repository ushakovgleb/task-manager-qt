    #ifndef MINIWINDOW_H
#define MINIWINDOW_H

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

#endif // MINIWINDOW_H
