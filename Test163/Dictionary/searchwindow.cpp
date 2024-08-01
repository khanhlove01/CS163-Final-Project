#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "mainwindow.h"

searchWindow::searchWindow(MainWindow *parentWindow, std::shared_ptr<Dictionary> dict, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::searchWindow),
    mainWindow(parentWindow),
    dict(dict)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #ebebd3;");
}

searchWindow::~searchWindow()
{
    delete ui;
}

void searchWindow::on_backButton_clicked()
{

    if (mainWindow) {
        mainWindow->show();
    }
    this->ui->definition->clear();
    this->ui->lineEdit->clear();
    this->close();  // Close the SwitchDataset window
}


void searchWindow::on_lineEdit_editingFinished()
{
    QString input =  ui->lineEdit->text();
    string definition = this->dict->search(input.toStdString());
    cout << definition << endl;
    qDebug() << QString::fromStdString(definition);
    this->ui->definition->setText(QString::fromStdString(definition));
}

