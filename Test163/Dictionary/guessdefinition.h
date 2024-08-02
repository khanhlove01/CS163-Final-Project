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
    explicit guessDefinition(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~guessDefinition();

private slots:
    void on_backButton_clicked();

private:
    Ui::guessDefinition *ui;
    MainWindow *mainWindow;
    std::shared_ptr<Dictionary> dict;
};

#endif // GUESSDEFINITION_H
