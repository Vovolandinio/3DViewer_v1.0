#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

extern "C" {
#include "../parser/s21_parser.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_file_name(QString filename, int verticles, int lines);
    void parser_work(QString filename);

private slots:

    void on_action_open_file_triggered();

    void on_actionJPG_2_triggered();

    void on_actionPNG_2_triggered();

    void on_actionGIF_2_triggered();

    void on_pushButton_clicked();

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

//    void on_zoom_button_clicked();

    void on_proection_central_clicked();

    void on_proection_parallel_clicked();
    void oneGif();
    void null_sliders();

    void on_movex_slider_sliderMoved(int position);

    void on_movey_slider_sliderMoved(int position);

    void on_movez_slider_sliderMoved(int position);

    void on_rotatex_slider_sliderMoved(int position);

    void on_rotatey_slider_sliderMoved(int position);

    void on_rotatez_slider_sliderMoved(int position);

    void on_zoom_slider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    QString open_file();
    QDateTime dateTime;
    QString currentDateTime;

    const int GifFps = 10, GifLength = 5;
    QTimer *timer;
    void createGif();
    int startTime, tmpTime;
    int counter = 1;



public slots:
    void update_sliders();
    void update_rotate_sliders();
    void update_zoom();
};
#endif // MAINWINDOW_H
