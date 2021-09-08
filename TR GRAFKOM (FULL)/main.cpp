#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#define PI 3.1415927

//Kelompok 8 :
//Dewa Asmara Putra (672019124)
//Danang Maulana Ikhsan (672019098)
//Dikky Wahyudi (672019097)

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0;
float yrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
bool cek = false;
int is_depth;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0);
}
void draw_cylinder(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */

    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void tampil() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0, 0.0, 0.0);
    glRotatef(yrot, 0.0, 1.0, 0.0);

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-30.0, -10.0, 12.0);
    glVertex3f(-30.0, 10.0, 12.0);
    glVertex3f(30.0, 10.0, 12.0);
    glVertex3f(30.0, -10.0, 12.0);
    glEnd();

    //pilar-pilar kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-30.0, 8.0, 14.0);
    glVertex3f(-14.0, 8.0, 14.0);
    glVertex3f(-14.0, 10.0, 14.0);
    glVertex3f(-30.0, 10.0, 14.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 8.0, 12.0);
    glVertex3f(-30.0, 8.0, 14.0);
    glVertex3f(-30.0, 10.0, 14.0);
    glVertex3f(-30.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 10.0, 14.0);
    glVertex3f(-14.0, 10.0, 14.0);
    glVertex3f(-14.0, 10.0, 12.0);
    glVertex3f(-30.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 8.0, 14.0);
    glVertex3f(-14.0, 8.0, 14.0);
    glVertex3f(-14.0, 8.0, 12.0);
    glVertex3f(-30.0, 8.0, 12.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glVertex3f(-30.0, -2.0, 14.0);
    glVertex3f(-17.0, -2.0, 14.0);
    glVertex3f(-17.0, 0.0, 14.0);
    glVertex3f(-30.0, 0.0, 14.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, -2.0, 12.0);
    glVertex3f(-30.0, -2.0, 14.0);
    glVertex3f(-30.0, 0.0, 14.0);
    glVertex3f(-30.0, 0.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, 0.0, 14.0);
    glVertex3f(-17.0, 0.0, 14.0);
    glVertex3f(-17.0, 0.0, 12.0);
    glVertex3f(-30.0, 0.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-30.0, -2.0, 14.0);
    glVertex3f(-17.0, -2.0, 14.0);
    glVertex3f(-17.0, -2.0, 12.0);
    glVertex3f(-30.0, -2.0, 12.0);
    glEnd();

    //mulai
    int z1 = -30, z2 = -29;
    for (int i = 0; i <= 5; i++) {
        glBegin(GL_QUADS);
        glVertex3f(z1, -10.0, 14.0);
        glVertex3f(z2, -10.0, 14.0);
        glVertex3f(z2, 8.0, 14.0);
        glVertex3f(z1, 8.0, 14.0);

        glVertex3f(z1, -10.0, 12.0);
        glVertex3f(z1, -10.0, 14.0);
        glVertex3f(z1, 8.0, 14.0);
        glVertex3f(z1, 8.0, 12.0);

        glVertex3f(z2, -10.0, 12.0);
        glVertex3f(z2, -10.0, 14.0);
        glVertex3f(z2, 8.0, 14.0);
        glVertex3f(z2, 8.0, 12.0);

        glVertex3f(z1, -10.0, 14.0);
        glVertex3f(z2, -10.0, 14.0);
        glVertex3f(z2, -10.0, 12.0);
        glVertex3f(z1, -10.0, 12.0);
        glEnd();

        z1 += 3;
        z2 += 3;
    }

    //pilar tambahan
    glBegin(GL_QUADS);
    glVertex3f(-12.0, -10.0, 15.0);
    glVertex3f(-11.0, -10.0, 16.0);
    glVertex3f(-11.0, 8.0, 16.0);
    glVertex3f(-12.0, 8.0, 15.0);

    glVertex3f(-11.0, -10.0, 16.0);
    glVertex3f(-10.0, -10.0, 15.5);
    glVertex3f(-10.0, 8.0, 15.5);
    glVertex3f(-11.0, 8.0, 16.0);

    glVertex3f(-10.0, -10.0, 15.5);
    glVertex3f(-11.0, -10.0, 14.5);
    glVertex3f(-11.0, 8.0, 14.5);
    glVertex3f(-10.0, 8.0, 15.5);

    glVertex3f(-11.0, -10.0, 14.5);
    glVertex3f(-12.0, -10.0, 15.0);
    glVertex3f(-12.0, 8.0, 15.0);
    glVertex3f(-11.0, 8.0, 14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, -10.0, 17.0);
    glVertex3f(-9.0, -10.0, 18.0);
    glVertex3f(-9.0, 8.0, 18.0);
    glVertex3f(-10.0, 8.0, 17.0);

    glVertex3f(-10.0, -10.0, 18.0);
    glVertex3f(-8.0, -10.0, 17.5);
    glVertex3f(-8.0, 8.0, 17.5);
    glVertex3f(-9.0, 8.0, 18.0);

    glVertex3f(-8.0, -10.0, 17.5);
    glVertex3f(-9.0, -10.0, 16.5);
    glVertex3f(-9.0, 8.0, 16.5);
    glVertex3f(-8.0, 8.0, 17.5);

    glVertex3f(-9.0, -10.0, 16.5);
    glVertex3f(-10.0, -10.0, 17.0);
    glVertex3f(-10.0, 8.0, 17.0);
    glVertex3f(-9.0, 8.0, 16.5);
    glEnd();
    //
    glBegin(GL_QUADS);
    glVertex3f(-14.0, 8.0, 14.0);
    glVertex3f(-8.0, 8.0, 18.0);
    glVertex3f(-8.0, 10.0, 18.0);
    glVertex3f(-14.0, 10.0, 14.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 8.0, 12.0);
    glVertex3f(-8.0, 8.0, 18.0);
    glVertex3f(-8.0, 10.0, 18.0);
    glVertex3f(-8.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-14.0, 10.0, 14.0);
    glVertex3f(-8.0, 10.0, 18.0);
    glVertex3f(-8.0, 10.0, 12.0);
    glVertex3f(-14.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-14.0, 8.0, 14.0);
    glVertex3f(-8.0, 8.0, 18.0);
    glVertex3f(-8.0, 8.0, 12.0);
    glVertex3f(-14.0, 8.0, 12.0);
    glEnd();

    //pilar-pilar kanan
    glBegin(GL_QUADS);
    glVertex3f(9.0, 8.0, 14.0);
    glVertex3f(30.0, 8.0, 14.0);
    glVertex3f(30.0, 10.0, 14.0);
    glVertex3f(9.0, 10.0, 14.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(9.0, 10.0, 14.0);
    glVertex3f(30.0, 10.0, 14.0);
    glVertex3f(30.0, 10.0, 12.0);
    glVertex3f(9.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(9.0, 8.0, 14.0);
    glVertex3f(30.0, 8.0, 14.0);
    glVertex3f(30.0, 8.0, 12.0);
    glVertex3f(9.0, 8.0, 12.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glVertex3f(15.0, -2.0, 14.0);
    glVertex3f(30.0, -2.0, 14.0);
    glVertex3f(30.0, 0.0, 14.0);
    glVertex3f(15.0, 0.0, 14.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(15.0, -2.0, 12.0);
    glVertex3f(15.0, -2.0, 14.0);
    glVertex3f(15.0, 0.0, 14.0);
    glVertex3f(15.0, 0.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(15.0, 0.0, 14.0);
    glVertex3f(30.0, 0.0, 14.0);
    glVertex3f(30.0, 0.0, 12.0);
    glVertex3f(15.0, 0.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(15.0, -2.0, 14.0);
    glVertex3f(30.0, -2.0, 14.0);
    glVertex3f(30.0, -2.0, 12.0);
    glVertex3f(15.0, -2.0, 12.0);
    glEnd();

    int s1 = 9, s2 = 10;
    for (int i = 0; i <= 6; i++) {
        glBegin(GL_QUADS);
        glVertex3f(s1, -10.0, 14.0);
        glVertex3f(s2, -10.0, 14.0);
        glVertex3f(s2, 8.0, 14.0);
        glVertex3f(s1, 8.0, 14.0);

        glVertex3f(s1, -10.0, 12.0);
        glVertex3f(s1, -10.0, 14.0);
        glVertex3f(s1, 8.0, 14.0);
        glVertex3f(s1, 8.0, 12.0);

        glVertex3f(s2, -10.0, 12.0);
        glVertex3f(s2, -10.0, 14.0);
        glVertex3f(s2, 8.0, 14.0);
        glVertex3f(s2, 8.0, 12.0);

        glVertex3f(s1, -10.0, 14.0);
        glVertex3f(s2, -10.0, 14.0);
        glVertex3f(s2, -10.0, 12.0);
        glVertex3f(s1, -10.0, 12.0);
        glEnd();

        s1 += 3;
        s2 += 3;
    }
    //pilar tambahan
    glBegin(GL_QUADS);
    glVertex3f(7.0, -10.0, 15.0);
    glVertex3f(6.0, -10.0, 16.0);
    glVertex3f(6.0, 8.0, 16.0);
    glVertex3f(7.0, 8.0, 15.0);

    glVertex3f(6.0, -10.0, 16.0);
    glVertex3f(5.0, -10.0, 15.5);
    glVertex3f(5.0, 8.0, 15.5);
    glVertex3f(6.0, 8.0, 16.0);

    glVertex3f(5.0, -10.0, 15.5);
    glVertex3f(6.0, -10.0, 14.5);
    glVertex3f(6.0, 8.0, 14.5);
    glVertex3f(5.0, 8.0, 15.5);

    glVertex3f(6.0, -10.0, 14.5);
    glVertex3f(7.0, -10.0, 15.0);
    glVertex3f(7.0, 8.0, 15.0);
    glVertex3f(6.0, 8.0, 14.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, -10.0, 17.0);
    glVertex3f(4.0, -10.0, 18.0);
    glVertex3f(4.0, 8.0, 18.0);
    glVertex3f(5.0, 8.0, 17.0);

    glVertex3f(4.0, -10.0, 18.0);
    glVertex3f(3.0, -10.0, 17.5);
    glVertex3f(3.0, 8.0, 17.5);
    glVertex3f(4.0, 8.0, 18.0);

    glVertex3f(3.0, -10.0, 17.5);
    glVertex3f(4.0, -10.0, 16.5);
    glVertex3f(4.0, 8.0, 16.5);
    glVertex3f(3.0, 8.0, 17.5);

    glVertex3f(4.0, -10.0, 16.5);
    glVertex3f(5.0, -10.0, 17.0);
    glVertex3f(5.0, 8.0, 17.0);
    glVertex3f(4.0, 8.0, 16.5);
    glEnd();

    //
    glBegin(GL_QUADS);
    glVertex3f(9.0, 8.0, 14.0);
    glVertex3f(3.0, 8.0, 18.0);
    glVertex3f(3.0, 10.0, 18.0);
    glVertex3f(9.0, 10.0, 14.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(3.0, 8.0, 12.0);
    glVertex3f(3.0, 8.0, 18.0);
    glVertex3f(3.0, 10.0, 18.0);
    glVertex3f(3.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(3.0, 10.0, 18.0);
    glVertex3f(9.0, 10.0, 14.0);
    glVertex3f(9.0, 10.0, 12.0);
    glVertex3f(3.0, 10.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(3.0, 8.0, 18.0);
    glVertex3f(9.0, 8.0, 14.0);
    glVertex3f(9.0, 8.0, 12.0);
    glVertex3f(3.0, 8.0, 12.0);
    glEnd();

    //lengukungan depan bagian kanan
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(3.0, 10.0, 18.0);
    glVertex3f(3.0, 10.0, 12.0);
    glVertex3f(2.5, 11.5, 12.0);
    glVertex3f(2.5, 11.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(2.5, 11.5, 18.0);
    glVertex3f(2.5, 11.5, 12.0);
    glVertex3f(1.0, 13.0, 12.0);
    glVertex3f(1.0, 13.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(1.0, 13.0, 18.0);
    glVertex3f(1.0, 13.0, 12.0);
    glVertex3f(-1.0, 14.5, 12.0);
    glVertex3f(-1.0, 14.5, 18.0);
    glEnd();

    //lengkungan depan bagian kiri
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-8.0, 10.0, 18.0);
    glVertex3f(-8.0, 10.0, 12.0);
    glVertex3f(-7.5, 11.5, 12.0);
    glVertex3f(-7.5, 11.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-7.5, 11.5, 18.0);
    glVertex3f(-7.5, 11.5, 12.0);
    glVertex3f(-6.0, 13.0, 12.0);
    glVertex3f(-6.0, 13.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-6.0, 13.0, 18.0);
    glVertex3f(-6.0, 13.0, 12.0);
    glVertex3f(-4.0, 14.5, 12.0);
    glVertex3f(-4.0, 14.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-1.0, 14.5, 18.0);
    glVertex3f(-1.0, 14.5, 12.0);
    glVertex3f(-4.0, 14.5, 12.0);
    glVertex3f(-4.0, 14.5, 18.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-30.0, -10.0, -28.0);
    glVertex3f(-30.0, 10.0, -28.0);
    glVertex3f(20.0, 10.0, -28.0);
    glVertex3f(20.0, -10.0, -28.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-30.0, 10.0, 12.0);
    glVertex3f(-30.0, -10.0, 12.0);
    glVertex3f(-30.0, -10.0, -28.0);
    glVertex3f(-30.0, 10.0, -28.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.4);
    glVertex3f(-30.0, 10.0, 12.0);
    glVertex3f(20.0, 10.0, 12.0);
    glVertex3f(20.0, 10.0, -28.0);
    glVertex3f(-30.0, 10.0, -28.0);

    glVertex3f(20.0, 10.0, 12.0);
    glVertex3f(40.0, 10.0, 12.0);
    glVertex3f(40.0, 10.0, 10.0);
    glVertex3f(20.0, 10.0, 10.0);
    glEnd();
    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.85);
    glVertex3f(-30.0, -10.1, 18.0);
    glVertex3f(40.0, -10.1, 18.0);
    glVertex3f(40.0, -10.1, -28.0);
    glVertex3f(-30.0, -10.1, -28.0);
    glEnd();
    //pondasi atas
    //depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-15.0, 74.0, 6.0);
    glVertex3f(-15.0, 10.0, 6.0);
    glVertex3f(10.0, 10.0, 6.0);
    glVertex3f(10.0, 74.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0, 74.0, 3.0);
    glVertex3f(-15.0, 10.0, 3.0);
    glVertex3f(10.0, 10.0, 3.0);
    glVertex3f(10.0, 74.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0, 74.0, 6.0);
    glVertex3f(-15.0, 74.0, 3.0);
    glVertex3f(10.0, 74.0, 3.0);
    glVertex3f(10.0, 74.0, 6.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(4.0, 75.5, 4.0);
    glVertex3f(10.0, 75.5, 4.0);
    glVertex3f(10.0, 79.0, 4.0);
    glVertex3f(4.0, 79.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(4.0, 75.5, 3.0);
    glVertex3f(10.0, 75.5, 3.0);
    glVertex3f(10.0, 79.0, 3.0);
    glVertex3f(4.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(4.0, 79.0, 4.0);
    glVertex3f(10.0, 79.0, 4.0);
    glVertex3f(10.0, 79.0, 3.0);
    glVertex3f(4.0, 79.0, 3.0);
    glEnd();
    //
    glBegin(GL_QUADS);
    glVertex3f(4.0, 75.5, 4.0);
    glVertex3f(0.0, 75.5, 6.0);
    glVertex3f(0.0, 79.0, 6.0);
    glVertex3f(4.0, 79.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 75.5, 3.0);
    glVertex3f(0.0, 75.5, 6.0);
    glVertex3f(0.0, 79.0, 6.0);
    glVertex3f(0.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 75.5, 3.0);
    glVertex3f(4.0, 75.5, 3.0);
    glVertex3f(4.0, 79.0, 3.0);
    glVertex3f(0.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 79.0, 6.0);
    glVertex3f(4.0, 79.0, 4.0);
    glVertex3f(4.0, 79.0, 3.0);
    glVertex3f(0.0, 79.0, 3.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glVertex3f(-15.0, 75.5, 4.0);
    glVertex3f(-9.0, 75.5, 4.0);
    glVertex3f(-9.0, 79.0, 4.0);
    glVertex3f(-15.0, 79.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0, 75.5, 3.0);
    glVertex3f(-9.0, 75.5, 3.0);
    glVertex3f(-9.0, 79.0, 3.0);
    glVertex3f(-15.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0, 79.0, 4.0);
    glVertex3f(-9.0, 79.0, 4.0);
    glVertex3f(-9.0, 79.0, 3.0);
    glVertex3f(-15.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-9.0, 75.5, 4.0);
    glVertex3f(-5.0, 75.5, 6.0);
    glVertex3f(-5.0, 79.0, 6.0);
    glVertex3f(-9.0, 79.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.0, 75.5, 6.0);
    glVertex3f(-5.0, 75.5, 3.0);
    glVertex3f(-5.0, 79.0, 3.0);
    glVertex3f(-5.0, 79.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-9.0, 75.5, 3.0);
    glVertex3f(-5.0, 75.5, 3.0);
    glVertex3f(-5.0, 79.0, 3.0);
    glVertex3f(-9.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-9.0, 79.0, 4.0);
    glVertex3f(-5.0, 79.0, 6.0);
    glVertex3f(-5.0, 79.0, 3.0);
    glVertex3f(-9.0, 79.0, 3.0);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-5.0, 78.5, 5.5);
    glVertex3f(-2.5, 74.0, 5.5);

    glVertex3f(0.0, 78.5, 5.5);
    glVertex3f(-2.5, 74.0, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-5.0, 74.0, 4.5);
    glVertex3f(0.0, 74.0, 4.5);
    glVertex3f(0.0, 79.0, 4.5);
    glVertex3f(-5.0, 79.0, 4.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.0, 74.0, 3.0);
    glVertex3f(0.0, 74.0, 3.0);
    glVertex3f(0.0, 79.0, 3.0);
    glVertex3f(-5.0, 79.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.0, 79.0, 5.5);
    glVertex3f(0.0, 79.0, 5.5);
    glVertex3f(0.0, 79.0, 3.0);
    glVertex3f(-5.0, 79.0, 3.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glVertex3f(-15.0, 74.0, 4.0);
    glVertex3f(-9.0, 74.0, 4.0);
    glVertex3f(-9.0, 75.5, 4.0);
    glVertex3f(-15.0, 75.5, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-15.0, 74.0, 3.0);
    glVertex3f(-9.0, 74.0, 3.0);
    glVertex3f(-9.0, 75.5, 3.0);
    glVertex3f(-15.0, 75.5, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-9.0, 74.0, 4.0);
    glVertex3f(-7.0, 74.0, 5.0);
    glVertex3f(-7.0, 75.5, 5.0);
    glVertex3f(-9.0, 75.5, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-9.0, 74.0, 3.0);
    glVertex3f(-7.0, 74.0, 3.0);
    glVertex3f(-7.0, 75.5, 3.0);
    glVertex3f(-9.0, 75.5, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-7.0, 74.0, 5.0);
    glVertex3f(-5.0, 74.0, 6.0);
    glVertex3f(-5.0, 75.5, 6.0);
    glVertex3f(-7.0, 75.5, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-7.0, 74.0, 3.0);
    glVertex3f(-5.0, 74.0, 3.0);
    glVertex3f(-5.0, 75.5, 3.0);
    glVertex3f(-7.0, 75.5, 3.0);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(4.0, 74.0, 4.0);
    glVertex3f(10.0, 74.0, 4.0);
    glVertex3f(10.0, 75.5, 4.0);
    glVertex3f(4.0, 75.5, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(4.0, 74.0, 3.0);
    glVertex3f(10.0, 74.0, 3.0);
    glVertex3f(10.0, 75.5, 3.0);
    glVertex3f(4.0, 75.5, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(4.0, 74.0, 4.0);
    glVertex3f(2.0, 74.0, 5.0);
    glVertex3f(2.0, 75.5, 5.0);
    glVertex3f(4.0, 75.5, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(4.0, 74.0, 3.0);
    glVertex3f(2.0, 74.0, 3.0);
    glVertex3f(2.0, 75.5, 3.0);
    glVertex3f(4.0, 75.5, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(2.0, 74.0, 5.0);
    glVertex3f(0.0, 74.0, 6.0);
    glVertex3f(0.0, 75.5, 6.0);
    glVertex3f(2.0, 75.5, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 74.0, 3.0);
    glVertex3f(2.0, 74.0, 3.0);
    glVertex3f(2.0, 75.5, 3.0);
    glVertex3f(0.0, 75.5, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 74.0, 6.0);
    glVertex3f(0.0, 74.0, 4.0);
    glVertex3f(0.0, 75.5, 4.0);
    glVertex3f(0.0, 75.5, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.0, 74.0, 6.0);
    glVertex3f(-5.0, 74.0, 4.0);
    glVertex3f(-5.0, 75.5, 4.0);
    glVertex3f(-5.0, 75.5, 6.0);
    glEnd();

    //jendela pondasi atas bagian depan
    float x1 = -12, x2 = -11, y1 = 15, y2 = 17;
    for (int i = 1; i <= 190; i++) {
        if (i % 10 == 0) {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(x1, y1, 6.1);
            glVertex3f(x2, y1, 6.1);
            glVertex3f(x2, y2, 6.1);
            glVertex3f(x1, y2, 6.1);
            glEnd();
            x1 = -12;
            x2 = -11;
            y1 += 3;
            y2 += 3;
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(x1, y1, 6.1);
            glVertex3f(x2, y1, 6.1);
            glVertex3f(x2, y2, 6.1);
            glVertex3f(x1, y2, 6.1);
            glEnd();
            x1 += 2.0;
            x2 += 2.0;
        }
    }
    //sisi depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-4.5, 54.0, 6.2);
    glVertex3f(-0.5, 54.0, 6.2);
    glVertex3f(-0.5, 59.0, 6.2);
    glVertex3f(-4.5, 59.0, 6.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-4.5, 58.0, 6.3);
    glVertex3f(-0.5, 58.0, 6.3);
    glVertex3f(-0.5, 59.0, 6.3);
    glVertex3f(-4.5, 59.0, 6.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-4.5, 54.0, 6.3);
    glVertex3f(-0.5, 54.0, 6.3);
    glVertex3f(-0.5, 55.0, 6.3);
    glVertex3f(-4.5, 55.0, 6.3);
    glEnd();

    glLineWidth(1.0);

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.5, 55.0, 6.3);
    glVertex3f(-2.5, 58.0, 6.3);
    glEnd();

    //sisi belakang
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-4.5, 54.0, -28.2);
    glVertex3f(-0.5, 54.0, -28.2);
    glVertex3f(-0.5, 59.0, -28.2);
    glVertex3f(-4.5, 59.0, -28.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-4.5, 58.0, -28.3);
    glVertex3f(-0.5, 58.0, -28.3);
    glVertex3f(-0.5, 59.0, -28.3);
    glVertex3f(-4.5, 59.0, -28.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-4.5, 54.0, -28.3);
    glVertex3f(-0.5, 54.0, -28.3);
    glVertex3f(-0.5, 55.0, -28.3);
    glVertex3f(-4.5, 55.0, -28.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-2.5, 55.0, -28.3);
    glVertex3f(-2.5, 58.0, -28.3);
    glEnd();

    //sisi kanan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(20.2, 54.0, -9.5);
    glVertex3f(20.2, 54.0, -13.5);
    glVertex3f(20.2, 59.0, -13.5);
    glVertex3f(20.2, 59.0, -9.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(20.3, 58.0, -9.5);
    glVertex3f(20.3, 58.0, -13.5);
    glVertex3f(20.3, 59.0, -13.5);
    glVertex3f(20.3, 59.0, -9.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(20.3, 54.0, -9.5);
    glVertex3f(20.3, 54.0, -13.5);
    glVertex3f(20.3, 55.0, -13.5);
    glVertex3f(20.3, 55.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.3, 55.0, -11.5);
    glVertex3f(20.3, 58.0, -11.5);
    glEnd();

    //sisi kiri
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-24.2, 54.0, -9.5);
    glVertex3f(-24.2, 54.0, -13.5);
    glVertex3f(-24.2, 59.0, -13.5);
    glVertex3f(-24.2, 59.0, -9.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-24.3, 58.0, -9.5);
    glVertex3f(-24.3, 58.0, -13.5);
    glVertex3f(-24.3, 59.0, -13.5);
    glVertex3f(-24.3, 59.0, -9.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-24.3, 54.0, -9.5);
    glVertex3f(-24.3, 54.0, -13.5);
    glVertex3f(-24.3, 55.0, -13.5);
    glVertex3f(-24.3, 55.0, -9.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-24.3, 55.0, -11.5);
    glVertex3f(-24.3, 58.0, -11.5);
    glEnd();

    //jendela pondasi atas bagian belakang
    float a1 = -12, a2 = -11, b1 = 12, b2 = 14;
    for (int i = 1; i <= 200; i++) {
        if (i % 10 == 0) {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(a1, b1, -28.1);
            glVertex3f(a2, b1, -28.1);
            glVertex3f(a2, b2, -28.1);
            glVertex3f(a1, b2, -28.1);
            glEnd();
            a1 = -12;
            a2 = -11;
            b1 += 3;
            b2 += 3;
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(a1, b1, -28.1);
            glVertex3f(a2, b1, -28.1);
            glVertex3f(a2, b2, -28.1);
            glVertex3f(a1, b2, -28.1);
            glEnd();
            a1 += 2.0;
            a2 += 2.0;
        }
    }

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-17.0, 10.0, -28.0);
    glVertex3f(-17.0, 74.0, -28.0);
    glVertex3f(15.0, 74.0, -28.0);
    glVertex3f(15.0, 10.0, -28.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.0, 10.0, -24.0);
    glVertex3f(-17.0, 74.0, -24.0);
    glVertex3f(15.0, 74.0, -24.0);
    glVertex3f(15.0, 10.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-17.0, 74.0, -24.0);
    glVertex3f(-17.0, 74.0, -28.0);
    glVertex3f(15.0, 74.0, -28.0);
    glVertex3f(15.0, 74.0, -24.0);
    glEnd();

    //bagian atas belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-11.0, 74.0, -27.0);
    glVertex3f(-11.0, 79.0, -27.0);
    glVertex3f(-5.0, 79.0, -27.0);
    glVertex3f(-5.0, 74.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 74.0, -26.0);
    glVertex3f(-11.0, 79.0, -26.0);
    glVertex3f(-5.0, 79.0, -26.0);
    glVertex3f(-5.0, 74.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 74.0, -26.0);
    glVertex3f(-11.0, 74.0, -27.0);
    glVertex3f(-11.0, 79.0, -27.0);
    glVertex3f(-11.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.0, 74.0, -26.0);
    glVertex3f(-5.0, 74.0, -27.0);
    glVertex3f(-5.0, 79.0, -27.0);
    glVertex3f(-5.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 79.0, -26.0);
    glVertex3f(-11.0, 79.0, -27.0);
    glVertex3f(-5.0, 79.0, -27.0);
    glVertex3f(-5.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10.0, 74.0, -24.0);
    glVertex3f(-10.0, 74.0, -26.0);
    glVertex3f(-10.0, 79.0, -26.0);
    glVertex3f(-10.0, 79.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 74.0, -25.0);
    glVertex3f(-11.0, 74.0, -26.0);
    glVertex3f(-11.0, 79.0, -26.0);
    glVertex3f(-11.0, 79.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.5, 74.0, -24.0);
    glVertex3f(-10.0, 74.0, -24.0);
    glVertex3f(-10.0, 79.0, -24.0);
    glVertex3f(-16.5, 79.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.5, 74.0, -25.0);
    glVertex3f(-11.0, 74.0, -25.0);
    glVertex3f(-11.0, 79.0, -25.0);
    glVertex3f(-16.5, 79.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 79.0, -24.0);
    glVertex3f(-10.0, 79.0, -24.0);
    glVertex3f(-10.0, 79.0, -26.0);
    glVertex3f(-11.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.5, 79.0, -24.0);
    glVertex3f(-11.0, 79.0, -24.0);
    glVertex3f(-11.0, 79.0, -25.0);
    glVertex3f(-16.5, 79.0, -25.0);
    glEnd();

    //mulai
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 74.0, -24.0);
    glVertex3f(-10.0, 74.0, -26.0);
    glVertex3f(-10.0, 79.0, -26.0);
    glVertex3f(-10.0, 79.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 74.0, -25.0);
    glVertex3f(-11.0, 74.0, -26.0);
    glVertex3f(-11.0, 79.0, -26.0);
    glVertex3f(-11.0, 79.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.5, 74.0, -24.0);
    glVertex3f(-10.0, 74.0, -24.0);
    glVertex3f(-10.0, 79.0, -24.0);
    glVertex3f(-16.5, 79.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.5, 74.0, -25.0);
    glVertex3f(-11.0, 74.0, -25.0);
    glVertex3f(-11.0, 79.0, -25.0);
    glVertex3f(-16.5, 79.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-11.0, 79.0, -24.0);
    glVertex3f(-10.0, 79.0, -24.0);
    glVertex3f(-10.0, 79.0, -26.0);
    glVertex3f(-11.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-16.5, 79.0, -24.0);
    glVertex3f(-11.0, 79.0, -24.0);
    glVertex3f(-11.0, 79.0, -25.0);
    glVertex3f(-16.5, 79.0, -25.0);
    glEnd();

    //bagian kedua
    glBegin(GL_QUADS);
    glVertex3f(0.0, 74.0, -27.0);
    glVertex3f(0.0, 79.0, -27.0);
    glVertex3f(6.0, 79.0, -27.0);
    glVertex3f(6.0, 74.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 74.0, -26.0);
    glVertex3f(0.0, 79.0, -26.0);
    glVertex3f(6.0, 79.0, -26.0);
    glVertex3f(6.0, 74.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(6.0, 74.0, -26.0);
    glVertex3f(6.0, 74.0, -27.0);
    glVertex3f(6.0, 79.0, -27.0);
    glVertex3f(6.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 74.0, -26.0);
    glVertex3f(0.0, 74.0, -27.0);
    glVertex3f(0.0, 79.0, -27.0);
    glVertex3f(0.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 79.0, -26.0);
    glVertex3f(0.0, 79.0, -27.0);
    glVertex3f(6.0, 79.0, -27.0);
    glVertex3f(6.0, 79.0, -26.0);
    glEnd();
    //
    glBegin(GL_QUADS);
    glVertex3f(5.0, 74.0, -24.0);
    glVertex3f(5.0, 74.0, -26.0);
    glVertex3f(5.0, 79.0, -26.0);
    glVertex3f(5.0, 79.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(6.0, 74.0, -25.0);
    glVertex3f(6.0, 74.0, -26.0);
    glVertex3f(6.0, 79.0, -26.0);
    glVertex3f(6.0, 79.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 74.0, -24.0);
    glVertex3f(11.0, 74.0, -24.0);
    glVertex3f(11.0, 79.0, -24.0);
    glVertex3f(5.0, 79.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(6.0, 74.0, -25.0);
    glVertex3f(11.0, 74.0, -25.0);
    glVertex3f(11.0, 79.0, -25.0);
    glVertex3f(6.0, 79.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 79.0, -24.0);
    glVertex3f(6.0, 79.0, -24.0);
    glVertex3f(6.0, 79.0, -26.0);
    glVertex3f(5.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(6.0, 79.0, -24.0);
    glVertex3f(11.0, 79.0, -24.0);
    glVertex3f(11.0, 79.0, -25.0);
    glVertex3f(6.0, 79.0, -25.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(19.0, 10.0, 2.0);
    glVertex3f(19.0, 74.0, 2.0);
    glVertex3f(19.0, 74.0, -25.0);
    glVertex3f(19.0, 10.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(18.0, 10.0, 2.0);
    glVertex3f(18.0, 74.0, 2.0);
    glVertex3f(18.0, 74.0, -25.0);
    glVertex3f(18.0, 10.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.0, 74.0, 2.0);
    glVertex3f(18.0, 74.0, 2.0);
    glVertex3f(18.0, 74.0, -24.0);
    glVertex3f(19.0, 74.0, -24.0);
    glEnd();

    //mulai
    glColor3f(1.0, 0.8, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(19.0, 75.5, 2.0);
    glVertex3f(19.0, 75.5, -25.0);
    glVertex3f(19.0, 79.0, -25.0);
    glVertex3f(19.0, 79.0, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(18.0, 75.5, 2.0);
    glVertex3f(18.0, 75.5, -25.0);
    glVertex3f(18.0, 79.0, -25.0);
    glVertex3f(18.0, 79.0, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.0, 79.0, 2.0);
    glVertex3f(19.0, 79.0, -25.0);
    glVertex3f(18.0, 79.0, -25.0);
    glVertex3f(18.0, 79.0, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(18.5, 74.0, 2.0);
    glVertex3f(18.5, 74.0, -24.0);
    glVertex3f(18.5, 75.5, -24.0);
    glVertex3f(18.5, 75.5, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(18.0, 74.0, 2.0);
    glVertex3f(18.0, 74.0, -24.0);
    glVertex3f(18.0, 75.5, -24.0);
    glVertex3f(18.0, 75.5, 2.0);
    glEnd();

    //jendela pondasi atas bagian kanan
    float n1 = 15, n2 = 17, m1 = -20, m2 = -21;
    for (int i = 1; i <= 190; i++) {
        if (i % 10 == 0) {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(20.1, n1, m1);
            glVertex3f(20.1, n1, m2);
            glVertex3f(20.1, n2, m2);
            glVertex3f(20.1, n2, m1);
            glEnd();
            n1 += 3;
            n2 += 3;
            m1 = -20;
            m2 = -21;
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(20.1, n1, m1);
            glVertex3f(20.1, n1, m2);
            glVertex3f(20.1, n2, m2);
            glVertex3f(20.1, n2, m1);
            glEnd();
            m1 += 2.0;
            m2 += 2.0;
        }
    }

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-24.0, 10.0, 2.0);
    glVertex3f(-24.0, 74.0, 2.0);
    glVertex3f(-24.0, 74.0, -25.0);
    glVertex3f(-24.0, 10.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-23.0, 10.0, 2.0);
    glVertex3f(-23.0, 74.0, 2.0);
    glVertex3f(-23.0, 74.0, -25.0);
    glVertex3f(-23.0, 10.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-23.0, 74.0, 2.0);
    glVertex3f(-24.0, 74.0, 2.0);
    glVertex3f(-24.0, 74.0, -25.0);
    glVertex3f(-23.0, 74.0, -25.0);
    glEnd();

    //
    glColor3f(1.0, 0.8, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-23.0, 75.5, 2.0);
    glVertex3f(-23.0, 75.5, -25.0);
    glVertex3f(-23.0, 79.0, -25.0);
    glVertex3f(-23.0, 79.0, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-24.0, 75.5, 2.0);
    glVertex3f(-24.0, 75.5, -25.0);
    glVertex3f(-24.0, 79.0, -25.0);
    glVertex3f(-24.0, 79.0, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-23.0, 79.0, 2.0);
    glVertex3f(-23.0, 79.0, -25.0);
    glVertex3f(-24.0, 79.0, -25.0);
    glVertex3f(-24.0, 79.0, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-23.5, 74.0, 2.0);
    glVertex3f(-23.5, 74.0, -24.0);
    glVertex3f(-23.5, 75.5, -24.0);
    glVertex3f(-23.5, 75.5, 2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-23.0, 74.0, 2.0);
    glVertex3f(-23.0, 74.0, -24.0);
    glVertex3f(-23.0, 75.5, -24.0);
    glVertex3f(-23.0, 75.5, 2.0);
    glEnd();

    //jendela pondasi atas bagian kiri
    float c1 = 12, c2 = 14, d1 = -20, d2 = -21;
    for (int i = 1; i <= 200; i++) {
        if (i % 10 == 0) {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(-24.1, c1, d1);
            glVertex3f(-24.1, c1, d2);
            glVertex3f(-24.1, c2, d2);
            glVertex3f(-24.1, c2, d1);
            glEnd();
            c1 += 3;
            c2 += 3;
            d1 = -20;
            d2 = -21;
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(-24.1, c1, d1);
            glVertex3f(-24.1, c1, d2);
            glVertex3f(-24.1, c2, d2);
            glVertex3f(-24.1, c2, d1);
            glEnd();
            d1 += 2.0;
            d2 += 2.0;
        }
    }

    //atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-23.0, 78.3, 3.0);
    glVertex3f(18.0, 78.3, 3.0);
    glVertex3f(18.0, 78.3, -24.0);
    glVertex3f(-23.0, 78.3, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 78.3, -24.0);
    glVertex3f(-10.0, 78.3, -24.0);
    glVertex3f(-10.0, 78.3, -26.0);
    glVertex3f(5.0, 78.3, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(0.0, 78.3, -26.0);
    glVertex3f(-5.0, 78.3, -26.0);
    glVertex3f(-5.0, 78.3, -27.0);
    glVertex3f(0.0, 78.3, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 79.0, -26.0);
    glVertex3f(-5.0, 79.0, -26.0);
    glVertex3f(-5.0, 79.0, -27.0);
    glVertex3f(0.0, 79.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5.0, 78.3, -26.0);
    glVertex3f(0.0, 78.3, -26.0);
    glVertex3f(0.0, 79.0, -26.0);
    glVertex3f(-5.0, 79.0, -26.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 78.3, -27.0);
    glVertex3f(-5.0, 78.3, -27.0);
    glVertex3f(-5.0, 79.0, -27.0);
    glVertex3f(0.0, 79.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.0, 74.0, -26.5);
    glVertex3f(-5.0, 74.0, -26.5);
    glVertex3f(-5.0, 79.0, -26.0);
    glVertex3f(0.0, 79.0, -26.5);
    glEnd();

    //bangunan kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(20.0, 9.0, 9.5);
    glVertex3f(20.0, 14.5, 9.5);
    glVertex3f(39.0, 14.5, 9.5);
    glVertex3f(39.0, 9.0, 9.5);
    glEnd();
    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(20.0, -10.0, -28.0);
    glVertex3f(20.0, 14.5, -28.0);
    glVertex3f(40.0, 14.5, -28.0);
    glVertex3f(40.0, -10.0, -28.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(40.0, 14.5, 12.0);
    glVertex3f(40.0, -10.0, 12.0);
    glVertex3f(40.0, -10.0, -28.0);
    glVertex3f(40.0, 14.5, -28.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(20.0, 14.5, 10.0);
    glVertex3f(20.0, -10.0, 10.0);
    glVertex3f(20.0, -10.0, 5.0);
    glVertex3f(20.0, 14.5, 5.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.4);
    glVertex3f(20.0, 14.5, 10.0);
    glVertex3f(40.0, 14.5, 10.0);
    glVertex3f(40.0, 14.5, -28.0);
    glVertex3f(20.0, 14.5, -28.0);
    glEnd();

    //lantai dalam gedung utama
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-23.0, 60.0, 3.0);
    glVertex3f(18.0, 60.0, 3.0);
    glVertex3f(18.0, 60.0, -24.0);
    glVertex3f(-23.0, 60.0, -24.0);
    glEnd();

    //objek dalam gedung utama

    //meja
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.4, 0.0);
    glVertex3f(-3.0, 62.0, 0.0);
    glVertex3f(0.0, 62.0, 0.0);
    glVertex3f(0.0, 62.0, -3.0);
    glVertex3f(-3.0, 62.0, -3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 61.5, 0.0);
    glVertex3f(0.0, 61.5, 0.0);
    glVertex3f(0.0, 61.5, -3.0);
    glVertex3f(-3.0, 61.5, -3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 61.5, 0.0);
    glVertex3f(0.0, 61.5, 0.0);
    glVertex3f(0.0, 62.0, 0.0);
    glVertex3f(-3.0, 62.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 61.5, -3.0);
    glVertex3f(0.0, 61.5, -3.0);
    glVertex3f(0.0, 62.0, -3.0);
    glVertex3f(-3.0, 62.0, -3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, 61.5, -3.0);
    glVertex3f(-3.0, 61.5, 0.0);
    glVertex3f(-3.0, 62.0, 0.0);
    glVertex3f(-3.0, 62.0, -3.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 61.5, -3.0);
    glVertex3f(0.0, 61.5, 0.0);
    glVertex3f(0.0, 62.0, 0.0);
    glVertex3f(0.0, 62.0, -3.0);
    glEnd();

    glLineWidth(3.0);

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.5, 61.5, -0.5);
    glVertex3f(-2.5, 60.0, -0.5);

    glVertex3f(-0.5, 61.5, -0.5);
    glVertex3f(-0.5, 60.0, -0.5);

    glVertex3f(-0.5, 61.5, -2.5);
    glVertex3f(-0.5, 60.0, -2.5);

    glVertex3f(-2.5, 61.5, -2.5);
    glVertex3f(-2.5, 60.0, -2.5);
    glEnd();

    //kursi
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.4, 0.0);
    glVertex3f(-2.0, 61.3, -4.0);
    glVertex3f(0.0, 61.3, -4.0);
    glVertex3f(0.0, 61.3, -6.0);
    glVertex3f(-2.0, 61.3, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.0, 60.8, -4.0);
    glVertex3f(0.0, 60.8, -4.0);
    glVertex3f(0.0, 60.8, -6.0);
    glVertex3f(-2.0, 60.8, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.0, 60.8, -6.0);
    glVertex3f(-2.0, 60.8, -4.0);
    glVertex3f(-2.0, 61.3, -4.0);
    glVertex3f(-2.0, 61.3, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0, 60.8, -6.0);
    glVertex3f(0.0, 60.8, -4.0);
    glVertex3f(0.0, 61.3, -4.0);
    glVertex3f(0.0, 61.3, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.0, 60.8, -4.0);
    glVertex3f(0.0, 60.8, -4.0);
    glVertex3f(0.0, 61.3, -4.0);
    glVertex3f(-2.0, 61.3, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.0, 60.8, -6.0);
    glVertex3f(0.0, 60.8, -6.0);
    glVertex3f(0.0, 61.3, -6.0);
    glVertex3f(-2.0, 61.3, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.0, 62.0, -5.8);
    glVertex3f(0.0, 62.0, -5.8);
    glVertex3f(0.0, 63.0, -5.8);
    glVertex3f(-2.0, 63.0, -5.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.8, 60.8, -4.2);
    glVertex3f(-1.8, 60.0, -4.2);

    glVertex3f(-0.2, 60.8, -4.2);
    glVertex3f(-0.2, 60.0, -4.2);

    glVertex3f(-0.2, 60.8, -5.8);
    glVertex3f(-0.2, 60.0, -5.8);

    glVertex3f(-1.8, 60.8, -5.8);
    glVertex3f(-1.8, 60.0, -5.8);

    glVertex3f(-0.4, 62.0, -5.8);
    glVertex3f(-0.4, 60.8, -5.8);

    glVertex3f(-1.6, 62.0, -5.8);
    glVertex3f(-1.6, 60.8, -5.8);
    glEnd();

    //lemari
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.4, 0.0);
    glVertex3f(-12.0, 60.0, -4.0);
    glVertex3f(-8.0, 60.0, -4.0);
    glVertex3f(-8.0, 60.0, -6.0);
    glVertex3f(-12.0, 60.0, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-12.0, 65.0, -4.0);
    glVertex3f(-8.0, 65.0, -4.0);
    glVertex3f(-8.0, 65.0, -6.0);
    glVertex3f(-12.0, 65.0, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-12.0, 60.0, -4.0);
    glVertex3f(-8.0, 60.0, -4.0);
    glVertex3f(-8.0, 65.0, -4.0);
    glVertex3f(-12.0, 65.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-12.0, 60.0, -6.0);
    glVertex3f(-8.0, 60.0, -6.0);
    glVertex3f(-8.0, 65.0, -6.0);
    glVertex3f(-12.0, 65.0, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-12.0, 60.0, -6.0);
    glVertex3f(-12.0, 60.0, -4.0);
    glVertex3f(-12.0, 65.0, -4.0);
    glVertex3f(-12.0, 65.0, -6.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 60.0, -6.0);
    glVertex3f(-8.0, 60.0, -4.0);
    glVertex3f(-8.0, 65.0, -4.0);
    glVertex3f(-8.0, 65.0, -6.0);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 65.0, -4.0);
    glVertex3f(-10.0, 60.0, -4.0);
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 62.5, -4.0);
    glVertex3f(-9.5, 62.5, -4.0);
    glEnd();

    //papan tulis
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(5.0, 62.0, -4.0);
    glVertex3f(9.0, 62.0, -4.0);
    glVertex3f(9.0, 65.0, -4.0);
    glVertex3f(5.0, 65.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 62.0, -4.5);
    glVertex3f(9.0, 62.0, -4.5);
    glVertex3f(9.0, 65.0, -4.5);
    glVertex3f(5.0, 65.0, -4.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 62.0, -4.5);
    glVertex3f(5.0, 62.0, -4.0);
    glVertex3f(5.0, 65.0, -4.0);
    glVertex3f(5.0, 65.0, -4.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(9.0, 62.0, -4.5);
    glVertex3f(9.0, 62.0, -4.0);
    glVertex3f(9.0, 65.0, -4.0);
    glVertex3f(9.0, 65.0, -4.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 65.0, -4.0);
    glVertex3f(9.0, 65.0, -4.0);
    glVertex3f(9.0, 65.0, -4.5);
    glVertex3f(5.0, 65.0, -4.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5.0, 62.0, -4.0);
    glVertex3f(9.0, 62.0, -4.0);
    glVertex3f(9.0, 62.0, -4.5);
    glVertex3f(5.0, 62.0, -4.5);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(8.0, 62.0, -4.25);
    glVertex3f(8.0, 60.0, -4.25);

    glVertex3f(6.0, 62.0, -4.25);
    glVertex3f(6.0, 60.0, -4.25);
    glEnd();



//------------------------------------------------------------------------------------------------------------------------------------

    //tangga1
    for (int tanggayz = 0; tanggayz <= 2; tanggayz++) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.7, 0.5);
        glVertex3f(-42.0, -9.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-20.0, -9.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-20.0, -9.0 + tanggayz, -79.0 + tanggayz);
        glVertex3f(-42.0, -9.0 + tanggayz, -79.0 + tanggayz);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-42.0, -9.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-20.0, -9.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-20.0, -10.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-42.0, -10.0 + tanggayz, -80.0 + tanggayz);
        glEnd();

        //tangga miring merah
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-42.0, -9.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-45.0, -9.0 + tanggayz, -77.0 + tanggayz);
        glVertex3f(-45.0, -9.0 + tanggayz, -76.0 + tanggayz);
        glVertex3f(-42.0, -9.0 + tanggayz, -79.0 + tanggayz);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.0, 0.0);
        glVertex3f(-42.0, -9.0 + tanggayz, -80.0 + tanggayz);
        glVertex3f(-45.0, -9.0 + tanggayz, -77.0 + tanggayz);
        glVertex3f(-45.0, -10.0 + tanggayz, -77.0 + tanggayz);
        glVertex3f(-42.0, -10.0 + tanggayz, -80.0 + tanggayz);
        glEnd();

        //tutup pojok tangga
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-45.0, -9.0 + tanggayz, -74.0);
        glVertex3f(-45.0, -9.0 + tanggayz, -77.0 + tanggayz);
        glVertex3f(-45.0, -10.0 + tanggayz, -77.0 + tanggayz);
        glVertex3f(-45.0, -10.0 + tanggayz, -74.0);
        glEnd();
    }

    //alas datar tangga utama
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.5);
    glVertex3f(-42.0, -7.0, -78.0);
    glVertex3f(-20.0, -7.0, -78.0);
    glVertex3f(-20.0, -7.0, -74.0);
    glVertex3f(-42.0, -7.0, -74.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-42.0, -7.0, -78.0);
    glVertex3f(-45.0, -7.0, -74.0);
    glVertex3f(-42.0, -7.0, -74.0);
    glEnd();

    //tembok kanan
    for (int tembok1 = 0; tembok1 <= 3; tembok1 += 3) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-45.0 + tembok1, -10.0, -74.0);
        glVertex3f(-45.0 + tembok1, -10.0, -58.0);
        glVertex3f(-45.0 + tembok1, 9.0, -58.0);
        glVertex3f(-45.0 + tembok1, 9.0, -74.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-45.0 + tembok1, -10.0, -58.0);
        glVertex3f(-45.0 + tembok1, -10.0, -40.0);
        glVertex3f(-45.0 + tembok1, 5.0, -40.0);
        glVertex3f(-45.0 + tembok1, 5.0, -58.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-42.0, 5.0, -58.0);
    glVertex3f(-42.0, 9.0, -58.0);
    glVertex3f(-42.0, 9.0, -55.0);
    glVertex3f(-42.0, 5.0, -55.0);
    glEnd();

    //penutup tambok kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-45.0, -10.0, -74.0);
    glVertex3f(-45.0, 9.0, -74.0);
    glVertex3f(-42.0, 9.0, -74.0);
    glVertex3f(-42.0, -10.0, -74.0);
    glEnd();

    //tembok kiri
    for (int tembok1 = 0; tembok1 <= 3; tembok1 += 3) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-20.0 + tembok1, -6.0, -74.0);
        glVertex3f(-20.0 + tembok1, -6.0, -40.0);
        glVertex3f(-20.0 + tembok1, 9.0, -40.0);
        glVertex3f(-20.0 + tembok1, 9.0, -74.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-20.0, -6.0, -74.0);
    glVertex3f(-20.0, 9.0, -74.0);
    glVertex3f(-17.0, 9.0, -74.0);
    glVertex3f(-17.0, -6.0, -74.0);
    glEnd();

    //tembok luar ruangan kecil sebelah tangga
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-24.0, -10.0, -74.0);
    glVertex3f(-24.0, -10.0, -60.0);
    glVertex3f(-24.0, 2.0, -60.0);
    glVertex3f(-24.0, 2.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-24.0, -10.0, -74.0);
    glVertex3f(-24.0, 2.0, -74.0);
    glVertex3f(-23.5, 2.0, -74.0);
    glVertex3f(-23.5, -10.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-20.0, -10.0, -74.0);
    glVertex3f(-20.0, 2.0, -74.0);
    glVertex3f(-20.5, 2.0, -74.0);
    glVertex3f(-20.5, -10.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-23.5, 2.0, -74.0);
    glVertex3f(-23.5, -1.0, -74.0);
    glVertex3f(-20.5, -1.0, -74.0);
    glVertex3f(-20.5, 2.0, -74.0);
    glEnd();

    //ruangan kecil
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-23.5, -1.0, -74.0);
    glVertex3f(-23.5, -1.0, -64.0);
    glVertex3f(-20.5, -1.0, -64.0);
    glVertex3f(-20.5, -1.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-20.5, -10.0, -64.0);
    glVertex3f(-20.5, 0.0, -64.0);
    glVertex3f(-20.5, 0.0, -74.0);
    glVertex3f(-20.5, -10.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 0.0);
    glVertex3f(-23.5, -10.0, -64.0);
    glVertex3f(-23.5, 0.0, -64.0);
    glVertex3f(-23.5, 0.0, -74.0);
    glVertex3f(-23.5, -10.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.5);
    glVertex3f(-24.0, 2.0, -60.0);
    glVertex3f(-24.0, 1.0, -60.0);
    glVertex3f(-20.0, 1.0, -60.0);
    glVertex3f(-20.0, 2.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-24.0, 2.0, -67.0);
    glVertex3f(-24.0, -10.0, -67.0);
    glVertex3f(-20.0, -10.0, -67.0);
    glVertex3f(-20.0, 2.0, -67.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-24.0, -7.0, -74.0);
    glVertex3f(-24.0, -9.0, -67.0);
    glVertex3f(-20.0, -9.0, -67.0);
    glVertex3f(-20.0, -7.0, -74.0);
    glEnd();

    //alas dalam pagar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.5);
    glVertex3f(-24.0, 2.0, -74.0);
    glVertex3f(-24.0, 2.0, -60.0);
    glVertex3f(-20.0, 2.0, -60.0);
    glVertex3f(-20.0, 2.0, -74.0);
    glEnd();

    //pagar atas ruangan kecil
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-20.5, 2.0, -74.0);
    glVertex3f(-20.5, 9.0, -74.0);
    glVertex3f(-21.0, 9.0, -74.0);
    glVertex3f(-21.0, 2.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-22.0, 2.0, -74.0);
    glVertex3f(-22.0, 9.0, -74.0);
    glVertex3f(-22.5, 9.0, -74.0);
    glVertex3f(-22.5, 2.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-23.7, 2.0, -74.0);
    glVertex3f(-23.7, 9.0, -74.0);
    glVertex3f(-24.0, 9.0, -74.0);
    glVertex3f(-24.0, 2.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-20.0, 7.5, -74.0);
    glVertex3f(-20.0, 8.0, -74.0);
    glVertex3f(-24.0, 8.0, -74.0);
    glVertex3f(-24.0, 7.5, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-24.0, 7.5, -74.0);
    glVertex3f(-24.0, 8.0, -74.0);
    glVertex3f(-24.0, 8.0, -60.0);
    glVertex3f(-24.0, 7.5, -60.0);
    glEnd();

    //pagar kecil-kecil dekat tangga atas
    for (float pagarkecil = 0; pagarkecil <= 2.0; pagarkecil += 0.2) {
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-20.0, 6.4 - pagarkecil, -74.0);
        glVertex3f(-24.0, 6.4 - pagarkecil, -74.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-24.0, 6.4 - pagarkecil, -74.0);
        glVertex3f(-24.0, 6.4 - pagarkecil, -60.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-20.0, 3.5, -74.0);
    glVertex3f(-20.0, 3.0, -74.0);
    glVertex3f(-24.0, 3.0, -74.0);
    glVertex3f(-24.0, 3.5, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-24.0, 3.5, -74.0);
    glVertex3f(-24.0, 3.0, -74.0);
    glVertex3f(-24.0, 3.0, -60.0);
    glVertex3f(-24.0, 3.5, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-24.0, 2.0, -74.0);
    glVertex3f(-24.0, 9.0, -74.0);
    glVertex3f(-24.0, 9.0, -73.7);
    glVertex3f(-24.0, 2.0, -73.7);
    glEnd();

    for (int pagar = 0; pagar <= 10; pagar += 2) {
        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-24.0, 2.0, -72.0 + pagar);
        glVertex3f(-24.0, 9.0, -72.0 + pagar);
        glVertex3f(-24.0, 9.0, -71.5 + pagar);
        glVertex3f(-24.0, 2.0, -71.5 + pagar);
        glEnd();
    }

    //tembok penutup ruang pagar-pagar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.5);
    glVertex3f(-20.0, 2.0, -60.0);
    glVertex3f(-20.0, 9.0, -60.0);
    glVertex3f(-24.0, 9.0, -60.0);
    glVertex3f(-24.0, 2.0, -60.0);
    glEnd();

    //tembok tengah tangga
    for (int tembok2 = 0; tembok2 <= 3; tembok2 += 3) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-35.0 + tembok2, -10.0, -74.0);
        glVertex3f(-35.0 + tembok2, -10.0, -71.0);
        glVertex3f(-35.0 + tembok2, 9.0, -71.0);
        glVertex3f(-35.0 + tembok2, 9.0, -74.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-35.0, -10.0, -74.0 + tembok2);
        glVertex3f(-32.0, -10.0, -74.0 + tembok2);
        glVertex3f(-32.0, 9.0, -74.0 + tembok2);
        glVertex3f(-35.0, 9.0, -74.0 + tembok2);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-35.0 + tembok2, 1.0, -65.0);
        glVertex3f(-35.0 + tembok2, 1.0, -62.0);
        glVertex3f(-35.0 + tembok2, 9.0, -62.0);
        glVertex3f(-35.0 + tembok2, 9.0, -65.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-35.0, 1.0, -65.0 + tembok2);
        glVertex3f(-32.0, 1.0, -65.0 + tembok2);
        glVertex3f(-32.0, 9.0, -65.0 + tembok2);
        glVertex3f(-35.0, 9.0, -65.0 + tembok2);
        glEnd();
    }

    //pegangan di tangga
    glLineWidth(15.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-35.1, -1.0, -74.0);
    glVertex3f(-35.1, 5.0, -63.0);

    glVertex3f(-35.1, -3.0, -69.0);
    glVertex3f(-35.1, 1.7, -69.0);

    glVertex3f(-35.1, -1.0, -66.5);
    glVertex3f(-35.1, 3.1, -66.5);
    glEnd();

    //tangga 2 sebelah tembok
    for (int tangga2 = 0; tangga2 <= 3; tangga2 += 1) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-35.0, -8.0 + tangga2, -74.0 + tangga2);
        glVertex3f(-42.0, -8.0 + tangga2, -74.0 + tangga2);
        glVertex3f(-42.0, -9.0 + tangga2, -74.0 + tangga2);
        glVertex3f(-35.0, -9.0 + tangga2, -74.0 + tangga2);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-32.0, -8.0 + tangga2, -74.0 + tangga2);
        glVertex3f(-24.0, -8.0 + tangga2, -74.0 + tangga2);
        glVertex3f(-24.0, -9.0 + tangga2, -74.0 + tangga2);
        glVertex3f(-32.0, -9.0 + tangga2, -74.0 + tangga2);
        glEnd();

        if (tangga2 <= 2) {
            glBegin(GL_QUADS);
            glColor3f(1.0, 0.7, 0.5);
            glVertex3f(-35.0, -8.0 + tangga2, -74.0 + tangga2);
            glVertex3f(-42.0, -8.0 + tangga2, -74.0 + tangga2);
            glVertex3f(-42.0, -8.0 + tangga2, -73.0 + tangga2);
            glVertex3f(-35.0, -8.0 + tangga2, -73.0 + tangga2);
            glEnd();

            glBegin(GL_QUADS);
            glColor3f(1.0, 0.7, 0.5);
            glVertex3f(-32.0, -8.0 + tangga2, -74.0 + tangga2);
            glVertex3f(-24.0, -8.0 + tangga2, -74.0 + tangga2);
            glVertex3f(-24.0, -8.0 + tangga2, -73.0 + tangga2);
            glVertex3f(-32.0, -8.0 + tangga2, -73.0 + tangga2);
            glEnd();
        }
    }

    //tangga atas yang ada pegangannya
    for (int tangga3 = 0; tangga3 <= 5; tangga3 += 1) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-42.0, -5.0 + tangga3, -70.0 + tangga3);
        glVertex3f(-24.0, -5.0 + tangga3, -70.0 + tangga3);
        glVertex3f(-24.0, -4.0 + tangga3, -70.0 + tangga3);
        glVertex3f(-42.0, -4.0 + tangga3, -70.0 + tangga3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.7, 0.5);
        glVertex3f(-42.0, -5.0 + tangga3, -71.0 + tangga3);
        glVertex3f(-24.0, -5.0 + tangga3, -71.0 + tangga3);
        glVertex3f(-24.0, -5.0 + tangga3, -70.0 + tangga3);
        glVertex3f(-42.0, -5.0 + tangga3, -70.0 + tangga3);
        glEnd();
    }

    //lantai depan pintu masuk
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.7, 0.5);
    glVertex3f(-42.0, 1.0, -65.0);
    glVertex3f(-20.0, 1.0, -65.0);
    glVertex3f(-20.0, 1.0, -55.0);
    glVertex3f(-42.0, 1.0, -55.0);
    glEnd();

    //tembok pintu
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-20.0, 1.0, -55.0);
    glVertex3f(-20.0, 9.0, -55.0);
    glVertex3f(-24.0, 9.0, -55.0);
    glVertex3f(-24.0, 1.0, -55.0);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-42.0, 1.0, -55.0);
    glVertex3f(-42.0, 9.0, -55.0);
    glVertex3f(-24.0, 9.0, -55.0);
    glVertex3f(-24.0, 1.0, -55.0);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-33.0, 1.0, -55.0);
    glVertex3f(-33.0, 9.0, -55.0);
    glEnd();

    //atap ruangan atas tangga dan pintu
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, 9.0, -40.0);
    glVertex3f(-45.0, 9.0, -74.0);
    glVertex3f(-20.0, 9.0, -74.0);
    glVertex3f(-20.0, 9.0, -40.0);
    glEnd();

    //lahan kosong
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-20.0, -5.0, -73.0);
    glVertex3f(-20.0, -5.0, -83.0);
    glVertex3f(-20.0, -10.0, -83.0);
    glVertex3f(-20.0, -10.0, -73.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-12.0, -5.0, -73.0);
    glVertex3f(-12.0, -5.0, -83.0);
    glVertex3f(-20.0, -5.0, -83.0);
    glVertex3f(-20.0, -5.0, -73.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-12.0, -5.0, -83.0);
    glVertex3f(-12.0, -10.0, -83.0);
    glVertex3f(-20.0, -10.0, -83.0);
    glVertex3f(-20.0, -5.0, -83.0);
    glEnd();

    int tegak = 0;
    //pagar lahan kosong
    for (float pgr = 0; pgr <= 6; pgr += 1.5) {
        if (pgr < 4) {
            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-20.0, -4.5 + pgr, -73.0);
            glVertex3f(-20.0, -4.5 + pgr, -83.0);
            glVertex3f(-20.0, -4.0 + pgr, -83.0);
            glVertex3f(-20.0, -4.0 + pgr, -73.0);
            glEnd();
        }

        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-20.0, -5.0, -83.0 + tegak);
        glVertex3f(-20.0, -5.0, -82.5 + tegak);
        glVertex3f(-20.0, -1.0, -82.5 + tegak);
        glVertex3f(-20.0, -1.0, -83.0 + tegak);
        glEnd();

        tegak += 2;
    }

    float tegak2 = 0;
    for (float pgr2 = 0; pgr2 <= 8.5; pgr2 += 0.1) {
        if (pgr2 <= 2.6) {
            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-20.0, -3.9 + pgr2, -73.0);
            glVertex3f(-20.0, -3.9 + pgr2, -83.0);
            glEnd();
        }

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-20.0, -1.0, -82.4 + tegak2);
        glVertex3f(-20.0, -4.0, -82.4 + tegak2);
        glEnd();

        tegak2 += 0.1;
    }

    float miring = 0;
    for (float pgr = 0; pgr <= 7.6; pgr += 0.4) {
        if (pgr < 4) {
            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-20.0, -4.6 + pgr, -83.0);
            glVertex3f(-12.0, -4.6 + pgr, -83.0);
            glVertex3f(-12.0, -4.7 + pgr, -83.0);
            glVertex3f(-20.0, -4.7 + pgr, -83.0);
            glEnd();
        }

        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-12.4 - miring, -4.7, -83.0);
        glVertex3f(-12.4 - miring, -1.0, -83.0);
        glVertex3f(-12.5 - miring, -1.0, -83.0);
        glVertex3f(-12.5 - miring, -4.7, -83.0);
        glEnd();

        miring += 0.4;
    }

    //tembok jendela atas tangga
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-20.0, 9.0, -40.0);
    glVertex3f(-20.0, 9.0, -74.0);
    glVertex3f(-20.0, 17.0, -74.0);
    glVertex3f(-20.0, 17.0, -40.0);
    glEnd();

    //tembok kotak abu-abu atas tangga
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-20.0, 17.0, -58.0);
    glVertex3f(-20.0, 17.0, -74.0);
    glVertex3f(-45.0, 17.0, -74.0);
    glVertex3f(-45.0, 17.0, -58.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-45.0, 9.0, -58.0);
    glVertex3f(-45.0, 9.0, -74.0);
    glVertex3f(-45.0, 17.0, -74.0);
    glVertex3f(-45.0, 17.0, -58.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-43.0, 17.0, -58.0);
    glVertex3f(-43.0, 35.0, -58.0);
    glVertex3f(-45.0, 35.0, -58.0);
    glVertex3f(-45.0, 17.0, -58.0);
    glEnd();

    //tembok jendela bagian kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-45.0, 5.0, -58.0);
    glVertex3f(-45.0, 35.0, -58.0);
    glVertex3f(-45.0, 35.0, -52.0);
    glVertex3f(-45.0, 5.0, -52.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-45.0, 5.0, -40.0);
    glVertex3f(-45.0, 35.0, -40.0);
    glVertex3f(-45.0, 35.0, -49.0);
    glVertex3f(-45.0, 5.0, -49.0);
    glEnd();

    //jendela bagian kanan
    for (int jk = 0; jk < 30; jk += 8) {
        glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-45.0, 5.0 + jk, -49.0);
        glVertex3f(-45.0, 9.0 + jk, -49.0);
        glVertex3f(-45.0, 9.0 + jk, -52.0);
        glVertex3f(-45.0, 5.0 + jk, -52.0);
        glEnd();

        if (jk < 24) {
            glBegin(GL_QUADS);
            glColor3f(1.0, 0.8, 0.5);
            glVertex3f(-45.0, 13.0 + jk, -49.0);
            glVertex3f(-45.0, 9.0 + jk, -49.0);
            glVertex3f(-45.0, 9.0 + jk, -52.0);
            glVertex3f(-45.0, 13.0 + jk, -52.0);
            glEnd();
        }
    }

    //Jendela banyak atas atap kosong abu-abu
    for (int jendelax = 0; jendelax < 20; jendelax += 6) {
        for (int jendelay = 0; jendelay < 15; jendelay += 6) {
            glBegin(GL_QUADS);
            glColor3f(0.0, 1.0, 1.0);
            glVertex3f(-43.0 + jendelax, 19.0 + jendelay, -58.0);
            glVertex3f(-43.0 + jendelax, 22.0 + jendelay, -58.0);
            glVertex3f(-40.0 + jendelax, 22.0 + jendelay, -58.0);
            glVertex3f(-40.0 + jendelax, 19.0 + jendelay, -58.0);
            glEnd();

            //tembok sekat-sekat
            glBegin(GL_QUADS);
            glColor3f(1.0, 0.9, 0.5);
            glVertex3f(-40.0 + jendelax, 17.0, -58.0);
            glVertex3f(-40.0 + jendelax, 35.0, -58.0);
            glVertex3f(-37.0 + jendelax, 35.0, -58.0);
            glVertex3f(-37.0 + jendelax, 17.0, -58.0);
            glEnd();

            glBegin(GL_QUADS);
            glColor3f(1.0, 0.9, 0.5);
            glVertex3f(-43.0, 17.0 + jendelay, -58.0);
            glVertex3f(-43.0, 19.0 + jendelay, -58.0);
            glVertex3f(-21.0, 19.0 + jendelay, -58.0);
            glVertex3f(-21.0, 17.0 + jendelay, -58.0);
            glEnd();

            glBegin(GL_QUADS);
            glColor3f(1.0, 0.9, 0.5);
            glVertex3f(-43.0, 22.0 + jendelay, -58.0);
            glVertex3f(-43.0, 23.0 + jendelay, -58.0);
            glVertex3f(-21.0, 23.0 + jendelay, -58.0);
            glVertex3f(-21.0, 22.0 + jendelay, -58.0);
            glEnd();
        }
    }

    //tembok siku bagian atap kosong abu-abu
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-20.0, 35.0, -58.0);
    glVertex3f(-20.0, 35.0, -74.0);
    glVertex3f(-20.0, 17.0, -74.0);
    glVertex3f(-20.0, 17.0, -58.0);
    glEnd();

    //2 jendela besar di atas tangga
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-41.5, 15.0, -74.0);
    glVertex3f(-41.5, 11.0, -74.0);
    glVertex3f(-35.5, 11.0, -74.0);
    glVertex3f(-35.5, 15.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-20.5, 15.0, -74.0);
    glVertex3f(-20.5, 11.0, -74.0);
    glVertex3f(-31.5, 11.0, -74.0);
    glVertex3f(-31.5, 15.0, -74.0);
    glEnd();

    //tembok-tembok jendelanya
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-45.0, 11.0, -74.0);
    glVertex3f(-45.0, 15.0, -74.0);
    glVertex3f(-41.5, 15.0, -74.0);
    glVertex3f(-41.5, 11.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-45.0, 11.0, -74.0);
    glVertex3f(-45.0, 9.0, -74.0);
    glVertex3f(-20.0, 9.0, -74.0);
    glVertex3f(-20.0, 11.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-45.0, 17.0, -74.0);
    glVertex3f(-45.0, 15.0, -74.0);
    glVertex3f(-20.0, 15.0, -74.0);
    glVertex3f(-20.0, 17.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-35.5, 11.0, -74.0);
    glVertex3f(-35.5, 15.0, -74.0);
    glVertex3f(-31.5, 15.0, -74.0);
    glVertex3f(-31.5, 11.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-20.5, 11.0, -74.0);
    glVertex3f(-20.5, 15.0, -74.0);
    glVertex3f(-20.0, 15.0, -74.0);
    glVertex3f(-20.0, 11.0, -74.0);
    glEnd();

    //tembok tegak/pilar dekat pagar atas ruangan kecil
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-20.0, 9.0, -74.0);
    glVertex3f(-20.0, 35.0, -74.0);
    glVertex3f(-17.0, 35.0, -74.0);
    glVertex3f(-17.0, 9.0, -74.0);
    glEnd();

    //sekat-sekat tembok dan jendela atas lahan kososng
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-12.0, 9.0, -74.0);
    glVertex3f(-12.0, 11.0, -74.0);
    glVertex3f(-17.0, 11.0, -74.0);
    glVertex3f(-17.0, 9.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-12.0, -1.0, -74.0);
    glVertex3f(-12.0, 4.3, -74.0);
    glVertex3f(-17.0, 4.3, -74.0);
    glVertex3f(-17.0, -1.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-12.0, -1.0, -74.0);
    glVertex3f(-12.0, -5.0, -74.0);
    glVertex3f(-17.0, -5.0, -74.0);
    glVertex3f(-17.0, -1.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-12.0, 4.3, -74.0);
    glVertex3f(-12.0, 9.0, -74.0);
    glVertex3f(-17.0, 9.0, -74.0);
    glVertex3f(-17.0, 4.3, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-12.0, 15.0, -74.0);
    glVertex3f(-12.0, 11.0, -74.0);
    glVertex3f(-17.0, 11.0, -74.0);
    glVertex3f(-17.0, 15.0, -74.0);
    glEnd();

    //tembok siku dekat lahan kososng
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-12.0, -5.0, -73.0);
    glVertex3f(-12.0, 11.0, -73.0);
    glVertex3f(-12.0, 11.0, -83.0);
    glVertex3f(-12.0, -5.0, -83.0);
    glEnd();

    int maju = 0;
    for (int tj = 0; tj <= 16; tj += 16) {
        //jendela tembok tengah
        for (int jd = 0; jd <= 7; jd += 7) {
            glBegin(GL_QUADS);
            glColor3f(0.0, 1.0, 1.0);
            glVertex3f(-10.0 + jd + tj, -1.0, -83.0 - maju);
            glVertex3f(-10.0 + jd + tj, -5.0, -83.0 - maju);
            glVertex3f(-5.0 + jd + tj, -5.0, -83.0 - maju);
            glVertex3f(-5.0 + jd + tj, -1.0, -83.0 - maju);
            glEnd();

            glBegin(GL_QUADS);
            glColor3f(0.0, 1.0, 1.0);
            glVertex3f(-10.0 + jd + tj, 4.3, -83.0 - maju);
            glVertex3f(-10.0 + jd + tj, 9.0, -83.0 - maju);
            glVertex3f(-5.0 + jd + tj, 9.0, -83.0 - maju);
            glVertex3f(-5.0 + jd + tj, 4.3, -83.0 - maju);
            glEnd();
        }

        //tembok sekat" jendela tengah
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-12.0 + tj, -5.0, -83.0 - maju);
        glVertex3f(-12.0 + tj, -10.0, -83.0 - maju);
        glVertex3f(4.0 + tj, -10.0, -83.0 - maju);
        glVertex3f(4.0 + tj, -5.0, -83.0 - maju);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-12.0 + tj, 4.3, -83.0 - maju);
        glVertex3f(-12.0 + tj, -1.0, -83.0 - maju);
        glVertex3f(4.0 + tj, -1.0, -83.0 - maju);
        glVertex3f(4.0 + tj, 4.3, -83.0 - maju);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-12.0 + tj, 9.0, -83.0 - maju);
        glVertex3f(-12.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(4.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(4.0 + tj, 9.0, -83.0 - maju);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-12.0 + tj, -10.0, -83.0 - maju);
        glVertex3f(-12.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(-10.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(-10.0 + tj, -10.0, -83.0 - maju);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-3.0 + tj, -10.0, -83.0 - maju);
        glVertex3f(-3.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(-5.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(-5.0 + tj, -10.0, -83.0 - maju);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(2.0 + tj, -10.0, -83.0 - maju);
        glVertex3f(2.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(4.0 + tj, 11.0, -83.0 - maju);
        glVertex3f(4.0 + tj, -10.0, -83.0 - maju);
        glEnd();

        maju += 5;
    }

    //tembok pintu ruang tengah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-2.0, -10.0, -73.0);
    glVertex3f(-2.0, 11.0, -73.0);
    glVertex3f(20.0, 11.0, -73.0);
    glVertex3f(20.0, -10.0, -73.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-6.0, -10.0, -73.0);
    glVertex3f(-6.0, 11.0, -73.0);
    glVertex3f(-12.0, 11.0, -73.0);
    glVertex3f(-12.0, -10.0, -73.0);
    glEnd();

    //pintu
    for (float p = 0; p <= 10.5; p += 10.5) {
        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(-6.0, -10.0 + p, -73.0);
        glVertex3f(-6.0, -2.0 + p, -73.0);
        glVertex3f(-2.0, -2.0 + p, -73.0);
        glVertex3f(-2.0, -10.0 + p, -73.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-6.0, 0.5 + p, -73.0);
        glVertex3f(-6.0, -2.0 + p, -73.0);
        glVertex3f(-2.0, -2.0 + p, -73.0);
        glVertex3f(-2.0, 0.5 + p, -73.0);
        glEnd();
    }

    //tembok kanan kiri ruang tengah
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-12.0, -10.0, -73.0);
    glVertex3f(-12.0, 11.0, -73.0);
    glVertex3f(-12.0, 11.0, -83.0);
    glVertex3f(-12.0, -10.0, -83.0);
    glEnd();

    for (int tk = 0; tk <= 16; tk += 16) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(4.0 + tk, -10.0, -73.0);
        glVertex3f(4.0 + tk, 11.0, -73.0);
        glVertex3f(4.0 + tk, 11.0, -88.0);
        glVertex3f(4.0 + tk, -10.0, -88.0);
        glEnd();
    }

    //alas ruang tengah
    for (float ta = 0; ta <= 10.5; ta += 10.5) {
        glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8);
        glVertex3f(-12.0, -10.0 + ta, -73.0);
        glVertex3f(-12.0, -10.0 + ta, -83.0);
        glVertex3f(4.0, -10.0 + ta, -83.0);
        glVertex3f(4.0, -10.0 + ta, -73.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-12.0, 11.0, -73.0);
    glVertex3f(-12.0, 11.0, -83.0);
    glVertex3f(4.0, 11.0, -83.0);
    glVertex3f(4.0, 11.0, -73.0);
    glEnd();

    for (float mk2 = 0; mk2 <= 10.5; mk2 += 10.5) {
        for (int mk = 0; mk <= 9; mk += 9) {
            //kursi ruang tengah
            glBegin(GL_QUADS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(3.0 - mk, -8.0 + mk2, -76.0);
            glVertex3f(3.0 - mk, -8.0 + mk2, -79.0);
            glVertex3f(0.5 - mk, -8.0 + mk2, -79.0);
            glVertex3f(0.5 - mk, -8.0 + mk2, -76.0);
            glEnd();

            for (int kk = 0; kk <= 3; kk += 3) {
                glBegin(GL_QUADS);
                glColor3f(1.0, 0.0, 0.0);
                glVertex3f(2.5 - mk, -8.0 + mk2, -79.0 + kk);
                glVertex3f(2.5 - mk, -10.0 + mk2, -79.0 + kk);
                glVertex3f(3.0 - mk, -10.0 + mk2, -79.0 + kk);
                glVertex3f(3.0 - mk, -8.0 + mk2, -79.0 + kk);
                glEnd();

                glBegin(GL_QUADS);
                glColor3f(1.0, 0.0, 0.0);
                glVertex3f(0.5 - mk, -8.0 + mk2, -79.0 + kk);
                glVertex3f(0.5 - mk, -10.0 + mk2, -79.0 + kk);
                glVertex3f(1.0 - mk, -10.0 + mk2, -79.0 + kk);
                glVertex3f(1.0 - mk, -8.0 + mk2, -79.0 + kk);
                glEnd();
            }

            glBegin(GL_QUADS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(3.0 - mk, -8.0 + mk2, -76.0);
            glVertex3f(3.0 - mk, -4.0 + mk2, -76.0);
            glVertex3f(3.0 - mk, -4.0 + mk2, -79.0);
            glVertex3f(3.0 - mk, -8.0 + mk2, -79.0);
            glEnd();

            //Meja
            glBegin(GL_QUADS);
            glColor3f(0.5, 0.5, 0.0);
            glVertex3f(-2.0 - mk, -6.0 + mk2, -74.0);
            glVertex3f(-2.0 - mk, -6.0 + mk2, -81.0);
            glVertex3f(1.5 - mk, -6.0 + mk2, -81.0);
            glVertex3f(1.5 - mk, -6.0 + mk2, -74.0);
            glEnd();

            for (int km = 0; km <= 7; km += 7) {
                glBegin(GL_QUADS);
                glColor3f(0.5, 0.5, 0.0);
                glVertex3f(1.5 - mk, -6.0 + mk2, -81.0 + km);
                glVertex3f(1.5 - mk, -10.0 + mk2, -81.0 + km);
                glVertex3f(1.0 - mk, -10.0 + mk2, -81.0 + km);
                glVertex3f(1.0 - mk, -6.0 + mk2, -81.0 + km);
                glEnd();

                glBegin(GL_QUADS);
                glColor3f(0.5, 0.5, 0.0);
                glVertex3f(-2.0 - mk, -6.0 + mk2, -81.0 + km);
                glVertex3f(-2.0 - mk, -10.0 + mk2, -81.0 + km);
                glVertex3f(-1.5 - mk, -10.0 + mk2, -81.0 + km);
                glVertex3f(-1.5 - mk, -6.0 + mk2, -81.0 + km);
                glEnd();

                glBegin(GL_QUADS);
                glColor3f(0.5, 0.5, 0.0);
                glVertex3f(-2.0 - mk, -6.0 + mk2, -81.0 + km);
                glVertex3f(-2.0 - mk, -9.0 + mk2, -81.0 + km);
                glVertex3f(1.5 - mk, -9.0 + mk2, -81.0 + km);
                glVertex3f(1.5 - mk, -6.0 + mk2, -81.0 + km);
                glEnd();
            }

            glBegin(GL_QUADS);
            glColor3f(0.5, 0.5, 0.0);
            glVertex3f(-2.0 - mk, -6.0 + mk2, -81.0);
            glVertex3f(-2.0 - mk, -9.0 + mk2, -81.0);
            glVertex3f(-2.0 - mk, -9.0 + mk2, -74.0);
            glVertex3f(-2.0 - mk, -6.0 + mk2, -74.0);
            glEnd();
        }
    }

    //alas dan atap ruang paling kiri
    for (int aa = 0; aa <= 21; aa += 21) {
        glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8);
        glVertex3f(20.0, -10.0 + aa, -73.0);
        glVertex3f(20.0, -10.0 + aa, -88.0);
        glVertex3f(4.0, -10.0 + aa, -88.0);
        glVertex3f(4.0, -10.0 + aa, -73.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-12.0, 11.0, -74.0);
    glVertex3f(-12.0, 15.0, -74.0);
    glVertex3f(20.0, 15.0, -74.0);
    glVertex3f(20.0, 11.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-17.0, 17.0, -74.0);
    glVertex3f(-17.0, 15.0, -74.0);
    glVertex3f(20.0, 15.0, -74.0);
    glVertex3f(20.0, 17.0, -74.0);
    glEnd();

    //Jendela banyak atas atap ruang tenag
    for (int jendelax = 0; jendelax < 33; jendelax += 6) {
        for (int jendelay = 0; jendelay < 15; jendelay += 6) {
            glBegin(GL_QUADS);
            glColor3f(0.0, 1.0, 1.0);
            glVertex3f(-17.0 + jendelax, 19.0 + jendelay, -74.0);
            glVertex3f(-17.0 + jendelax, 22.0 + jendelay, -74.0);
            glVertex3f(-14.0 + jendelax, 22.0 + jendelay, -74.0);
            glVertex3f(-14.0 + jendelax, 19.0 + jendelay, -74.0);
            glEnd();

            //tembok sekat-sekat
            glBegin(GL_QUADS);
            glColor3f(1.0, 0.9, 0.5);
            glVertex3f(-14.0 + jendelax, 17.0, -74.0);
            glVertex3f(-14.0 + jendelax, 35.0, -74.0);
            glVertex3f(-11.0 + jendelax, 35.0, -74.0);
            glVertex3f(-11.0 + jendelax, 17.0, -74.0);
            glEnd();

            glBegin(GL_QUADS);
            glColor3f(1.0, 0.9, 0.5);
            glVertex3f(-17.0, 16.0 + jendelay, -74.0);
            glVertex3f(-17.0, 19.0 + jendelay, -74.0);
            glVertex3f(20.0, 19.0 + jendelay, -74.0);
            glVertex3f(20.0, 16.0 + jendelay, -74.0);
            glEnd();
        }
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-17.0, 34.0, -74.0);
    glVertex3f(-17.0, 35.0, -74.0);
    glVertex3f(20.0, 35.0, -74.0);
    glVertex3f(20.0, 34.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(19.0, 34.0, -74.0);
    glVertex3f(19.0, 16.0, -74.0);
    glVertex3f(20.0, 16.0, -74.0);
    glVertex3f(20.0, 34.0, -74.0);
    glEnd();

    //tembok kiri sebelah ruang paling kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(20.0, 35.0, -74.0);
    glVertex3f(20.0, -10.0, -74.0);
    glVertex3f(20.0, -10.0, -40.0);
    glVertex3f(20.0, 35.0, -40.0);
    glEnd();

    //tembok belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(20.0, 35.0, -40.0);
    glVertex3f(20.0, -10.0, -40.0);
    glVertex3f(-45.0, -10.0, -40.0);
    glVertex3f(-45.0, 35.0, -40.0);
    glEnd();

    //alas bangunan
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(20.0, -10.0, -73.0);
    glVertex3f(20.0, -10.0, -40.0);
    glVertex3f(-45.0, -10.0, -40.0);
    glVertex3f(-45.0, -10.0, -73.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-12.0, -10.0, -73.0);
    glVertex3f(-12.0, -10.0, -83.0);
    glVertex3f(-20.0, -10.0, -83.0);
    glVertex3f(-20.0, -10.0, -73.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-45.0, -10.0, -73.0);
    glVertex3f(-45.0, -10.0, -80.0);
    glVertex3f(-20.0, -10.0, -80.0);
    glVertex3f(-20.0, -10.0, -73.0);
    glEnd();

    //atap gedung
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(20.0, 35.0, -74.0);
    glVertex3f(20.0, 35.0, -40.0);
    glVertex3f(-13.0, 35.0, -40.0);
    glVertex3f(-13.0, 35.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-20.0, 35.0, -74.0);
    glVertex3f(-20.0, 35.0, -58.0);
    glVertex3f(-13.0, 35.0, -58.0);
    glVertex3f(-13.0, 35.0, -74.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-45.0, 35.0, -40.0);
    glVertex3f(-45.0, 35.0, -48.0);
    glVertex3f(-13.0, 35.0, -48.0);
    glVertex3f(-13.0, 35.0, -40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-45.0, 35.0, -56.0);
    glVertex3f(-45.0, 35.0, -58.0);
    glVertex3f(-13.0, 35.0, -58.0);
    glVertex3f(-13.0, 35.0, -56.0);
    glEnd();

    //bangunan persegi panjang di atap
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-45.0, 35.0, -48.0);
    glVertex3f(-45.0, 43.0, -48.0);
    glVertex3f(-13.0, 43.0, -48.0);
    glVertex3f(-13.0, 35.0, -48.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(-45.0, 35.0, -56.0);
    glVertex3f(-45.0, 43.0, -56.0);
    glVertex3f(-13.0, 43.0, -56.0);
    glVertex3f(-13.0, 35.0, -56.0);
    glEnd();

    for (int pg = 0; pg <= 32; pg += 32) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(-13.0 - pg, 35.0, -48.0);
        glVertex3f(-13.0 - pg, 43.0, -48.0);
        glVertex3f(-13.0 - pg, 43.0, -56.0);
        glVertex3f(-13.0 - pg, 35.0, -56.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(-45.0, 35.0, -49.0);
    glVertex3f(-45.0, 33.0, -49.0);
    glVertex3f(-45.0, 33.0, -52.0);
    glVertex3f(-45.0, 35.0, -52.0);
    glEnd();

    for (int pg2 = 0; pg2 <= 18; pg2 += 9) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.5);
        glVertex3f(-21.0 - pg2, 43.0, -48.0);
        glVertex3f(-21.0 - pg2, 43.0, -56.0);
        glVertex3f(-22.0 - pg2, 43.0, -56.0);
        glVertex3f(-22.0 - pg2, 43.0, -48.0);
        glEnd();
    }

    for (int kca = 0; kca <= 18; kca += 9) {
        glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-21.0 - kca, 43.0, -48.0);
        glVertex3f(-21.0 - kca, 43.0, -56.0);
        glVertex3f(-13.0 - kca, 43.0, -56.0);
        glVertex3f(-13.0 - kca, 43.0, -48.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-40.0, 43.0, -48.0);
    glVertex3f(-40.0, 43.0, -56.0);
    glVertex3f(-45.0, 43.0, -56.0);
    glVertex3f(-45.0, 43.0, -48.0);
    glEnd();

    int tinggi = 0;
    //tembok paling kiri
    for (int tpk = 0; tpk <= 2; tpk += 2) {
        glBegin(GL_QUADS);
        glColor3f(0.6, 0.6, 0.6);
        glVertex3f(28.0 + tpk, 5.0, -93.0);
        glVertex3f(28.0 + tpk, -10.0, -93.0);
        glVertex3f(28.0 + tpk, -10.0, -40.0);
        glVertex3f(28.0 + tpk, 5.0, -40.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.5);
        glVertex3f(28.0 + tpk, 5.0, -88.0);
        glVertex3f(28.0 + tpk, 8.0 + tinggi, -88.0);
        glVertex3f(28.0 + tpk, 8.0 + tinggi, -40.0);
        glVertex3f(28.0 + tpk, 5.0, -40.0);
        glEnd();

        tinggi += 2;
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(30.0, 10.0, -88.0);
    glVertex3f(30.0, 5.0, -88.0);
    glVertex3f(20.0, 5.0, -88.0);
    glVertex3f(20.0, 10.0, -88.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(30.0, 5.0, -88.0);
    glVertex3f(30.0, 5.0, -93.0);
    glVertex3f(28.0, 5.0, -93.0);
    glVertex3f(28.0, 5.0, -88.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(30.0, 5.0, -93.0);
    glVertex3f(30.0, -10.0, -93.0);
    glVertex3f(28.0, -10.0, -93.0);
    glVertex3f(28.0, 5.0, -93.0);
    glEnd();

    //atap dan alas
    for (int atk = 0; atk <= 20; atk += 20) {
        glBegin(GL_QUADS);
        glColor3f(0.9, 0.9, 0.9);
        glVertex3f(30.0, -10.0 + atk, -88.0);
        glVertex3f(30.0, -10.0 + atk, -40.0);
        glVertex3f(20.0, -10.0 + atk, -40.0);
        glVertex3f(20.0, -10.0 + atk, -88.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(30.0, 5.0, -88.0);
    glVertex3f(30.0, 5.0, -40.0);
    glVertex3f(20.0, 5.0, -40.0);
    glVertex3f(20.0, 5.0, -88.0);
    glEnd();

    //tembok kaca ruang paling kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(30.0, -1.0, -75.0);
    glVertex3f(30.0, -8.0, -75.0);
    glVertex3f(20.0, -8.0, -75.0);
    glVertex3f(20.0, -1.0, -75.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(30.0, 5.0, -75.0);
    glVertex3f(30.0, -1.0, -75.0);
    glVertex3f(20.0, -1.0, -75.0);
    glVertex3f(20.0, 5.0, -75.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.9, 0.5);
    glVertex3f(30.0, -8.0, -75.0);
    glVertex3f(30.0, -10.0, -75.0);
    glVertex3f(20.0, -10.0, -75.0);
    glVertex3f(20.0, -8.0, -75.0);
    glEnd();

    //tembok belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.5);
    glVertex3f(30.0, 10.0, -40.0);
    glVertex3f(30.0, -10.0, -40.0);
    glVertex3f(20.0, -10.0, -40.0);
    glVertex3f(20.0, 10.0, -40.0);
    glEnd();

    //alas halaman depan gedung
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-45.0, -10.0, -93.0);
    glVertex3f(-45.0, -10.0, -88.0);
    glVertex3f(30.0, -10.0, -88.0);
    glVertex3f(30.0, -10.0, -93.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-45.0, -10.0, -83.0);
    glVertex3f(-45.0, -10.0, -88.0);
    glVertex3f(4.0, -10.0, -88.0);
    glVertex3f(4.0, -10.0, -83.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-45.0, -10.0, -83.0);
    glVertex3f(-45.0, -10.0, -80.0);
    glVertex3f(-14.0, -10.0, -80.0);
    glVertex3f(-14.0, -10.0, -83.0);
    glEnd();

    //pagar ruang paling kiri
    for (float pgr = 0; pgr <= 6; pgr += 0.5) {
        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(28.0, -4.2 - pgr, -88.0);
        glVertex3f(28.0, -4.0 - pgr, -88.0);
        glVertex3f(24.5, -4.0 - pgr, -88.0);
        glVertex3f(24.5, -4.2 - pgr, -88.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(23.5, -4.2 - pgr, -88.0);
        glVertex3f(23.5, -4.0 - pgr, -88.0);
        glVertex3f(20.0, -4.0 - pgr, -88.0);
        glVertex3f(20.0, -4.2 - pgr, -88.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(24.1, -4.0, -88.0);
        glVertex3f(24.1, -9.7, -88.0);
        glVertex3f(24.5, -9.7, -88.0);
        glVertex3f(24.5, -4.0, -88.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(23.9, -4.0, -88.0);
        glVertex3f(23.9, -9.7, -88.0);
        glVertex3f(23.5, -9.7, -88.0);
        glVertex3f(23.5, -4.0, -88.0);
        glEnd();
    }

//-----------------------------------------------------------------------------------------------------------------------------------


        //tabung depan kiri
    glColor3f(1.0, 0.8, 0.5);
    glTranslatef(-20.0, 10.0, 5.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    draw_cylinder(5.0, 69.0, 255, 160, 100);
    //glEnd();
    //tabung depan kanan
    glTranslatef(35.0, 0.0, -1.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    draw_cylinder(5.0, 70.0, 255, 160, 100);
    //glEnd();
    //tabung belakang kanan
    glTranslatef(0.0, 32.5, -19.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    draw_cylinder(5.0, 89.0, 255, 160, 100);
    //glEnd();
    //tabung belakang kiri
    glTranslatef(-35.0, 0.0, 0.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    draw_cylinder(5.0, 89.0, 255, 160, 100);
    //glEnd();
    //tabung bawah depan bagian kanan
    glTranslatef(55.0, -40.0, 0.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    draw_cylinder(5.0, 24.0, 255, 160, 100);
    //glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth) {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3;
        yrot += 0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi) {
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR GRAFKOM F");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);
    glutMotionFunc(mouseMotion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
