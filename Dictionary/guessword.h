#ifndef GUESSWORD_H
#define GUESSWORD_H

#include <QMainWindow>
#include <QListWidget>
#include <QString>
#include "function.h"

namespace Ui {
class guessWord;
}

class MainWindow;

class guessWord : public QMainWindow
{
    Q_OBJECT

public:
    explicit guessWord(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~guessWord();

private slots:
    void on_backButton_clicked();

    void on_answer4_clicked();

    void on_answer1_clicked();

    void on_answer2_clicked();

    void on_answer3_clicked();

    void generateNewDefinition();

    void on_tryAnotherButton_clicked();

private:
    Ui::guessWord *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
    int correctIndex;
    vector<string> definitions;
};

#endif // GUESSWORD_H
