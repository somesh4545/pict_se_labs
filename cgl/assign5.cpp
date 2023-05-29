
#include <stdlib.h>
#include <bits/stdc++.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;


int xmin = -100, xmax = 100, ymin = -100, ymax = 100;

float sx, sy, dx, dy;

void display();
int code(int x, int y){
    int c = 0;
    if(y > ymax) c = 8;
    if(y < ymin) c = 4;
    if(x > xmax) c = c|2;
    if(x < xmin) c = c|1;
    return c;
}

void cohen(float x1, float y1, float x2, float y2) {
    int c1 = code(x1, y1);
    int c2 = code(x2, y2);

    float m = (y2 - y1) / (x2 - x1);

    while ((c1 | c2) > 0) {
        if ((c1 & c2) > 0) {
            cout << "Line is completely outside window" << endl;
            display();
            return;
        }

        int c;
        float xi = x1;
        float yi = y1;

        c = c1;
        float x, y;

        if (c == 0) {
            c = c2;
            xi = x2;
            yi = y2;
        }

        if ((c & 8) > 0) {
            y = ymax;
            x = xi + 1.0 / m * (ymax - yi);
        }
        else if ((c & 4) > 0) {
            y = ymin;
            x = xi + 1.0 / m * (ymin - yi);
        }
        else if ((c & 2) > 0) {
            x = xmax;
            y = yi + m * (xmax - xi);
        }
        else if ((c & 1) > 0) {
            x = xmin;
            y = yi + m * (xmin - xi);
        }

        if (c == c1) {
            sx = x;
            sy = y;
            c1 = code(sx, sy);
        }
        else if (c == c2) {
            dx = x;
            dy = y;
            c2 = code(dx, dy);
        }
    }

    display();
}

void keyboard(unsigned char c, int x, int y){
    if(c == 'c'){
        cohen(sx, sy, dx, dy);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(xmin, ymin);
        glVertex2i(xmax, ymin);
        glVertex2i(xmax, ymax);
        glVertex2i(xmin, ymax);
    glEnd();
    glFlush();

    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(sx,sy);
    glVertex2i(dx, dy);
    glEnd();
    glFlush();
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv){

    cout << "Window is coordinates are (-100, 100, -100, 100)" << endl;
    cout << "Enter line coordinates limits are(-300, 300, -300, 300)" << endl;
    cout << "Enter x coordinate for starting point: ";
    cin >> sx;
    cout << "Enter y coordinate for starting point: ";
    cin >> sy;
    cout << "Enter x coordinate for destination point: ";
    cin >> dx;
    cout << "Enter y coordinate for destination point: ";
    cin >> dy;

    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("Assignment 5 - line clipping");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
