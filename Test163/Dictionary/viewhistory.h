#ifndef VIEWHISTORY_H
#define VIEWHISTORY_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"
#include <memory>

namespace Ui {
class viewHIstory;
}

class MainWindow;
class viewHIstory : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewHIstory(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~viewHIstory();

private slots:
    void on_backButton_clicked();

private:
    Ui::viewHIstory *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};


#endif // VIEWHISTORY_H
