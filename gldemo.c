#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

int shape = 0;
int c = 1;
const GLfloat r = 0.5;
const GLfloat PI = 3.1415926;

void draw_sin(int);

void init(void) {
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void init_menu(void) {
	glutAddMenuEntry("Triangles", 0);
	glutAddMenuEntry("Quads", 1);
	glutAddMenuEntry("Circles1", 2);
	glutAddMenuEntry("Circles2", 3);
	glutAddMenuEntry("sin(i)", 4);
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
	} else if (shape == 1) {
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
	} else if (shape == 2) {
		long n = 1024;
		for (int i = 0; i <= n; ++i) {
			glBegin(GL_LINES);
			glColor3f(1.0, 0.5, 0.0);
			glVertex2f(r * cos(2 * PI / n * i), r * sin(2 * PI / n * i));
			glColor3f(1.0, 0.0, 1.0);
			glVertex2f(0, 0);
			glEnd();
		}
	} else if (shape == 3) {
		int n = 64;
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		for (int i = 0; i <= n; ++i) {
			glVertex2f(r * cos(2 * PI / n * i), r * sin(2 * PI / n * i));
		}
		glEnd();
	} else if (shape == 4) {
		glutTimerFunc(500, draw_sin, 0);
	}
	glutSwapBuffers();
}

void draw_sin(int n) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.8, 0.0);
	c++;
	if (c == 16) {
		c = 1;
	} else if (c == 1) {
		c = 16;
	}
	for (float i = -c; i <=c; i += 0.001) {
		glVertex2f(i / c, sin(i) / c);
	}
	glEnd();
	glutSwapBuffers();
	glutTimerFunc(500, draw_sin, 0);
}

void on_menu(int value) {
	shape = value;
	on_draw();
}

void on_reshape(int w, int h) {
	if (w > h) {
		glViewport(0.5 *(w - h), 0, (GLsizei)h, (GLsizei)h);
	} else if (h > w) {
		glViewport(0, 0.5 * (h -w), (GLsizei)w, (GLsizei)w);
	} else {
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	}
}

int main(int argc, char *argv[]) {
	printf("%s(%s, %s)\n", argv[0], __DATE__, __TIME__);
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
