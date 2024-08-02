#ifndef MANAGEFAVORITES_H
#define MANAGEFAVORITES_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"
#include <memory>

namespace Ui {
class manageFavorites;
}

class MainWindow;

class manageFavorites : public QMainWindow
{
    Q_OBJECT

public:
    explicit manageFavorites(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~manageFavorites();

private slots:
    void on_backButton_clicked();

    void on_wordEdit_editingFinished();

private:
    Ui::manageFavorites *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // MANAGEFAVORITES_H
