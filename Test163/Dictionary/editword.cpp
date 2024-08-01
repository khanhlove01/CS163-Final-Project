#include "editword.h"
#include "ui_editword.h"
#include "mainwindow.h"

editWord::editWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::editWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

editWord::~editWord()
{
    delete ui;
}

void editWord::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->ui->resultLabel->clear();
    this->ui->definitionEdit->clear();
    this->ui->wordEdit->clear();
    this->close();
}


void editWord::on_backButton_2_clicked()
{
    if (!this->ui->wordEdit->text().isEmpty() && !this->ui->definitionEdit->text().isEmpty()) {
        string word = this->ui->wordEdit->text().toStdString();
        string definition = this->ui->definitionEdit->text().toStdString();
        bool res = this->dict->editDefinition(word, definition);
        if (res) {
            this->ui->resultLabel->clear();
            this->ui->resultLabel->setText("Successfully update the word");
        }
        else {
            this->ui->resultLabel->clear();
            this->ui->resultLabel->setText("Word not found");
        }
    }
    else {
        this->ui->resultLabel->clear();
        this->ui->resultLabel->setText("Please fill in both the word and definition");
    }
}

