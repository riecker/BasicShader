#include "mainwindow.h"
#include "shaderwidget.h"

#include <QApplication>
#include <QGLFormat>

#include <GL/glut.h>

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv );
    glutInit( &argc, argv );

    MainWindow w;
    w.show();

    return a.exec();
}
