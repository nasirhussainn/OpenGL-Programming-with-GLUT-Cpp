#include<GL/glut.h>
#include<GL/gl.h>
#include<cmath>

GLint screenWidth = 480, screeHeight = 640;

class GLintPoint {
public:
	GLint x, y;
};

int random(int m) {
	return rand() % m;
}

void drawDot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Sierpinski(void) {
	GLintPoint T[3] = { {10,10},{300,30},{200,300} };
	int index = random(3);
	GLintPoint point = T[index];
	drawDot (point.x, point.y);
	for (int i = 0; i < 5000; i++) {
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();

}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glPointSize(2.0);
	glLoadIdentity();
	glLineWidth(5.0);
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screeHeight);
}

void mydisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	Sierpinski();
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
