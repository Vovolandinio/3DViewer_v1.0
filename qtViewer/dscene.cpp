#include "dscene.h"

#include <math.h>

#define GL_PI 3.1415f

DScene::DScene(QWidget *parent)
    : QOpenGLWidget(parent) {
  this->setFocusPolicy(Qt::StrongFocus);
}

QOpenGLShaderProgram * DScene::initialize_shaders() {

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

      return prog;
}

void DScene::initializeGL() {

  //включаем буфер глубины для отображения Z-координаты
  glEnable(GL_DEPTH_TEST);


//  // устанавливаем текущей проекционную матрицу
//  glMatrixMode(GL_PROJECTION);
//  // присваиваем проекционной матрице единичную матрицу
//  glLoadIdentity();
//  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
//  glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 1.0);

  lineColor.setRgb(255,255,255);
  verticleColor.setRgb(255,0,0);
  backgroundColor.setRgb(0,0,0);

  prog = initialize_shaders();

  vertex_count = 4;
  vertex_array = new float[3 * vertex_count];
  float buff_vertex[] = {-0.5, 0, -0.5, 0.5, 0, -0.5, 0, 0.5, -0.5, 0, -0.5, -1};
  for (int i = 0; i < vertex_count * 3; i++) {
      vertex_array[i] = buff_vertex[i];
  }

  lines_count = 6;
  unsigned int buff_lines[] = {0,1,1,2,2,0,0,3,1,3,2,3};
  lines_array = new unsigned int[2*lines_count];
  for (int i = 0; i < 2*lines_count; i++) {
      lines_array[i] = buff_lines[i];
  }
}

void DScene::paintGL() {

    glClearColor(backgroundColor.redF(),backgroundColor.greenF(),backgroundColor.blueF(),1);

    prog->bind();


    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo.allocate(vertex_array, vertex_count* 3 * sizeof(float));

    prog->setAttributeBuffer(0, GL_FLOAT, 0, 3, 0);
    prog->enableAttributeArray(0);

    QOpenGLBuffer ibo(QOpenGLBuffer::IndexBuffer);
    ibo.create();
    ibo.bind();
    ibo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    ibo.allocate(lines_array, sizeof(unsigned int) * 2*lines_count);


    glClear( GL_COLOR_BUFFER_BIT );
    lineColorV = {lineColor.redF(), lineColor.greenF(), lineColor.blueF()};
    prog->setUniformValue(prog->uniformLocation("color"), lineColorV);

    if (lines_paint) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(3, 0x00FF);
    }
    glLineWidth(lines_size);
    glDrawElements(GL_LINES, 2*lines_count, GL_UNSIGNED_INT, 0);

    if (lines_paint) glDisable(GL_LINE_STIPPLE);

    if (verticles_paint) {
        verticleColorV = {verticleColor.redF(), verticleColor.greenF(), verticleColor.blueF()};
        prog->setUniformValue(prog->uniformLocation("color"), verticleColorV);
        glPointSize(verticles_size);
        if (verticles_paint == 1) glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS,0, vertex_count);
        if (verticles_paint == 1) glDisable(GL_POINT_SMOOTH);
    }
  }

void DScene::resizeGL(int w, int h) {
  // Prevent a divide by zero
  if (h == 0) {
    h = 1;
  }

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

}
