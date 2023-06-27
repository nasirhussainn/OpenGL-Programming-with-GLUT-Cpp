#include<GL/glut.h>
#include<GL/gl.h>

GLint screenWidth = 480, screeHeight = 640;

void myInit(void) {
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glPointSize(12.0);
	glLoadIdentity();
	glLineWidth(5.0);
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screeHeight);
}

void mydisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2d(289, 190);
	glVertex2d(320, 128);
	glVertex2d(194, 101);
	glVertex2d(129, 83);
	glVertex2d(75, 73);
	glVertex2d(74, 74);
	glVertex2d(20, 10);
	glEnd();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(screenWidth, screeHeight);
	glutCreateWindow("prac");
	glutInitDisplayMode(GLUT_SINGLE | GL_RGB);
	glutDisplayFunc(mydisplay);
	myInit();
	glutMainLoop();

}
