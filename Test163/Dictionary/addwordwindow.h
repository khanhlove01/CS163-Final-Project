#ifndef ADDWORDWINDOW_H
#define ADDWORDWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"
#include <memory>

namespace Ui {
class addWordWindow;
}

class MainWindow;

class addWordWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit addWordWindow(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~addWordWindow();

private slots:
    void on_backButton_clicked();

    void on_backButton_2_clicked();

private:
    Ui::addWordWindow *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // ADDWORDWINDOW_H
