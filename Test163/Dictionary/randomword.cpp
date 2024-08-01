#include "randomword.h"
#include "ui_randomword.h"

randomWord::randomWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::randomWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

randomWord::~randomWord()
{
    delete ui;
}
