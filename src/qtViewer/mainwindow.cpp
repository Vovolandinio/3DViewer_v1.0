#include "mainwindow.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>
#include "../gif/gif.h"
#include <QScrollArea>

#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("3D Viewer");
    int RANGE_MAX = 25000;
    int ROTATE_MAX = 18000;
    int ZOOM_MAX = 10000;
    ui->widget_3->dl_settings();

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidget(ui->centralwidget);
    setCentralWidget(scrollArea);

    scrollArea->setVisible(true);

    connect(ui->widget_3, SIGNAL(aboba()), this, SLOT(update_sliders()));
    connect(ui->widget_3, SIGNAL(beba()), this, SLOT(update_rotate_sliders()));
    connect(ui->widget_3, SIGNAL(pepe()), this, SLOT(update_zoom()));

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
    QString file =
        QFileDialog::getOpenFileName(this, "Выбрать файл для открытия",
                                     0, "Text Files (*.obj)");
    if (file.isEmpty()) return NULL;
    parser_work(file);
    set_file_name(file, ui->widget_3->get_verticles_count(), ui->widget_3->get_lines_count());
    null_sliders();
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

void MainWindow::on_actionGIF_2_triggered() {
    ui->actionGIF_2->setEnabled(false);
    QDir *pathDir = new QDir();
    pathDir->mkdir(QDir::homePath() + "/screenshots/gif_obj/");
    startTime = 0, tmpTime = 1000 / GifFps;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
    timer->start(1000 / GifFps);
}


void MainWindow::on_pushButton_clicked() {
    QString file = this->open_file();
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

//void MainWindow::on_zoom_button_clicked() {
//    double zoom = ui->zoom_line->text().toDouble();
//    ui->widget_3->change_zoom(zoom);
//    ui->zoom_line->setText("1");
//}

void MainWindow::set_file_name(QString filename, int verticles, int lines) {
    QStringList pieces = filename.split( "/" );

    ui->label->setText(
        "Название файла:\n" + pieces[pieces.length() - 1] +
        "\n\n\n Количество вершин:" + QString::number(verticles) +
        "\n Количество линий: " + QString::number(lines));
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

void MainWindow::oneGif() {
  if (startTime == tmpTime) {
    ui->widget_3->grab().scaled(640, 480, Qt::IgnoreAspectRatio).save(QDir::homePath() + "/screenshots/gif_obj/" + QString::number(counter) +".bmp");
    counter++;
    tmpTime += 1000 / GifFps;
  }
  if (startTime == 1000 * GifLength) {
    createGif();
    timer->stop();
    counter = 1;
  }
  startTime += 1000 / GifFps;
}


void MainWindow::createGif() {
  QDir pathFile;
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  QString gif_name = QDir::homePath() + "/screenshots/" + currentDateTime + ".gif";
  QByteArray ga = gif_name.toLocal8Bit();
  GifWriter writer = {};
  int err = 0;

  if (GifBegin(&writer, ga.data(), 640, 480, 10, 8, false)) {
    for (int i = 1; i <= 50; i++) {
      if (err == 1) {
        break;
      }
      QImage img(QDir::homePath() + "/screenshots/gif_obj/" + QString::number(i) +
                 ".bmp");
      if (!img.isNull()) {
        if (GifWriteFrame(&writer,
                          img.convertToFormat(QImage::Format_Indexed8)
                              .convertToFormat(QImage::Format_RGBA8888)
                              .constBits(),
                          640, 480, 10, 8, false)) {
        } else {
          QMessageBox::critical(0, "Error", "Gif file can not be created...");
          err = 1;
        }
      } else {
        QMessageBox::critical(0, "Error", "Gif file can not be created...");
        err = 1;
      }
    }
    if (err == 0) {
      GifEnd(&writer);
    }
  } else {
    err = 1;
    QMessageBox::critical(0, "Error", "Gif file can not be created...");
  }

  if (err == 1) {
    if (QFile::exists(gif_name)) {
      QFile::remove(gif_name);
    }
  }

  pathFile.setPath(QDir::homePath() + "/screenshots/gif_obj/");
  pathFile.removeRecursively();
  ui->actionGIF_2->setEnabled(true);
}

void MainWindow::update_sliders() {
    ui->movex_line->setText(QString::number(ui->widget_3->movex));
    ui->movey_line->setText(QString::number(ui->widget_3->movey));
}

void MainWindow::update_rotate_sliders() {
    ui->rotatex_line->setText(QString::number(ui->widget_3->rotatex));
    ui->rotatey_line->setText(QString::number(ui->widget_3->rotatey));
}

void MainWindow::null_sliders() {
    ui->widget_3->movex = 0;
    ui->widget_3->movey = 0;
    ui->widget_3->movez = 0;
    ui->widget_3->rotatex = 0;
    ui->widget_3->rotatey = 0;
    ui->widget_3->rotatez = 0;
    ui->widget_3->zoom = 1;
}

void MainWindow::on_movex_slider_sliderMoved(int position)
{
    double move_x = ui->movex_line->text().toDouble();
    double move_y = ui->movey_line->text().toDouble();
    double move_z = ui->movez_line->text().toDouble();
    ui->widget_3->move_object(move_x-ui->widget_3->movex, move_y-ui->widget_3->movey, move_z-ui->widget_3->movez);
    ui->widget_3->movex = move_x;
    ui->widget_3->movey = move_y;
    ui->widget_3->movez = move_z;
    ui->widget_3->update();
}


void MainWindow::on_movey_slider_sliderMoved(int position)
{
    double move_x = ui->movex_line->text().toDouble();
    double move_y = ui->movey_line->text().toDouble();
    double move_z = ui->movez_line->text().toDouble();
    ui->widget_3->move_object(move_x-ui->widget_3->movex, move_y-ui->widget_3->movey, move_z-ui->widget_3->movez);
    ui->widget_3->movex = move_x;
    ui->widget_3->movey = move_y;
    ui->widget_3->movez = move_z;
    ui->widget_3->update();
}


void MainWindow::on_movez_slider_sliderMoved(int position)
{
    double move_x = ui->movex_line->text().toDouble();
    double move_y = ui->movey_line->text().toDouble();
    double move_z = ui->movez_line->text().toDouble();
    ui->widget_3->move_object(move_x-ui->widget_3->movex, move_y-ui->widget_3->movey, move_z-ui->widget_3->movez);

    ui->widget_3->movez = move_z;
    ui->widget_3->update();
}


void MainWindow::on_rotatex_slider_sliderMoved(int position)
{
    double rotate_x = ui->rotatex_slider->value() / 100;
    double rotate_y = ui->rotatey_slider->value() / 100;
    double rotate_z = ui->rotatez_slider->value() / 100;
    ui->widget_3->rotate_object(rotate_x-ui->widget_3->rotatex, rotate_y-ui->widget_3->rotatey, 0);
    ui->widget_3->rotatex = rotate_x;
    ui->widget_3->rotatey = rotate_y;
}


void MainWindow::on_rotatey_slider_sliderMoved(int position)
{
    double rot_x = ui->rotatex_slider->value() / 100;
    double rot_y = ui->rotatey_slider->value() / 100;
    double rot_z = ui->rotatez_slider->value() / 100;
    ui->widget_3->rotate_object(rot_x-ui->widget_3->rotatex, rot_y-ui->widget_3->rotatey, 0);
    ui->widget_3->rotatex = rot_x;
    ui->widget_3->rotatey = rot_y;
}


void MainWindow::on_rotatez_slider_sliderMoved(int position)
{
    double rot_x = ui->rotatex_slider->value() / 100;
    double rot_y = ui->rotatey_slider->value() / 100;
    double rot_z = ui->rotatez_slider->value() / 100;
    ui->widget_3->rotate_object(rot_x-ui->widget_3->rotatex, rot_y-ui->widget_3->rotatey, rot_z-ui->widget_3->rotatez);
    ui->widget_3->rotatez = rot_z;
}

void MainWindow::update_zoom() {
    ui->zoom_line->setText(QString::number(ui->widget_3->zoom, 'f', 2));
}
void MainWindow::on_zoom_slider_sliderMoved(int position)
{
    double zoomq = ui->zoom_line->text().toDouble();
    ui->widget_3->change_zoom(zoomq-ui->widget_3->zoom);

}

