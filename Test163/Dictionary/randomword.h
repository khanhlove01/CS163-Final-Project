#ifndef RANDOMWORD_H
#define RANDOMWORD_H

#include <QMainWindow>
#include <QListWidget>
#include <QString>
#include "function.h"

namespace Ui {
class randomWord;
}

class MainWindow;

class randomWord : public QMainWindow
{
    Q_OBJECT

public:
    explicit randomWord(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~randomWord();

private slots:
    void on_backButton_clicked();

    void on_anotherWordButton_clicked();

private:
    Ui::randomWord *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};

#endif // RANDOMWORD_H
