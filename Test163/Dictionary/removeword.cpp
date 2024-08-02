#include "removeword.h"
#include "ui_removeword.h"
#include "mainwindow.h"

removeWord::removeWord(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::removeWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

removeWord::~removeWord()
{
    delete ui;
}

void removeWord::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->ui->resultLabel->clear();
    this->ui->wordEdit->clear();
    this->close();
}


void removeWord::on_wordEdit_editingFinished()
{
    string word = this->ui->wordEdit->text().toStdString();
    bool res = this->dict->wordExists(word);
    if (!res) {
        this->ui->resultLabel->clear();
        this->ui->resultLabel->setText("Word not found");
    }
    else {
        this->dict->removeWordFromDictionary(word);
        this->ui->resultLabel->clear();
        this->ui->resultLabel->setText("Successfully remove word");
    }

}

