#ifndef UNSORTEDPAGE_H
#define UNSORTEDPAGE_H

#include <QWidget>

namespace Ui {
class UnsortedPage;
}

class UnsortedPage : public QWidget
{
    Q_OBJECT

public:
    explicit UnsortedPage(QWidget *parent = nullptr);
    ~UnsortedPage();

private:
    Ui::UnsortedPage *ui;
};

#endif // UNSORTEDPAGE_H
