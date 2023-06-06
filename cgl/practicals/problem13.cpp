/*
Write a program in OpenGL on Linux Platform to draw
a design shown on Right using Bresenhem Circle
Drawing Algorithm. User should only give centre
coordinates and radius. Rest should be drawn
automatically. Use Mouse/Without Mouse to Plot the
Points (bangle)
*/

#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

int m_x, m_y;

void drawCirclePoints(int cx, int cy, int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(cx+x, cy+y);
    glVertex2i(cx+x, cy-y);
    glVertex2i(cx-x, cy+y);
    glVertex2i(cx-x, cy-y);
    glVertex2i(cx+y, cy+x);
    glVertex2i(cx+y, cy-x);
    glVertex2i(cx-y, cy+x);
    glVertex2i(cx-y, cy-x);
    glEnd();
    glFlush();
}

void drawCircle(int cx, int cy, int radius){
    int x=0, y=radius;
    int d = 3-2*radius;

    while(y>=x){
        if(d > 0){
            y--;
            d += 4*(x-y) + 10;
        }else{
            d += 4*x + 6;
        }
        x++;
        drawCirclePoints(cx, cy, x, y);
    }
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

void display(){
    glColor3f(1, 0, 1);
    drawCircle(m_x, m_y, 100);
    drawCircle(m_x, m_y, 80);

    drawCircle(m_x, m_y-130, 30);
    drawCircle(m_x+60, m_y-115, 30);
    drawCircle(m_x+105, m_y-75, 30);
    drawCircle(m_x+130, m_y-20, 30);

    drawCircle(m_x, m_y+130, 30);
    drawCircle(m_x+60, m_y+115, 30);
    drawCircle(m_x+105, m_y+75, 30);
    drawCircle(m_x+130, m_y+20, 30);

    glFlush();
}

void mouse(int button, int state, int x, int y){
    cout << x <<  " " << y <<endl;
}

int main(int argc, char** argv){

    m_x = 300;
    m_y = 300;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 13 - bangle");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}


