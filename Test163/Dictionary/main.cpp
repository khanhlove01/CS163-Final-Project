#include "mainwindow.h"
#include "function.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::string currentDataset = "slang";
    Dictionary* dict = new Dictionary("slang.txt", "slang_history.txt", "slang_favourites.txt");
    dict->loadDataSet();

    QApplication a(argc, argv);
    MainWindow w(dict, currentDataset); // Pass currentDataset reference
    w.show();
    return a.exec();
}
