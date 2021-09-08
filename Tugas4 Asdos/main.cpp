#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

float angle = 0.0;
float delta_angle = 5.0;
bool transisi = false;
bool transisi2 = false;

void myInit(void) {
    //glClearColor(0.7, 0.9, 0.4, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void waktu(int) {
    glutPostRedisplay();
    glutTimerFunc(500, waktu, 0);
    angle += delta_angle;
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    if (transisi2 == false) {
        glClearColor(0.5, 0.2, 0.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glScalef(1.0, 1.0, 0.0);
        glBegin(GL_QUADS);
        glVertex2d(-80, -80);
        glVertex2d(80, -80);
        glVertex2d(80, 80);
        glVertex2d(-80, 80);
        glEnd();
        transisi2 = true;
    }
    else {
        glClearColor(0.0, 0.4, 0.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glScalef(1.5, 1.5, 0.0);
        glBegin(GL_QUADS);
        glVertex2d(-80, -80);
        glVertex2d(80, -80);
        glVertex2d(80, 80);
        glVertex2d(-80, 80);
        glEnd();
        transisi2 = false;
    }
    glPopMatrix();
    glPushMatrix();
    if (transisi == false) {
        glColor3f(0.0, 0.9, 0.9);
        glRotatef(-angle, 0.0, 0.0, 1.0);
        glScalef(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2d(150, 220);
        glVertex2d(200, 220);
        glVertex2d(240, 240);
        glVertex2d(200, 280);
        glVertex2d(150, 280);
        glVertex2d(90, 240);
        glEnd();
        transisi = true;
    }
    else {
        glColor3f(0.0, 0.0, 0.7);
        glRotatef(-angle, 0.0, 0.0, 1.0);
        glScalef(0.5, 0.5, 0.0);
        glBegin(GL_POLYGON);
        glVertex2d(150, 220);
        glVertex2d(200, 220);
        glVertex2d(240, 240);
        glVertex2d(200, 280);
        glVertex2d(150, 280);
        glVertex2d(90, 240);
        glEnd();
        transisi = false;
    }
    glPopMatrix();
    glPushMatrix();
    if (transisi == false) {
        glColor3f(0.5, 0.3, 0.7);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glScalef(1.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2d(-350, 250);
        glVertex2d(-250, 250);
        glVertex2d(-300, 300);
        glEnd();
        transisi == true;
    }
    else {
        glColor3f(0.9, 0.7, 0.7);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glScalef(0.5, 0.5, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2d(-350, 250);
        glVertex2d(-250, 250);
        glVertex2d(-300, 300);
        glEnd();
        transisi == false;
    }
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Danang Maulana Ikhsan-672019098");
    glutDisplayFunc(myDisplay);
    myInit();
    glutTimerFunc(500, waktu, 0);
    glutMainLoop();
    return 0;
}
