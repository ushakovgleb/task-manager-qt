#ifndef PLANS_H
#define PLANS_H

#include <QWidget>

namespace Ui {
class plans;
}

class plans : public QWidget
{
    Q_OBJECT

public:
    explicit plans(QWidget *parent = nullptr);
    ~plans();

private:
    Ui::plans *ui;
};

#endif // PLANS_H
