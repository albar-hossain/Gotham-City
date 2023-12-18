#include <GL/glut.h>
#include <iostream>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//play sound
#include<mmsystem.h>

float blimpX = 2.19;  // Initial x-coordinate of the ellipse
float blimpSpeed = 0.001;     // blimpSpeed of movement
bool blimpReverse = true;  // Flag to indicate the direction of movement


void updateBlimp(int value) {
    // Update the x-coordinate of the ellipse based on the direction of movement
    if (blimpReverse) {
        blimpX += blimpSpeed;
    }
    else {
        blimpX -= blimpSpeed;
    }

    // Check if the blimp has reached the right or left edge
    if (blimpX > 5) {
        blimpReverse = false;
    }
    else if (blimpX < -5) {
        blimpReverse = true;
    }

    glutPostRedisplay(); // Request a redraw to create animation effect
    glutTimerFunc(16.66, updateBlimp, 0); // 60 frames per second (1000 ms / 60 frames = 16.66 ms per frame)
}

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void drawEllipse(float centerX, float centerY, float radiusX, float radiusY, int segments, float red, float green, float blue) {


    glBegin(GL_TRIANGLE_FAN);

    glColor3ub(red, green, blue); // Set fill color
    glVertex2f(centerX, centerY); // Center of the ellipse


    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);

        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);

        glVertex2f(x + centerX, y + centerY);
    }

    glEnd();
}

void policeBlimp() {
    drawEllipse(blimpX, 14.51, 0.75, 0.32, 100, 57, 52, 57);
    //box
    glBegin(GL_QUADS);
    glColor3ub(71, 66, 72);
    glVertex2f((1.96175 - 2.19) + blimpX, 14.07416);
    glVertex2f((2.31214 - 2.19) + blimpX, 14.07416);
    glVertex2f((2.32 - 2.19) + blimpX, 14.21);
    glVertex2f((1.94 - 2.19) + blimpX, 14.21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(88, 96, 104);
    glVertex2f((1.99719 - 2.19) + blimpX, 14.1616);
    glVertex2f((1.99962 - 2.19) + blimpX, 14.12766);
    glVertex2f((2.31356 - 2.19) + blimpX, 14.12766);
    glVertex2f((2.31356 - 2.19) + blimpX, 14.1616);
    glEnd();


}

void bottomRightbuilding() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(48, 33, 30);
    glVertex2f(4.60729, 2.16452);
    glVertex2f(3.83891, 0.74136);
    glVertex2f(5.9955, 0.36659);
    glVertex2f(6, 1.96);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(73, 47, 49);
    glVertex2f(3.83891, 0.74136);
    glVertex2f(3.84895, 0.58293);
    glVertex2f(6, 0.2);
    glVertex2f(5.9955, 0.36659);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 46, 48);
    glVertex2f(4.01, 0.56);
    glVertex2f(4, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 0.2);
    glEnd();

}

void buildingWithVerticleWindows() {
    //Antenna top
    glBegin(GL_QUADS);
    glColor3ub(142, 99, 63); //

    glVertex2f(5.52085, 12.64831);//j1
    glVertex2f(5.51921, 12.1929);//k1
    glVertex2f(5.54875, 12.19425);//h1
    glVertex2f(5.54912, 12.64755);//i1
    glEnd();

    //Antenna mid
    glBegin(GL_QUADS);
    glColor3ub(113, 84, 63); // Building rgb(131, 91, 59)

    glVertex2f(5.51921, 12.1929);//k1
    glVertex2f(5.48451, 12.15581);//l1
    glVertex2f(5.58, 11.74);//f1

    glVertex2f(5.54875, 12.19425);//h1
    glEnd();

    //Antennabottom
    glBegin(GL_QUADS);
    glColor3ub(75, 49, 46); // Building rgb(131, 91, 59)

    glVertex2f(5.48451, 12.15581);//l1
    glVertex2f(5.487, 11.74127);//m1
    glVertex2f(5.58, 11.74);//f1
    glColor3ub(115, 82, 55);
    glVertex2f(5.57833, 12.15752);//g1
    glEnd();

    //Drawing Tall building right side main structure
    glBegin(GL_QUADS);
    glColor3ub(21, 22, 25); // Building rgb(21, 22, 25)
    glVertex2f(6, 11.4);
    glVertex2f(6, 5);
    glVertex2f(4.28, 5);
    glVertex2f(4.28, 11.36);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 44, 41); // Building rgb(67, 44, 41)
    glVertex2f(5.92, 11.59);
    glVertex2f(5.92, 11.4);
    glVertex2f(5.69, 11.38);
    glVertex2f(5.7, 11.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 28, 33); // Building rgb(36, 28, 33)
    glVertex2f(5.69, 11.38);
    glVertex2f(5.7, 11.75);
    glVertex2f(5.26, 11.73);
    glVertex2f(5.27, 11.38);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 28, 33); // Building rgb(36, 28, 33)
    glVertex2f(5.27, 11.38);
    glVertex2f(5.27, 11.57);
    glVertex2f(4.95, 11.55);
    glVertex2f(4.94, 11.37);
    glEnd();

    //Amtenna
    // glBegin(GL_POLYGON);
    // glColor3ub(131, 91, 59); // Building rgb(131, 91, 59)

    // glVertex2f(5.58, 11.74);
    // glVertex2f(5.58, 12.16);
    // glVertex2f(5.55, 12.19);
    // glVertex2f(5.55, 12.65);
    // glVertex2f(5.52, 12.65);
    // glVertex2f(5.52, 12.19);
    // glVertex2f(5.49, 12.16);
    // glVertex2f(5.49, 11.74);
    // glEnd();



    //drawing lines //22 total lines //0.08 difference

    // glBegin(GL_QUADS);
    // glColor3ub(188, 158, 115); // Building light lines rgb(188, 158, 115)
    // glVertex2f(4.4, 11.24);
    // glVertex2f(4.4, 7.2);
    // glVertex2f(4.34, 7.2);
    // glVertex2f(4.34, 11.24);
    // glEnd();


    for (float x = 4.34; x <= 5.92; x += 0.09)
    {

        glBegin(GL_QUADS);
        glColor3ub(188, 158, 115); // Building light lines rgb(188, 158, 115)
        glVertex2f(x, 11.24);
        glVertex2f(x + 0.06, 11.24);
        glColor3ub(88, 51, 46); // Building light lines rgb(88, 51, 46)S
        glVertex2f(x + 0.06, 5.32);
        glVertex2f(x, 5.32);
        glEnd();
    }
}

void wayneTower() {

    //top tower
    glBegin(GL_POLYGON);
    glColor3ub(59, 43, 41); // Building rgb(59, 43, 41)
    glVertex2f(-3.53, 10.86);
    //glColor3ub(142, 89, 53); // Building rgb(142, 89, 53)
    glVertex2f(-3.53418, 12.38);
    glColor3ub(84, 64, 54); // Building rgb(84, 64, 54)
    glVertex2f(-4.4, 12.6);
    glColor3ub(52, 39, 41); // Building rgb(52, 39, 41)
    glVertex2f(-4.4, 10.92);
    //glVertex2f(-5.1, 10.94);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(35, 30, 36); // Building rgb(35, 30, 36)
    glVertex2f(-6, 10.86);
    glVertex2f(-4.4, 10.92);
    glVertex2f(-4.4, 12.6);
    glVertex2f(-5.2, 12.8);
    glVertex2f(-6, 12.51);
    glEnd();

    //Drawing  main structure
    glBegin(GL_QUADS);
    glColor3ub(31, 28, 33); // Building rgb(31, 28, 33)
    glVertex2f(-6.00025, 7.44631);
    glVertex2f(-4.09051, 7.36871);
    glVertex2f(-4.09986, 10.93592);
    glVertex2f(-6, 10.86204);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(56, 40, 41); // Building rgb(56, 40, 41)
    glVertex2f(-4.09051, 7.36871);
    glVertex2f(-4.09986, 10.93592);
    glColor3ub(34, 28, 32); // Building rgb(56, 40, 41)
    glVertex2f(-3, 10.8);

    glVertex2f(-3, 7.37229);


    //glVertex2f(-6, 10.86);
    glEnd();


}


void batmanBuilding() {

    //building body
    glBegin(GL_POLYGON);
    glColor3ub(18, 14, 16); // Building rgb(18, 14, 16)
    glVertex2f(-6, 2.8196);
    glVertex2f(-6, 0);
    glVertex2f(-3.33, 0);
    glColor3ub(32, 24, 25); // Building rgb(32, 24, 25)
    glVertex2f(-1.32857, 1.61253);
    glVertex2f(-1.32902, 4.95088);
    glEnd();
    //building mid ledge
    glBegin(GL_POLYGON);
    glColor3ub(13, 20, 26); // Building rgb(18, 14, 16)
    glVertex2f(-3.72, 0);
    glVertex2f(-3.53812, 0.00917);
    glColor3ub(13, 20, 26); // Building rgb(32, 24, 25)
    glVertex2f(-0.89972, 2.18233);
    glVertex2f(-0.87452, 2.33164);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(18, 14, 16); // Building rgb(18, 14, 16)
    glVertex2f(-4.08156, 0.00368);
    glVertex2f(-3.72, 0);
    glColor3ub(32, 24, 25); // Building rgb(32, 24, 25)
    glVertex2f(-0.87452, 2.33164);
    glVertex2f(-1.31265, 2.39414);
    glEnd();





    //bottom ledge
    glBegin(GL_QUADS);
    glColor3ub(21, 16, 16); // Building rgb(21, 16, 16)
    glVertex2f(-2.2, 0);
    glVertex2f(-1.51, 0);
    glColor3ub(33, 22, 23); // Building rgb(33, 22, 23)
    glVertex2f(-0.57942, 0.87968);
    glVertex2f(-0.6014, 1.50076);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(4, 11, 19); // Building rgb(4, 11, 19)
    glVertex2f(-3.33, 0);
    glVertex2f(-2.2, 0);
    glColor3ub(9, 15, 18); // Building rgb(9, 15, 18)
    glVertex2f(-0.6014, 1.50076);
    glVertex2f(-1.32857, 1.61253);
    glEnd();


}
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, 0, 17);
    glMatrixMode(GL_MODELVIEW);

    //Objects
    policeBlimp();
    buildingWithVerticleWindows();
    wayneTower();
    batmanBuilding();
    bottomRightbuilding();

    glFlush(); // Render now

}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT

    glutInitWindowSize(750, 1040);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 750) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 1061) / 2);
    glutCreateWindow("Batman"); // Create a window with the given title
    // Set the window's initial width & height
    // gluOrtho2D(-6, 6, 0, 17);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    // Initialize updateBlimp function and timer
    glutTimerFunc(0, updateBlimp, 0);


    //Code to play music
    sndPlaySound("bat.wav", SND_ASYNC);
    // sndPlaySound("instrumental.wav", SND_ASYNC);
    // PlaySound("instrumental.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}