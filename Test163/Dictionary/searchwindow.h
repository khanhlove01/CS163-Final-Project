#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>
#include <QString>
#include "function.h"
#include <memory>

namespace Ui {
class searchWindow;
}

class MainWindow;

class searchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchWindow(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~searchWindow();

private slots:
    void on_backButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::searchWindow *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};

#endif // SEARCHWINDOW_H
