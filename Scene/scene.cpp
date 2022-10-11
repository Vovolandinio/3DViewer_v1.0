
#include <math.h>
#include "Scene.h"

// Define a constant for the value of PI
#define GL_PI 3.1415f

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent ),
    xRot( 0.0f ),
    yRot( 0.0f )
{
    this->setFocusPolicy( Qt::StrongFocus );
}

void Scene::initializeGL()
{
    // Black background
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

    // Set drawing color to green
    glColor3f( 0.0f, 1.0f, 0.0f );
}

void Scene::paintGL()
{
    // Storeage for coordinates and angles
    GLfloat x, y, z, angle;

    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Save matrix state and do the rotation
    glPushMatrix();
    glRotatef( xRot, 1.0f, 0.0f, 0.0f );
    glRotatef( yRot, 0.0f, 1.0f, 0.0f );

    // Call only once for all remaining points
    glBegin( GL_POINTS );

    z = -50.0f;
    for( angle = 0.0f; angle <= ( 2.0f * GL_PI ) * 3.0f; angle += 0.1f )
    {
        x = 50.0f * sin( angle );
        y = 50.0f * cos( angle  );

        // Specify the point and move the Z value up a little
        glVertex3f( x, y, z );
        z += 0.5f;
    }

    // Done drawing points
    glEnd();

    // Restore transformations
    glPopMatrix();
}

void Scene::resizeGL( int w, int h )
{
    // Prevent a divide by zero
    if( h == 0 ) {
        h = 1;
    }

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset projection matrix stack
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    GLfloat nRange = 100.0f;

    // Establish clipping volume (left, right, bottom, top, near, far)
    if ( w <= h ) {
        glOrtho ( -nRange, nRange, -nRange*h/w, nRange*h/w,
                  -nRange, nRange );
    } else {
        glOrtho ( -nRange*w/h, nRange*w/h, -nRange, nRange,
                  -nRange, nRange );
    }

    // Reset Model view matrix stack
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch ( event->key() ) {
    case Qt::Key_Up:
        xRot -= 5.0f;
        break;
    case Qt::Key_Down:
        xRot += 5.0f;
        break;
    case Qt::Key_Left:
        yRot -= 5.0f;
        break;
    case Qt::Key_Right:
        yRot += 5.0f;
        break;
    }

    if( xRot > 356.0f ) {
        xRot = 0.0f;
    }

    if( xRot < -1.0f ) {
        xRot = 355.0f;
    }

    if( yRot > 356.0f) {
        yRot = 0.0f;
    }

    if( yRot < -1.0f) {
        yRot = 355.0f;
    }

    update();
}
