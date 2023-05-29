#include <stdlib.h>
#include <bits/stdc++.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

float f_color[] = {0, 0, 1};
float b_color[] = {1, 0, 0};

float mat1[20][3];
float ans1[20][3];

void initialize_col(){
    int x, y;
    y = 90;
    // horizontal lines
    for(int i=0; i<10; i+=2){
        mat1[i][0] = 90;
        mat1[i][1] = y;
        mat1[i][2] = 1;

        mat1[i+1][0] = 210;
        mat1[i+1][1] = y;
        mat1[i+1][2] = 1;
        y+=30;
    }

    x = 90;
    // vertical lines
    for(int i=10; i<20; i+=2){
        mat1[i][0] = x;
        mat1[i][1] = 90;
        mat1[i][2] = 1;

        mat1[i+1][0] = x;
        mat1[i+1][1] = 210;
        mat1[i+1][2] = 1;
        x += 30;
    }
}

void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void boundary_fill(int x, int y){
    float c[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,&c);

    if((c[0]!=b_color[0] || c[1]!=b_color[1] || c[2]!=b_color[2]) && (c[0]!=f_color[0] || c[1]!=f_color[1] || c[2]!=f_color[2])){
        glColor3f(f_color[0], f_color[1], f_color[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundary_fill(x+1, y);
        boundary_fill(x-2, y);
        boundary_fill(x, y+2);
        boundary_fill(x, y-2);
    }
}

void drawMatrix(){
    initialize_col();

    glColor3f(1, 0, 0);
    glPointSize(2);
    glLineWidth(5);
    glBegin(GL_LINES);

    for(int i=0; i<20; i+=2){
        glVertex2f(mat1[i][0], mat1[i][1]);
        glVertex2f(mat1[i+1][0], mat1[i+1][1]);
    }
    glEnd();
    glFlush();
    delay(2000);
    boundary_fill(100, 100);
    boundary_fill(160, 100);

}

void mouse(int btn, int state, int x, int y){
    cout << x << " " << y<<endl;
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 0, 600);
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Practical 4 - filling");
    init();
    glutDisplayFunc(drawMatrix);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
