
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

float xmin=-200, ymin=-200, xmax=200, ymax=200;
float sx=100, sy=100, dx=230, dy=230;

void putPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawLine(int x1, int y1, int x2, int y2){
    float dx, dy, x, y, p;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = min(x1, x2);
    y = min(y2, y1);

    if(dx > dy){
        p = 2*dy-dx;
        for(int i=0; i<dx; i++){
            if(p>=0){
                p += 2*(dy-dx);
                y++;
            }else{
                p += 2*dy;
            }
            x++;
            putPixel(x, y);
        }
    }else{
        p = 2*dx-dy;
        for(int i=0; i<dy; i++){
            if(p>=0){
                p += 2*(dx-dy);
                x++;
            }else{
                p += 2*dx;
            }
            y++;
            putPixel(x, y);
        }
    }
}

void display();

int calcCode(int x, int y){
    int code = 0;
    if(y > ymax) code = 8;
    if(y < ymin) code = 4;
    if(x > xmax) code |= 2;
    if(x < xmin) code |= 1;
    return code;
}

void cohen(float x1, float y1, float x2, float y2){
    int c1 = calcCode(x1, y1);
    int c2 = calcCode(x2, y2);
    float m = (y2-y1) / (x2-x1);
    while((c1 | c2) > 0){
        if((c1 & c2) > 0){
            cout << "Line is completly outside";
            return;
        }
        float xi=x1, yi=y1;
        int c = c1;
        float x, y;

        if(c == 0){
            c = c2;
            xi = x2;
            yi = y2;
        }

        if((c&8) > 0){
            y = ymax;
            x = xi + 1.0/m * (ymax-yi);
        }else if((c&4) > 0){
            y = ymin;
            x = xi + 1.0/m * (ymin-yi);
        }else if((c&2) > 0){
            x = xmax;
            y = yi + m*(xmax-xi);
        }else if((c&1) > 0){
            x = xmin;
            y = yi + m*(xmin-xi);
        }

        if(c == c1){
            sx = x;
            sy = y;
            c1 = calcCode(x, y);
        }else{
            dx = x;
            dy = y;
            c2 = calcCode(x, y);
        }
    }
    display();
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

void keyboard(unsigned char c, int x, int y){
    if(c == 'c') cohen(sx, sy, dx, dy);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmax, ymin);
    glVertex2i(xmax, ymax);
    glVertex2i(xmin, ymax);
    glEnd();
    glFlush();

    drawLine(sx, sy, dx, dy);

}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("Problem 6 - line clipping");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}
