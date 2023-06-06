#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

#define RADIAN (3.14/180)

void kochs(int xa, int ya, int xb, int yb, int n){

    float xc, yc, xd, yd, midx, midy;
    xc = (2*xa+xb) / 3;
    yc = (2*ya+yb) / 3;
    xd = (2*xb+xa) / 3;
    yd = (2*yb+ya) / 3;
    midx = xc + ((xd-xc)*cos(60*RADIAN)) + ((yd-yc)*sin(60*RADIAN));
    midy = yc - ((xd-xc)*sin(60*RADIAN)) + ((yd-yc)*cos(60*RADIAN));

    if(n > 0){
        kochs(xa, ya, xc, yc, n-1);
        kochs(xc, yc, midx, midy, n-1);
        kochs(midx, midy, xd, yd, n-1);
        kochs(xd, yd, xb, yb, n-1);
    }else{
        glVertex2i(xa, ya);
        glVertex2i(xc, yc);
        glVertex2i(xc, yc);
        glVertex2i(midx, midy);
        glVertex2i(midx, midy);
        glVertex2i(xd, yd);
        glVertex2i(xd, yd);
        glVertex2i(xb, yb);
    }

}

void display(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    kochs(200, 200, 400, 200, 4);
    kochs(400, 200, 300, 370, 4);
    kochs(300, 370, 200, 200, 4);
    glEnd();
    glFlush();
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 4 - kochs curve");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
