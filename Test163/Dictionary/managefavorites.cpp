#include "managefavorites.h"
#include "ui_managefavorites.h"
#include "mainwindow.h"

manageFavorites::manageFavorites(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::manageFavorites),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

manageFavorites::~manageFavorites()
{
    delete ui;
}

void manageFavorites::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }

    this->close();
}


void manageFavorites::on_wordEdit_editingFinished()
{

}

