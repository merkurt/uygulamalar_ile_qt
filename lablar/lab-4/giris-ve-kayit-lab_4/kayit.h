#ifndef KAYIT_H
#define KAYIT_H

#include <QWidget>

namespace Ui {
class kayit;
}

class kayit : public QWidget
{
    Q_OBJECT

public:
    explicit kayit(QWidget *parent = 0);
    ~kayit();

private:
    Ui::kayit *ui;
};

#endif // KAYIT_H
