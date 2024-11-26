#ifndef THANKYOUWINDOW_H
#define THANKYOUWINDOW_H

#include <QWidget>

namespace Ui {
class thankyouwindow;
}

class thankyouwindow : public QWidget
{
    Q_OBJECT

public:
    explicit thankyouwindow(QWidget *parent = nullptr);
    ~thankyouwindow();

private slots:
    void on_ExploreBtn_clicked();

private:
    Ui::thankyouwindow *ui;
};

#endif // THANKYOUWINDOW_H
