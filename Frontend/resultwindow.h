#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QLabel>

namespace Ui {
class resultwindow;
}

class resultwindow : public QWidget
{
    Q_OBJECT

public:
    explicit resultwindow(QWidget *parent = nullptr);
    ~resultwindow();

    void setPathString(const QString& pathString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::resultwindow *ui;
    QString m_pathString;
    QFrame *m_pathFrame;
    QLabel *m_pathLabel;
};

#endif // RESULTWINDOW_H
