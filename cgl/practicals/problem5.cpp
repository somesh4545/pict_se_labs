#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

float b_color[3] = {1, 0, 0};
float f_color[3] = {0, 0, 1};
double mat1[12][3]={1}, ans[12][3]={1};

void setMatrix(){
    mat1[0][0] = 50;
    mat1[0][1] = -150;
    mat1[1][0] =  50;
    mat1[1][1] = -50;
    mat1[2][0] =  150;
    mat1[2][1] = -50;

    mat1[3][0] = 150;
    mat1[3][1] = 50;
    mat1[4][0] = 50;
    mat1[4][1] = 50;
    mat1[5][0] = 50;
    mat1[5][1] = 150;

    mat1[6][0] = -50;
    mat1[6][1] = 150;
    mat1[7][0] = -50;
    mat1[7][1] = 50;
    mat1[8][0] = -150;
    mat1[8][1] = 50;

    mat1[9][0] = -150;
    mat1[9][1] = -50;
    mat1[10][0] = -50;
    mat1[10][1] = -50;
    mat1[11][0] =  -50;
    mat1[11][1] = -150;
}

void boundary_fill(int x, int y){
    float pix[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &pix);

    if((pix[0]!=b_color[0] || pix[1]!=b_color[1] || pix[2]!=b_color[2]) && (pix[0]!=f_color[0] || pix[1]!=f_color[1] || pix[2]!=f_color[2])){
        glColor3f(f_color[0], f_color[1], f_color[2]);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundary_fill(x+1, y);
        boundary_fill(x-2, y);
        boundary_fill(x, y+1);
        boundary_fill(x, y-2);
    }
}

void display(){
    setMatrix();
    glColor3f(1, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<12; i++){
        glVertex2i(mat1[i][0], mat1[i][1]);
    }
    glEnd();
    glFlush();
   //boundary_fill(0, 0);
}



void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

void rotation(){
    float angle = 45;
    float rx = 0;
    float ry = 0;

    float rMat[3][3]={0};
    rMat[2][2] = 1;
    rMat[0][0] = cos(angle);
    rMat[0][1] = -sin(angle);
    rMat[1][0] = sin(angle);
    rMat[1][1] = cos(angle);

    rMat[2][0] = rx - (rx*cos(angle)) + (ry*sin(angle));
    rMat[2][1] = ry - (rx*sin(angle)) - (ry*cos(angle));

    for(int i=0; i<12; i++){
        for(int j=0; j<3; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum += mat1[i][k]*rMat[k][j];
            }
            ans[i][j] = sum;
            //cout << sum<<" ";
        }
        //cout << endl;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    glColor3f(1, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<12; i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
        glVertex2i(ans[i][0], ans[i][1]);
    }
    glEnd();
    glFlush();
    //boundary_fill(0, 0);
}

void keyboard(unsigned char c, int x, int y){
    if(c == 'r'){
        rotation();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 5 - Rotation of polygon");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
