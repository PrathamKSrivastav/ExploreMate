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
    void setAlterRoute1(const QString& route1String);
    void setAlterRoute2(const QString& route2String);
    void setAlterRoute3(const QString& route3String);

private slots:
    void on_pushButton_clicked();

private:
    Ui::resultwindow *ui;
    QString m_pathString;
    QString m_route1String;
    QString m_route2String;
    QString m_route3String;
    QFrame *m_pathFrame;
    QLabel *m_pathLabel;
};

#endif // RESULTWINDOW_H
