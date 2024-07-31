#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "switchdataset.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    SwitchDataset *SwitchData;
};
#endif // MAINWINDOW_H
