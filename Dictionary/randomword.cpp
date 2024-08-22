#include "randomword.h"
#include "ui_randomword.h"
#include "mainwindow.h"

randomWord::randomWord(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::randomWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
    auto word = this->dict->getRandomWord();
    this->ui->wordLabel->setText(QString::fromStdString(word.first));
    this->ui->definitionLabel->setText(QString::fromStdString(word.second));

}

randomWord::~randomWord()
{
    delete ui;
}

void randomWord::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }

    this->close();
}


void randomWord::on_anotherWordButton_clicked()
{
    auto word = this->dict->getRandomWord();
    this->ui->wordLabel->setText(QString::fromStdString(word.first));
    this->ui->definitionLabel->setText(QString::fromStdString(word.second));
}

