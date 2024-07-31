#include "switchdataset.h"
#include "ui_switchdataset.h"
#include "mainwindow.h"

SwitchDataset::SwitchDataset(MainWindow *parentWindow, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SwitchDataset),
    mainWindow(parentWindow)  // Initialize the main window pointer
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #ebebd3;");
}

SwitchDataset::~SwitchDataset()
{
    delete ui;
}

void SwitchDataset::on_backButton_clicked()
{
    // Show the main window and close the current window
    if (mainWindow) {
        mainWindow->show();
    }
    this->close();  // Close the SwitchDataset window
}
