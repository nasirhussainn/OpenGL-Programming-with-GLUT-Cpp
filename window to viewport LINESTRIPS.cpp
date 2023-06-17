#include<math.h>
#include<GL/glut.h>
#include<GL/GL.h>
#include<iostream>
using namespace std;

const int screenWidth = 640;
const int screenHeight = 480;

GLdouble A, B, C, D,maxi,mini;

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	A = 1.0;
	B = 0.0;
	//C = screenHeight / 436.0;
	//D = 0.0;
	maxi = 0.0;
	mini = 0.0;


}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for (GLdouble x = 0; x < 100.0; x += 3) {
		GLdouble x1 = 100 * cos((2 * 3.14159265 * x)/100);
		GLdouble x2 = 30 * cos((4 * 3.14159265 * x) / 100);
		GLdouble x3 = 6 * cos((6 * 3.14159265 * x) / 100);
		GLdouble func = 300 - x1 + x2 + x3;
		if (func > maxi || func==0) {
			maxi = func;
		}
		if (func < mini || func == 0) {
			mini = func;
		}


		double func_min = 300 - 100 - 30 - 6;  // Minimum value of func
		double func_max = 300 + 100 + 30 + 6;  // Maximum value of func

		// Calculate the scaling factor for the y-axis
		C = (maxi - mini) / (func_max - func_min);

		// Calculate the translation factor for the y-axis
		D = mini - func_min * C;
		glVertex2d(A * x + B, C * func + D);
	}
	glEnd();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	//glutInitWindowPosition(100, 1150);
	glutCreateWindow("dot plot function");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
