#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 800);
    glutInitWindowPosition(250, 10);
    glutCreateWindow("Dewa Asmara Putra - 672019124");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
}

void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    for(int a=0; a<=144; a+=72){
        //depan1
        if(a==144){
            a-=20;
            glBegin(GL_QUADS);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(-55.0+a, -55.0, 10.0);
            glVertex3f(-62.0+a, -55.0, 10.0);
            glVertex3f(-62.0+a, 10.0, 10.0);
            glVertex3f(-55.0+a, 10.0, 10.0);
            glEnd();
        }else{
            glBegin(GL_QUADS);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(-55.0+a, -50.0, 10.0);
            glVertex3f(-62.0+a, -50.0, 10.0);
            glVertex3f(-62.0+a, 10.0, 10.0);
            glVertex3f(-55.0+a, 10.0, 10.0);
            glEnd();
        }
    }

    for(int b=0; b<=65; b+=65){
        //siku" tembok depan
        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-55.0+b, 10.0, 10.0);
        glVertex3f(-55.0+b, -50.0, 10.0);
        glVertex3f(-55.0+b, -50.0, 8.0);
        glVertex3f(-55.0+b, 10.0, 8.0);
        glEnd();
    }

    for(int c=0; c<=55; c+=55){
    //tembok depan2 pagar
        if(c==55){
            glBegin(GL_QUADS);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(-55.0+c, -40.0+5, 8.0);
            glVertex3f(-45.0+c, -40.0+5, 8.0);
            glVertex3f(-45.0+c, 10.0, 8.0);
            glVertex3f(-55.0+c, 10.0, 8.0);
            glEnd();
        }else{
            glBegin(GL_QUADS);
            glColor3f(0.8, 0.8, 0.8);
            glVertex3f(-55.0+c, -40.0, 8.0);
            glVertex3f(-45.0+c, -40.0, 8.0);
            glVertex3f(-45.0+c, 10.0, 8.0);
            glVertex3f(-55.0+c, 10.0, 8.0);
            glEnd();
        }
    }

    //tembok depan3 pagar
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-45.0, -35.0, 8.0);
    glVertex3f(0.0, -35.0, 8.0);
    glVertex3f(0.0, -25.0, 8.0);
    glVertex3f(-45.0, -25.0, 8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-55.0, -35.0, 3.0);
    glVertex3f(0.0, -35.0, 3.0);
    glVertex3f(0.0, -25.0, 3.0);
    glVertex3f(-55.0, -25.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.0, -35.0, 3.0);
    glVertex3f(17.0, -35.0, 3.0);
    glVertex3f(17.0, 10.0, 3.0);
    glVertex3f(0.0, 10.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-57.0, -35.0, 3.0);
    glVertex3f(-45.0, -35.0, 3.0);
    glVertex3f(-45.0, 10.0, 3.0);
    glVertex3f(-57.0, 10.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-57.0, 10.0, 3.0);
    glVertex3f(-45.0, 10.0, 3.0);
    glVertex3f(-45.0, 10.0, 8.0);
    glVertex3f(-57.0, 10.0, 8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-57.0, 10.0, 8.0);
    glVertex3f(-55.0, 10.0, 8.0);
    glVertex3f(-55.0, 10.0, 10.0);
    glVertex3f(-57.0, 10.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, 10.0, 8.0);
    glVertex3f(-45.0, -35.0, 8.0);
    glVertex3f(-45.0, -35.0, 3.0);
    glVertex3f(-45.0, 10.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-45.0, -25.0, 8.0);
    glVertex3f(0.0, -25.0, 8.0);
    glVertex3f(0.0, -25.0, 3.0);
    glVertex3f(-45.0, -25.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.0, 10.0, 8.0);
    glVertex3f(0.0, -35.0, 8.0);
    glVertex3f(0.0, -35.0, 3.0);
    glVertex3f(0.0, 10.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(10.0, 10.0, 8.0);
    glVertex3f(17.0, 10.0, 8.0);
    glVertex3f(17.0, 10.0, 10.0);
    glVertex3f(10.0, 10.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0.0, 10.0, 3.0);
    glVertex3f(17.0, 10.0, 3.0);
    glVertex3f(17.0, 10.0, 8.0);
    glVertex3f(0.0, 10.0, 8.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-57.0, 10.0, 10.0);
    glVertex3f(-57.0, -50.0, 10.0);
    glVertex3f(-57.0, -50.0, 3.0);
    glVertex3f(-57.0, 10.0, 3.0);
    glEnd();

    for(int y3=0; y3<=40; y3+=5){
        //pagar atas
        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_LINES);
        glVertex3f(2.0, 8.0-y3, 5.0);
        glVertex3f(-45.0, 8.0-y3, 5.0);
        glEnd();

        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_LINES);
        glVertex3f(-40.0+y3, 8.0, 5.0);
        glVertex3f(-40.0+y3, -40.0, 5.0);
        glEnd();
    }

    for(int y4=0; y4<=4; y4+=2){
        //jaring fentilasi
        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_LINES);
        glVertex3f(-57.0, 42.0+y4, -88.0);
        glVertex3f(62.0, 42.0+y4, -88.0);
        glEnd();
    }

    //tembok depan4 bawah pagar warna hijau
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-45.0, -50.0, 10.0);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(10.0, -35.0, 10.0);
    glVertex3f(10.0, -50.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-55.0, -50.0, 10.0);
    glVertex3f(-55.0, -40.0, 10.0);
    glVertex3f(-45.0, -40.0, 10.0);
    glVertex3f(-45.0, -50.0, 10.0);
    glEnd();

    //siku"2 depan4 bawah pagar warna hijau
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(10.0, -35.0, 10.0);
    glVertex3f(10.0, -35.0, 8.0);
    glVertex3f(-45.0, -35.0, 8.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-55.0, -40.0, 10.0);
    glVertex3f(-45.0, -40.0, 10.0);
    glVertex3f(-45.0, -40.0, 8.0);
    glVertex3f(-55.0, -40.0, 8.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-45.0, -40.0, 10.0);
    glVertex3f(-45.0, -35.0, 10.0);
    glVertex3f(-45.0, -35.0, 8.0);
    glVertex3f(-45.0, -40.0, 8.0);
    glEnd();

    //lantai hijau depan rumah
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-62.0, -50.0, 20.0);
    glVertex3f(17.0, -50.0, 20.0);
    glVertex3f(17.0, -50.0, 10.0);
    glVertex3f(-62.0, -50.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.5, 0.0);
    glVertex3f(-62.0, -50.0, 20.0);
    glVertex3f(17.0, -50.0, 20.0);
    glVertex3f(17.0, -55.0, 20.0);
    glVertex3f(-62.0, -55.0, 20.0);
    glEnd();

    for(int d=0; d<=79; d+=79){
        if(d==79){
            glBegin(GL_POLYGON);
            glColor3f(0.6, 0.5, 0.0);
            glVertex3f(-62.0+d, -55.0, 20.0);
            glVertex3f(-62.0+d, -50.0, 20.0);
            glVertex3f(-62.0+d, -50.0, 10.0);
            glVertex3f(-62.0+d, -55.0, 10.0);
            glEnd();
        }else{
            glBegin(GL_POLYGON);
            glColor3f(0.6, 0.5, 0.0);
            glVertex3f(-62.0, -55.0, 20.0);
            glVertex3f(-62.0, -50.0, 20.0);
            glVertex3f(-62.0, -50.0, 10.0);
            glVertex3f(-62.0, -55.0, 10.0);
            glEnd();
        }
    }

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(17.0, 10.0, 10.0);
    glVertex3f(17.0, -50.0, 10.0);
    glVertex3f(17.0, -50.0, 3.0);
    glVertex3f(17.0, 10.0, 3.0);
    glEnd();

    //Tangga halaman rumah
    for(int e=0; e<=16; e+=8){
        for(int f=0; f<=10; f+=10){
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.4);
            glVertex3f(17.0+f, -43.0+e, 8.0-e);
            glVertex3f(27.0+f, -43.0+e, 8.0-e);
            glVertex3f(27.0+f, -43.0+e, 16.0-e);
            glVertex3f(17.0+f, -43.0+e, 16.0-e);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.9, 0.9, 0.9);
            glVertex3f(27.0, -43.0+e, 8.0-e);
            glVertex3f(27.0, -43.0+e, 16.0-e);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.4);
            glVertex3f(17.0+f, -43.0+e, 16.0-e);
            glVertex3f(27.0+f, -43.0+e, 16.0-e);
            glVertex3f(27.0+f, -51.0+e, 16.0-e);
            glVertex3f(17.0+f, -51.0+e, 16.0-e);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.9, 0.9, 0.9);
            glVertex3f(27.0, -43.0+e, 16.0-e);
            glVertex3f(27.0, -51.0+e, 16.0-e);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.4);
            glVertex3f(17.0+2*f, -43.0+e, 8.0-e);
            glVertex3f(17.0+2*f, -51.0+e, 8.0-e);
            glVertex3f(17.0+2*f, -51.0+e, 16.0-e);
            glVertex3f(17.0+2*f, -43.0+e, 16.0-e);
            glEnd();
        }
    }

    //kotak kecil tembok sebelah tangga
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(17.0, -27.0, 0.0);
    glVertex3f(17.0, -35.0, 0.0);
    glVertex3f(17.0, -35.0, 3.0);
    glVertex3f(17.0, -27.0, 3.0);
    glEnd();

    //tangga halam rumah paling bawah
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(17.0, -51.0, 16.0);
    glVertex3f(37.0, -51.0, 16.0);
    glVertex3f(37.0, -51.0, 20.0);
    glVertex3f(17.0, -51.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(17.0, -51.0, 20.0);
    glVertex3f(37.0, -51.0, 20.0);
    glVertex3f(37.0, -55.0, 20.0);
    glVertex3f(17.0, -55.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(37.0, -51.0, 20.0);
    glVertex3f(37.0, -51.0, 8.0);
    glVertex3f(37.0, -55.0, 8.0);
    glVertex3f(37.0, -55.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(37.0, -27.0, -8.0);
    glVertex3f(37.0, -55.0, 20.0);
    glVertex3f(37.0, -55.0, -8.0);
    glEnd();

    //jalan naik miring halaman rumah
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(37.0, -27.0, -8.0);
    glVertex3f(65.0, -27.0, -8.0);
    glVertex3f(65.0, -55.0, 20.0);
    glVertex3f(37.0, -55.0, 20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(65.0, -27.0, -8.0);
    glVertex3f(65.0, -55.0, 20.0);
    glVertex3f(65.0, -55.0, -8.0);
    glEnd();

    //Tanah
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2, 0.0);
    glVertex3f(-62.0, -30.0, -8.0);
    glVertex3f(17.0, -30.0, -8.0);
    glVertex3f(17.0, -30.0, 5.0);
    glVertex3f(-62.0, -30.0, 5.0);
    glEnd();

    //lantai teras
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-62.0, -27.0, -85.0);
    glVertex3f(62.0, -27.0, -85.0);
    glVertex3f(62.0, -27.0, -8.0);
    glVertex3f(-62.0, -27.0, -8.0);
    glEnd();

    //siku labtai teras dekat tanah
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-62.0, -27.0, -8.0);
    glVertex3f(17.0, -27.0, -8.0);
    glVertex3f(17.0, -30.0, -8.0);
    glVertex3f(-62.0, -30.0, -8.0);
    glEnd();

    for(int q=0; q<=100; q+=15){
        glLineWidth(2.0f);
        if(q<=85){
            glBegin(GL_LINES);
            glColor3f(0.7, 0.7, 0.7);
            glVertex3f(-57.0, -27.0, -8.0-q);
            glVertex3f(67.0, -27.0, -8.0-q);
            glEnd();
        }

            glBegin(GL_LINES);
            glColor3f(0.7, 0.7, 0.7);
            glVertex3f(-42.0+q, -27.0, -8.0);
            glVertex3f(-42.0+q, -27.0, -85.0);
            glEnd();
    }

    //lantai dalam
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-62.0, -27.0, -230.0);
    glVertex3f(62.0, -27.0, -230.0);
    glVertex3f(62.0, -27.0, -85.0);
    glVertex3f(-62.0, -27.0, -85.0);
    glEnd();

    for(int q=0; q<=160; q+=10){
        glLineWidth(2.0f);
            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-57.0, -27.0, -95.0-q);
            glVertex3f(67.0, -27.0, -95.0-q);
            glEnd();

        if(q<=100){
            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-47.0+q, -27.0, -85.0);
            glVertex3f(-47.0+q, -27.0, -230.0);
            glEnd();
        }
    }

    //lantai dapur
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.0, -20.0, -230.0);
    glVertex3f(62.0, -20.0, -230.0);
    glVertex3f(62.0, -20.0, -330.0);
    glVertex3f(-15.0, -20.0, -330.0);
    glEnd();

    for(int q=0; q<80; q+=20){
        glLineWidth(2.0f);
            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-15.0, -20.0, -250.0-q);
            glVertex3f(0.0+q, -20.0, -230.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(62.0, -20.0, -250.0-q);
            glVertex3f(47-q, -20.0, -230.0);
            glEnd();

            for(int q2=0; q2<=60; q2+=20){
                glBegin(GL_LINES);
                glColor3f(0.0, 0.0, 0.0);
                glVertex3f(-15.0, -20.0, -250.0-q2);
                glVertex3f(62-q2, -20.0, -330.0);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(0.0, 0.0, 0.0);
                glVertex3f(62.0, -20.0, -250.0-q);
                glVertex3f(-15+q, -20.0, -330.0);
                glEnd();
            }
    }

    //lantai kamar mandi
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.7, 0.7);
    glVertex3f(-15.0, -20.0, -230.0);
    glVertex3f(-57.0, -20.0, -230.0);
    glVertex3f(-57.0, -20.0, -315.0);
    glVertex3f(-15.0, -20.0, -315.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-15.0, -20.0, -330.0);
    glVertex3f(-57.0, -20.0, -330.0);
    glVertex3f(-57.0, -20.0, -315.0);
    glVertex3f(-15.0, -20.0, -315.0);
    glEnd();

    int v1=0;
    for(int v=0; v<=40; v+=5){
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-15.0-v, -20.0, -230.0);
        glVertex3f(-15.0-v, -20.0, -315.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-57.0, -20.0, -235.0-v1);
        glVertex3f(-15.0, -20.0, -235.0-v1);
        glEnd();

        v1+=10;
    }

    //atap ruang tamu
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-15.0, 57.0, -230.0);
    glVertex3f(67.0, 57.0, -230.0);
    glVertex3f(67.0, 57.0, -85.0);
    glVertex3f(-15.0, 57.0, -85.0);
    glEnd();

    //atap kamar bawah
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-15.0, 57.0, -235.0);
    glVertex3f(-58.0, 57.0, -235.0);
    glVertex3f(-58.0, 57.0, -90.0);
    glVertex3f(-15.0, 57.0, -90.0);
    glEnd();

    //atap kamar mandi
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-15.0, 57.0, -235.0);
    glVertex3f(-58.0, 57.0, -235.0);
    glVertex3f(-58.0, 57.0, -270.0);
    glVertex3f(-15.0, 57.0, -270.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-15.0, 57.0, -315.0);
    glVertex3f(-43.0, 57.0, -315.0);
    glVertex3f(-43.0, 57.0, -270.0);
    glVertex3f(-15.0, 57.0, -270.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-15.0, 57.0, -315.0);
    glVertex3f(-39.0, 57.0, -315.0);
    glVertex3f(-39.0, 57.0, -330.0);
    glVertex3f(-15.0, 57.0, -330.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-15.0, 57.0, -330.0);
    glVertex3f(-62.0, 57.0, -330.0);
    glVertex3f(-62.0, 140.0, -330.0);
    glVertex3f(-15.0, 140.0, -330.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-57.0, 57.0, -330.0);
    glVertex3f(-57.0, 57.0, -230.0);
    glVertex3f(-57.0, 140.0, -230.0);
    glVertex3f(-57.0, 140.0, -330.0);
    glEnd();

    //lantai kamar atas
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.0, 57.0, -230.0);
    glVertex3f(62.0, 57.0, -230.0);
    glVertex3f(62.0, 57.0, -330.0);
    glVertex3f(-15.0, 57.0, -330.0);
    glEnd();

    for(int w=0; w<=90; w+=9){
        if(w<=80){
            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-15.0+w, 57.0, -235.0);
            glVertex3f(-15.0+w, 57.0, -330.0);
            glEnd();
        }

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(62.0, 57.0, -235.0-w);
        glVertex3f(-15.0, 57.0, -235.0-w);
        glEnd();
    }

    //dasar rumah
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-64.0, -55.0, -335.0);
    glVertex3f(69.0, -55.0, -335.0);
    glVertex3f(69.0, -55.0, 20.0);
    glVertex3f(-64.0, -55.0, 20.0);
    glEnd();

    //Tembok kanan kiri putih
    int g3=0;
    for(int g=0; g<=129; g+=129){
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-62.0+g, 10.0, 10.0);
        glVertex3f(-62.0+g, -55.0, 10.0);
        glVertex3f(-62.0+g, -55.0, -230.0);
        glVertex3f(-62.0+g, 10.0, -230.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-62.0+g, 10.0, 7.0);
        glVertex3f(-62.0+g, 57.0, 7.0);
        glVertex3f(-62.0+g, 57.0, -230.0);
        glVertex3f(-62.0+g, 10.0, -230.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-57.0+g3, 57.0, 7.0);
        glVertex3f(-62.0+g3, 57.0, 7.0);
        glVertex3f(-62.0+g3, 10.0, 7.0);
        glVertex3f(-57.0+g3, 10.0, 7.0);
        glEnd();

        g3=+124;
    }

    //tembok kiri abu-abu
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 10.0, 10.0);
    glVertex3f(-57.0, -55.0, 10.0);
    glVertex3f(-57.0, -55.0, -230.0);
    glVertex3f(-57.0, 10.0, -230.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 10.0, 7.0);
    glVertex3f(-57.0, 57.0, 7.0);
    glVertex3f(-57.0, 57.0, -230.0);
    glVertex3f(-57.0, 10.0, -230.0);
    glEnd();

    //tembok kanan teras abu-abu
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(62.0, 10.0, 10.0);
    glVertex3f(62.0, -55.0, 10.0);
    glVertex3f(62.0, -55.0, -90.0);
    glVertex3f(62.0, 10.0, -90.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(62.0, 10.0, 7.0);
    glVertex3f(62.0, 57.0, 7.0);
    glVertex3f(62.0, 57.0, -90.0);
    glVertex3f(62.0, 10.0, -90.0);
    glEnd();

    //tembok kanan ruang tamu
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(62.0, -55.0, -90.0);
    glVertex3f(62.0, 57.0, -90.0);
    glVertex3f(62.0, 57.0, -230.0);
    glVertex3f(62.0, -55.0, -230.0);
    glEnd();

    //Tembok kanan kiri belakang
    for(int g=0; g<=129; g+=129){
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-62.0+g, 10.0, -230.0);
        glVertex3f(-62.0+g, -55.0, -230.0);
        glVertex3f(-62.0+g, -55.0, -335.0);
        glVertex3f(-62.0+g, 10.0, -335.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-62.0+g, 10.0, -230.0);
        glVertex3f(-62.0+g, 57.0, -230.0);
        glVertex3f(-62.0+g, 57.0, -335.0);
        glVertex3f(-62.0+g, 10.0, -335.0);
        glEnd();

        for(int g2=0; g2<=119; g2+=119){
            glColor3f(0.6, 0.6, 0.6);
            glBegin(GL_QUADS);
            glVertex3f(-57.0+g2, 10.0, -230.0);
            glVertex3f(-57.0+g2, -55.0, -230.0);
            glVertex3f(-57.0+g2, -55.0, -335.0);
            glVertex3f(-57.0+g2, 10.0, -335.0);
            glEnd();

            glColor3f(0.6, 0.6, 0.6);
            glBegin(GL_QUADS);
            glVertex3f(-57.0+g2, 10.0, -230.0);
            glVertex3f(-57.0+g2, 57.0, -230.0);
            glVertex3f(-57.0+g2, 57.0, -335.0);
            glVertex3f(-57.0+g2, 10.0, -335.0);
            glEnd();
        }
    }

    //siku tembok pilar depan
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-62.0, 10.0, 7.0);
    glVertex3f(-57.0, 10.0, 7.0);
    glVertex3f(-57.0, 10.0, 10.0);
    glVertex3f(-62.0, 10.0, 10.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 10.0, 7.0);
    glVertex3f(62.0, 10.0, 7.0);
    glVertex3f(62.0, 10.0, 10.0);
    glVertex3f(67.0, 10.0, 10.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(69.0, 10.0, 10.0);
    glVertex3f(69.0, -55.0, 10.0);
    glVertex3f(69.0, -55.0, 5.0);
    glVertex3f(69.0, 10.0, 5.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 10.0, 5.0);
    glVertex3f(67.0, -55.0, 5.0);
    glVertex3f(69.0, -55.0, 5.0);
    glVertex3f(69.0, 10.0, 5.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 10.0, 5.0);
    glVertex3f(69.0, 10.0, 5.0);
    glVertex3f(69.0, 10.0, 10.0);
    glVertex3f(67.0, 10.0, 10.0);
    glEnd();

    //tembok belakang rumah
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-62.0, -20.0, -330.0);
    glVertex3f(67.0, -20.0, -330.0);
    glVertex3f(67.0, 57.0, -330.0);
    glVertex3f(-62.0, 57.0, -330.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-62.0, -55.0, -335.0);
    glVertex3f(67.0, -55.0, -335.0);
    glVertex3f(67.0, 57.0, -335.0);
    glVertex3f(-62.0, 57.0, -335.0);
    glEnd();

    //Tembok Pintu depan
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(62.0, 0.0, -85.0);
    glVertex3f(12.0, 0.0, -85.0);
    glVertex3f(12.0, -27.0, -85.0);
    glVertex3f(62.0, -27.0, -85.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(62.0, 0.0, -90.0);
    glVertex3f(12.0, 0.0, -90.0);
    glVertex3f(12.0, -27.0, -90.0);
    glVertex3f(62.0, -27.0, -90.0);
    glEnd();

    for(int h=0; h<=5; h+=5){
        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, 0.0, -85.0-h);
        glVertex3f(-13.0, 0.0, -85.0-h);
        glVertex3f(-13.0, -27.0, -85.0-h);
        glVertex3f(-57.0, -27.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, 35.0, -85.0-h);
        glVertex3f(-13.0, 35.0, -85.0-h);
        glVertex3f(-13.0, 40.0, -85.0-h);
        glVertex3f(-57.0, 40.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-14.0, 35.0, -85.0);
        glVertex3f(62.0, 35.0, -85.0);
        glVertex3f(62.0, 40.0, -85.0);
        glVertex3f(-14.0, 40.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-14.0, 35.0, -90.0);
        glVertex3f(62.0, 35.0, -90.0);
        glVertex3f(62.0, 40.0, -90.0);
        glVertex3f(-14.0, 40.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, 47.0, -85.0);
        glVertex3f(62.0, 47.0, -85.0);
        glVertex3f(62.0, 57.0, -85.0);
        glVertex3f(-57.0, 57.0, -85.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, 47.0, -90.0);
        glVertex3f(-14.0, 47.0, -90.0);
        glVertex3f(-14.0, 57.0, -90.0);
        glVertex3f(-57.0, 57.0, -90.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-14.0, 47.0, -90.0);
        glVertex3f(62.0, 47.0, -90.0);
        glVertex3f(62.0, 57.0, -90.0);
        glVertex3f(-14.0, 57.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, 0.0, -85.0-h);
        glVertex3f(-54.0, 0.0, -85.0-h);
        glVertex3f(-54.0, 40.0, -85.0-h);
        glVertex3f(-57.0, 40.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-38.0, 0.0, -85.0-h);
        glVertex3f(-34.0, 0.0, -85.0-h);
        glVertex3f(-34.0, 40.0, -85.0-h);
        glVertex3f(-38.0, 40.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-18.0, 0.0, -85.0-h);
        glVertex3f(-13.0, 0.0, -85.0-h);
        glVertex3f(-13.0, 40.0, -85.0-h);
        glVertex3f(-18.0, 40.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(17.0, 0.0, -85.0);
        glVertex3f(12.0, 0.0, -85.0);
        glVertex3f(12.0, 40.0, -85.0);
        glVertex3f(17.0, 40.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(17.0, 0.0, -90.0);
        glVertex3f(12.0, 0.0, -90.0);
        glVertex3f(12.0, 40.0, -90.0);
        glVertex3f(17.0, 40.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(35.0, 0.0, -85.0);
        glVertex3f(40.0, 0.0, -85.0);
        glVertex3f(40.0, 40.0, -85.0);
        glVertex3f(35.0, 40.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(35.0, 0.0, -90.0);
        glVertex3f(40.0, 0.0, -90.0);
        glVertex3f(40.0, 40.0, -90.0);
        glVertex3f(35.0, 40.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(62.0, 0.0, -85.0);
        glVertex3f(58.0, 0.0, -85.0);
        glVertex3f(58.0, 40.0, -85.0);
        glVertex3f(62.0, 40.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(62.0, 0.0, -90.0);
        glVertex3f(58.0, 0.0, -90.0);
        glVertex3f(58.0, 40.0, -90.0);
        glVertex3f(62.0, 40.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, 40.0, -85.0-h);
        glVertex3f(-49.0, 40.0, -85.0-h);
        glVertex3f(-49.0, 47.0, -85.0-h);
        glVertex3f(-57.0, 47.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-42.0, 40.0, -85.0-h);
        glVertex3f(-30.0, 40.0, -85.0-h);
        glVertex3f(-30.0, 47.0, -85.0-h);
        glVertex3f(-42.0, 47.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-23.0, 40.0, -85.0-h);
        glVertex3f(-10.0, 40.0, -85.0-h);
        glVertex3f(-10.0, 47.0, -85.0-h);
        glVertex3f(-23.0, 47.0, -85.0-h);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-3.0, 40.0, -85.0);
        glVertex3f(3.0, 40.0, -85.0);
        glVertex3f(3.0, 47.0, -85.0);
        glVertex3f(-3.0, 47.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-3.0, 40.0, -90.0);
        glVertex3f(3.0, 40.0, -90.0);
        glVertex3f(3.0, 47.0, -90.0);
        glVertex3f(-3.0, 47.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(10.0, 40.0, -85.0);
        glVertex3f(23.0, 40.0, -85.0);
        glVertex3f(23.0, 47.0, -85.0);
        glVertex3f(10.0, 47.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(10.0, 40.0, -90.0);
        glVertex3f(23.0, 40.0, -90.0);
        glVertex3f(23.0, 47.0, -90.0);
        glVertex3f(10.0, 47.0, -90.0);
        glEnd();


        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(30.0, 40.0, -85.0);
        glVertex3f(45.0, 40.0, -85.0);
        glVertex3f(45.0, 47.0, -85.0);
        glVertex3f(30.0, 47.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(30.0, 40.0, -90.0);
        glVertex3f(45.0, 40.0, -90.0);
        glVertex3f(45.0, 47.0, -90.0);
        glVertex3f(30.0, 47.0, -90.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(52.0, 40.0, -85.0);
        glVertex3f(62.0, 40.0, -85.0);
        glVertex3f(62.0, 47.0, -85.0);
        glVertex3f(52.0, 47.0, -85.0);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(52.0, 40.0, -90.0);
        glVertex3f(62.0, 40.0, -90.0);
        glVertex3f(62.0, 47.0, -90.0);
        glVertex3f(52.0, 47.0, -90.0);
        glEnd();
    }

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(12.0, -30.0, -85.0);
    glVertex3f(12.0, -30.0, -90.0);
    glVertex3f(12.0, 40.0, -90.0);
    glVertex3f(12.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(17.0, -30.0, -85.0);
    glVertex3f(17.0, -30.0, -90.0);
    glVertex3f(17.0, 40.0, -90.0);
    glVertex3f(17.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(35.0, -30.0, -85.0);
    glVertex3f(35.0, -30.0, -90.0);
    glVertex3f(35.0, 40.0, -90.0);
    glVertex3f(35.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(40.0, -30.0, -85.0);
    glVertex3f(40.0, -30.0, -90.0);
    glVertex3f(40.0, 40.0, -90.0);
    glVertex3f(40.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(58.0, -30.0, -85.0);
    glVertex3f(58.0, -30.0, -90.0);
    glVertex3f(58.0, 40.0, -90.0);
    glVertex3f(58.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-13.0, -30.0, -85.0);
    glVertex3f(-13.0, -30.0, -90.0);
    glVertex3f(-13.0, 40.0, -90.0);
    glVertex3f(-13.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-18.0, -30.0, -85.0);
    glVertex3f(-18.0, -30.0, -90.0);
    glVertex3f(-18.0, 40.0, -90.0);
    glVertex3f(-18.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-34.0, -30.0, -85.0);
    glVertex3f(-34.0, -30.0, -90.0);
    glVertex3f(-34.0, 40.0, -90.0);
    glVertex3f(-34.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-38.0, -30.0, -85.0);
    glVertex3f(-38.0, -30.0, -90.0);
    glVertex3f(-38.0, 40.0, -90.0);
    glVertex3f(-38.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-54.0, -30.0, -85.0);
    glVertex3f(-54.0, -30.0, -90.0);
    glVertex3f(-54.0, 40.0, -90.0);
    glVertex3f(-54.0, 40.0, -85.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 57.0, -85.0);
    glVertex3f(62.0, 57.0, -85.0);
    glVertex3f(62.0, 57.0, -90.0);
    glVertex3f(-57.0, 57.0, -90.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 47.0, -85.0);
    glVertex3f(62.0, 47.0, -85.0);
    glVertex3f(62.0, 47.0, -90.0);
    glVertex3f(-57.0, 47.0, -90.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 40.0, -85.0);
    glVertex3f(62.0, 40.0, -85.0);
    glVertex3f(62.0, 40.0, -90.0);
    glVertex3f(-57.0, 40.0, -90.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 35.0, -85.0);
    glVertex3f(62.0, 35.0, -85.0);
    glVertex3f(62.0, 35.0, -90.0);
    glVertex3f(-57.0, 35.0, -90.0);
    glEnd();

    //Pintu depan
    glColor3f(0.7, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-13.0, -27.0, -87.0);
    glVertex3f(12.0, -27.0, -87.0);
    glVertex3f(12.0, 35.0, -87.0);
    glVertex3f(-13.0, 35.0, -87.0);
    glEnd();

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-13.0, -27.0, -90.0);
    glVertex3f(12.0, -27.0, -90.0);
    glVertex3f(12.0, 35.0, -90.0);
    glVertex3f(-13.0, 35.0, -90.0);
    glEnd();

    for(int i=0; i<=62; i+=62){
        glColor3f(1.0, 0.5, 0.0);
        glBegin(GL_QUADS);
        glVertex3f(-13.0, -27.0+i, -87.0);
        glVertex3f(12.0, -27.0+i, -87.0);
        glVertex3f(12.0, -27.0+i, -90.0);
        glVertex3f(-13.0, -27.0+i, -90.0);
        glEnd();
    }

    for(int j=0; j<=25; j+=25){
        glColor3f(1.0, 0.5, 0.0);
        glBegin(GL_QUADS);
        glVertex3f(-13.0+j, -30.0, -90.0);
        glVertex3f(-13.0+j, -30.0, -87.0);
        glVertex3f(-13.0+j, 35.0, -87.0);
        glVertex3f(-13.0+j, 35.0, -90.0);
        glEnd();
    }

    //tembok kamar dalam
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -90.0);
    glVertex3f(-14.0, 57.0, -90.0);
    glVertex3f(-14.0, 57.0, -160.0);
    glVertex3f(-14.0, -30.0, -160.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, -30.0, -90.0);
    glVertex3f(-10.0, 57.0, -90.0);
    glVertex3f(-10.0, 57.0, -160.0);
    glVertex3f(-10.0, -30.0, -160.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, 35.0, -160.0);
    glVertex3f(-14.0, 57.0, -160.0);
    glVertex3f(-14.0, 57.0, -210.0);
    glVertex3f(-14.0, 35.0, -210.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 35.0, -160.0);
    glVertex3f(-10.0, 57.0, -160.0);
    glVertex3f(-10.0, 57.0, -210.0);
    glVertex3f(-10.0, 35.0, -210.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -190.0);
    glVertex3f(-14.0, 57.0, -190.0);
    glVertex3f(-14.0, 57.0, -230.0);
    glVertex3f(-14.0, -30.0, -230.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, -30.0, -190.0);
    glVertex3f(-10.0, 57.0, -190.0);
    glVertex3f(-10.0, 57.0, -230.0);
    glVertex3f(-10.0, -30.0, -230.0);
    glEnd();

    for(int j=0; j<=4; j+=4){
        //pintu kamar
        glColor3f(0.7, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex3f(-14.0+j, -30.0, -160.0);
        glVertex3f(-14.0+j, 35.0, -160.0);
        glVertex3f(-14.0+j, 35.0, -190.0);
        glVertex3f(-14.0+j, -30.0, -190.0);
        glEnd();
    }

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -230.0);
    glVertex3f(-14.0, 57.0, -230.0);
    glVertex3f(20.0, 57.0, -230.0);
    glVertex3f(20.0, -30.0, -230.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -226.0);
    glVertex3f(-14.0, 57.0, -226.0);
    glVertex3f(20.0, 57.0, -226.0);
    glVertex3f(20.0, -30.0, -226.0);
    glEnd();

    //tembok dapur sebelah kamar mandi
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -230.0);
    glVertex3f(-14.0, 57.0, -230.0);
    glVertex3f(-14.0, 57.0, -270.0);
    glVertex3f(-14.0, -30.0, -270.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-15.0, -30.0, -235.0);
    glVertex3f(-15.0, 57.0, -235.0);
    glVertex3f(-15.0, 57.0, -270.0);
    glVertex3f(-15.0, -30.0, -270.0);
    glEnd();

    //tembok kamar mandi
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -270.0);
    glVertex3f(-14.0, 57.0, -270.0);
    glVertex3f(-18.0, 57.0, -270.0);
    glVertex3f(-18.0, -30.0, -270.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-14.0, -30.0, -268.0);
    glVertex3f(-14.0, 57.0, -268.0);
    glVertex3f(-18.0, 57.0, -268.0);
    glVertex3f(-18.0, -30.0, -268.0);
    glEnd();

    for(int k=0; k>=-4; k-=4){
        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_QUADS);
        glVertex3f(-57.0, -30.0, -230.0+k);
        glVertex3f(-57.0, 57.0, -230.0+k);
        glVertex3f(-14.0, 57.0, -230.0+k);
        glVertex3f(-14.0, -30.0, -230.0+k);
        glEnd();
    }

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, -30.0, -270.0);
    glVertex3f(-57.0, 50.0, -270.0);
    glVertex3f(-36.0, 50.0, -270.0);
    glVertex3f(-36.0, -30.0, -270.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, -30.0, -268.0);
    glVertex3f(-57.0, 50.0, -268.0);
    glVertex3f(-36.0, 50.0, -268.0);
    glVertex3f(-36.0, -30.0, -268.0);
    glEnd();

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 50.0, -270.0);
    glVertex3f(-57.0, 57.0, -270.0);
    glVertex3f(-45.0, 57.0, -270.0);
    glVertex3f(-45.0, 50.0, -270.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-51.0, 50.0, -270.0);
    glVertex3f(-51.0, 57.0, -270.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 50.0, -268.0);
    glVertex3f(-57.0, 57.0, -268.0);
    glVertex3f(-45.0, 57.0, -268.0);
    glVertex3f(-45.0, 50.0, -268.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-45.0, 50.0, -268.0);
    glVertex3f(-45.0, 57.0, -268.0);
    glVertex3f(-36.0, 57.0, -268.0);
    glVertex3f(-36.0, 50.0, -268.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-45.0, 50.0, -270.0);
    glVertex3f(-45.0, 57.0, -270.0);
    glVertex3f(-36.0, 57.0, -270.0);
    glVertex3f(-36.0, 50.0, -270.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-36.0, 28.0, -270.0);
    glVertex3f(-36.0, 57.0, -270.0);
    glVertex3f(-18.0, 57.0, -270.0);
    glVertex3f(-18.0, 28.0, -270.0);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-36.0, 28.0, -268.0);
    glVertex3f(-36.0, 57.0, -268.0);
    glVertex3f(-18.0, 57.0, -268.0);
    glVertex3f(-18.0, 28.0, -268.0);
    glEnd();

    for(int p=0; p<=2; p+=2){
        //pintu kamar mandi
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex3f(-18.0, -30.0, -270.0+p);
        glVertex3f(-18.0, 28.0, -270.0+p);
        glVertex3f(-36.0, 28.0, -270.0+p);
        glVertex3f(-36.0, -30.0, -270.0+p);
        glEnd();
    }

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-36.0, 28.0, -268.0);
    glVertex3f(-18.0, 28.0, -268.0);
    glVertex3f(-18.0, 28.0, -270.0);
    glVertex3f(-36.0, 28.0, -270.0);
    glEnd();

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-36.0, 28.0, -268.0);
    glVertex3f(-36.0, -30.0, -268.0);
    glVertex3f(-36.0, -30.0, -270.0);
    glVertex3f(-36.0, 28.0, -270.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(20.0, -30.0, -226.0);
    glVertex3f(20.0, 57.0, -226.0);
    glVertex3f(20.0, 57.0, -230.0);
    glVertex3f(20.0, -30.0, -230.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(67.0, -30.0, -230.0);
    glVertex3f(67.0, -20.0, -230.0);
    glVertex3f(20.0, -20.0, -230.0);
    glVertex3f(20.0, -30.0, -230.0);
    glEnd();

    //tangga dalam
    for(int l=0; l<40; l+=10){
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex3f(-15.0-l, -10.0+l, -315.0);
        glVertex3f(-25.0-l, -10.0+l, -315.0);
        glVertex3f(-25.0-l, -10.0+l, -330.0);
        glVertex3f(-15.0-l, -10.0+l, -330.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-15.0-l, -10.0+l, -322.5);
        glVertex3f(-27.0-l, -10.0+l, -322.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex3f(-15.0-l, -10.0+l, -315.0);
        glVertex3f(-15.0-l, -20.0+l, -315.0);
        glVertex3f(-15.0-l, -20.0+l, -330.0);
        glVertex3f(-15.0-l, -10.0+l, -330.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-15.0-l, -10.0+l, -322.5);
        glVertex3f(-15.0-l, -20.0+l, -322.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.5, 0.0);
        glVertex3f(-15.0-l+10, -20.0+l-10, -315.0);
        glVertex3f(-15.0-l+10, -10.0+l-10, -315.0);
        glVertex3f(-25.0-l+10, -10.0+l-10, -315.0);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-45.0, 10.0, -315.0);
    glVertex3f(-45.0, 10.0, -330.0);
    glVertex3f(-15.0, -20.0, -330.0);
    glVertex3f(-15.0, -20.0, -315.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-45.0, 10.0, -315.0);
    glVertex3f(-45.0, 10.0, -330.0);
    glVertex3f(-57.0, 10.0, -330.0);
    glVertex3f(-57.0, 10.0, -315.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-57.0, 20.0, -315.0);
    glVertex3f(-57.0, 10.0, -315.0);
    glVertex3f(-45.0, 10.0, -315.0);
    glVertex3f(-45.0, 20.0, -315.0);
    glEnd();

    int n=0;
    for(int m=0; m<=30; m+=10){
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex3f(-45.0, 20.0+m, -315.0+n);
        glVertex3f(-57.0, 20.0+m, -315.0+n);
        glVertex3f(-57.0, 20.0+m, -330.0+n);
        glVertex3f(-45.0, 20.0+m, -330.0+n);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-51.0, 20.0+m, -315.0+n);
        glVertex3f(-51.0, 20.0+m, -330.0+n);
        glEnd();

        if(m>20){
            break;
        }else{
            glBegin(GL_POLYGON);
            glColor3f(1.0, 0.5, 0.0);
            glVertex3f(-45.0, 20.0+m, -315.0+n);
            glVertex3f(-57.0, 20.0+m, -315.0+n);
            glVertex3f(-57.0, 30.0+m, -315.0+n);
            glVertex3f(-45.0, 30.0+m, -315.0+n);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-51.0, 20.0+m, -315.0+n);
            glVertex3f(-51.0, 30.0+m, -315.0+n);
            glEnd();

            glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.5, 0.0);
            glVertex3f(-45.0, 30.0+m, -300.0+n);
            glVertex3f(-45.0, 30.0+m, -315.0+n);
            glVertex3f(-45.0, 20.0+m, -315.0+n);
            glEnd();

            n+=15;
        }
    }

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-45.0, 20.0, -315.0);
    glVertex3f(-57.0, 20.0, -315.0);
    glVertex3f(-57.0, 50.0, -270.0);
    glVertex3f(-45.0, 50.0, -270.0);
    glEnd();

    //kasur
    glBegin(GL_QUADS);
    glColor3f(1.0, 8.0, 0.0);
    glVertex3f(-49.0, -10.0, -92.0);
    glVertex3f(-19.0, -10.0, -92.0);
    glVertex3f(-19.0, -10.0, -132.0);
    glVertex3f(-49.0, -10.0, -132.0);
    glEnd();

    for(int s=0; s<=30; s+=30){
        glBegin(GL_QUADS);
        glColor3f(1.0, 8.0, 0.0);
        glVertex3f(-49.0+s, -10.0, -92.0);
        glVertex3f(-49.0+s, -27.0, -92.0);
        glVertex3f(-49.0+s, -27.0, -132.0);
        glVertex3f(-49.0+s, -10.0, -132.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 8.0, 0.0);
    glVertex3f(-49.0, 5.0, -92.0);
    glVertex3f(-19.0, 5.0, -92.0);
    glVertex3f(-19.0, -27.0, -92.0);
    glVertex3f(-49.0, -27.0, -92.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 8.0, 0.0);
    glVertex3f(-49.0, -10.0, -132.0);
    glVertex3f(-19.0, -10.0, -132.0);
    glVertex3f(-19.0, -27.0, -132.0);
    glVertex3f(-49.0, -27.0, -132.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-49.0, -9.0, -97.0);
    glVertex3f(-19.0, -9.0, -97.0);
    glVertex3f(-19.0, -9.0, -132.0);
    glVertex3f(-49.0, -9.0, -132.0);
    glEnd();

    for(int s=0; s<=30; s+=30){
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-49.0+s, -9.0, -97.0);
        glVertex3f(-49.0+s, -10.0, -97.0);
        glVertex3f(-49.0+s, -10.0, -132.0);
        glVertex3f(-49.0+s, -9.0, -132.0);
        glEnd();
    }

    for(int s=0; s<=35; s+=35){
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-49.0, -10.0, -97.0-s);
        glVertex3f(-19.0, -10.0, -97.0-s);
        glVertex3f(-19.0, -9.0, -97.0-s);
        glVertex3f(-49.0, -9.0, -97.0-s);
        glEnd();
    }

    //kursi ruang tamu
    int t1=0, t2=0, t3=0;
    for(int t=0; t<=1; t++){
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.5, 0.0);
        glVertex3f(43.0, -4.0, -150.0-t);
        glVertex3f(14.0, -4.0, -150.0-t);
        glVertex3f(14.0, -15.0, -150.0-t);
        glVertex3f(43.0, -15.0, -150.0-t);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(43.0, -4.0-t2, -150.0);
        glVertex3f(13.0, -4.0-t2, -150.0);
        glVertex3f(13.0, -4.0-t2, -151.0);
        glVertex3f(43.0, -4.0-t2, -151.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(13.0+t1, -4.0, -150.0);
        glVertex3f(13.0+t1, -27.0, -150.0);
        glVertex3f(13.0+t1, -27.0, -151.0);
        glVertex3f(13.0+t1, -4.0, -151.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(13.0, -9.0, -150.0);
        glVertex3f(13.0, -20.0, -150.0);
        glVertex3f(13.0, -20.0, -142.0);
        glVertex3f(13.0, -9.0, -142.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(43.0, -15.0, -150.0);
        glVertex3f(43.0, -20.0, -150.0);
        glVertex3f(43.0, -20.0, -142.0);
        glVertex3f(43.0, -15.0, -142.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(13.0, -15.0, -142.0);
        glVertex3f(13.0, -20.0, -142.0);
        glVertex3f(43.0, -20.0, -142.0);
        glVertex3f(43.0, -15.0, -142.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(14.0, -4.0, -150.0);
        glVertex3f(14.0, -27.0, -150.0);
        glVertex3f(13.0, -27.0, -150.0);
        glVertex3f(13.0, -4.0, -150.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(14.0, -9.0, -142.0);
        glVertex3f(14.0, -27.0, -142.0);
        glVertex3f(13.0, -27.0, -142.0);
        glVertex3f(13.0, -9.0, -142.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(43.0, -15.0, -150.0+t3);
        glVertex3f(43.0, -27.0, -150.0+t3);
        glVertex3f(42.0, -27.0, -150.0+t3);
        glVertex3f(42.0, -15.0, -150.0+t3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(13.0+t1, -15.0, -143.0);
        glVertex3f(13.0+t1, -27.0, -143.0);
        glVertex3f(13.0+t1, -27.0, -142.0);
        glVertex3f(13.0+t1, -15.0, -142.0);
        glEnd();

        t1+=30;
        t2+=11;
        t3+=8;
    }

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(43.0, -15.0, -150.0);
    glVertex3f(13.0, -15.0, -150.0);
    glVertex3f(13.0, -15.0, -142.0);
    glVertex3f(43.0, -15.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(14.0, -9.0, -150.0);
    glVertex3f(13.0, -9.0, -150.0);
    glVertex3f(13.0, -9.0, -142.0);
    glVertex3f(14.0, -9.0, -142.0);
    glEnd();

    //Kursi ruang tamu ke 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(43.5, -4.0, -150.0);
    glVertex3f(60.0, -4.0, -150.0);
    glVertex3f(60.0, -15.0, -150.0);
    glVertex3f(43.5, -15.0, -150.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(43.5, -4.0, -151.0);
    glVertex3f(60.0, -4.0, -151.0);
    glVertex3f(60.0, -15.0, -151.0);
    glVertex3f(43.5, -15.0, -151.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -4.0, -150.0);
    glVertex3f(60.0, -4.0, -150.0);
    glVertex3f(60.0, -4.0, -151.0);
    glVertex3f(43.5, -4.0, -151.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -4.0, -150.0);
    glVertex3f(43.5, -15.0, -150.0);
    glVertex3f(43.5, -15.0, -151.0);
    glVertex3f(43.5, -4.0, -151.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(60.0, -4.0, -150.0);
    glVertex3f(60.0, -4.0, -142.0);
    glVertex3f(60.0, -15.0, -142.0);
    glVertex3f(60.0, -15.0, -150.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(43.5, -15.0, -150.0);
    glVertex3f(60.0, -15.0, -150.0);
    glVertex3f(60.0, -15.0, -142.0);
    glVertex3f(43.5, -15.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -151.0);
    glVertex3f(60.0, -4.0, -142.0);
    glVertex3f(61.0, -4.0, -142.0);
    glVertex3f(61.0, -4.0, -151.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -150.0);
    glVertex3f(43.5, -20.0, -150.0);
    glVertex3f(43.5, -20.0, -142.0);
    glVertex3f(43.5, -15.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -15.0, -150.0);
    glVertex3f(60.0, -20.0, -150.0);
    glVertex3f(60.0, -20.0, -142.0);
    glVertex3f(60.0, -15.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -142.0);
    glVertex3f(43.5, -20.0, -142.0);
    glVertex3f(60.0, -20.0, -142.0);
    glVertex3f(60.0, -15.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -150.0);
    glVertex3f(60.0, -30.0, -150.0);
    glVertex3f(61.0, -30.0, -150.0);
    glVertex3f(61.0, -4.0, -150.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -4.0, -142.0);
    glVertex3f(43.5, -30.0, -142.0);
    glVertex3f(43.5, -30.0, -142.0);
    glVertex3f(43.5, -4.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -150.0);
    glVertex3f(43.5, -30.0, -150.0);
    glVertex3f(44.5, -30.0, -150.0);
    glVertex3f(44.5, -15.0, -150.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -142.0);
    glVertex3f(43.5, -30.0, -142.0);
    glVertex3f(44.5, -30.0, -142.0);
    glVertex3f(44.5, -15.0, -142.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -20.0, -142.0);
    glVertex3f(43.5, -30.0, -142.0);
    glVertex3f(43.5, -30.0, -143.0);
    glVertex3f(43.5, -20.0, -143.0);
    glEnd();

    //Kursi ruang tamu ke 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(60.0, -4.0, -127.0);
    glVertex3f(60.0, -4.0, -141.5);
    glVertex3f(60.0, -15.0, -141.5);
    glVertex3f(60.0, -15.0, -127.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(43.5, -15.0, -127.0);
    glVertex3f(60.0, -15.0, -127.0);
    glVertex3f(60.0, -15.0, -141.5);
    glVertex3f(43.5, -15.0, -141.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -127.0);
    glVertex3f(60.0, -4.0, -141.5);
    glVertex3f(61.0, -4.0, -141.5);
    glVertex3f(61.0, -4.0, -127.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -141.5);
    glVertex3f(43.5, -20.0, -141.5);
    glVertex3f(60.0, -20.0, -141.5);
    glVertex3f(60.0, -15.0, -141.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -127.0);
    glVertex3f(43.5, -20.0, -127.0);
    glVertex3f(60.0, -20.0, -127.0);
    glVertex3f(60.0, -15.0, -127.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -141.5);
    glVertex3f(43.5, -20.0, -141.5);
    glVertex3f(43.5, -20.0, -127.0);
    glVertex3f(43.5, -15.0, -127.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -141.5);
    glVertex3f(60.0, -30.0, -141.5);
    glVertex3f(61.0, -30.0, -141.5);
    glVertex3f(61.0, -4.0, -141.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -127.0);
    glVertex3f(60.0, -30.0, -127.0);
    glVertex3f(61.0, -30.0, -127.0);
    glVertex3f(61.0, -4.0, -127.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -20.0, -140.5);
    glVertex3f(43.5, -30.0, -140.5);
    glVertex3f(43.5, -30.0, -141.5);
    glVertex3f(43.5, -20.0, -141.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -20.0, -128.0);
    glVertex3f(43.5, -30.0, -128.0);
    glVertex3f(43.5, -30.0, -127.0);
    glVertex3f(43.5, -20.0, -127.0);
    glEnd();

    //Kursi ruang tamu ke 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(60.0, -4.0, -94.0);
    glVertex3f(60.0, -4.0, -126.5);
    glVertex3f(60.0, -15.0, -126.5);
    glVertex3f(60.0, -15.0, -94.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(43.5, -15.0, -94.0);
    glVertex3f(60.0, -15.0, -94.0);
    glVertex3f(60.0, -15.0, -126.5);
    glVertex3f(43.5, -15.0, -126.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -9.0, -94.0);
    glVertex3f(60.0, -9.0, -94.0);
    glVertex3f(60.0, -15.0, -94.0);
    glVertex3f(43.5, -15.0, -94.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -126.5);
    glVertex3f(60.0, -4.0, -94.0);
    glVertex3f(61.0, -4.0, -94.0);
    glVertex3f(61.0, -4.0, -126.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -126.5);
    glVertex3f(43.5, -20.0, -126.5);
    glVertex3f(60.0, -20.0, -126.5);
    glVertex3f(60.0, -15.0, -126.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -94.0);
    glVertex3f(43.5, -20.0, -94.0);
    glVertex3f(60.0, -20.0, -94.0);
    glVertex3f(60.0, -15.0, -94.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -15.0, -126.5);
    glVertex3f(43.5, -20.0, -126.5);
    glVertex3f(43.5, -20.0, -94.0);
    glVertex3f(43.5, -15.0, -94.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -126.5);
    glVertex3f(60.0, -30.0, -126.5);
    glVertex3f(61.0, -30.0, -126.5);
    glVertex3f(61.0, -4.0, -126.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(60.0, -4.0, -94.0);
    glVertex3f(60.0, -30.0, -94.0);
    glVertex3f(61.0, -30.0, -94.0);
    glVertex3f(61.0, -4.0, -94.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -20.0, -126.5);
    glVertex3f(43.5, -30.0, -126.5);
    glVertex3f(43.5, -30.0, -125.5);
    glVertex3f(43.5, -20.0, -125.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(43.5, -20.0, -94.0);
    glVertex3f(43.5, -30.0, -94.0);
    glVertex3f(43.5, -30.0, -95.0);
    glVertex3f(43.5, -20.0, -95.0);
    glEnd();

    //Meja
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(34.0, -15.0, -132.0);
    glVertex3f(15.0, -15.0, -132.0);
    glVertex3f(15.0, -15.0, -103.0);
    glVertex3f(34.0, -15.0, -103.0);
    glEnd();

    int u1=0;
    for (int u=0; u<=19; u+=19){
        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(15.0+u, -15.0, -132.0);
        glVertex3f(15.0+u, -15.0, -103.0);
        glVertex3f(15.0+u, -23.0, -103.0);
        glVertex3f(15.0+u, -23.0, -132.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(15.0+u, -23.0, -132.0);
        glVertex3f(15.0+u, -23.0, -131.0);
        glVertex3f(15.0+u, -30.0, -131.0);
        glVertex3f(15.0+u, -30.0, -132.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(15.0+u, -23.0, -103.0);
        glVertex3f(15.0+u, -23.0, -104.0);
        glVertex3f(15.0+u, -30.0, -104.0);
        glVertex3f(15.0+u, -30.0, -103.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(34.0, -15.0, -103.0-u1);
        glVertex3f(15.0, -15.0, -103.0-u1);
        glVertex3f(15.0, -23.0, -103.0-u1);
        glVertex3f(34.0, -23.0, -103.0-u1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(16.0, -23.0, -103.0-u1);
        glVertex3f(15.0, -23.0, -103.0-u1);
        glVertex3f(15.0, -30.0, -103.0-u1);
        glVertex3f(16.0, -30.0, -103.0-u1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(34.0, -23.0, -103.0-u1);
        glVertex3f(33.0, -23.0, -103.0-u1);
        glVertex3f(33.0, -30.0, -103.0-u1);
        glVertex3f(34.0, -30.0, -103.0-u1);
        glEnd();

        u1+=29;
    }

    //Tembok Kamar atas
    for(int x=0; x<=129; x+=129){
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(67.0-x, 57.0, -230.0);
        glVertex3f(67.0-x, 57.0, -335.0);
        glVertex3f(67.0-x, 140.0, -335.0);
        glVertex3f(67.0-x, 140.0, -230.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(62.0, 57.0, -230.0);
    glVertex3f(62.0, 57.0, -335.0);
    glVertex3f(62.0, 140.0, -335.0);
    glVertex3f(62.0, 140.0, -230.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(67.0, 57.0, -335.0);
    glVertex3f(67.0, 140.0, -335.0);
    glVertex3f(-62.0, 140.0, -335.0);
    glVertex3f(-62.0, 57.0, -335.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(67.0, 57.0, -330.0);
    glVertex3f(67.0, 140.0, -330.0);
    glVertex3f(-15.0, 140.0, -330.0);
    glVertex3f(-15.0, 57.0, -330.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(67.0, 57.0, -235.0);
    glVertex3f(67.0, 140.0, -235.0);
    glVertex3f(15.0, 140.0, -235.0);
    glVertex3f(15.0, 57.0, -235.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-15.0, 57.0, -235.0);
    glVertex3f(-15.0, 140.0, -235.0);
    glVertex3f(-5.0, 140.0, -235.0);
    glVertex3f(-5.0, 57.0, -235.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(15.0, 57.0, -235.0);
    glVertex3f(15.0, 100.0, -235.0);
    glVertex3f(-5.0, 100.0, -235.0);
    glVertex3f(-5.0, 57.0, -235.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(15.0, 140.0, -235.0);
    glVertex3f(15.0, 125.0, -235.0);
    glVertex3f(-5.0, 125.0, -235.0);
    glVertex3f(-5.0, 140.0, -235.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(67.0, 57.0, -230.0);
    glVertex3f(67.0, 140.0, -230.0);
    glVertex3f(15.0, 140.0, -230.0);
    glVertex3f(15.0, 57.0, -230.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-15.0, 57.0, -230.0);
    glVertex3f(-15.0, 140.0, -230.0);
    glVertex3f(-5.0, 140.0, -230.0);
    glVertex3f(-5.0, 57.0, -230.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(15.0, 57.0, -230.0);
    glVertex3f(15.0, 100.0, -230.0);
    glVertex3f(-5.0, 100.0, -230.0);
    glVertex3f(-5.0, 57.0, -230.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(15.0, 140.0, -230.0);
    glVertex3f(15.0, 125.0, -230.0);
    glVertex3f(-5.0, 125.0, -230.0);
    glVertex3f(-5.0, 140.0, -230.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-15.0, 140.0, -330.0);
    glVertex3f(-15.0, 57.0, -330.0);
    glVertex3f(-15.0, 57.0, -270.0);
    glVertex3f(-15.0, 140.0, -270.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-15.0, 140.0, -245.0);
    glVertex3f(-15.0, 57.0, -245.0);
    glVertex3f(-15.0, 57.0, -230.0);
    glVertex3f(-15.0, 140.0, -230.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.5, 1.0);
    glVertex3f(-15.0, 140.0, -245.0);
    glVertex3f(-15.0, 100.0, -245.0);
    glVertex3f(-15.0, 100.0, -270.0);
    glVertex3f(-15.0, 140.0, -270.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-15.0, 57.0, -245.0);
    glVertex3f(-15.0, 100.0, -245.0);
    glVertex3f(-15.0, 100.0, -270.0);
    glVertex3f(-15.0, 57.0, -270.0);
    glEnd();

    //atap kamar atas
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-62.0, 140.0, -335.0);
    glVertex3f(67.0, 140.0, -335.0);
    glVertex3f(67.0, 140.0, -220.0);
    glVertex3f(-62.0, 140.0, -220.0);
    glEnd();

    //tembok kiri atas
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-62.0, 100.0, -85.0);
    glVertex3f(-62.0, 57.0, -85.0);
    glVertex3f(-62.0, 57.0, -230.0);
    glVertex3f(-62.0, 100.0, -230.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-57.0, 100.0, -85.0);
    glVertex3f(-57.0, 57.0, -85.0);
    glVertex3f(-57.0, 57.0, -230.0);
    glVertex3f(-57.0, 100.0, -230.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-15.0, 100.0, -85.0);
    glVertex3f(-15.0, 57.0, -85.0);
    glVertex3f(-15.0, 57.0, -90.0);
    glVertex3f(-15.0, 100.0, -90.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 100.0, -85.0);
    glVertex3f(-10.0, 57.0, -85.0);
    glVertex3f(-10.0, 57.0, -90.0);
    glVertex3f(-10.0, 100.0, -90.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-62.0, 100.0, -85.0);
    glVertex3f(-62.0, 57.0, -85.0);
    glVertex3f(-57.0, 57.0, -85.0);
    glVertex3f(-57.0, 100.0, -85.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-62.0, 100.0, -85.0);
    glVertex3f(-62.0, 100.0, -230.0);
    glVertex3f(-57.0, 100.0, -230.0);
    glVertex3f(-57.0, 100.0, -85.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-62.0, 100.0, -230.0);
    glVertex3f(-62.0, 140.0, -230.0);
    glVertex3f(-57.0, 140.0, -230.0);
    glVertex3f(-57.0, 100.0, -230.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 70.0, -85.0);
    glVertex3f(67.0, 57.0, -85.0);
    glVertex3f(67.0, 57.0, -230.0);
    glVertex3f(67.0, 70.0, -230.0);
    glEnd();

    //tembok depan pagar atas
    for(int y1=0; y1<=5; y1+=5){
        glColor3f(0.8, 0.8, 0.8);
        glBegin(GL_QUADS);
        glVertex3f(67.0, 57.0, -85.0-y1);
        glVertex3f(67.0, 70.0, -85.0-y1);
        glVertex3f(-57.0, 70.0, -85.0-y1);
        glVertex3f(-57.0, 57.0, -85.0-y1);
        glEnd();

        glColor3f(0.8, 0.8, 0.8);
        glBegin(GL_QUADS);
        glVertex3f(-10.0, 100.0, -85.0-y1);
        glVertex3f(-10.0, 57.0, -85.0-y1);
        glVertex3f(-15.0, 57.0, -85.0-y1);
        glVertex3f(-15.0, 100.0, -85.0-y1);
        glEnd();
    }

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 70.0, -85.0);
    glVertex3f(67.0, 70.0, -90.0);
    glVertex3f(-57.0, 70.0, -90.0);
    glVertex3f(-57.0, 70.0, -85.0);
    glEnd();

    for(int y2=0; y2<=30; y2+=5){
        //pagar atas
        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_LINES);
        glVertex3f(-13.0, 98.0-y2, -87.0);
        glVertex3f(-62.0, 98.0-y2, -87.0);
        glEnd();

        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_LINES);
        glVertex3f(-51.0+y2, 98.0, -87.0);
        glVertex3f(-51.0+y2, 57.0, -87.0);
        glEnd();
    }

    //tembok atap ruang tamu
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-10.0, 70.0, -77.0);
    glVertex3f(-10.0, 70.0, -157.5);
    glVertex3f(-10.0, 120.0, -157.5);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 70.0, -77.0);
    glVertex3f(67.0, 120.0, -157.5);
    glVertex3f(-10.0, 120.0, -157.5);
    glVertex3f(-10.0, 70.0, -77.0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 70.0, -230.0);
    glVertex3f(67.0, 120.0, -157.5);
    glVertex3f(-5.0, 120.0, -157.5);
    glVertex3f(-5.0, 70.0, -230.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-5.0, 70.0, -230.0);
    glVertex3f(-5.0, 120.0, -230.0);
    glVertex3f(-5.0, 120.0, -157.5);
    glVertex3f(-5.0, 70.0, -157.5);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 70.0, -230.0);
    glVertex3f(-10.0, 120.0, -230.0);
    glVertex3f(-10.0, 120.0, -157.5);
    glVertex3f(-10.0, 70.0, -157.5);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 70.0, -230.0);
    glVertex3f(-10.0, 57.0, -230.0);
    glVertex3f(-10.0, 57.0, -85.0);
    glVertex3f(-10.0, 70.0, -85.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-5.0, 120.0, -157.5);
    glVertex3f(-5.0, 120.0, -230.0);
    glVertex3f(-10.0, 120.0, -230.0);
    glVertex3f(-10.0, 120.0, -157.5);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(67.0, 70.0, -77.0);
    glVertex3f(67.0, 70.0, -230.0);
    glVertex3f(67.0, 120.0, -157.5);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(67.0, 70.0, -77.0);
    glVertex3f(67.0, 70.0, -85.0);
    glVertex3f(-10.0, 70.0, -85.0);
    glVertex3f(-10.0, 70.0, -77.0);
    glEnd();


    //atap teras
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-62.0, 57.0, -85.0);
    glVertex3f(67.0, 57.0, -85.0);
    glVertex3f(67.0, 57.0, 10.0);
    glVertex3f(-62.0, 57.0, 10.0);
    glEnd();

    //pilar atap teras
    for(int z=0; z<=5; z+=5){
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-62.0, 57.0, -20.0-z);
        glVertex3f(67.0, 57.0, -20.0-z);
        glVertex3f(67.0, 52.0, -20.0-z);
        glVertex3f(-62.0, 52.0, -20.0-z);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-62.0, 52.0, -20.0);
        glVertex3f(67.0, 52.0, -20.0);
        glVertex3f(67.0, 52.0, -25.0);
        glVertex3f(-62.0, 52.0, -25.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-62.0, 57.0, -50.0-z);
        glVertex3f(67.0, 57.0, -50.0-z);
        glVertex3f(67.0, 52.0, -50.0-z);
        glVertex3f(-62.0, 52.0, -50.0-z);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(10.0, 52.0, -85.0);
        glVertex3f(15.0, 52.0, -85.0);
        glVertex3f(15.0, 52.0, 10.0);
        glVertex3f(10.0, 52.0, 10.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(10.0, 48.0, -85.0);
        glVertex3f(15.0, 48.0, -85.0);
        glVertex3f(15.0, 48.0, 10.0);
        glVertex3f(10.0, 48.0, 10.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(10.0, 52.0, -85.0);
        glVertex3f(10.0, 48.0, -85.0);
        glVertex3f(10.0, 48.0, 10.0);
        glVertex3f(10.0, 52.0, 10.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(15.0, 52.0, -85.0);
        glVertex3f(15.0, 48.0, -85.0);
        glVertex3f(15.0, 48.0, 10.0);
        glVertex3f(15.0, 52.0, 10.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(10.0, 52.0, 10.0);
        glVertex3f(10.0, 48.0, 10.0);
        glVertex3f(15.0, 48.0, 10.0);
        glVertex3f(15.0, 52.0, 10.0);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(12.0, 10.0, 7.0);
    glVertex3f(12.0, 48.0, 7.0);
    glVertex3f(14.0, 48.0, 7.0);
    glVertex3f(14.0, 10.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(12.0, 10.0, 5.0);
    glVertex3f(12.0, 48.0, 5.0);
    glVertex3f(14.0, 48.0, 5.0);
    glVertex3f(14.0, 10.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(12.0, 10.0, 5.0);
    glVertex3f(12.0, 48.0, 5.0);
    glVertex3f(12.0, 48.0, 7.0);
    glVertex3f(12.0, 10.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(14.0, 10.0, 5.0);
    glVertex3f(14.0, 48.0, 5.0);
    glVertex3f(14.0, 48.0, 7.0);
    glVertex3f(14.0, 10.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-62.0, 52.0, -50.0);
    glVertex3f(67.0, 52.0, -50.0);
    glVertex3f(67.0, 52.0, -55.0);
    glVertex3f(-62.0, 52.0, -55.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-55.0, 0.0, -90.0);
    glVertex3f(-15.0, 0.0, -90.0);
    glVertex3f(-15.0, 0.0, -85.0);
    glVertex3f(-55.0, 0.0, -85.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(60.0, 0.0, -90.0);
    glVertex3f(15.0, 0.0, -90.0);
    glVertex3f(15.0, 0.0, -85.0);
    glVertex3f(60.0, 0.0, -85.0);
    glEnd();

    //Jendela bawah
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-55.0, 40.0, -88.0);
    glVertex3f(-37.0, 40.0, -88.0);
    glVertex3f(-37.0, 0.0, -88.0);
    glVertex3f(-55.0, 0.0, -88.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-35.0, 40.0, -88.0);
    glVertex3f(-17.0, 40.0, -88.0);
    glVertex3f(-17.0, 0.0, -88.0);
    glVertex3f(-35.0, 0.0, -88.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(35.0, 40.0, -88.0);
    glVertex3f(17.0, 40.0, -88.0);
    glVertex3f(17.0, 0.0, -88.0);
    glVertex3f(35.0, 0.0, -88.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(58.0, 40.0, -88.0);
    glVertex3f(37.0, 40.0, -88.0);
    glVertex3f(37.0, 0.0, -88.0);
    glVertex3f(58.0, 0.0, -88.0);
    glEnd();

    //jendela atas
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-7.0, 130.0, -232.0);
    glVertex3f(15.0, 130.0, -232.0);
    glVertex3f(15.0, 100.0, -232.0);
    glVertex3f(-7.0, 100.0, -232.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
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
            if(is_depth){
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }else{
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, lebar/tinggi, 5.0, 800.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if (mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
