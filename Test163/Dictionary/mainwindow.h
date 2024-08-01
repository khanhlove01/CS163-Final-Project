#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "switchdataset.h"
#include "function.h"
#include "searchwindow.h"
#include "searchdefinitionwindow.h"
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<Dictionary> dict, std::string &dataset, QWidget *parent = nullptr); // Add reference to currentDataset
    ~MainWindow();

    void setCurrentDataset(const std::string &dataset); // Setter for currentDataset
    void setDictionary(shared_ptr<Dictionary> dict);

private slots:
    void on_listWidget_clicked(const QModelIndex &index);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    SwitchDataset *SwitchData;
    searchWindow *SearchWindow;
    searchDefinitionWindow *SearchDefinitionWindow;
    shared_ptr<Dictionary> dictionary;
    std::string &currentDataset; // Reference to currentDataset
};

#endif // MAINWINDOW_H
