#include "searchdefinitionwindow.h"
#include "ui_searchdefinitionwindow.h"
#include "mainwindow.h"

searchDefinitionWindow::searchDefinitionWindow(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::searchDefinitionWindow),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

searchDefinitionWindow::~searchDefinitionWindow()
{
    delete ui;
}

void searchDefinitionWindow::on_backButton_clicked()
{
    if (mainWindow) {
        mainWindow->show();
    }
    this->ui->definition->clear();
    this->ui->lineEdit->clear();
    this->close();
}


void searchDefinitionWindow::on_lineEdit_editingFinished()
{
    QString input =  ui->lineEdit->text();
    vector<string> res = this->dict->searchByDefinition(input.toStdString());
    if (!res.empty()) displayVectorInListWidget(this->ui->definition, res);
    else {
        this->ui->definition->clear();
        this->ui->definition->addItem("There are no word matching the definition");}
}

void displayVectorInListWidget(QListWidget* listWidget, const vector<string>& vec) {
    listWidget->clear();
    for (const auto& str : vec) {
        listWidget->addItem(QString::fromStdString(str));
    }
}

