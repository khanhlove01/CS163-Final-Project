#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::shared_ptr<Dictionary> dict, std::string &dataset, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    dictionary(dict),
    currentDataset(dataset),
    SwitchData(nullptr),
    SearchWindow(nullptr),
    SearchDefinitionWindow(nullptr),
    ViewHistory(nullptr),
    AddWordWindow(nullptr),
    EditWord(nullptr),
    RemoveWord(nullptr),
    RandomWord(nullptr),
    ViewFavorites(nullptr),
    ManageFavorites(nullptr)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #ebebd3;");

    this->ui->resetButton->setVisible(false);

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
    else if (index.row() == 2)
    {
        if (!SearchDefinitionWindow) {
            SearchDefinitionWindow = new searchDefinitionWindow(this, dictionary);
        }
        SearchDefinitionWindow->show();
        this->hide();
    }
    else if (index.row() == 3)
    {
        if (!ViewHistory) {
            ViewHistory = new viewHIstory(this, dictionary);
        }
        ViewHistory->show();
        this->hide();
    }
    else if (index.row() == 4)
    {
        if (!AddWordWindow) {
            AddWordWindow = new addWordWindow(this, dictionary);
        }
        AddWordWindow->show();
        this->hide();
    }
    else if (index.row() == 5)
    {
        if (!EditWord) {
            EditWord = new editWord(this, dictionary);
        }
        EditWord->show();
        this->hide();
    }
    else if (index.row() == 6)
    {
        if (!RemoveWord) {
            RemoveWord = new removeWord(this, dictionary);
        }
        RemoveWord->show();
        this->hide();
    }
    else if (index.row() == 7)
    {
        this->dictionary->resetToOriginal(currentDataset == "slang" ? "originalslang.txt" : "originalemotional.txt.TXT");
        this->ui->resetButton->setVisible(true);
    }
    else if (index.row() == 8)
    {
        if (!RandomWord) {
            RandomWord = new randomWord(this, dictionary);
        }
        else {
            delete RandomWord;
            RandomWord = new randomWord(this, dictionary);
        }
        RandomWord->show();
        this->hide();
    }
    else if (index.row() == 9)
    {
        if (!ViewFavorites) {
            ViewFavorites = new viewFavorites(this, dictionary);
        }
        ViewFavorites->show();
        this->hide();
    }
    else if (index.row() == 10)
    {
        if (!ManageFavorites) {
            ManageFavorites = new manageFavorites(this, dictionary);
        }
        ManageFavorites->show();
        this->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}



void MainWindow::on_resetButton_clicked()
{
    this->ui->resetButton->setVisible(false);
}

