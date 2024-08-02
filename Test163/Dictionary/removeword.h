#ifndef REMOVEWORD_H
#define REMOVEWORD_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"
#include <memory>

namespace Ui {
class removeWord;
}

class MainWindow;

class removeWord : public QMainWindow
{
    Q_OBJECT

public:
    explicit removeWord(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~removeWord();

private slots:
    void on_backButton_clicked();

    void on_wordEdit_editingFinished();

private:
    Ui::removeWord *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};

#endif // REMOVEWORD_H
