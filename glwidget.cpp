#include "glwidget.h"

GlWidget::GlWidget(QWidget *parent) : QOpenGLWidget(parent),
    m_xRot(0),
    m_yRot(0),
    m_zRot(0)
{

}

GlWidget::~GlWidget()
{

}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GlWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
        update();
    }
}

void GlWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
        update();
    }
}

void GlWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
        update();
    }
}

void GlWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1,1,1,1);
}

void GlWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
        glTranslatef(0.0, 0.0, -10.0);
        glRotatef(m_xRot / 16.0, 1.0, 0.0, 0.0);
        glRotatef(m_yRot / 16.0, 0.0, 1.0, 0.0);
        glRotatef(m_zRot / 16.0, 0.0, 0.0, 1.0);

    glColor3f(0.5, 0.5, 0.5);

            glBegin(GL_LINES);

            for (double l = 0.2; l < 40 * 0.2 - 0.2 / 2; l += 0.2)
            {
                glVertex3f(l, 0, -40 * 0.2);
                glVertex3f(l, 0, 40 * 0.2);
                glVertex3f(-40 * 0.2, 0, l);
                glVertex3f(40 * 0.2, 0, l);
            }

            for (double l = -0.2; l > -40 * 0.2 + 0.2 / 2; l -= 0.2)
            {
                glVertex3f(l, 0, -40 * 0.2);
                glVertex3f(l, 0, 40 * 0.2);
                glVertex3f(-40 * 0.2, 0, l);
                glVertex3f(40 * 0.2, 0, l);
            }

            glEnd();

            //Contour lines

            glColor3f(0.1, 0.1, 0.1);

            glBegin(GL_LINE_LOOP);
            glVertex3f(40 * 0.2, 0, 40 * 0.2);
            glVertex3f(40 * 0.2, 0, -40 * 0.2);
            glVertex3f(-40 * 0.2, 0, -40 * 0.2);
            glVertex3f(-40 * 0.2, 0, 40 * 0.2);
            glEnd();

            //Axis lines
            glBegin(GL_LINES);

            glColor3f(1, 0, 0);
            glVertex3f(-1, 0, 0);
            glVertex3f(1, 0, 0);

            glColor3f(0, 1, 0);
            glVertex3f(0, -1, 0);
            glVertex3f(0, 1, 0);

            glColor3f(0, 0, 1);
            glVertex3f(0, 0, -1);
            glVertex3f(0, 0, 1);
            glEnd();
}

void GlWidget::resizeGL(int width, int height)
{

}

void GlWidget::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}

void GlWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(m_xRot + 8 * dy);
        setYRotation(m_yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(m_xRot + 8 * dy);
        setZRotation(m_zRot + 8 * dx);
    }
    m_lastPos = event->pos();
}
