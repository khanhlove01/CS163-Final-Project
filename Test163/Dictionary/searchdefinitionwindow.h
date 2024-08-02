#ifndef SEARCHDEFINITIONWINDOW_H
#define SEARCHDEFINITIONWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QString>
#include "function.h"
#include <memory>

namespace Ui {
class searchDefinitionWindow;
}

class MainWindow;

class searchDefinitionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchDefinitionWindow(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~searchDefinitionWindow();

private slots:
    void on_backButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::searchDefinitionWindow *ui;
    MainWindow *mainWindow;
    Dictionary* dict;
};


#endif // SEARCHDEFINITIONWINDOW_H
