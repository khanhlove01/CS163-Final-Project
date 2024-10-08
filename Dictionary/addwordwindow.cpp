#include "addwordwindow.h"
#include "ui_addwordwindow.h"
#include "mainwindow.h"

addWordWindow::addWordWindow(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent)
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
    this->ui->resultLabel->clear();
    this->ui->wordEdit->clear();
    this->ui->definitionEdit->clear();
    this->close();
}


void addWordWindow::on_backButton_2_clicked()
{
    if (!this->ui->wordEdit->text().isEmpty() && !this->ui->definitionEdit->text().isEmpty()) {
        string word = this->ui->wordEdit->text().toStdString();
        string definition = this->ui->definitionEdit->text().toStdString();
        bool res = this->dict->wordExists(word);
        if (res) {
            this->ui->resultLabel->clear();
            this->ui->resultLabel->setText("The word is already in the dictionary");
            return;
        }
        this->dict->insert(word, definition);
        this->ui->resultLabel->clear();
        this->ui->resultLabel->setText("Successfully insert new word");
    }
    else {
        this->ui->resultLabel->clear();
        this->ui->resultLabel->setText("Please fill in both the word and definition");
    }
}

