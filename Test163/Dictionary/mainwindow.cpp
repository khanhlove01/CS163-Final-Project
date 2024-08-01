#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Dictionary *dict, std::string &dataset, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    dictionary(dict),
    currentDataset(dataset),
    SwitchData(nullptr)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #ebebd3;");
}

MainWindow::~MainWindow()
{
    delete ui;
    if (SwitchData) delete SwitchData;
}

void MainWindow::setCurrentDataset(const std::string &dataset)
{
    currentDataset = dataset;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    if (index.row() == 0)
    {
        if (!SwitchData) {
            SwitchData = new SwitchDataset(this, dictionary);
        }
        SwitchData->show();
        this->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}
