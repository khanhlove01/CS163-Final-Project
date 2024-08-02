#ifndef GUESSDEFINITION_H
#define GUESSDEFINITION_H

#include <QMainWindow>
#include <QListWidget>
#include <QString>
#include "function.h"
#include <memory>

namespace Ui {
class guessDefinition;
}

class MainWindow;

class guessDefinition : public QMainWindow
{
    Q_OBJECT

public:
    explicit guessDefinition(MainWindow *parentWindow, Dictionary*& dict, QWidget *parent = nullptr);
    ~guessDefinition();

private slots:
    void on_backButton_clicked();

    void on_answer4_clicked();

    void on_answer1_clicked();

    void on_answer2_clicked();

    void on_answer3_clicked();

    void on_tryAnotherButton_clicked();

    void generateNewWord();

private:
    Ui::guessDefinition *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
    int correctIndex;
    vector<string> definitions;
};

#endif // GUESSDEFINITION_H
