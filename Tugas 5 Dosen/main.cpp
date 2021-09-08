#include <windows.h>
#include <stdio.h>
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
    gluOrtho2D(0.0, 30.0, 0.0, 30.0);
}

void Display(void){
    float Ax=6, Ay=4, Bx=6.1, By=20, Cx=4, Cy=20, Dx=13, Dy=14,
    Ex=13, Ey=10, Fx=4, Fy=4, Gx=12, Gy=8, Hx=12.1, Hy=16,
    Mab, Mcd, Mef, Mgh,
    Cab, Ccd, Cef, Cgh,
    P1x, P1y, P2x, P2y, P3x, P3y, P4x, P4y;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(Ax, Ay);
    glVertex2f(Bx, By);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(Cx, Cy);
    glVertex2f(Dx, Dy);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(Ex, Ey);
    glVertex2f(Fx, Fy);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(Gx, Gy);
    glVertex2f(Hx, Hy);
    glEnd();

    Mab=(By-Ay)/(Bx-Ax);
    Mcd=(Dy-Cy)/(Dx-Cx);
    Mef=(Fy-Ey)/(Fx-Ex);
    Mgh=(Hy-Gy)/(Hx-Gx);

    Cab=Ay-(Mab*Ax);
    Ccd=Cy-(Mcd*Cx);
    Cef=Ey-(Mef*Ex);
    Cgh=Gy-(Mgh*Gx);

    P1x=(Ccd-Cab)/(Mab-Mcd);
    P1y=(Mab*P1x)+Cab;
    P2x=(Cgh-Ccd)/(Mcd-Mgh);
    P2y=(Mcd*P2x)+Ccd;
    P3x=(Cef-Cgh)/(Mgh-Mef);
    P3y=(Mef*P3x)+Cef;
    P4x=(Cab-Cef)/(Mef-Mab);
    P4y=(Mab*P4x)+Cab;

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(P1x, P1y);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(P2x, P2y);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(P3x, P3y);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(P4x, P4y);
    glEnd();

    glFlush();

    printf("Mcd dan Ccd = %f & %f\n", Mab, Cab);
    printf("Mcd dan Ccd = %f & %f\n", Mcd, Ccd);
    printf("Mcd dan Ccd = %f & %f\n", Mef, Cef);
    printf("Mcd dan Ccd = %f & %f\n\n", Mgh, Cgh);

    printf("Titik Perpotongan AB dan CD = (%f, %f)\n", P1x, P1y);
    printf("Titik Perpotongan CD dan GH = (%f, %f)\n", P2x, P2y);
    printf("Titik Perpotongan GH dan EF = (%f, %f)\n", P3x, P3y);
    printf("Titik Perpotongan EF dan AB = (%f, %f)\n\n", P4x, P4y);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Tugas 5 Perpotongan Garis Bentuk Inisial Nama Dewa (D)");
    glutDisplayFunc(Display);
    Inisialisasi();
    glutMainLoop();
}
