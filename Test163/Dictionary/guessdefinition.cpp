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

    generateNewWord();

    connect(ui->tryAnotherButton, &QPushButton::clicked, this, &guessDefinition::on_tryAnotherButton_clicked);

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

void guessDefinition::on_answer1_clicked()
{
    if (this->ui->answer1->property("index").toInt() == this->correctIndex)
        this->ui->resultLabel->setText("Correct");
    else this->ui->resultLabel->setText(QString::fromStdString("Incorrect. The correct definition is: " + this->definitions[this->correctIndex]));
}

void guessDefinition::on_answer2_clicked()
{
    if (this->ui->answer2->property("index").toInt() == this->correctIndex)
        this->ui->resultLabel->setText("Correct");
    else this->ui->resultLabel->setText(QString::fromStdString("Incorrect. The correct definition is: " + this->definitions[this->correctIndex]));
}

void guessDefinition::on_answer3_clicked()
{
    if (this->ui->answer3->property("index").toInt() == this->correctIndex)
        this->ui->resultLabel->setText("Correct");
    else this->ui->resultLabel->setText(QString::fromStdString("Incorrect. The correct definition is: " + this->definitions[this->correctIndex]));
}

void guessDefinition::on_answer4_clicked()
{
    if (this->ui->answer4->property("index").toInt() == this->correctIndex)
        this->ui->resultLabel->setText("Correct");
    else this->ui->resultLabel->setText(QString::fromStdString("Incorrect. The correct definition is: " + this->definitions[this->correctIndex]));
}

void guessDefinition::on_tryAnotherButton_clicked()
{
    generateNewWord();
}

void guessDefinition::generateNewWord()
{
    auto result = dict->getRandomWordWithDefinitions();
    string word = std::get<0>(result);
    this->definitions = std::get<1>(result);
    this->correctIndex = std::get<2>(result);

    this->ui->wordLabel->setText(QString::fromStdString("Guess the definition for this word: " + word));

    this->ui->answer1->setText(QString::fromStdString(definitions[0]));
    this->ui->answer1->setProperty("index", 0);

    this->ui->answer2->setText(QString::fromStdString(definitions[1]));
    this->ui->answer2->setProperty("index", 1);

    this->ui->answer3->setText(QString::fromStdString(definitions[2]));
    this->ui->answer3->setProperty("index", 2);

    this->ui->answer4->setText(QString::fromStdString(definitions[3]));
    this->ui->answer4->setProperty("index", 3);

    // Clear the result label
    this->ui->resultLabel->setText("");
}

