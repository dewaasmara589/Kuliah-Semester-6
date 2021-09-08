#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#define RATIO 1.200

#define WW 100
#define WH (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001

int WindowWidth;
int WindowHeight;

void Display(){
    glLineWidth(4.0);
    float StartShape[14][2] = {
        {-10, -20}, {-10, 20}, {5, 20}, {10, 10}, {10, -10}, {5, -20}, {-10, -20},
        {-5, -12}, {-5, 12}, {0, 12}, {4, 5}, {4, -5}, {0, -12}, {-5, -12}
        };

    float EndShape[14][2] = {
        {0, -12}, {0, 12}, {-8, 12}, {0, 20}, {7, 20}, {7, -12}, {15, -12},
        {15, -18}, {-8, -18}, {-8, -12}, {0, -12}
        };

    float IntermediateShape[14][2];

    float VertexColors[14][3] = {
        {1,0,0},{1,1,0},{1,0,1},{0,1,0},{0,1,1},{0,0,1},{1,0.5,0},
        {1,0,0.5},{0.5,1,0},{0.5,0,1},{1,0,0.5},{0,1,0.5},{1.0,0.5,0},{1,0,0}
        };

    static float Tween = 0.0 - deltat;

    if(Tween<1){
        Tween += deltat;
    }

    for(int Vtx=0; Vtx<14; Vtx++){
        IntermediateShape[Vtx][0] = (1.0 - Tween)*StartShape[Vtx][0] + Tween*EndShape[Vtx][0];
        IntermediateShape[Vtx][1] = (1.0 - Tween)*StartShape[Vtx][1] + Tween*EndShape[Vtx][1];
    }

    glVertexPointer(2, GL_FLOAT, 0, IntermediateShape);
    glColorPointer(3, GL_FLOAT, 0, VertexColors);

    for(int i=0; i<1000000; i++);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_LINE_LOOP, 0, 14);
        glutSwapBuffers();
        glutPostRedisplay();
}

void InitGL(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-HALFX, HALFX, -HALFY, HALFY);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0);

    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glViewport(0, 0, WindowWidth, WindowHeight);
}

void Reshape(int w, int h){
    glutReshapeWindow(w, (int)(w/RATIO));
    WindowWidth = w;
    WindowHeight = (int)(w/RATIO);
    InitGL();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
    WindowHeight = (int)(WindowWidth/RATIO);

    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1), (glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2) - (WindowHeight/2));

    glutCreateWindow("Dewa Asmara Putra - 672019124");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    InitGL();
    glutMainLoop();

    return 0;
}
