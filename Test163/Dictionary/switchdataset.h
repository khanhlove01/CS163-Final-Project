#ifndef SWITCHDATASET_H
#define SWITCHDATASET_H

#include <QMainWindow>
#include "function.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class SwitchDataset;
}
QT_END_NAMESPACE

class MainWindow;  // Forward declaration

class SwitchDataset : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwitchDataset(MainWindow *parentWindow, shared_ptr<Dictionary> dict, QWidget *parent = nullptr);
    ~SwitchDataset();

private slots:
    void on_backButton_clicked();
    void on_englishButton_clicked();
    void on_slangButton_clicked();
    void on_emoteButton_clicked();

private:
    Ui::SwitchDataset *ui;
    MainWindow *mainWindow;  // Pointer to the main window
    std::shared_ptr<Dictionary> dictionary;  // Pointer to the Dictionary object
};

#endif // SWITCHDATASET_H
