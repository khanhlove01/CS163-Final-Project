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
    explicit removeWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~removeWord();

private slots:
    void on_backButton_clicked();

private:
    Ui::removeWord *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // REMOVEWORD_H
