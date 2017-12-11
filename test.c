#include <gl/glut.h>
void display() {
	//glPointSize(5.0f); 
	glBegin(GL_LINE_STRIP); 
	glVertex2f(-0.5f, 0.5f); 
	glVertex2f(0.5f, 0.5f); 
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
	glFlush();
}
int main() { 

	glutInitDisplayMode(GLUT_RGBA); 
	glutInitWindowSize(1000, 500); 
	glutCreateWindow("opengl project"); 
	glutDisplayFunc(display); 
	glutMainLoop();
	return 0;
}
