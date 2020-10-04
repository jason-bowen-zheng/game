#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();
	glFlush();
}

void init(void) {
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 200);
	glutCreateWindow("Demo");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
