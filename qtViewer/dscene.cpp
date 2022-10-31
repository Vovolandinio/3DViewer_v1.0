#include "dscene.h"

#include <math.h>

#define GL_PI 3.1415f

DScene::DScene(QWidget *parent)
    : QOpenGLWidget(parent), xRot(0.0f), yRot(0.0f) {
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
      prog->bind();

      return prog;
}

void DScene::initializeGL() {

  //включаем буфер глубины для отображения Z-координаты
  glEnable(GL_DEPTH_TEST);

  prog = initialize_shaders();
}

void DScene::paintGL() {
    vertex_count = 4;
    vertex_array = new float[3 * vertex_count];
    float buff_vertex[] = {-0.5, 0, -0.5, 0.5, 0, -0.5, 0, 0.5, -0.5, 0, 0, -1};
    for (int i = 0; i < vertex_count * 3; i++) {
        vertex_array[i] = buff_vertex[i];
    }

    lines_count = 12;
    unsigned int buff_lines[] = {0,1,1,2,2,0,0,3,1,3,2,3};
    lines_array = new unsigned int[lines_count];
    for (int i = 0; i < lines_count; i++) {
        lines_array[i] = buff_lines[i];
    }


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
    ibo.allocate(lines_array, sizeof(unsigned int) * lines_count);


    glClear( GL_COLOR_BUFFER_BIT );
    QVector3D lineColorV = {0.5, 0.5, 1};
    prog->setUniformValue(prog->uniformLocation("color"), lineColorV);

    glDrawElements(GL_LINES, lines_count, GL_UNSIGNED_INT, 0);

  }

void DScene::resizeGL(int w, int h) {
  // Prevent a divide by zero
  if (h == 0) {
    h = 1;
  }

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

}
