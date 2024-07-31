#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "switchdataset.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , SwitchData(nullptr)
{
    ui->setupUi(this);

    // Set the background color using a stylesheet
    this->setStyleSheet("background-color: #ebebd3;");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete SwitchData;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    if (index.row() == 0)
    {
        if (!SwitchData) {
            SwitchData = new SwitchDataset(this); // Create window2 if it doesn't exist
        }
        SwitchData->show();
        this->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}



