#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#define PI acos(-1)
using namespace std;

float x,y,x1, yl,x2, y2,x3, y3, len, ang ;
int n ;

void S_Gasket(float x1,float yl,float x2,float y2,float x3,float y3,int n)
{
float x12 , x13 , x23 , yl2 , yl3, y23 ;
if(n>0)
{
x12 = (x1 + x2) / 2;    x23 = (x2 + x3) / 2 ;   x13 = (x1 + x3) / 2 ;
yl2 = (yl + y2) / 2;    y23 = (y2 + y3) / 2 ;   yl3 = (yl + y3) / 2 ;
S_Gasket(x1,yl,x12,yl2,x13,yl3,n-1);
S_Gasket(x12,yl2,x2,y2,x23,y23,n-1);
S_Gasket(x13,yl3,x23,y23,x3,y3,n-1);

}
else
{

glBegin(GL_TRIANGLES);
glVertex2f(x1,yl);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
glEnd();

}

}
void display(void)
{
S_Gasket(x,y,x2,y2,x3,y3,n);

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
printf("Enter the value of x1 , yl: ");
scanf("%f %f",&x1,&yl);
printf("Enter the value of x2, y2: ");
scanf("%f %f",&x2,&y2);
printf("Enter the value of x3 , y3: ");
scanf("%f %f",&x3,&y3);
printf("Enter the value of n: ");
scanf("%d",&n);


glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(200,100);
glutCreateWindow(" S Gasket Curve");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
