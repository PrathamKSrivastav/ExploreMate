#ifndef FEEDBACKWINDOW_H
#define FEEDBACKWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QMessageBox>

namespace Ui {
class feedbackwindow;
}

class feedbackwindow : public QWidget
{
    Q_OBJECT

public:
    explicit feedbackwindow(QWidget *parent = nullptr);
    ~feedbackwindow();

private slots:
    void onDestinationChanged(const QString &destination); // Slot for destination change

    void on_ExploreBtn_clicked();

private:
    Ui::feedbackwindow *ui;

    void setupDropdown(); // Function to populate the dropdown with destinations
};

#endif // FEEDBACKWINDOW_H
