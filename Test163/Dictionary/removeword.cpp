#include "removeword.h"
#include "ui_removeword.h"
#include "mainwindow.h"

removeWord::removeWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::removeWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

removeWord::~removeWord()
{
    delete ui;
}

void removeWord::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->close();
}


void removeWord::on_wordEdit_editingFinished()
{

}

