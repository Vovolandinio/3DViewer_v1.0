#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("3D Viewer");
    this->setStyleSheet("background-color: black;");
    int RANGE_MAX = 25000;
    int ROTATE_MAX = 36000;
    int ZOOM_MAX = 10000;


    ui->movex_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movex_slider->setTickInterval(0);
    connect(ui->movex_slider,&QSlider::sliderMoved,this,[=]{double val=ui->movex_slider->value() / 100.0; ui->movex_line->setText(QString::number(val, 'f', 2));
    });



    connect(ui->movex_line, &QLineEdit::textChanged, this, [=]{QString val = ui->movex_line->text(); double dval = val.toDouble() * 100; ui->movex_slider->setSliderPosition(dval);});

    ui->movey_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movey_slider->setTickInterval(0);
    connect(ui->movey_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->movey_slider->value() / 100.0;
            ui->movey_line->setText(QString::number(val, 'f', 2));
    connect(ui->movey_line, &QLineEdit::textChanged, this, [=]{QString val = ui->movey_line->text(); double dval = val.toDouble() * 100; ui->movey_slider->setSliderPosition(dval);});
        });

    ui->movez_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movez_slider->setTickInterval(0);
    connect(ui->movez_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->movez_slider->value() / 100.0;
            ui->movez_line->setText(QString::number(val, 'f', 2));
        });
    connect(ui->movez_line, &QLineEdit::textChanged, this, [=]{QString val = ui->movez_line->text(); double dval = val.toDouble() * 100; ui->movez_slider->setSliderPosition(dval);});



    ui->rotatex_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatex_slider->setTickInterval(0);
    connect(ui->rotatex_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->rotatex_slider->value() / 100.0;
            ui->rotatex_line->setText(QString::number(val, 'f', 2));
        });
    connect(ui->rotatex_line, &QLineEdit::textChanged, this, [=]{QString val = ui->rotatex_line->text(); double dval = val.toDouble() * 100; ui->rotatex_slider->setSliderPosition(dval);});
    ui->rotatey_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatey_slider->setTickInterval(0);
    connect(ui->rotatey_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->rotatey_slider->value() / 100.0;
            ui->rotatey_line->setText(QString::number(val, 'f', 2));
        });
    connect(ui->rotatey_line, &QLineEdit::textChanged, this, [=]{QString val = ui->rotatey_line->text(); double dval = val.toDouble() * 100; ui->rotatey_slider->setSliderPosition(dval);});
    ui->rotatez_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatez_slider->setTickInterval(0);
    connect(ui->rotatez_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->rotatez_slider->value() / 100.0;
            ui->rotatez_line->setText(QString::number(val, 'f', 2));
        });
    connect(ui->rotatez_line, &QLineEdit::textChanged, this, [=]{QString val = ui->rotatez_line->text(); double dval = val.toDouble() * 100; ui->rotatez_slider->setSliderPosition(dval);});


    ui->zoom_slider->setRange(0, ZOOM_MAX);
    ui->zoom_slider->setValue(10);
    ui->zoom_slider->setTickInterval(0);
    connect(ui->zoom_slider,&QSlider::sliderMoved,this,[=]{
        double val=ui->zoom_slider->value() / 100.0;
            ui->zoom_line->setText(QString::number(val, 'f', 2));
        });
    connect(ui->zoom_line, &QLineEdit::textChanged, this, [=]{QString val = ui->zoom_line->text(); double dval = val.toDouble() * 100; ui->zoom_slider->setSliderPosition(dval);});



}

MainWindow::~MainWindow()
{
    delete ui;
}





QString MainWindow::open_file() {
    QString file = QFileDialog::getOpenFileName(this, "Выбрать файл для открытия", QDir::homePath(), "Text Files (*.obj)");
    if (file.isEmpty()) return NULL;
    return file;
}

void MainWindow::on_action_open_file_triggered()
{
    QString file = this->open_file();
    // Здесь будет наш парсер.

}


void MainWindow::on_pushButton_clicked()
{
    QString file = this->open_file();
    // Здесь будет наш парсер.

}



void MainWindow::on_move_apply_clicked()
{
    double move_x = ui->movex_line->text().toDouble();
    double move_y = ui->movey_line->text().toDouble();
    double move_z = ui->movez_line->text().toDouble();
    for (int i = 0; i < ui->widget_3->vertex_count*3; i+=3) {
        ui->widget_3->vertex_array[i] += move_x/100;
        ui->widget_3->vertex_array[i+1] += move_y/100;
        ui->widget_3->vertex_array[i+2] += move_z/100;
    }
    ui->movex_line->setText("0");
    ui->movey_line->setText("0");
    ui->movez_line->setText("0");
    ui->widget_3->update();
}


void MainWindow::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
//      if (color.isValid()) {
//        ui->OGLwidget->lineColor = color;
//        updateUiColors();
//      }
}


void MainWindow::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
      if (color.isValid()) {
        ui->widget_3->lineColor = color;
        ui->widget_3->update();
      }
}

