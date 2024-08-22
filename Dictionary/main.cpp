#include "mainwindow.h"
#include "function.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    std::string currentDataset = "english";
    auto dict = new Dictionary("english.txt", "english_history.txt", "english_favourites.txt");
    dict->loadDataSet();
    QApplication a(argc, argv);
    MainWindow w(dict, currentDataset);
    w.show();
    return a.exec();
}
