#include <GL/glew.h>
#include <GL/glut.h>

#include "shaderwidget.h"

#include <QCoreApplication>
#include <QKeyEvent>

ShaderWidget::ShaderWidget(QWidget* parent )
    : QGLWidget( parent ),
      m_shader(),
      m_theta( 0.0f ),
      m_phi( 0.0f )
{
    QGLFormat glFormat = QGLWidget::format();
    qDebug() << QString( "OpenGL Version = %1, %2" )
                .arg( glFormat.majorVersion() )
                .arg( glFormat.minorVersion() );

    if ( !glFormat.sampleBuffers() )
        qWarning() << "Could not enable sample buffers";

    qDebug() << "OpenGL context valid =" << context()->isValid();
}

ShaderWidget::~ShaderWidget()
{
}

void ShaderWidget::initializeGL()
{
    // Set the clear color to black
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

    // Set the drawing color to green
    glColor3f( 0.9f, 0.9f, 0.0f );

    bool result;
    result = m_shader.addShaderFromSourceFile( QGLShader::Vertex,
                                               "/home/riecker/OpenGL/src/ProjectS/simple.vert" );
    if ( !result )
        qDebug() << m_shader.log();
    result = m_shader.addShaderFromSourceFile( QGLShader::Fragment,
                                               "/home/riecker/OpenGL/src/ProjectS/simple.frag" );
    if ( !result )
        qDebug() << m_shader.log();
    result = m_shader.link();
    if ( !result )
        qDebug() << m_shader.log();

    loadGLTextures();

    //    m_shader.setUniformValue("color",1.0,0.0,1.0);

    //    glUniform3f(glGetUniformLocation(program,"color"),0.0,0.0,1.0);
}

void ShaderWidget::resizeGL( int w, int h )
{
    // Prevent a divde by zero
    if ( h == 0 )
        h = 1;

    // Set the viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset the coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish the clipping volume by setting up an perspective projection
    double aspectRatio = double( w ) / double( h );
    double verticalViewingAngle = 45.0;
    gluPerspective( verticalViewingAngle, aspectRatio, 1.0, 425.0 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void ShaderWidget::paintGL()
{
    /*    // Clear the buffer with the current clearing color
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glPushMatrix();
    glTranslatef( 0.0f, 0.0f, -200.0 );
    glRotatef( m_theta, 1.0f, 0.0f, 0.0f );
    glRotatef( m_phi,   0.0f, 1.0f, 0.0f );

//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texHandle);

    m_shader.bind();
    m_shader.setUniformValue("color", 1.0, 1.0, 1.0, 1.0);
//    m_shader.setUniformValue("tga",int(0));

    glutSolidTeapot( 40 );

    glPopMatrix();*/

    /*    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();

      glTranslatef(-1.5f,0.0f,-6.0f);

      glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f, 0.0f);
      glEnd();

      glTranslatef(3.0f,0.0f,0.0f);

      glBegin(GL_QUADS);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f,-1.0f, 0.0f);
        glVertex3f(-1.0f,-1.0f, 0.0f);
      glEnd();*/

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
    glLoadIdentity();                   // Reset The View
    glTranslatef(-1.5f,0.0f,-6.0f);             // Move Left And Into The Screen

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Front)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);          // Left Of Triangle (Front)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Right)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f( 1.0f,-1.0f, 1.0f);          // Left Of Triangle (Right)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f( 1.0f,-1.0f, -1.0f);
    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Back)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f( 1.0f,-1.0f, -1.0f);         // Left Of Triangle (Back)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f(-1.0f,-1.0f, -1.0f);
    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Left)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f(-1.0f,-1.0f,-1.0f);          // Left Of Triangle (Left)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);          // Right Of Triangle (Left)
    glEnd();

    glLoadIdentity();
    glTranslatef(1.5f,0.0f,-7.0f);              // Move Right And Into The Screen

    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);          // Set The Color To Green
    glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);          // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glColor3f(1.0f,0.5f,0.0f);          // Set The Color To Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);          // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);          // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glColor3f(1.0f,0.0f,0.0f);          // Set The Color To Red
    glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,1.0f,0.0f);          // Set The Color To Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);          // Set The Color To Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);          // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);          // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);          // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,0.0f,1.0f);          // Set The Color To Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);          // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);          // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);          // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);          // Bottom Right Of The Quad (Right)
    glEnd();                        // Done Drawing The Quad

}

void ShaderWidget::loadGLTextures()
{
    QImage t;
    QImage b;

    if ( !b.load( "/home/riecker/OpenGL/src/ProjectS/texture.png" ) )
    {
        b = QImage( 16, 16, QImage::Format_RGB32 );
        b.fill( Qt::green );
    }

    t = QGLWidget::convertToGLFormat( b );
    glGenTextures( 1, &m_texture );
    glBindTexture( GL_TEXTURE_2D, m_texture );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits() );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}

//void ShaderWidget::loadTexture(QString const& file)
//{
//    QImage texture;

//    if(texture.load(file))
//    {
//        std::cerr << "Could not load the image" << std::endl;
//        return;
//    }

//    texture = QGLWidget::convertToGLFormat(texture);
//    int w = texture.width();
//    int h = texture.height();

//    std::cout << "Texture width: " << w << " - height: " << h << std::endl;

//    glGenTextures(1, &texHandle);
//    glBindTexture(GL_TEXTURE_2D, texHandle);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, (Gvoid*)texture.bits());
//}

void ShaderWidget::keyPressEvent( QKeyEvent* e )
{
    switch ( e->key() )
    {
    case Qt::Key_Escape:
        QCoreApplication::instance()->quit();
        break;

    case Qt::Key_Left:
        m_phi += 1.0f;
        updateGL();
        break;

    case Qt::Key_Right:
        m_phi -= 1.0f;
        updateGL();
        break;

    case Qt::Key_Up:
        m_theta += 1.0f;
        updateGL();
        break;

    case Qt::Key_Down:
        m_theta -= 1.0f;
        updateGL();
        break;

    default:
        QGLWidget::keyPressEvent( e );
    }
}
