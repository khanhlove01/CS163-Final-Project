#ifndef SWITCHDATASET_H
#define SWITCHDATASET_H

#include <QMainWindow>

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
    explicit SwitchDataset(MainWindow *parentWindow, QWidget *parent = nullptr);
    ~SwitchDataset();

private slots:
    void on_backButton_clicked();

private:
    Ui::SwitchDataset *ui;
    MainWindow *mainWindow;  // Pointer to the main window
};

#endif // SWITCHDATASET_H
