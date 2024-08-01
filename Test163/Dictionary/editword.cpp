#include "editword.h"
#include "ui_editword.h"
#include "mainwindow.h"

editWord::editWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::editWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

editWord::~editWord()
{
    delete ui;
}

void editWord::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }

    this->close();
}

