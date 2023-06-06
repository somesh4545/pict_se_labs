
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

using namespace std;

double board[20][3], ans[20][3];

void putPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawLine(int x1, int y1, int x2, int y2){
    int dx, dy, x, y;
    float p;
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    x = min(x1, x2);
    y = min(y1, y2);

    if(dx > dy){
        p = 2*dy - dx;
        for(int i=0; i<dx; i++){
            if(p>=0){
                p += 2*(dy - dx);
                y++;
            }else{
                p += 2*dy;
            }
            x++;
            putPixel(x, y);
        }
    }else{
        p = 2*dx - dy;
        for(int i=0; i<dy; i++){
            if(p>=0){
                p += 2*(dx - dy);
                x++;
            }else{
                p += 2*dx;
            }
            y++;
            putPixel(x, y);
        }
    }
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 0, 600);
}

void createBoard(){
    int i=0;
    int y = 80;
    // prepare horizontal lines
    for(i=0; i<10; i+=2){
        board[i][0] = 80;
        board[i][1] =  y;

        board[i+1][0] = 240;
        board[i+1][1] = y;
        y+=40;
    }

    int x = 80;
    // prepare vertical lines
    for(i=10; i<20; i+=2){
        board[i][0] = x;
        board[i][1] =  80;

        board[i+1][0] = x;
        board[i+1][1] = 240;
        x+=40;
    }
}

struct Color{
    float r, g, b;
};
Color background={1.0, 1.0, 1.0}, f_color={0, 0, 1.0};
void seed_fill(int x, int y){
    Color c;
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &c);
    cout << x << " " << y <<" called " << c.r << " " << c.g << " " << c.b << endl;
    if(c.r==background.r && c.g==background.g && c.b==background.b){

        glColor3f(f_color.r, f_color.g, f_color.b);
        putPixel(x, y);
        seed_fill(x+1, y);
        seed_fill(x-1, y);
        seed_fill(x, y+1);
        seed_fill(x, y-1);
    }
}

void display(){
    createBoard();
    glPointSize(3);
    glColor3f(1, 0, 0);
    for(int i=0; i<20; i+=2){
        drawLine(board[i][0], board[i][1], board[i+1][0], board[i+1][1]);
    }
    glPointSize(1);
    seed_fill(186, 145);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 6 - seed fill");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
