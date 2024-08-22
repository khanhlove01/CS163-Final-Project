#include "viewhistory.h"
#include "ui_viewhistory.h"
#include "mainwindow.h"

viewHIstory::viewHIstory(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::viewHIstory),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
    vector<string> res = this->dict->viewHistory();
    displayVectorInListWidget(this->ui->history,res);

}

viewHIstory::~viewHIstory()
{
    delete ui;
}

void viewHIstory::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->close();
}




