#include <GL/glut.h>
#include <GL/gl.h>
#include <cmath>
#include <fstream>
#include <string> // Include the <string> header for string operations
using namespace std;

GLint screenWidth = 780, screenHeight = 640;

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glPointSize(2.0);
	glLoadIdentity();
	glLineWidth(2.0);
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawPolyLineFile(const char* fileName) {
	ifstream in(fileName); // Use ifstream instead of fstream for input operations
	if (!in.is_open()) {
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT);

	GLint numPolys, numLines, x, y;
	in >> numPolys;

	for (int i = 0; i < numPolys; i++) {
		in >> numLines;
		glBegin(GL_LINE_STRIP);

		for (int j = 0; j < numLines; j++) {
			in >> x >> y;
			glVertex2d(x, y);
		}

		glEnd();
	}

	glFlush();
	in.close();
}

void mydisplay(const char* fileName) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLineFile(fileName);
	glFlush();
}

void displayWrapper() {
	mydisplay("dino.dat");
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("prac");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutDisplayFunc(displayWrapper); // Call the wrapper function
	myInit();
	glutMainLoop();
	return 0;
}
