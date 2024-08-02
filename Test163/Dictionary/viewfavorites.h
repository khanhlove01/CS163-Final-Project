#ifndef VIEWFAVORITES_H
#define VIEWFAVORITES_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"
#include <memory>

namespace Ui {
class viewFavorites;
}

class MainWindow;

class viewFavorites : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewFavorites(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~viewFavorites();

private slots:
    void on_backButton_clicked();

private:
    Ui::viewFavorites *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // VIEWFAVORITES_H
