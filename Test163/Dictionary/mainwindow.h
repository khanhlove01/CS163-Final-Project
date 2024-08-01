#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "switchdataset.h"
#include "function.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Dictionary *dict, std::string &dataset, QWidget *parent = nullptr); // Add reference to currentDataset
    ~MainWindow();

    void setCurrentDataset(const std::string &dataset); // Setter for currentDataset

private slots:
    void on_listWidget_clicked(const QModelIndex &index);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SwitchDataset *SwitchData;
    Dictionary *dictionary;
    std::string &currentDataset; // Reference to currentDataset
};

#endif // MAINWINDOW_H
