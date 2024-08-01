#include "mainwindow.h"
#include "function.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    std::string currentDataset = "slang";
    auto dict = std::make_shared<Dictionary>("slang.txt", "slang_history.txt", "slang_favourites.txt");
    dict->loadDataSet();
    qDebug() << QString::fromStdString(dict->root->definition);
    QApplication a(argc, argv);
    MainWindow w(dict, currentDataset);
    w.show();
    return a.exec();
}
