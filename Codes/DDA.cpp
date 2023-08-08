#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x, y,x1, x2, y1, y2,m;
void display(void) {
  m=(y2-y1)/(x2-x1);
  x = x1;
  y = y1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  while(x<=x2 && y<=y2){
    if(m>1){
        x=x+1/m;
        y=y+1;
    }
    else{
        x=x+1;
        y=y+m;
    }
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
  glFlush();
}

void myInit (void) {
  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-100, 1000, -100, 1100);
}

int main(int argc, char ** argv) {

  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y1);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1000, 500);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("DDA");
  myInit ();
  glutDisplayFunc(display);
  glutMainLoop();
}

