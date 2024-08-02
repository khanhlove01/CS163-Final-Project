#ifndef GUESSWORD_H
#define GUESSWORD_H

#include <QMainWindow>
#include <QListWidget>
#include <QString>
#include "function.h"
#include <memory>


namespace Ui {
class guessWord;
}

class MainWindow;

class guessWord : public QMainWindow
{
    Q_OBJECT

public:
    explicit guessWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~guessWord();

private:
    Ui::guessWord *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
    int correctIndex;
    vector<string> definitions;
};

#endif // GUESSWORD_H
