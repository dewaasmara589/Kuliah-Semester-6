#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
 	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 400.0);
}


class GLintPoint
{
public:
		GLint x, y;
};


class Point2
{
public:
	float x,y;
	void set(float dx,float dy)
	{
		x = dx;
		y = dy;
	}
	void set(Point2 &p)
	{
		x = p.x;
		y = p.y;
	}
	Point2(float xx,float yy)
	{
		x = xx;
		y = yy;
	}
	Point2()
	{
		x = y = 0;
	}
};


GLintPoint CP;


float lerp (float a, float b, float t)
{
	return a + (b - a) *t;
}


Point2 Tween(Point2 A, Point2 B ,float t)
	{
		Point2 P;
		P.x = lerp(A.x,B.x,t);
		P.y = lerp(A.y,B.y,t);
		return P;
	}


void moveTo(GLint x ,GLint y)
{
	CP.x = x; CP.y = y;
}


void lineTo(GLint x ,GLint y)
{
	glBegin (GL_LINES);
	glVertex2i(CP.x,CP.y);
	glVertex2i(x,y);
	glEnd();
	glutSwapBuffers();
	CP.x = x; CP.y = y;
}


void drawTween (Point2 A[], Point2 B[], int n, float t)
{
     for (int i = 0; i < n; i++)
     {
        Point2 P;
        P = Tween (A[i], B[i], t);
        if (i == 0) moveTo (P.x, P.y);
        else lineTo (P.x, P.y);
       }
}


void myDisplay(void)
{
	int x;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);

	Point2 A[29];
		A [0].set(50,110);
		A [1].set(70,110);
		A [2].set(70,140);
		A [3].set(80,140);
		A [4].set(80,110);
		A [5].set(100,110);
		A [6].set(100,140);
		A [7].set(110,140);
		A [8].set(110,180);
		A [9].set(120,180);
		A [10].set(120,150);
		A [11].set(135,150);
		A [12].set(135,195);
		A [13].set(90,195);
		A [14].set(90,210);
		A [15].set(115,210);
		A [16].set(115,255);
		A [17].set(35,255);
		A [18].set(35,210);
		A [19].set(60,210);
		A [20].set(60,195);
		A [21].set(15,195);
		A [22].set(15,150);
		A [23].set(30,150);
		A [24].set(30,180);
		A [25].set(40,180);
        A [26].set(40,140);
        A [27].set(50,140);
        A [28].set(50,110);

	Point2 B[29];
		B [0].set(675,110);
		B [1].set(705,110);
		B [2].set(710,100);
		B [3].set(765,100);
		B [4].set(770,110);
		B [5].set(795,110);
		B [6].set(795,110);
		B [7].set(795,110);
		B [8].set(795,140);
		B [9].set(795,170);
		B [10].set(795,200);
		B [11].set(780,200);
		B [12].set(765,200);
		B [13].set(765,210);
		B [14].set(755,210);
		B [15].set(775,235);
		B [16].set(770,240);
		B [17].set(745,210);
		B [18].set(730,210);
		B [19].set(710,240);
		B [20].set(705,235);
		B [21].set(720,210);
		B [22].set(710,210);
		B [23].set(710,200);
        B [24].set(685,200);
		B [25].set(675,200);
        B [26].set(675,170);
        B [27].set(675,140);
        B [28].set(675,110);

	glColor3f(1,0,0);
	drawTween(A,B,29,0.0);

	glColor3f(0,0,1);
	for(x=1;x<=5;x+=1)
	{
		drawTween(A,B,29,0.2*x);
	}

	glColor3f(1,0,0);
	drawTween(A,B,29,1);

	glFlush();
	glutSwapBuffers();
}

main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(800,400);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Robot menjadi TV");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
