#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void Inisialisasi(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(6.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(2.0);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void Display(void){
    float A1x=50, A1y=50, A2x=50, A2y=160, A3x=200, A3y=200, A4x=50, A4y=90,
    B1x=120, B1y=200, B2x=200, B2y=160,B3x=130, B3y=50, B4x=200, B4y=90,
    MA1B1, MA2B2, MA3B3, MA4B4,
    CA1B1, CA2B2, CA3B3, CA4B4,
    pa, pb, pc, pd, pe, pf, pg, ph;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(A1x, A1y);
    glVertex2f(B1x, B1y);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(A2x, A2y);
    glVertex2f(B2x, B2y);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(A3x, A3y);
    glVertex2f(B3x, B3y);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(A4x, A4y);
    glVertex2f(B4x, B4y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(A1x, A1y);
    glVertex2f(50, 200);
    glVertex2f(A3x, A3y);
    glVertex2f(200, 50);
    glEnd();

    MA1B1=(B1y-A1y)/(B1x-A1x);
    MA2B2=(B2y-A2y)/(B2x-A2x);
    MA3B3=(B3y-A3y)/(B3x-A3x);
    MA4B4=(B4y-A4y)/(B4x-A4x);

    CA1B1=A1y-(MA1B1*A1x);
    CA2B2=A2y-(MA2B2*A2x);
    CA3B3=A3y-(MA3B3*A3x);
    CA4B4=A4y-(MA4B4*A4x);

    pa=(CA2B2-CA1B1)/(MA1B1-MA2B2);
    pb=(MA1B1*pa)+CA1B1;
    pc=(CA3B3-CA2B2)/(MA2B2-MA3B3);
    pd=(MA2B2*pc)+CA2B2;
    pe=(CA4B4-CA3B3)/(MA3B3-MA4B4);
    pf=(MA3B3*pe)+CA3B3;
    pg=(CA1B1-CA4B4)/(MA4B4-MA1B1);
    ph=(MA4B4*pg)+CA4B4;

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(pa, pb);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(pc, pd);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(pe, pf);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(pg, ph);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Dewa Asmara Putra - 672019124");
    glutDisplayFunc(Display);
    Inisialisasi();
    glutMainLoop();
}
