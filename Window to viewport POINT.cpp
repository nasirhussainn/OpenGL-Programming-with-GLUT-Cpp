#include<math.h>
#include<GL/glut.h>
#include<GL/GL.h>

const int screenWidth = 640;
const int screenHeight = 480;

GLdouble A, B, C, D;

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (GLdouble x = 0; x < 4.0; x += 0.0005) {
		GLdouble func = exp(-x) * cos(2 * 3.14159265 * x);
		//setter(x, func);
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
