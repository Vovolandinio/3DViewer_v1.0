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

    void on_move_apply_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_vertices_no_clicked();

    void on_vertices_circle_clicked();

    void on_vertices_square_clicked();

    void on_verticles_size_slider_sliderReleased();

    void on_edges_solid_clicked();

    void on_edges_dashed_clicked();

    void on_lines_sie_slider_sliderReleased();


    void on_bg_color_button_clicked();

    void on_zoom_button_clicked();

private:
    Ui::MainWindow *ui;

    QString open_file();
};
#endif // MAINWINDOW_H
