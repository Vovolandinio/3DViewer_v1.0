#ifndef SCENE_H
#define SCENE_H

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>

class DScene : public QOpenGLWidget {
 public:
  DScene(QWidget *parent = 0);

 private:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

  QOpenGLShaderProgram * initialize_shaders();
  QOpenGLShaderProgram * prog = NULL;

  GLfloat xRot;
  GLfloat yRot;

  float * vertex_array;

  int vertex_count = 0;
  unsigned int * lines_array;
  int lines_count = 0;


};

#endif  // SCENE_H
