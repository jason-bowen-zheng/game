#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int shape = 0;

void init(void) {
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void init_menu(void) {
	glutAddMenuEntry("Triangles", 0);
	glutAddMenuEntry("Quads", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void on_draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (shape == 0) {
		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.5, -0.5, 0.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.5);
		glVertex3f(0.0, 0.5, 0.0);
		glEnd();
	} else {
		glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-0.5, -0.5, 0.0);
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glEnd();
	}
	glutSwapBuffers();
}

void on_menu(int value) {
	if (value == 0) {
		shape = 0;
	} else {
		shape = 1;
	}
	on_draw();
}

void on_reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize(300, 200);
	glutCreateWindow("Demo");
	glutCreateMenu(on_menu);
	init_menu();
	init();
	glutDisplayFunc(on_draw);
	glutReshapeFunc(on_reshape);
	glutMainLoop();
	return 0;
}
