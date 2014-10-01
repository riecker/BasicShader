#ifndef SHADERWIDGET_H
#define SHADERWIDGET_H

#include <QGLWidget>

#include <QGLShaderProgram>

#include <QString>
#include <QImage>

class ShaderWidget : public QGLWidget
{
    Q_OBJECT
public:
    ShaderWidget(QWidget* parent = 0 );
    ~ShaderWidget();

protected:
    virtual void initializeGL();
    virtual void resizeGL( int w, int h );
    virtual void paintGL();

    virtual void keyPressEvent( QKeyEvent* e );

private:
//    void loadTexture(QString const&);
    void loadGLTextures();
    QGLShaderProgram m_shader;

    float m_theta;
    float m_phi;
//    GLuint texHandle;
    GLuint m_texture;
};

#endif // SHADERWIDGET_H
