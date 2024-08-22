#include "managefavorites.h"
#include "ui_managefavorites.h"
#include "mainwindow.h"

manageFavorites::manageFavorites(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::manageFavorites),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");

    this->ui->yesButton->setVisible(false);
    this->ui->noButton->setVisible(false);
}

manageFavorites::~manageFavorites()
{
    delete ui;
}

void manageFavorites::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }

    this->ui->wordEdit->clear();
    this->ui->resultLabel->clear();
    this->close();
}


void manageFavorites::on_wordEdit_editingFinished()
{
    string word = this->ui->wordEdit->text().toStdString();
    if (dict->wordExists(word)) {
        vector<string> favourites = dict->viewFavourites();
        if (::find(favourites.begin(), favourites.end(), word) != favourites.end()) {
            this->ui->resultLabel->setText("Remove this word from favorites?");
        }
        else {
            this->ui->resultLabel->setText("Add this word to favorties?");
        }
        this->ui->yesButton->setVisible(true);
        this->ui->noButton->setVisible(true);
    }
    else {
        this->ui->resultLabel->setText("Word not found in the dictionary");
    }
}


void manageFavorites::on_yesButton_clicked()
{
    string word = this->ui->wordEdit->text().toStdString();
    if (dict->wordExists(word)) {
        vector<string> favourites = dict->viewFavourites();
        if (::find(favourites.begin(), favourites.end(), word) != favourites.end()) {
            dict->removeFavourite(word);
            this->ui->resultLabel->setText("Word removed from favorites");
            this->ui->yesButton->setVisible(false);
            this->ui->noButton->setVisible(false);
        }
        else {
            dict->addFavourite(word);
            this->ui->resultLabel->setText("Word added to favorites");
            this->ui->yesButton->setVisible(false);
            this->ui->noButton->setVisible(false);
        }
    }
}


void manageFavorites::on_noButton_clicked()
{
    this->ui->yesButton->setVisible(false);
    this->ui->noButton->setVisible(false);
    this->ui->wordEdit->clear();
    this->ui->resultLabel->clear();
}

