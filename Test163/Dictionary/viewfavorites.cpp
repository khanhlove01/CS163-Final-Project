#include "viewfavorites.h"
#include "ui_viewfavorites.h"
#include "mainwindow.h"

viewFavorites::viewFavorites(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::viewFavorites),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");

}

viewFavorites::~viewFavorites()
{
    delete ui;
}

void viewFavorites::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->close();
}

