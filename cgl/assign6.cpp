

#include <stdlib.h>
#include <bits/stdc++.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<math.h>

using namespace std;

double et[3][3]={1}, ans[3][3]={0};
float xi, yi;
int length;

void drawEt(double temp[3][3]) {
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<3; i++){
        glVertex2i(temp[i][0], temp[i][1]);
    }
    glEnd();
    glFlush();
}

void multi3X3(double m1[3][3], double m2[3][3]){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum += m1[i][k]*m2[k][j];
            }
            ans[i][j] = sum;
        }
    }

}

void translation(){
    double tx, ty;
    double temp[3][3]={0};
    cout << "Enter tx: ";
    cin >> tx;
    cout << "Enter ty: ";
    cin >> ty;

    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;

    multi3X3(et, temp);
    glColor3f(1, 1, 0);
    drawEt(ans);

}

void scalling(){
    double sx, sy;
    double temp[3][3] = {0};
    cout << "ENter sx: ";
    cin >> sx;
    cout << "Enter sy: ";
    cin >> sy;

    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;

    multi3X3(et, temp);
    glColor3f(1, 0, 1);
    drawEt(ans);
}

void rotation(){
    double rx, ry, angle, temp[3][3] = {0};
    cout << "Enter arbiratary x point: ";
    cin >> rx;
    cout << "Enter arbitratiry y point: ";
    cin >> ry;
    cout << "Enter rotation angle: ";
    cin >> angle;

    angle = angle*(M_PI/180);

    temp[0][0] = cos(angle);
    temp[0][1] = sin(angle);
    temp[1][0] = -sin(angle);
    temp[1][1] = cos(angle);
    temp[2][0] = rx -(rx*cos(angle))+(ry*sin(angle));
    temp[2][1]=ry -(rx*sin(angle))-(ry*cos(angle));
    temp[2][2]=1;

    multi3X3(et, temp);
    glColor3f(0, 1, 1);
    drawEt(ans);
}

void shearing(){
    int ch = 0;
    double shx, shy, temp[3][3]={0};

    cout<<"Enter 1 for shx, 2 for shy: ";
    cin >> ch;

    if(ch == 1){
        cout<<"Enter shx factor: ";
        cin >> shx;
        temp[0][0] = 1;
        temp[1][1] = 1;
        temp[2][2] = 1;
        temp[1][0] = shx;
    }else{
        cout << "Enter shy factor: ";
        cin >> shy;
        temp[0][0] = 1;
        temp[1][1] = 1;
        temp[2][2] = 1;
        temp[0][1] = shy;
    }

    multi3X3(et, temp);
    glColor3f(1, 0, 0);
    drawEt(ans);
}

void menu(int item){
    switch(item){
    case 1:
        translation();
        break;
    case 2:
        scalling();
        break;
    case 3:
        rotation();
        break;
    case 4:
        shearing();
        break;
    default:
        break;
    }
}

void display(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(-300, 0);
        glVertex2i(300, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(0, 300);
        glVertex2i(0, -300);
    glEnd();
    glFlush();

    glColor3f(0, 0, 1);
    drawEt(et);
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv){

    cout << "Enter x coordinate: ";
    cin >> xi;
    cout << "Enter y coordinate: ";
    cin >> yi;
    cout << "Enter line length: ";
    cin >> length;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            et[i][j] = 1;
        }
    }

    et[0][0] = xi;
    et[0][1] = yi;
    et[1][0] = xi + length;
    et[1][1] = yi;
    et[2][0] = length/2 + xi;
    et[2][1] = (sqrt(3)/2 * length) + yi;

    glutInit(&argc ,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Practical 6th");

    init();

    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("1. Translation", 1);
    glutAddMenuEntry("2. Scalling", 2);
    glutAddMenuEntry("3. Rotation", 3);
    glutAddMenuEntry("4. Shearing", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    glutMainLoop();
    return 0;

}

