#include "mainwindow.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("3D Viewer");
    int RANGE_MAX = 25000;
    int ROTATE_MAX = 36000;
    int ZOOM_MAX = 10000;
    QString bg_color = ui->widget_3->dl_settings();
    this->setStyleSheet("background-color: " + bg_color);



    if (ui->widget_3->get_lines_paint()) ui->edges_dashed->setChecked(true);
    if (ui->widget_3->get_verticles_paint() == 1) ui->vertices_circle->setChecked(true);
    if (ui->widget_3->get_verticles_paint() == 2) ui->vertices_square->setChecked(true);

        ui->movex_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movex_slider->setTickInterval(0);
    connect(ui->movex_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->movex_slider->value() / 100.0;
        ui->movex_line->setText(QString::number(val, 'f', 2));
    });

    connect(ui->movex_line, &QLineEdit::textChanged, this, [=] {
        QString val = ui->movex_line->text();
        double dval = val.toDouble() * 100;
        ui->movex_slider->setSliderPosition(dval);
    });

    ui->movey_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movey_slider->setTickInterval(0);
    connect(ui->movey_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->movey_slider->value() / 100.0;
        ui->movey_line->setText(QString::number(val, 'f', 2));
        connect(ui->movey_line, &QLineEdit::textChanged, this, [=] {
            QString val = ui->movey_line->text();
            double dval = val.toDouble() * 100;
            ui->movey_slider->setSliderPosition(dval);
        });
    });

    ui->movez_slider->setRange(-RANGE_MAX, RANGE_MAX);
    ui->movez_slider->setTickInterval(0);
    connect(ui->movez_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->movez_slider->value() / 100.0;
        ui->movez_line->setText(QString::number(val, 'f', 2));
    });
    connect(ui->movez_line, &QLineEdit::textChanged, this, [=] {
        QString val = ui->movez_line->text();
        double dval = val.toDouble() * 100;
        ui->movez_slider->setSliderPosition(dval);
    });

    ui->rotatex_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatex_slider->setTickInterval(0);
    connect(ui->rotatex_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->rotatex_slider->value() / 100.0;
        ui->rotatex_line->setText(QString::number(val, 'f', 2));
    });
    connect(ui->rotatex_line, &QLineEdit::textChanged, this, [=] {
        QString val = ui->rotatex_line->text();
        double dval = val.toDouble() * 100;
        ui->rotatex_slider->setSliderPosition(dval);
    });
    ui->rotatey_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatey_slider->setTickInterval(0);
    connect(ui->rotatey_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->rotatey_slider->value() / 100.0;
        ui->rotatey_line->setText(QString::number(val, 'f', 2));
    });
    connect(ui->rotatey_line, &QLineEdit::textChanged, this, [=] {
        QString val = ui->rotatey_line->text();
        double dval = val.toDouble() * 100;
        ui->rotatey_slider->setSliderPosition(dval);
    });
    ui->rotatez_slider->setRange(-ROTATE_MAX, ROTATE_MAX);
    ui->rotatez_slider->setTickInterval(0);
    connect(ui->rotatez_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->rotatez_slider->value() / 100.0;
        ui->rotatez_line->setText(QString::number(val, 'f', 2));
    });
    connect(ui->rotatez_line, &QLineEdit::textChanged, this, [=] {
        QString val = ui->rotatez_line->text();
        double dval = val.toDouble() * 100;
        ui->rotatez_slider->setSliderPosition(dval);
    });

    ui->zoom_slider->setRange(0, ZOOM_MAX);
    ui->zoom_slider->setValue(1000);
    ui->zoom_slider->setTickInterval(0);
    connect(ui->zoom_slider, &QSlider::sliderMoved, this, [=] {
        double val = ui->zoom_slider->value() / 1000.0;
        ui->zoom_line->setText(QString::number(val, 'f', 2));
    });
    connect(ui->zoom_line, &QLineEdit::textChanged, this, [=] {
        QString val = ui->zoom_line->text();
        double dval = val.toDouble() * 1000;
        ui->zoom_slider->setSliderPosition(dval);
    });
}

MainWindow::~MainWindow() {
    ui->widget_3->clear_values();
    ui->widget_3->save_settings();
    delete ui;
}

QString MainWindow::open_file() {
    std::cout << "norm start"<< std::endl;

    QString file =
        QFileDialog::getOpenFileName(this, "Выбрать файл для открытия",
                                     QDir::homePath(), "Text Files (*.obj)");
    if (file.isEmpty()) return NULL;
    set_file_name(file, ui->widget_3->get_verticles_count(), ui->widget_3->get_lines_count());
//            QFile::filename()
    std::cout << "name ok"<< std::endl;
    parser_work(file);

    ui->widget_3->update();
    return file;
}

void MainWindow::on_action_open_file_triggered() {
    QString file = this->open_file();
}

void MainWindow::on_actionJPG_2_triggered() {
    dateTime = dateTime.currentDateTime();
    currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
    ui->widget_3->grab().save(QDir::homePath() + "/screenshots/" + currentDateTime +".jpg");
}

void MainWindow::on_actionPNG_2_triggered() {
    dateTime = dateTime.currentDateTime();
    currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
    ui->widget_3->grab().save(QDir::homePath() + "/screenshots/" + currentDateTime +".png");
}

void MainWindow::on_pushButton_clicked() {
    QString file = this->open_file();
}

void MainWindow::on_move_apply_clicked() {
    double move_x = ui->movex_line->text().toDouble();
    double move_y = ui->movey_line->text().toDouble();
    double move_z = ui->movez_line->text().toDouble();
    ui->widget_3->move_object(move_x, move_y, move_z);
    ui->movex_line->setText("0");
    ui->movey_line->setText("0");
    ui->movez_line->setText("0");
    ui->widget_3->update();
}

// Меняет цвет вершин
void MainWindow::on_pushButton_2_clicked() {
    ui->widget_3->change_verticles_color();
}

// меняет цвет линий
void MainWindow::on_pushButton_3_clicked() {
    ui->widget_3->change_line_color();
}

void MainWindow::on_vertices_no_clicked() {
    ui->widget_3->set_verticles_paint(0);
}

void MainWindow::on_vertices_circle_clicked() {
    ui->widget_3->set_verticles_paint(1);
}

void MainWindow::on_vertices_square_clicked() {
    ui->widget_3->set_verticles_paint(2);
}

void MainWindow::on_verticles_size_slider_sliderReleased() {
    double value = ui->verticles_size_slider->value();
    ui->widget_3->set_verticles_size(value);
}

void MainWindow::on_edges_solid_clicked() { ui->widget_3->set_lines_paint(0); }

void MainWindow::on_edges_dashed_clicked() { ui->widget_3->set_lines_paint(1); }

void MainWindow::on_lines_sie_slider_sliderReleased() {
    double value = ui->lines_sie_slider->value();
    ui->widget_3->change_line_size(value);
}

void MainWindow::on_bg_color_button_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid()) {
        ui->widget_3->change_bg_color(color);
        ui->centralwidget->setStyleSheet("background-color:" + color.name());
    }
}

void MainWindow::on_zoom_button_clicked() {
    double zoom = ui->zoom_line->text().toDouble();
    ui->widget_3->change_zoom(zoom);
    ui->zoom_line->setText("1");
}

void MainWindow::set_file_name(QString filename, int verticles, int lines) {
    ui->label->setText(
        "Название файла:\n" + filename +
        "\n\n\n Количество вершин:" + QString::number(verticles) +
        "\n Количество линий: " + QString::number(lines));
}

void MainWindow::on_rotate_apply_clicked() {
    double rotate_x = ui->rotatex_slider->value() / 100;
    double rotate_y = ui->rotatey_slider->value() / 100;
    double rotate_z = ui->rotatez_slider->value() / 100;
    ui->widget_3->rotate_object(rotate_x, rotate_y, rotate_z);
    ui->rotatex_line->setText("0");
    ui->rotatey_line->setText("0");
    ui->rotatez_line->setText("0");
}

void MainWindow::parser_work(QString filename) {
    indexes out;
    QByteArray ba = filename.toLocal8Bit();
    const char *fname = ba.data();
    std::cout << "parser start"<< std::endl;
    main_parser(fname, &out);
    std::cout << "parser ok"<< std::endl;
    ui->widget_3->set_obj_params(&out);
}

void MainWindow::on_proection_central_clicked()
{
    ui->widget_3->set_projection(1);
}


void MainWindow::on_proection_parallel_clicked()
{
    ui->widget_3->set_projection(0);
}

