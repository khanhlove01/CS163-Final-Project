#ifndef VIEWHISTORY_H
#define VIEWHISTORY_H

#include <QMainWindow>
#include <QString>
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
    explicit viewHIstory(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~viewHIstory();

private slots:
    void on_backButton_clicked();

private:
    Ui::viewHIstory *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};


#endif // VIEWHISTORY_H
