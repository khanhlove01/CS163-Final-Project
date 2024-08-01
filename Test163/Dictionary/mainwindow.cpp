#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<Dictionary> dict, std::string &dataset, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    dictionary(dict),
    currentDataset(dataset),
    SwitchData(nullptr),
    SearchWindow(nullptr)
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

void MainWindow::setDictionary(shared_ptr<Dictionary> dict) {
    dictionary = dict;
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
    else if (index.row() == 1)
    {
        if (!SearchWindow) {
            SearchWindow = new searchWindow(this, dictionary);
        }
        SearchWindow->show();
        this->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}
