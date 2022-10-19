#include "3dscene.h"

#include <math.h>

#define GL_PI 3.1415f

DScene::DScene(QWidget *parent)
    : QOpenGLWidget(parent), xRot(0.0f), yRot(0.0f) {
  this->setFocusPolicy(Qt::StrongFocus);
}

void DScene::initializeGL() {
  // Black background
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  // glClearColor(r, g, b, alpha);
  // glClear(GL_COLOR_BUFFER_BIT);

  // Set drawing color to green
  glColor3f(0.0f, 1.0f, 0.0f);

  //включаем буфер глубины для отображения Z-координаты
  glEnable(GL_DEPTH_TEST)
}

void DScene::paintGL() {
  // Storeage for coordinates and angles
  GLfloat x, y, z, angle;

  // Clear the window with current clearing color
  glClear(GL_COLOR_BUFFER_BIT);

  // Save matrix state and do the rotation
  glPushMatrix();
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);

  // Call only once for all remaining points
  glBegin(GL_POINTS);

  z = -50.0f;
  for (angle = 0.0f; angle <= (2.0f * GL_PI) * 3.0f; angle += 0.1f) {
    x = 50.0f * sin(angle);
    y = 50.0f * cos(angle);

    // Specify the point and move the Z value up a little
    glVertex3f(x, y, z);
    z += 0.5f;

    // 3 - это количество координат на вершину, GL_DOUBLE - тип данных в
    // массиве, 0 - расстояние между вершинами в массиве, в нашем случае
    // означает, что вершины упакованы в массив без пробелов, vertex_array -
    // указатель на массив вершин.

    // glVertexPointer(3, GL_DOUBLE, 0, vertex_array)

    // Включаем состояние OpenGL для отрисовки

    // glEnableClientState(GL_VERTEX_ARRAY)

    // Отрисовка вершин

    // glDrawArrays()

    // Отрисовка линий
    // edges_counter - размер массива индексов, третий аргумент тип данных
    // который хранится у нас в массиве,
    // indexes_array - указатель на массив индексов.

    // glDrawElements(GL_LINES, edges_counter, GL_UNSIGNED_INT, indexes_array)
  }

  // Done drawing points
  glEnd();

  // Restore transformations
  glPopMatrix();
}

void DScene::resizeGL(int w, int h) {
  // Prevent a divide by zero
  if (h == 0) {
    h = 1;
  }

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset projection matrix stack
  //   glMatrixMode(GL_PROJECTION);
  //   glLoadIdentity();

  //   GLfloat nRange = 100.0f;

  //   // Establish clipping volume (left, right, bottom, top, near, far)
  //   if (w <= h) {
  //     glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange,
  //     nRange);
  //   } else {
  //     glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange,
  //     nRange);
  //   }

  //   // Reset Model view matrix stack
  //   glMatrixMode(GL_MODELVIEW);
  //   glLoadIdentity();
}
