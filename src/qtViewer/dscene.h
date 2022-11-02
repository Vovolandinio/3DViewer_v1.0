#ifndef SCENE_H
#define SCENE_H

#include <QColorDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>

#include <iostream>
#include <fstream>

extern "C" {
#include "../parser/s21_parser.h"
}

class DScene : public QOpenGLWidget {
   public:
    DScene(QWidget *parent = 0);

    void move_object(float x, float y, float z);
    void change_line_color();
    void change_verticles_color();
    void set_verticles_paint(int i);
    void set_lines_paint(int i);
    void set_verticles_size(double value);
    void change_line_size(double value);
    void change_bg_color(QColor color);
    void change_zoom(double zoom);
    void rotate_object(double x, double y, double z);

    int get_verticles_count();
    int get_lines_count();

    int get_verticles_paint();
    int get_lines_paint();

    void save_settings();
    QString dl_settings();

    void clear_values();

   private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    QOpenGLShaderProgram *initialize_shaders();
    QOpenGLShaderProgram *prog = NULL;
    QOpenGLBuffer vbo;
    QOpenGLBuffer ibo;

    QVector3D lineColorV = {1, 1, 1};
    QVector3D verticleColorV = {1, 0, 0};

    float *vertex_array;
    int vertex_count = 0;
    unsigned int *lines_array;
    int lines_count = 0;

    QColor lineColor;
    QColor verticleColor;
    QColor backgroundColor;

    int verticles_paint = 0;
    float verticles_size = 10;

    int lines_paint = 0;
    float lines_size = 1;
};

#endif  // SCENE_H
