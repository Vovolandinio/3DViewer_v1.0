#ifndef SCENE_H
#define SCENE_H

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>

class DScene : public QOpenGLWidget {
 public:
  DScene(QWidget *parent = 0);

 private:
  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

 private:
  // Rotation amounts
  GLfloat xRot;
  GLfloat yRot;
};

#endif  // SCENE_H
