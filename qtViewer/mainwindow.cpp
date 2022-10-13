#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("3D Viewer");
    ui->setupUi(this);
    int RANGE_MAX = 25000;
    int ROTATE_MAX = 36000;
    int ZOOM_MAX = 10000;


    ui->movex_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movex_slider->setTickInterval(0);
    connect(ui->movex_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->movex_slider->value() / 100.0;
            ui->movex_line->setText(QString::number(val, 'f', 2));
        });
    ui->movey_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movey_slider->setTickInterval(0);
    connect(ui->movey_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->movey_slider->value() / 100.0;
            ui->movey_line->setText(QString::number(val, 'f', 2));
        });
    ui->movez_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movez_slider->setTickInterval(0);
    connect(ui->movez_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->movez_slider->value() / 100.0;
            ui->movez_line->setText(QString::number(val, 'f', 2));
        });



    ui->rotatex_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatex_slider->setTickInterval(0);
    connect(ui->rotatex_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->rotatex_slider->value() / 100.0;
            ui->rotatex_line->setText(QString::number(val, 'f', 2));
        });
    ui->rotatey_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatey_slider->setTickInterval(0);
    connect(ui->rotatey_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->rotatey_slider->value() / 100.0;
            ui->rotatey_line->setText(QString::number(val, 'f', 2));
        });
    ui->rotatez_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatez_slider->setTickInterval(0);
    connect(ui->rotatez_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->rotatez_slider->value() / 100.0;
            ui->rotatez_line->setText(QString::number(val, 'f', 2));
        });


    ui->zoom_slider->setRange(0, ZOOM_MAX);
    ui->zoom_slider->setValue(10);
    ui->zoom_slider->setTickInterval(0);
    connect(ui->zoom_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->zoom_slider->value() / 100.0;
            ui->zoom_line->setText(QString::number(val, 'f', 2));
        });


}

MainWindow::~MainWindow()
{
    delete ui;
}

