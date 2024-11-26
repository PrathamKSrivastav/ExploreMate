#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>

namespace Ui {
class resultwindow;
}

class resultwindow : public QWidget
{
    Q_OBJECT

public:
    explicit resultwindow(QWidget *parent = nullptr);
    ~resultwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::resultwindow *ui;
};

#endif // RESULTWINDOW_H
