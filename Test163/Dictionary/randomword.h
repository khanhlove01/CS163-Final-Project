#ifndef RANDOMWORD_H
#define RANDOMWORD_H

#include <QMainWindow>
#include <QListWidget>
#include <QString>
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

private slots:
    void on_backButton_clicked();

    void on_anotherWordButton_clicked();

private:
    Ui::randomWord *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // RANDOMWORD_H
