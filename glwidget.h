#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_2_0>
#include <QVector3D>
#include <QtMath>
#include <QMatrix4x4>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMouseEvent>

class GlWidget : public QOpenGLWidget, protected QOpenGLFunctions_2_0
{
    Q_OBJECT

public:
    GlWidget(QWidget *parent = 0);
    ~GlWidget();

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    int m_xRot;
    int m_yRot;
    int m_zRot;
    QPoint m_lastPos;
};

#endif // GLWIDGET_H
