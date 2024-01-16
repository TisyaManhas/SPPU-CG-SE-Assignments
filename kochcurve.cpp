#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

GLfloat x = -0.85, y = -0.5;
GLint iter;
void drKochCurve(GLfloat dir, GLfloat len, GLint iter)
{
    GLdouble dirrad = 0.0174533 * dir;
    GLfloat nx = x + len * cos(dirrad);
    GLfloat ny = y + len * sin(dirrad);
    if (iter == 0)
    {
        glVertex2f(x, y);
        glVertex2f(nx, ny);
        x = nx;
        y = ny;
    }
    else
    {
        iter--;
        drKochCurve(dir, len, iter);
        dir += 60.0;
        drKochCurve(dir, len, iter);
        dir -= 120.0;
        drKochCurve(dir, len, iter);
        dir += 60.0;
        drKochCurve(dir, len, iter);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    cout << "Enter the number of iterations : ";
    cin >> iter;
    drKochCurve(0.1, 0.015, iter);
    glEnd();
    glFlush();
}

int main(int argc, char *argv)
{
    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(" Koch Curve Generation");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}