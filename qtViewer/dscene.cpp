#include "dscene.h"

#include <math.h>

#define GL_PI 3.1415f

DScene::DScene(QWidget *parent)
    : QOpenGLWidget(parent), xRot(0.0f), yRot(0.0f) {
  this->setFocusPolicy(Qt::StrongFocus);
}

void DScene::initializeGL() {
  // Black background
//  glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
  // glClearColor(r, g, b, alpha);
  // glClear(GL_COLOR_BUFFER_BIT);

  // Set drawing color to green
  glColor3f(0.0f, 1.0f, 0.0f);

  //включаем буфер глубины для отображения Z-координаты
  glEnable(GL_DEPTH_TEST);
}

void DScene::paintGL() {
    static float vertex_array[] = {0.0,  1.0,  1.0, 0.0,  0.0,  0.5, 0.0,  0.5,  0.0, 0.0,  0.5,  0.5, 0.5,  0.0,  0.0, 0.5,  0.0,  0.5, 0.5,  0.5,  0.0, 0.5,  0.5,  0.5};
    int edges_counter = 8;
    static int polygon_array[] = {0, 6, 6, 4, 4, 0, 0, 2, 2, 6, 0, 6, 0, 2, 2, 3, 3, 0, 0, 1, 1, 3, 0, 3, 2, 7, 7, 6, 6, 2, 2, 3, 3, 7, 2, 7, 4, 6, 6, 7, 7, 4, 4, 7, 7, 5, 5, 4, 0, 4, 4, 5, 0, 5, 0, 5, 5, 1, 0, 1, 1, 5, 5, 7, 1, 7, 1, 7, 7, 3, 1, 3};
    int lines_count = 24;
    float width = 0.9;

    const char *vertexShaderSource =
          "attribute vec3 position;\n"
          "void main()\n"
          "{\n"
          "gl_Position = vec4(position.x, position.y, "
          "position.z, "
          "1.0);\n"
          "}\0";
      const char *fragmentShaderSource =
          "uniform vec3 color;\n"
          "void main()\n"
          "{\n"
          "gl_FragColor = vec4(color.x, color.y, color.z, 1);\n"
          "}\n\0";

     QOpenGLShaderProgram *prog = new QOpenGLShaderProgram;
     prog->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
       prog->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
       prog->bindAttributeLocation("position", 0);
     prog->link();
     prog->bind();

    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
     vbo.create();
     vbo.bind();
     vbo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
     vbo.allocate(vertex_array, 8 * sizeof(float));
//     std::free(inff.array);

     prog->setAttributeBuffer(0, GL_FLOAT, 0, 3, 0);
     prog->enableAttributeArray(0);

     QOpenGLBuffer ibo(QOpenGLBuffer::IndexBuffer);
     ibo.create();
     ibo.bind();
     ibo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
     ibo.allocate(polygon_array, sizeof(unsigned int) * 24);
//     std::free(inff.polygon);


    glClear( GL_COLOR_BUFFER_BIT );
//    glColor3f( 0.0f, 0.0f, 1.0f );
    QVector3D lineColorV = {0.5, 0.5, 1};
    prog->setUniformValue(prog->uniformLocation("color"), lineColorV);



    // 3 - это количество координат на вершину, GL_DOUBLE - тип данных в
    // массиве, 0 - расстояние между вершинами в массиве, в нашем случае
    // означает, что вершины упакованы в массив без пробелов, vertex_array -
    // указатель на массив вершин.
//    glVertexPointer(3, GL_DOUBLE, 0, vertex_array);

    // Включаем состояние OpenGL для отрисовки
//    glEnableClientState(GL_VERTEX_ARRAY);

    // Отрисовка вершин

//     glDrawArrays(GL_POINTS, 0,8);

    // line width
//    glLineWidth(width);

    // Отрисовка линий
    // edges_counter - размер массива индексов, третий аргумент тип данных
    // который хранится у нас в массиве,
    // polygon_array - указатель на массив индексов.

    glDrawElements(GL_LINES, lines_count, GL_UNSIGNED_INT, 0);

    // Вuiключаем состояние OpenGL для отрисовки
//    glDisableClientState(GL_VERTEX_ARRAY);
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
