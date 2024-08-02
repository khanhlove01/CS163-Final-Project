#include "guessword.h"
#include "ui_guessword.h"

guessWord::guessWord(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::guessWord),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");

    // auto result = dict->getRandomWordWithDefinitions();
    // string word = get<0>(result);
    // this->definitions = get<1>(result);
    // this->correctIndex = get<2>(result);

    // this->ui->wordLabel->setText(QString::fromStdString("Guess the definition for this word: " + word));

    // this->ui->answer1->setText(QString::fromStdString(definitions[0]));
    // this->ui->answer1->setProperty("index", 0);

    // this->ui->answer2->setText(QString::fromStdString(definitions[1]));
    // this->ui->answer2->setProperty("index", 1);

    // this->ui->answer3->setText(QString::fromStdString(definitions[2]));
    // this->ui->answer3->setProperty("index", 2);

    // this->ui->answer4->setText(QString::fromStdString(definitions[3]));
    // this->ui->answer4->setProperty("index", 3);
}

guessWord::~guessWord()
{
    delete ui;
}
