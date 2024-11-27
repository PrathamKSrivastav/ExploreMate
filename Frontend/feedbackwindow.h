#ifndef FEEDBACKWINDOW_H
#define FEEDBACKWINDOW_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
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
    void on_ExploreBtn_clicked(); // Slot for Explore button click

private:
    Ui::feedbackwindow *ui;

    // Button groups for the radio buttons
    QButtonGroup *groupQ1;
    QButtonGroup *groupQ2;
    QButtonGroup *groupQ3;
    QButtonGroup *groupQ4;

    // Helper functions
    void setupDropdown(); // Function to populate the dropdown with destinations
    void setupRadiobutton(); // Function to group radio buttons
    bool areAllGroupsSelected() const; // Function to validate all groups have a selection
};

#endif // FEEDBACKWINDOW_H
