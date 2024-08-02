#include "switchdataset.h"
#include "ui_switchdataset.h"
#include "mainwindow.h"

SwitchDataset::SwitchDataset(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SwitchDataset), mainWindow(parentWindow), dictionary(dict)
{
    ui->setupUi(this);
    this->ui->successful->setVisible(false);
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
    this->ui->successful->setVisible(false);
    this->ui->datasetName->setVisible(false);
    this->close();  // Close the SwitchDataset window
}

void SwitchDataset::on_englishButton_clicked()
{
    this->ui->datasetName->setText("English dataset");
    this->ui->successful->setVisible(true);
    this->ui->datasetName->setVisible(true);
}


void SwitchDataset::on_slangButton_clicked()
{
    delete dictionary;
    dictionary = new Dictionary("slang.txt", "slang_history.txt", "slang_favourites.txt");
    dictionary->loadDataSet();
    mainWindow->setDictionary(dictionary);
    mainWindow->setCurrentDataset("slang");
    ui->datasetName->setText("Slang dataset");
    ui->successful->setVisible(true);
    ui->datasetName->setVisible(true);
}


void SwitchDataset::on_emoteButton_clicked()
{
    delete dictionary;
    dictionary = new Dictionary("emotional.txt.TXT", "emotional_history.txt", "emotional_favourites.txt");
    dictionary->loadDataSet();
    mainWindow->setDictionary(dictionary);
    mainWindow->setCurrentDataset("emotional");
    ui->datasetName->setText("Emotional dataset");
    ui->successful->setVisible(true);
    ui->datasetName->setVisible(true);
}

