#ifndef EDITWORD_H
#define EDITWORD_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"

namespace Ui {
class editWord;
}

class MainWindow;

class editWord : public QMainWindow
{
    Q_OBJECT

public:
    explicit editWord(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~editWord();

private slots:
    void on_backButton_clicked();

    void on_backButton_2_clicked();

private:
    Ui::editWord *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};

#endif // EDITWORD_H
