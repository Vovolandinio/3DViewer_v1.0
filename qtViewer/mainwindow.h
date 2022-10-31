#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

//    void on_pushButton_clicked();

    void on_action_open_file_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QString open_file();
};
#endif // MAINWINDOW_H
