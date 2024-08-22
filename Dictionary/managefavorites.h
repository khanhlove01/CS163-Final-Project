#ifndef MANAGEFAVORITES_H
#define MANAGEFAVORITES_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"

namespace Ui {
class manageFavorites;
}

class MainWindow;

class manageFavorites : public QMainWindow
{
    Q_OBJECT

public:
    explicit manageFavorites(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~manageFavorites();

private slots:
    void on_backButton_clicked();

    void on_wordEdit_editingFinished();

    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::manageFavorites *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};

#endif // MANAGEFAVORITES_H
