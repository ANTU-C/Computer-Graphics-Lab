#include<windows.h>
#ifdef _APPLE_
#else
#include <GL/glut.h>
#endif
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
void delay(float ms)
{
    clock_t goal = ms + clock();
    while(goal>clock());
}
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void bfa(int x, int y, float* fc, float* bc)
{
    float cur_col[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,cur_col);
    if((cur_col[0]!=bc[0] || cur_col[1]!=bc[1] || cur_col[2]!=bc[2])&&(
                cur_col[0]!=fc[0] || cur_col[1]!=fc[1] || cur_col[2]!=fc[2]))
    {
        glColor3f(fc[0],fc[1],fc[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        bfa(x+1,y,fc,bc);
        bfa(x-2,y,fc,bc);
        bfa(x,y+1,fc,bc);
        bfa(x,y-2,fc,bc);
    }
}
void world()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(300,400);
    glVertex2i(150,350);
    glVertex2i(150,250);
    glVertex2i(300,200);
    glVertex2i(450,250);
    glVertex2i(450,350);
    glEnd();
    glFlush();
    float bCol[] = {1,0,0};
    float f_col[] = {0,1,1};
    bfa(300,300,f_col,bCol);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(300,300);
    glutCreateWindow("Fill algorithm");
    glutDisplayFunc(world);
    init();
    glutMainLoop();
    return 0;
}

