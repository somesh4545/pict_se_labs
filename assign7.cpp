#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

#define RADIAN (3.14/180)

void kochs(int xa, int ya, int xb, int yb, int n){


    int xc, yc, xd, yd, midx, midy;
    xc = (2*xa+xb) / 3;
    yc = (2*ya+yb) / 3;
    xd = (2*xb+xa) / 3;
    yd = (2*yb+ya) / 3;
    midx = xc + ((xd-xc)*cos(60*RADIAN))+ ((yd-yc)*sin(60*RADIAN));
    midy = yc - ((xd-xc)*sin(60*RADIAN))+ ((yd-yc)*cos(60*RADIAN));

    if(n > 0){
        kochs(xa, ya, xc, yc, n-1);
        kochs(xc, yc, midx, midy, n-1);
        kochs(midx, midy, xd, yd, n-1);
        kochs(xd, yd, xb, yb, n-1);
    }else{
        glVertex2f(xa, ya);
        glVertex2f(xc, yc);
        glVertex2f(xc, yc);
        glVertex2f(midx, midy);
        glVertex2f(midx, midy);
        glVertex2f(xd, yd);
        glVertex2f(xd, yd);
        glVertex2f(xb, yb);
    }
}

void draw(int n){
    glBegin(GL_LINES);
    kochs(200, 200, 400, 200, n);
    kochs(400, 200, 300, 370, n);
    kochs(300, 370, 200, 200, n);
    glEnd();
    glFlush();
}

void display(){
    int n;
    cout << "Enter number of iterations: ";
    cin >> n;
    draw(n);
}

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Fractals pattern - koch snowflake");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

