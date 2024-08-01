#include "addwordwindow.h"
#include "ui_addwordwindow.h"
#include "mainwindow.h"

addWordWindow::addWordWindow(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addWordWindow),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

addWordWindow::~addWordWindow()
{
    delete ui;
}

void addWordWindow::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->close();
}


void addWordWindow::on_backButton_2_clicked()
{
    if (!this->ui->wordEdit->text().isEmpty() && !this->ui->definitionEdit->text().isEmpty()) {

    }
}

