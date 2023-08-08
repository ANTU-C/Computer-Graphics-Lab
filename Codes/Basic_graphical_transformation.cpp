#include <iostream>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
using namespace std;

int pntX1, pntY1, shearingX, shearingY,transX, transY,choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
double scaleX, scaleY, angle, angleRad;
char reflectionAxis, shearingAxis;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}

void drawPolygonTrans(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.3, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}

void drawPolygonRotation(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.0, 0.8);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	if (choice == 1)
	{
		drawPolygon();
		drawPolygonTrans(transX, transY);
	}
	else if (choice == 2)
	{
		drawPolygon();
		drawPolygonScale(scaleX, scaleY);
	}
	else
	{
		drawPolygon();
		drawPolygonRotation(angleRad);
	}
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "Enter your choice:\n\n" << endl;
	cout << "1. Translation" << endl;
	cout << "2. Scaling" << endl;
	cout << "3. Rotation" << endl;
    cout << "Enter your choice" << " : ";cin >> choice;
	cout << "\nFor Polygon:\n" << endl;
	cout << "Enter no of edges: "; cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}
	if (choice == 1)
	{
		cout << "Enter the translation factor for X : "; cin >> transX ;
		cout << "Enter the translation factor for Y : ";cin>> transY;
	}
	else if (choice == 2)
	{
		cout << "Enter the scaling factor for X : "; cin >> scaleX ;
		cout << "Enter the scaling factor for X : "; cin>> scaleY;
	}
	else
	{
		cout << "Enter the angle for rotation: "; cin >> angle;
		angleRad = angle * 3.1416 / 180;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Extended Basic Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
