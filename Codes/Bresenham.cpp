#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1, x2, y1, y2;

void display(void)
{
    float dy, dx, x, y, m,p;
    dx =abs(x2-x1);
    dy = abs(y2 - y1);
    p=2*dy-dx;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    int i=0;
    while(i<dx)
    {
        i++;
        if (p < 0)
        {
            p=p+2*dy;
            x = x + 1;
            y = y;
        }
        else
        {
            p=p+2*(dy-dx);
            x = x+1;
            y = y+1;
        }
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }
    glFlush();
}

void init (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000,1000,-1000,1000);
}

int main(int argc, char *argv[])
{
    printf("coordinate of x1 : ");
    scanf("%f", & x1);
    printf("coordinate of y1 : ");
    scanf("%f", & y1);
    printf("coordinate of x2 : ");
    scanf("%f", & x2);
    printf("coordinate of y2 : ");
    scanf("%f", & y2);

    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("___");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}

