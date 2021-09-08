#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void Init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(5.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
    glViewport(40, 400, 60, 300);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;
    if (n < 3) return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;

    glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);

    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}

void display(void){

    int segi=3;
    for(int a=50;a>=10;a-=10){
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 0.0);
            ngon(segi,-40,-40,a,360);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(1.0, 1.0, 0.0);
            ngon(segi,40,40,a,180);
        glEnd();
    }

    for(int g=0; g<=55; g+=5){
        glBegin(GL_LINES);
        if(g%2==0){
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(-80, 75-g);
            glVertex2f(80, -20-g);
        }else{
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(-80, 75-g);
            glVertex2f(80, -20-g);
        }
        glEnd();
    }

	for(int l=0; l<100; l+=20){
        glBegin(GL_POLYGON);
            glColor3f(1.0, 0.0, 0.0);
                ngon(100, -72.5, -80+l, 5, 100);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(1.0, 0.0, 0.0);
                ngon(100, 72.5, 80-l, 5, 100);
        glEnd();
	}

	segi=10;
    for(int a=20;a>=0;a-=4){
        if(a%5==0){
            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);
                ngon(segi,20,-67,a,360);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);
                ngon(segi,-20,67,a,360);
            glEnd();
        }else{
            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 1.0, 0.0);
                ngon(segi,20,-67,a,360);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 1.0, 0.0);
                ngon(segi,-20,67,a,180);
            glEnd();
        }
    }

    for(int a=10;a>=0;a-=2){
        if(a%5==0){
            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);
                ngon(segi,-13,-75,a,360);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);
                ngon(segi,13,75,a,360);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);
                ngon(segi,53,-75,a,360);
            glEnd();

            glBegin(GL_POLYGON);
                glColor3f(1.0, 0.0, 0.0);
                ngon(segi,-53,75,a,360);
            glEnd();
        }else{
            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 1.0, 1.0);
                ngon(segi,-13,-75,a,360);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 1.0, 1.0);
                ngon(segi,13,75,a,180);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 1.0, 1.0);
                ngon(segi,53,-75,a,360);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(1.0, 1.0, 1.0);
                ngon(segi,-53,75,a,180);
            glEnd();
        }
    }

    double bingkai[4][2]={{-80, -90},{-80, 90},{80, 90},{80, -90}};
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 1.0);

        for(int k=0; k<4; k++){
            glVertex2d(bingkai[k][0], bingkai[k][1]);
        }
	glEnd();


    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 100);
	glutCreateWindow("Tugas3-Dewa Asmara Putra-672019124");
	glutDisplayFunc(display);
	Init();
	glutMainLoop();
	return 0;
}
