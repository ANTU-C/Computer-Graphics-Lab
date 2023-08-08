#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#define PI acos(-1)
using namespace std;

float x, y, len, alpha,ang, xl, yl ;
int n ;

Koch_curve(float x,float y,float len,float alpha, int n)
{
if (n > 0)
{
len = len/3;
Koch_curve(x, y, len, alpha, n - 1);
x = x + len*cos(alpha*PI/180);
y = y + len*sin(alpha*PI/180);
Koch_curve(x,y,len,alpha-60,n-1);
x = x + len*cos((alpha - 60)*PI/180);
y=y+len*sin((alpha-60)*PI/180);
Koch_curve(x,y,len,alpha+60,n-1);
x = x + len*cos((alpha + 60)*PI/180);
y = y + len*sin((alpha + 60)*PI/180);
Koch_curve(x, y, len, alpha, n - 1);
}
else
{
glBegin(GL_LINES);
glVertex2f(x,y);
glVertex2f(x + len * cos(alpha*PI/180) , y + len * sin(alpha*PI/180) );

xl = x + len * cos(alpha*PI/180), yl = y + len * sin(alpha*PI/180);
glEnd();
}
}

void display(void)
{
Koch_curve(x,y,len,ang,n);
glFlush();
}

void init(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);

glLoadIdentity();
gluOrtho2D(-300,300,-300,300);
}

int main(int argc, char** argv)
{
printf("Enter the value of x , y: ");
scanf("%f %f",&x,&y);
printf("Enter the value of len : ");
scanf("%f",&len);
printf("Enter the value of n : ");
scanf("%d",&n);
printf("Enter the value of ang : ");
scanf("%f",&ang);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("Koch_Curve");
init();
glutDisplayFunc(display);
glutMainLoop();
}
