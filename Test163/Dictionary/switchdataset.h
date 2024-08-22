#ifndef SWITCHDATASET_H
#define SWITCHDATASET_H

#include <QMainWindow>
#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SwitchDataset;
}
QT_END_NAMESPACE

class MainWindow;

class SwitchDataset : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwitchDataset(MainWindow *parentWindow, Dictionary* &dict, QWidget *parent = nullptr);
    ~SwitchDataset();

private slots:
    void on_backButton_clicked();
    void on_englishButton_clicked();
    void on_slangButton_clicked();
    void on_emoteButton_clicked();

    void on_eng2vietButton_clicked();

    void on_eng2spaButton_clicked();

private:
    Ui::SwitchDataset *ui;
    MainWindow *mainWindow;
    Dictionary* dictionary;
};

#endif // SWITCHDATASET_H
