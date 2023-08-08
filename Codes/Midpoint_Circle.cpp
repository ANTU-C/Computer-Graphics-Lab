#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float xc, yc, r,x,y,p;
void plot(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+xc, y+yc);
    glEnd();
}
void display(void) {
 x=0;
 y=r;
 p=1-r;
 plot(x,y);
 plot(-x,y);
 plot(x,-y);
 plot(-x,-y);
 while(x<=y)
 {
        if (p < 0){
            x++;
            p+=2*x+1;
        }
        else if (p>0){
            y--;
            x++;
            p+=2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y,-x);
    }
    glFlush();
}
void init (void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glClearColor(0, 0, 0, 0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char *argv[])
{
     printf("coordinate of xc : ");
     scanf("%f", & xc);
     printf("coordinate of yc : ");
     scanf("%f", & yc);
     printf("coordinate of r : ");
     scanf("%f", & r);
     glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 1180);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Midpoint Circle drawing");
    glutDisplayFunc(display);
    init ();
    glutMainLoop();
}
