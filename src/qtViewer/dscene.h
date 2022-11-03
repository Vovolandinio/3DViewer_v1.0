#ifndef SCENE_H
#define SCENE_H

#include <QColorDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>

#include <QGraphicsSceneMouseEvent>

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
    void set_obj_params(indexes * in);

    int get_verticles_count();
    int get_lines_count();

    int get_verticles_paint();
    int get_lines_paint();

    void save_settings();
    QString dl_settings();

    void add_example();

    void clear_values();
    void set_projection(int value);

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

    int projection = 0;

    QPointF mouse_down;
    QPointF mouse_up;
    float mx = 0;
    float my = 0;
    QPoint _p;

  protected:
    void mousePressEvent(QMouseEvent* event) override {
            if ( event->button() == Qt::LeftButton ) {
                _p = event->pos();
            }
        }
        void mouseMoveEvent(QMouseEvent* event) override {
            // Если _p - не null, значит он был установлен, а это значит,
            // что была нажата лкм, значит можно двигать окно относительно _p
            if( !_p.isNull() ) {
                _p = event->pos() - _p;
                move_object(_p.x(), _p.y(), 0);
            }
        }

        // В принципе, для перемещения окна можно обойтись и без этого метода,
        // но раз в вопросе сказано про отпускание км, то
        void mouseReleaseEvent(QMouseEvent* event) override {
            // устанавливаем _p в null-объект QPoint()
            _p = QPoint();
        }

};

#endif  // SCENE_H
