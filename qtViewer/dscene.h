#ifndef SCENE_H
#define SCENE_H

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>

class DScene : public QOpenGLWidget {
 public:
  DScene(QWidget *parent = 0);

  float * vertex_array;
  int vertex_count = 0;
  
  unsigned int * lines_array;
  int lines_count = 0;

  QColor lineColor;
  QColor verticleColor;
  QColor backgroundColor;

  int verticles_paint = 0;
  float verticles_size = 10;

  int lines_paint = 0;
  float lines_size = 1;




 private:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  QOpenGLShaderProgram * initialize_shaders();
  QOpenGLShaderProgram * prog = NULL;


  QOpenGLBuffer vbo;
  QOpenGLBuffer ibo;

  QVector3D lineColorV = {1, 1, 1};
  QVector3D verticleColorV = {1, 0, 0};


};

#endif  // SCENE_H
