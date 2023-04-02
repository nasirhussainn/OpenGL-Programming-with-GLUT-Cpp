#include<GL/glut.h>

void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Roof of house ->Triangle 
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1);
	glVertex2i(400, 600);
	glVertex2i(600, 400);
	glVertex2i(200, 400);
	glEnd();

	glLineWidth(2.5f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(400, 600);
	glVertex2i(600, 400);
	glVertex2i(200, 400);
	glEnd();
	

	//Wall of house
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0); 
	glVertex2i(250, 200); 
	glVertex2i(550, 200); 
	glVertex2i(550, 400); 
	glVertex2i(250, 400); 
	glEnd();

	glLineWidth(2.5f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(250, 200);
	glVertex2i(550, 200);
	glVertex2i(550, 400);
	glVertex2i(250, 400);
	glEnd();

	//Door of house
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0); 
	glVertex2i(270, 202); 
	glVertex2i(350, 202);  
	glVertex2i(350, 350);  
	glVertex2i(270, 350); 
	glEnd();
	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); 
	glVertex2i(270, 202); 
	glVertex2i(350, 202); 
	glVertex2i(350, 350); 
	glVertex2i(270, 350); 
	glEnd();
	
	//DoorWindow of house
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1); 
	glVertex2i(268, 360); 
	glVertex2i(352, 360); 
	glVertex2i(352, 380); 
	glVertex2i(268, 380); 
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2i(268, 360); 
	glVertex2i(352, 360); 
	glVertex2i(352, 380); 
	glVertex2i(268, 380); 
	glEnd();

	//window cover
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(410, 335);
	glVertex2i(480, 335);
	glVertex2i(480, 345);
	glVertex2i(410, 345);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2i(410, 335);
	glVertex2i(480, 335);
	glVertex2i(480, 345);
	glVertex2i(410, 345);
	glEnd();

	//Windows of house
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1); 
	glVertex2i(410, 260); 
	glVertex2i(480, 260); 
	glVertex2i(480, 330);
	glVertex2i(410, 330); 
	glEnd();


	glLineWidth(2.0f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); 
	glVertex2i(410, 260); 
	glVertex2i(480, 260); 
	glVertex2i(480, 330); 
	glVertex2i(410, 330); 
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0); 
	glVertex2f((410 + 480)/2, 260); //vertical line - as bottom-(right and left) corners divide by 2 to get center.
	glVertex2f((410 + 480) / 2, 330);
	glVertex2f(410, (260 + 330)/2); //horizontal line - as left-(bottom and top) corners divide by 2 to get center.
	glVertex2f(480, (260 + 330) / 2);
	glEnd();
	
	

	glFlush();
}

void myInit(void) {
	glClearColor(0, 1, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
}

int main(int argc,char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(200,100);
	glutCreateWindow("OpenGL House Hut");
	glutDisplayFunc(mydisplay);
	myInit();
	glutMainLoop();

}