//Rotation

#include "Angel.h"

using namespace std;

vec2 points[] = { vec2(0, 0.5), vec2(-0.5,-0.5), vec2(0.5,-0.5) };
double angle = 0.1;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2fv(points[0]);
	glVertex2fv(points[1]);
	glVertex2fv(points[2]);
	glEnd();
	glFlush();
}

void idle (int state)
{
	double thetaRad = angle * DegreesToRadians;
	vec2 point;
	for (size_t i = 0; i < 3; i++)
	{
		point.x = points[i].x * cos(thetaRad) - points[i].y * sin(thetaRad);
		point.y = points[i].x * sin(thetaRad) + points[i].y * cos(thetaRad);
		points[i] = point;
	}
	glutPostRedisplay();
	glutTimerFunc(1, idle, 0);
}

void myMouse(int key, int state, int x, int y)
{
	if (key == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		angle = -angle;
}

void myKeyBoard(unsigned char key, int x, int y)
{
	if (key == 'Q' || key == 'q')
		exit(0);
}

void menu(int option)
{
	switch (option)
	{
	case 1 :
	{
		angle = -0.1;
		break;
	}
	case 2 :
	{
		angle = 0.1;
		break;
	}
	case 3 :
	{
		angle = 0;
		break;
	}
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Rotation");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutCreateMenu(menu);
	glutAddMenuEntry("Clockwise Direction", 1);
	glutAddMenuEntry("Anti - Clockwise Direction", 2);
	glutAddMenuEntry("Stop Rotation", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyBoard);
	glutTimerFunc(1, idle, 0);
	glutMainLoop();
	return 0;
}