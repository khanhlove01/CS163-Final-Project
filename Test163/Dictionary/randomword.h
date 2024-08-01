#ifndef RANDOMWORD_H
#define RANDOMWORD_H

#include <QMainWindow>
#include <QListWidget>
#include "function.h"
#include <memory>

namespace Ui {
class randomWord;
}

class MainWindow;

class randomWord : public QMainWindow
{
    Q_OBJECT

public:
    explicit randomWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~randomWord();

private:
    Ui::randomWord *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // RANDOMWORD_H
