#include "guessdefinition.h"
#include "ui_guessdefinition.h"
#include "mainwindow.h"

guessDefinition::guessDefinition(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::guessDefinition),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");

}

guessDefinition::~guessDefinition()
{
    delete ui;
}

void guessDefinition::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }

    this->close();
}

