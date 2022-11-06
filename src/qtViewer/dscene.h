#ifndef SCENE_H
#define SCENE_H


#define GL_SILENCE_DEPRECATION

#include <QColorDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>


#include <QGraphicsSceneMouseEvent>

#include <iostream>
#include <fstream>

#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

extern "C" {
#include "../parser/s21_parser.h"
}

class DScene : public QOpenGLWidget {
    Q_OBJECT

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
    void setupProjection(int w, int h);

    void add_example();
    float move_rotate = 1;

    void clear_values();

    QMatrix4x4 projectionMatrix;
    QMatrix4x4 cameraMatrix;
    void set_projection(int value);

    float movex = 0;
    float movey = 0;
    float movez = 0;
    float rotatex = 0;
    float rotatey = 0;
    float rotatez = 0;
    float zoom = 1;


   private:
    void mouseMoveEvent(QMouseEvent* event);

    void initializeGL() ;
    void paintGL() ;
    void resizeGL(int w, int h) ;

    QOpenGLShaderProgram *initialize_shaders();
    QOpenGLShaderProgram *prog = NULL;
    QOpenGLBuffer vbo;
    QOpenGLBuffer ibo;

    QVector3D lineColorV = {1, 1, 1};
    QVector3D verticleColorV = {1, 0, 0};

    float *vertex_array = NULL;
    int vertex_count = 0;
    unsigned int *lines_array = NULL;
    int lines_count = 0;

    QColor lineColor;
    QColor verticleColor;
    QColor backgroundColor;

    int verticles_paint = 0;
    float verticles_size = 10;

    int lines_paint = 0;
    float lines_size = 1;

    int projection = 0;
    int m_coeffMatrixLoc = 0;

    QPointF mouse_down;
    QPointF mouse_up;
    float mx = 0;
    float my = 0;
    float mrx = 0;
    float mry = 0;
    QPoint _p;
    QPoint _r;


  protected:
    void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void wheelEvent(QWheelEvent *event);
signals:
        void aboba();
        void beba();
        void pepe();

};

#endif  // SCENE_H
