#include "dscene.h"

#include <math.h>

#define GL_PI 3.1415f


DScene::DScene(QWidget *parent) : QOpenGLWidget(parent) {
    this->setFocusPolicy(Qt::StrongFocus);
}

QOpenGLShaderProgram *DScene::initialize_shaders() {
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
    prog->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                  fragmentShaderSource);
    prog->bindAttributeLocation("position", 0);
    prog->link();

    return prog;
}

void DScene::initializeGL() {
    //включаем буфер глубины для отображения Z-координаты
    glEnable(GL_DEPTH_TEST);

    prog = initialize_shaders();

    add_example();
}


void DScene::resizeGL(int w, int h) {

}

void DScene::paintGL() {
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
                 backgroundColor.blueF(), 1);

    prog->bind();

    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo.allocate(vertex_array, vertex_count * 3 * sizeof(float));

    prog->setAttributeBuffer(0, GL_FLOAT, 0, 3, 0);
    prog->enableAttributeArray(0);

    QOpenGLBuffer ibo(QOpenGLBuffer::IndexBuffer);
    ibo.create();
    ibo.bind();
    ibo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    ibo.allocate(lines_array, sizeof(unsigned int) * 2 * lines_count);

    glClear(GL_COLOR_BUFFER_BIT);
    lineColorV = {lineColor.redF(), lineColor.greenF(), lineColor.blueF()};
    prog->setUniformValue(prog->uniformLocation("color"), lineColorV);

    if (lines_paint) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(3, 0x00FF);
    }
    glLineWidth(lines_size);
    glDrawElements(GL_LINES, 2 * lines_count, GL_UNSIGNED_INT, 0);

    if (lines_paint) glDisable(GL_LINE_STIPPLE);

    if (verticles_paint) {
        verticleColorV = {verticleColor.redF(), verticleColor.greenF(),
                          verticleColor.blueF()};
        prog->setUniformValue(prog->uniformLocation("color"), verticleColorV);
        glPointSize(verticles_size);
        if (verticles_paint == 1) glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS, 0, vertex_count);
        if (verticles_paint == 1) glDisable(GL_POINT_SMOOTH);
    }
}


void DScene::move_object(float x, float y, float z) {
    for (int i = 0; i < vertex_count * 3; i += 3) {
        vertex_array[i] += x / 100;
        vertex_array[i + 1] += y / 100;
        vertex_array[i + 2] += z / 100;
    }
}

void DScene::change_line_color() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid()) {
        lineColor = color;
        update();
    }
}

void DScene::change_verticles_color() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if (color.isValid()) {
        verticleColor = color;
        update();
    }
}

void DScene::set_verticles_paint(int i) {
    if (verticles_paint != i) {
        verticles_paint = i;
        update();
    }
}

void DScene::set_lines_paint(int i) {
    if (lines_paint != i) {
        lines_paint = i;
        update();
    }
}

void DScene::set_verticles_size(double value) {
    verticles_size = value;
    update();
}

void DScene::change_line_size(double value) {
    if (lines_size != value) {
        lines_size = value;
        update();
    }
}

void DScene::change_bg_color(QColor color) {
    backgroundColor = color;
    update();
}

void DScene::change_zoom(double zoom) {
    for (int i = 0; i < vertex_count * 3; i++) {
        vertex_array[i] = vertex_array[i] * zoom;
    }
    update();
}

void DScene::save_settings() {
    std::ofstream out;  // поток для записи
    out.open("../../../../qtViewer/settings.txt");  // окрываем файл для записи
    if (out.is_open()) {
        out << lineColor.name().toStdString() << std::endl;
        out << verticleColor.name().toStdString() << std::endl;
        out << backgroundColor.name().toStdString() << std::endl;

        out << verticles_paint << std::endl;
        out << verticles_size << std::endl;
        out << lines_paint << std::endl;
        out << lines_size << std::endl;
    }
    std::cout << "Settings saved" << std::endl;
    out.close();
}

QString DScene::dl_settings() {
    std::string line;
    QString out;

    std::ifstream in(
        "../../../../qtViewer/settings.txt");  // окрываем файл для чтения
    if (in.is_open()) {
        getline(in, line);
        lineColor.setNamedColor(QString::fromStdString(line));
        getline(in, line);
        verticleColor.setNamedColor(QString::fromStdString(line));
        getline(in, line);
        out = QString::fromStdString(line);
        backgroundColor.setNamedColor(out);

        getline(in, line);
        verticles_paint = std::stoi(line);
        getline(in, line);
        verticles_size = std::stoi(line);
        getline(in, line);
        lines_paint = std::stoi(line);
        getline(in, line);
        lines_size = std::stoi(line);

    }
    in.close();  // закрываем файл
    std::cout << "settings downloaded successfull" << std::endl;
    return out;
}

void DScene::rotate_object(double x, double y, double z) {
    if (x != 0) rotate_x(vertex_array, vertex_count, x);
    if (y != 0) rotate_y(vertex_array, vertex_count, y);
    if (z != 0) rotate_z(vertex_array, vertex_count, z);
    update();
}

void DScene::clear_values() {
  if (vertex_array) delete vertex_array;
  if (lines_array) delete lines_array;
}

int DScene::get_verticles_count() {
  return vertex_count;
}


int DScene::get_lines_count() {
  return lines_count;
}

int DScene::get_verticles_paint() {
  return verticles_paint;
}

int DScene::get_lines_paint() {
  return lines_paint;
}

void DScene::add_example() {
    vertex_count = 4;
    vertex_array = new float[3 * vertex_count];
    float buff_vertex[] = {-0.5, 0,   -0.5, 0.5, 0,    -0.5,
                           0,    0.5, -0.5, 0,   -0.5, -1};
    for (int i = 0; i < vertex_count * 3; i++) {
        vertex_array[i] = buff_vertex[i];
    }

    lines_count = 6;
    unsigned int buff_lines[] = {0, 1, 1, 2, 2, 0, 0, 3, 1, 3, 2, 3};
    lines_array = new unsigned int[2 * lines_count];
    for (int i = 0; i < 2 * lines_count; i++) {
        lines_array[i] = buff_lines[i];
    }
}

void DScene::set_obj_params(indexes * in) {
    if (vertex_array) free(vertex_array);
    if (lines_array) free(lines_array);
    vertex_count = in->indexV/3;
    vertex_array = in->array;
    lines_count = in->lines_count;
    lines_array = in->indexess;
}

void DScene::set_projection(int value) {
    if (projection != value) {
        projection = value;
        update();
    }
}
