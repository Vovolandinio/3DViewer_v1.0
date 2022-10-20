#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QMouseEvent>

class Scene : public QOpenGLWidget
{
public:
    Scene( QWidget *parent = 0 );
    void change_color();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void keyPressEvent( QKeyEvent *event );

private:
    // Rotation amounts
    GLfloat xRot;
    GLfloat yRot;
};

#endif // SCENE_H
