
    switch(item){
    case 1:
        translation();
        break;
    case 2:
        scaling();
        break;
    case 3:
        rotation();
        break;
    case 4:
        shearingX();
        break;
    case 5:
        shearY();
        break;
    default:
        break;
    }
}

void display(){
    dda(0, 300, 0, -300);
    dda(-300, 0, 300, 0);
    glColor3f(0, 1, 0);
    drawET(et);
}

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv){
    /*
    cout << "Enter the length of eq triangle: ";
    cin >> length;
    cout << "Enter the starting point of triangle: ";
    cout << "\nx point: ";
    cin >> xi;
    cout << "y point: ";
    cin >> yi;
    */
    length = 100;
    xi = 50;
    yi = 50;

    et[0][0] = xi;
    et[0][1] = yi;
    et[0][2] = 1;
    et[1][0] = xi+length;
    et[1][1] = yi;
    et[1][2] = 1;
    et[2][0] = xi+length/2;
    et[2][1] = (sqrt(3)/2 * length) + yi;
    et[2][2] = 1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 2 - ");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("Translation", 1);
    glutAddMenuEntry("Scaling", 2);
    glutAddMenuEntry("Rotation", 3);
    glutAddMenuEntry("Shearing x", 4);
    glutAddMenuEntry("Shearing y", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}
