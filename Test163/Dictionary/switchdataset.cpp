#include "switchdataset.h"
#include "ui_switchdataset.h"
#include "mainwindow.h"

SwitchDataset::SwitchDataset(MainWindow *parentWindow, Dictionary* dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::SwitchDataset),
    mainWindow(parentWindow),
    dictionary(dict)
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
    delete this->dictionary;
    this->dictionary = new Dictionary("slang.txt", "slang_history.txt", "slang_favourites.txt");
    this->dictionary->loadDataSet();
    mainWindow->setCurrentDataset("slang");
    this->ui->datasetName->setText("Slang dataset");
    this->ui->successful->setVisible(true);
    this->ui->datasetName->setVisible(true);
}


void SwitchDataset::on_emoteButton_clicked()
{
    delete this->dictionary;
    this->dictionary = new Dictionary("slang.txt", "slang_history.txt", "slang_favourites.txt");
    this->dictionary->loadDataSet();
    mainWindow->setCurrentDataset("slang");
    this->ui->datasetName->setText("Emote dataset");
    this->ui->successful->setVisible(true);
    this->ui->datasetName->setVisible(true);
}

