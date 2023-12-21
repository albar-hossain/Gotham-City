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

//testing commit
void updateBlimp(int value) {
    // Update the x-coordinate of the ellipse based on the direction of movement
    if (blimpReverse) {
        blimpX += blimpSpeed;
    }
    else {
        blimpX -= blimpSpeed;
    }

    // Check if the blimp has reached the right or left edge
    if (blimpX >= 4.3) {
        blimpReverse = false;
    }
    else if (blimpX <= -4.5) {
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

    // //light
    // glBegin(GL_QUADS);
    // glColor3ub(177, 160, 53);
    // glVertex2f((2.12859 - 2.19) + blimpX, 14.08628);
    // glVertex2f((2.31533 - 2.19) + blimpX, 10.89752);
    // glVertex2f((3.98194 - 2.19) + blimpX, 11.23578);
    // glVertex2f((2.31181 - 2.19) + blimpX, 14.08628);
    // glEnd();


        //light with gradient transparency
    glBegin(GL_QUADS);
    glColor4ub(177, 160, 53, 255); // Solid color at the bottom
    glVertex2f((2.12859 - 2.19) + blimpX, 14.08628);
    glVertex2f((2.31533 - 2.19) + blimpX, 10.89752);
    glColor4ub(177, 160, 53, 1); // Semi-transparent color at the top
    glVertex2f((3.98194 - 2.19) + blimpX, 11.23578);
    glVertex2f((2.31181 - 2.19) + blimpX, 14.08628);
    glEnd();
    //box
    glBegin(GL_QUADS);
    glColor3ub(71, 66, 72);
    glVertex2f((1.96175 - 2.19) + blimpX, 14.07416);
    glVertex2f((2.31214 - 2.19) + blimpX, 14.07416);
    glVertex2f((2.32 - 2.19) + blimpX, 14.21);
    glVertex2f((1.94 - 2.19) + blimpX, 14.21);
    glEnd();
    //glass
    glBegin(GL_QUADS);
    glColor3ub(88, 96, 104);
    glVertex2f((1.99719 - 2.19) + blimpX, 14.1616);
    glVertex2f((1.99962 - 2.19) + blimpX, 14.12766);
    glVertex2f((2.31356 - 2.19) + blimpX, 14.12766);
    glVertex2f((2.31356 - 2.19) + blimpX, 14.1616);
    glEnd();

}
void Buildinginfrontbatman() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(55, 37, 39);
    glVertex2f(-0.6121, 5.45109);
    glVertex2f(-1.8552, 4.83867);
    glVertex2f(0.09197, 4.49217);
    glVertex2f(1.40941, 5.26535);
    glEnd();
    //front
    glBegin(GL_QUADS);
    glColor3ub(31, 31, 36);
    glVertex2f(0.09197, 4.49217);
    glVertex2f(-1.41, 4.76);
    glVertex2f(-1.40174, 3.24704);
    glVertex2f(0.09639, 3.02589);
    glEnd();

    //WINDOW 1
    glBegin(GL_QUADS);
    glColor3ub(209, 147, 69);
    glVertex2f(-1.00879, 4.43414);
    glVertex2f(-1.33, 4.47);
    glVertex2f(-1.32, 3.98);
    glVertex2f(-1.01223, 3.95525);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-1.17, 4.45);
    glVertex2f(-1.17, 3.8);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-1.33, 4.23);
    glVertex2f(-1, 4.21);
    glEnd();

    //WINDOW 2
    glBegin(GL_QUADS);
    glColor3ub(206, 145, 71);
    glVertex2f(0.00604, 4.34053);
    glVertex2f(-0.29669, 4.37264);
    glVertex2f(-0.31504, 3.85892);
    glVertex2f(0.01062, 3.8314);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.15, 4.36);
    glVertex2f(-0.15, 3.85);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.31, 4.12);
    glVertex2f(0.1, 4.08);
    glEnd();

    //WINDOW 3
    glBegin(GL_QUADS);
    glColor3ub(197, 121, 66);
    glVertex2f(-0.51686, 3.72591);
    glVertex2f(-0.815, 3.75801);
    glVertex2f(-0.82417, 3.25806);
    glVertex2f(-0.50768, 3.22136);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.82, 3.51);
    glVertex2f(-0.51, 3.48);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.66, 3.74);
    glVertex2f(-0.67, 3.24);
    glEnd();

    //side
    glBegin(GL_QUADS);
    glColor3ub(32, 29, 35);
    glVertex2f(0.09197, 4.49217);
    glVertex2f(0.09639, 3.02589);
    glVertex2f(1.44491, 4.03971);
    glVertex2f(1.40941, 5.26535);
    glEnd();

    //windows4
    glBegin(GL_QUADS);
    glColor3ub(212, 155, 78);
    glVertex2f(0.43719, 4.51942);
    glVertex2f(0.2262, 4.3864);
    glVertex2f(0.22161, 3.9002);
    glVertex2f(0.44178, 4.03781);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.34, 4.46);
    glVertex2f(0.35, 3.9);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.44, 4.28);
    glVertex2f(0.22, 4.15);
    glEnd();

    //windows5
    glBegin(GL_QUADS);
    glColor3ub(222, 173, 109);
    glVertex2f(1.07098, 4.90999);
    glVertex2f(0.9, 4.8);
    glVertex2f(0.89231, 4.33075);
    glVertex2f(1.08827, 4.44459);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.98, 4.85);
    glVertex2f(0.99, 4.39);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.08219, 4.68478);
    glVertex2f(0.8, 4.57);
    glEnd();

    //windows6
    glBegin(GL_QUADS);
    glColor3ub(215, 168, 107);
    glVertex2f(1.35484, 5.08002);
    glVertex2f(1.18049, 4.97051);
    glVertex2f(1.18481, 4.52239);
    glVertex2f(1.36492, 4.64055);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.27, 5.03);
    glVertex2f(1.28365, 4.58267);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.36, 4.86);
    glVertex2f(1.18, 4.75);
    glEnd();

    //windows7
    glBegin(GL_QUADS);
    glColor3ub(203, 138, 64);
    glVertex2f(0.43735, 3.87304);
    glVertex2f(0.22423, 3.723);
    glVertex2f(0.22423, 3.23539);
    glVertex2f(0.4561, 3.38543);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.34, 3.8);
    glVertex2f(0.35, 3.32);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.45, 3.63);
    glVertex2f(0.22, 3.49);
    glEnd();

    //windows8
    glBegin(GL_QUADS);
    glColor3ub(205, 152, 82);
    glVertex2f(1.07158, 4.30438);
    glVertex2f(0.89427, 4.18504);
    glVertex2f(0.89427, 3.72641);
    glVertex2f(1.07499, 3.8594);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.99, 4.25);
    glVertex2f(1, 3.81);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.07, 4.09);
    glVertex2f(0.89, 3.97);
    glEnd();

    //balcony
    glBegin(GL_QUADS);
    glColor3ub(28, 27, 32);
    glVertex2f(-1.31127, 2.95822);
    glVertex2f(-1.31127, 2.71767);
    glVertex2f(0.16809, 2.46);
    glVertex2f(0.16628, 2.76324);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(42, 31, 30);
    glVertex2f(-0.88, 3.18);
    glVertex2f(-1.31127, 2.95822);
    glVertex2f(0.16628, 2.76324);
    glVertex2f(0.09639, 3.02589);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(29, 28, 32);
    glVertex2f(-1.4, 3.24704);
    glVertex2f(-1.4, 2.95822);
    glVertex2f(-0.88, 3.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 26, 30);
    glVertex2f(0.16628, 2.76324);
    glColor3ub(68, 41, 40);
    glVertex2f(0.16809, 2.50719);
    glVertex2f(2.15261, 4.01663);
    glVertex2f(2.15098, 4.2764);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(56, 37, 34);
    glVertex2f(2.15098, 4.2764);
    glVertex2f(1.43674, 4.35793);
    glVertex2f(1.44, 4.25);
    glVertex2f(2.02, 4.17);
    glEnd();
    //
    glBegin(GL_QUADS);
    glColor3ub(28, 28, 32);
    glVertex2f(0.09639, 3.02589);
    glVertex2f(-1.4, 3.24704);
    glVertex2f(-1.4, 2.65);
    glVertex2f(0.16628, 2.76324);
    glEnd();

    //
    glBegin(GL_QUADS);
    glColor3ub(84, 46, 41);
    glVertex2f(2.02, 4.17);
    glVertex2f(1.44491, 4.03971);
    glColor3ub(38, 33, 33);
    glVertex2f(0.09639, 3.02589);
    glVertex2f(0.16628, 2.76324);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(109, 59, 45);
    glVertex2f(2.02, 4.17);
    glColor3ub(55, 37, 36);
    glVertex2f(1.44, 4.25);
    glVertex2f(1.44491, 4.03971);
    glEnd();

    //botom front
    glBegin(GL_QUADS);

    glColor3ub(15, 23, 35);
    glVertex2f(0.16809, 2.50719);
    glVertex2f(-1.4175, 2.73);
    glColor3ub(72, 47, 45);
    glVertex2f(-1.6, 0);
    glVertex2f(0.1887, 0);
    glEnd();

    //window1
    glBegin(GL_QUADS);
    glColor3ub(164, 75, 57);
    glVertex2f(-0.65765, 1.95373);
    glVertex2f(-1, 2);
    glVertex2f(-1.01285, 1.52398);
    glVertex2f(-0.64449, 1.47575);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.82, 1.98);
    glVertex2f(-0.83, 1.5);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.65, 1.71);
    glVertex2f(-1.01, 1.76);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(190, 121, 63);
    glVertex2f(-0.03635, 1.86102);
    glVertex2f(-0.39449, 1.90923);
    glVertex2f(-0.40531, 1.41419);
    glVertex2f(-0.03088, 1.36268);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.22, 1.89);
    glVertex2f(-0.22574, 1.36145);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.4, 1.67);
    glVertex2f(-0.03, 1.61);
    glEnd();

    //window3
    glBegin(GL_QUADS);
    glColor3ub(213, 163, 68);
    glVertex2f(-0.03707, 1.19805);
    glVertex2f(-0.40472, 1.25389);
    glVertex2f(-0.41403, 0.76291);
    glVertex2f(-0.03009, 0.70707);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.22, 1.23);
    glVertex2f(-0.22, 0.7);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.03, 0.95);
    glVertex2f(-0.41577, 1.00216);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(223, 162, 73);
    glVertex2f(-0.64888, 0.65646);
    glVertex2f(-1.00175, 0.72042);
    glVertex2f(-1.00836, 0.23963);
    glVertex2f(-0.64667, 0.17127);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.82, 0.69);
    glVertex2f(-0.83, 0.21);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.65, 0.41);
    glVertex2f(-1.01, 0.48);
    glEnd();


    //side
    glBegin(GL_QUADS);
    glColor3ub(57, 38, 35);
    glVertex2f(2.02, 3.92);
    glColor3ub(30, 38, 41);
    glVertex2f(0.16569, 2.55);
    glColor3ub(107, 65, 53);
    glVertex2f(0.18, -0.00055);
    glVertex2f(2, -0.00055);
    glEnd();



}
void buildingBeforeverticleWindows() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(101, 58, 48);
    glVertex2f(6.00066, 6.82114);
    glVertex2f(5.32053, 6.85204);
    glVertex2f(4.91182, 6.50363);
    glVertex2f(5.99537, 6.45543);
    glEnd();
    //front
    glBegin(GL_QUADS);
    glColor3ub(27, 24, 28);
    glVertex2f(5.99537, 6.45543);
    glVertex2f(4.91182, 6.50363);
    glVertex2f(4.97154, 4.33331);
    glVertex2f(6.00122, 4.22725);
    glEnd();
    //window1
    glBegin(GL_QUADS);
    glColor3ub(216, 155, 68);
    glVertex2f(5.58879, 6.06626);
    glVertex2f(5.42083, 6.07059);
    glVertex2f(5.41845, 5.76085);
    glVertex2f(5.58879, 5.75448);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42, 6);
    glVertex2f(5.59, 6);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42, 5.91);
    glVertex2f(5.59, 5.91);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42, 5.83);
    glVertex2f(5.59, 5.83);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.48, 6.07);
    glVertex2f(5.48, 5.7);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.55, 6.07);
    glVertex2f(5.55, 5.7);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(210, 150, 63);
    glVertex2f(6, 6.05);
    glVertex2f(5.83549, 6.05498);
    glVertex2f(5.83448, 5.72331);
    glVertex2f(6, 5.72);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.84, 5.97);
    glVertex2f(6, 5.97);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.83, 5.89);
    glVertex2f(6, 5.89);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.83, 5.83);
    glVertex2f(6, 5.83);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.9, 6.05);
    glVertex2f(5.89, 5.72);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.96, 6.07);
    glVertex2f(5.96, 5.7);
    glEnd();

    //3rd window
    glBegin(GL_QUADS);
    glColor3ub(197, 111, 51);
    glVertex2f(5.17133, 5.72185);
    glVertex2f(5.00362, 5.72065);
    glVertex2f(5.00482, 5.41278);
    glVertex2f(5.17253, 5.41278);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.16773, 5.64039);
    glVertex2f(5, 5.64);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.00122, 5.56252);
    glVertex2f(5.17, 5.56);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5, 5.48);
    glVertex2f(5.17, 5.48);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.12, 5.72);
    glVertex2f(5.12, 5.4);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.06, 5.72);
    glVertex2f(5.06, 5.4);
    glEnd();

    //4th window
    glBegin(GL_QUADS);
    glColor3ub(198, 120, 54);
    glVertex2f(5.58688, 5.68345);
    glVertex2f(5.42561, 5.68833);
    glVertex2f(5.42381, 5.39291);
    glVertex2f(5.58369, 5.386);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.58, 5.61);
    glVertex2f(5.4, 5.62);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.58476, 5.53134);
    glVertex2f(5.4, 5.54);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42096, 5.46);
    glVertex2f(5.58369, 5.45);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.48, 5.69);
    glVertex2f(5.48, 5.39);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.55, 5.69);
    glVertex2f(5.54434, 5.38348);
    glEnd();

    //5th window
    glBegin(GL_QUADS);
    glColor3ub(174, 105, 49);
    glVertex2f(5.80282, 5.67387);
    glVertex2f(5.63817, 5.67752);
    glVertex2f(5.63457, 5.3767);
    glVertex2f(5.80175, 5.36434);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.8, 5.6);
    glVertex2f(5.62, 5.61);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.80069, 5.51645);
    glVertex2f(5.63, 5.52);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.8, 5.44);
    glVertex2f(5.64, 5.44);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.69, 5.68);
    glVertex2f(5.68, 5.37);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.75, 5.68);
    glVertex2f(5.75, 5.37);
    glEnd();

    //6th window
    glBegin(GL_QUADS);
    glColor3ub(171, 73, 41);
    glVertex2f(5.3769, 5.32453);
    glVertex2f(5.21626, 5.32874);
    glVertex2f(5.2099, 5.02481);
    glVertex2f(5.37763, 5.01825);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.38, 5.25);
    glVertex2f(5.21, 5.26);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.2099, 5.17212);
    glVertex2f(5.38, 5.17);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.21, 5.09);
    glVertex2f(5.38, 5.09);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.27, 5.33);
    glVertex2f(5.26824, 5.02);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.32804, 5.32817);
    glVertex2f(5.33, 5.02);
    glEnd();

    //7th window
    glBegin(GL_QUADS);
    glColor3ub(171, 73, 41);
    glVertex2f(5.8159, 5.30378);
    glVertex2f(5.62862, 5.30249);
    glVertex2f(5.62345, 4.98347);
    glVertex2f(5.81073, 4.98476);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.63, 5.22);
    glVertex2f(5.81, 5.22);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.63, 5.14);
    glVertex2f(5.81, 5.14);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.62, 5.06);
    glVertex2f(5.81, 5.06);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.68, 5.3);
    glVertex2f(5.68, 4.98);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.75, 5.32817);
    glVertex2f(5.75261, 4.98217);
    glEnd();

    //8th window
    glBegin(GL_QUADS);
    glColor3ub(171, 73, 41);
    glVertex2f(5.58376, 4.93316);
    glVertex2f(5.41422, 4.93815);
    glVertex2f(5.41405, 4.63767);
    glVertex2f(5.58043, 4.63002);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.41, 4.87);
    glVertex2f(5.59, 4.86);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.41, 4.78);
    glVertex2f(5.59, 4.78);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.41, 4.71);
    glVertex2f(5.58, 4.71);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.48, 4.94);
    glVertex2f(5.48, 4.63);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.54, 4.93);
    glVertex2f(5.53698, 4.62658);
    glEnd();

    //9th window
    glBegin(GL_QUADS);
    glColor3ub(129, 55, 35);
    glVertex2f(5.16774, 4.97713);
    glVertex2f(5.018, 4.97866);
    glVertex2f(5.01559, 4.66269);
    glVertex2f(5.17385, 4.66236);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.02, 4.9);
    glVertex2f(5.17, 4.9);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.02, 4.8);
    glVertex2f(5.17, 4.8);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.02, 4.74);
    glVertex2f(5.17966, 4.73473);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.06, 4.98);
    glVertex2f(5.06, 4.66);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.12, 4.98);
    glVertex2f(5.11936, 4.65646);
    glEnd();


}
void buildingAboveBottomRight() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(56, 37, 31);
    glVertex2f(6.00122, 4.22725);
    glVertex2f(4.97154, 4.33331);
    glVertex2f(4.46333, 3.63507);
    glVertex2f(6.00122, 3.44946);
    glEnd();

    //front
    glBegin(GL_QUADS);
    glColor3ub(22, 20, 23);
    glVertex2f(6.00122, 3.44946);
    glVertex2f(4.46333, 3.63507);
    glVertex2f(4.47349, 2.02625);
    glVertex2f(6, 1.96);
    glEnd();

    //1st_window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(4.9122, 3.33915);
    glVertex2f(4.80321, 3.34045);
    glVertex2f(4.8, 2.6);
    glVertex2f(4.91004, 2.59156);
    glEnd();
    //2nd window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.11792, 3.30495);
    glVertex2f(5.00295, 3.31322);
    glVertex2f(5.00035, 2.57379);
    glVertex2f(5.11233, 2.56);
    glEnd();
    //3rd window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.7069, 3.23365);
    glVertex2f(5.60107, 3.25232);
    glVertex2f(5.59796, 2.5022);
    glVertex2f(5.71312, 2.49286);
    glEnd();
    //4rth window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.91233, 3.20875);
    glVertex2f(5.8065, 3.23054);
    glVertex2f(5.8065, 2.4773);
    glVertex2f(5.91855, 2.46485);
    glEnd();

    //next row 
    //5th window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.51, 2.44827);
    glVertex2f(5.39891, 2.46153);
    glVertex2f(5.39, 2.05);
    glVertex2f(5.51, 2.04);
    glEnd();
    //6th window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.71417, 2.42627);
    glVertex2f(5.59802, 2.43456);
    glVertex2f(5.6, 2.02);
    glVertex2f(5.72, 2.00338);
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

    for (float x = 4.34; x <= 6; x += 0.09) {
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


    //antenna
    glBegin(GL_POLYGON);
    glColor3ub(134, 92, 70);
    glVertex2f(-5.15544, 13.50317);
    glColor3ub(51, 37, 37);
    glVertex2f(-5.19025, 13.50279);
    glColor3ub(84, 64, 54);
    glColor3ub(33, 31, 38);
    glVertex2f(-5.23, 12.79);

    glVertex2f(-5.13918, 12.78789);
    //glVertex2f(-5.1, 10.94);
    glEnd();
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

    //toptower
    glBegin(GL_TRIANGLES);
    glColor3ub(80, 51, 39);
    glVertex2f(-4.82, 12.71);
    glColor3ub(71, 46, 39);
    glVertex2f(-4.83099, 12.57187);
    glColor3ub(98, 64, 48);
    glVertex2f(-4.4, 12.6);
    glEnd();


    // Tower Logo
   //W
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.82666, 11.08687);
    glVertex2f(-5.75902, 11.28983);
    glVertex2f(-5.77953, 11.51969);
    glVertex2f(-5.8714, 11.51796);
    glVertex2f(-5.89019, 11.28498);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.82666, 11.08687);
    glVertex2f(-5.78938, 10.88175);
    glVertex2f(-5.65093, 10.88175);
    glVertex2f(-5.58534, 11.52303);
    glVertex2f(-5.72623, 11.51938);
    glVertex2f(-5.75902, 11.28983);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.82666, 11.08687);
    glVertex2f(-5.85983, 10.87446);
    glVertex2f(-5.99829, 10.87446);
    glVertex2f(-6, 11.5);
    glVertex2f(-5.92784, 11.49995);
    glVertex2f(-5.89019, 11.28498);
    glEnd();
    //A
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.60356, 10.88539);
    glVertex2f(-5.4651, 10.8866);
    glVertex2f(-5.45538, 11.02506);
    glVertex2f(-5.38251, 11.02628);
    glVertex2f(-5.36915, 10.8866);
    glVertex2f(-5.22583, 10.89632);
    glVertex2f(-5.33636, 11.52546);
    glVertex2f(-5.50154, 11.52546);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(35, 30, 36);
    glVertex2f(-5.4651, 10.8866);
    glVertex2f(-5.36915, 10.89511);
    glVertex2f(-5.38251, 11.02628);
    glVertex2f(-5.45538, 11.02628);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(35, 30, 36);
    glVertex2f(-5.41655, 11.26);
    glVertex2f(-5.46, 11.11);
    glVertex2f(-5.37, 11.11);
    glEnd();

    //Y
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.09764, 11.3497);
    glVertex2f(-5.1, 10.9);
    glVertex2f(-5.1817, 10.89838);
    glVertex2f(-5.18318, 11.14617);
    glVertex2f(-5.29675, 11.53554);
    glVertex2f(-5.13598, 11.53111);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.09764, 11.3497);
    glVertex2f(-5.1, 10.9);
    glVertex2f(-5, 10.9);
    glVertex2f(-5.00177, 11.17419);
    glVertex2f(-4.89557, 11.54439);
    glVertex2f(-5.05191, 11.54291);
    glEnd();

    //N
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.73653, 11.07);
    glVertex2f(-4.68409, 11.35);
    glVertex2f(-4.72779, 11.55061);
    glVertex2f(-4.87782, 11.55353);
    glVertex2f(-4.87782, 10.91115);
    glVertex2f(-4.74673, 10.91407);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.68409, 11.35);
    glVertex2f(-4.73653, 11.07);
    glVertex2f(-4.69574, 10.91844);
    glVertex2f(-4.52823, 10.92135);
    glVertex2f(-4.5326, 11.55207);
    glVertex2f(-4.66807, 11.54916);
    glEnd();

    //E
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.49659, 10.93531);
    glVertex2f(-4.19376, 10.93531);
    glVertex2f(-4.19479, 11.08621);
    glVertex2f(-4.49761, 11.08621);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.49537, 11.391);
    glVertex2f(-4.19115, 11.39193);
    glVertex2f(-4.19301, 11.56925);
    glVertex2f(-4.49648, 11.56803);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.34979, 11.32437);
    glVertex2f(-4.35, 11.39);
    glVertex2f(-4.49537, 11.391);
    glVertex2f(-4.49761, 11.08518);
    glVertex2f(-4.36, 11.09);
    glVertex2f(-4.35595, 11.15601);
    glVertex2f(-4.26972, 11.32539);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.5, 11.32);
    glVertex2f(-4.5, 11.15);
    glVertex2f(-4.2687, 11.15601);
    glVertex2f(-4.26972, 11.32539);
    glEnd();

    //E shadow
    glBegin(GL_POLYGON);
    glColor3ub(12, 24, 38);
    glVertex2f(-4.19115, 11.39193);
    glVertex2f(-4.13284, 11.38239);
    glVertex2f(-4.13207, 11.53779);
    glVertex2f(-4.19301, 11.56925);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(12, 24, 38);
    glVertex2f(-4.19376, 10.93531);
    glVertex2f(-4.13592, 10.93388);
    glVertex2f(-4.13515, 11.06543);
    glVertex2f(-4.19479, 11.08621);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(12, 24, 38);
    glVertex2f(-4.2687, 11.15601);
    glVertex2f(-4.21285, 11.1516);
    glVertex2f(-4.21131, 11.30853);
    glVertex2f(-4.26972, 11.32539);
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

void buildingNextTobuildingWithVerticleWindows() {
    glBegin(GL_QUADS);
    glColor3ub(21, 20, 23); // Building rgb(21, 20, 23)
    glVertex2f(3.8, 8.7);
    glVertex2f(4.28, 8.69);
    glVertex2f(4.28, 9.73);
    glVertex2f(3.8, 9.73);
    glEnd();


    //Windows

    //First floor
    for (float i = 3.83051; i <= 4.2; i += 0.0818000000)
    {
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glColor3ub(206, 158, 114); // Building rgb(206, 158, 114)
        glVertex2f(i, 9.69971);
        glVertex2f(i, 9.63574);
        glEnd();
    }
    //Second floor
    for (float i = 3.854; i <= 4.25015; i += 0.0653600000)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(206, 158, 114); // Building rgb(206, 158, 114)
        glVertex2f(i, 9.53336);
        glVertex2f(i, 9.60219);
        glEnd();
    }

    //Third floor
    for (float i = 3.82818; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2.2);
        glBegin(GL_LINES);
        glColor3ub(206, 158, 114); // Building rgb(206, 158, 114)
        glVertex2f(i, 9.42444);
        glVertex2f(i, 9.49947);
        glEnd();
    }

    //Forth floor
    for (float i = 3.89999; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(207, 146, 94); // Building rgb(207, 146, 94)
        glVertex2f(i, 9.32762);
        glVertex2f(i, 9.4);
        glEnd();
    }

    //Fifth floor
    for (float i = 3.85562; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(175, 126, 91); // Building rgb(175, 126, 91)
        glVertex2f(i, 9.22354);
        glVertex2f(i, 9.28486);
        glEnd();
    }
    //Sixth floor
    for (float i = 3.84072; i <= 4.3; i += 0.0818000000)
    {
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glColor3ub(191, 147, 102); // Building rgb(191, 147, 102)
        glVertex2f(i, 9.12077);
        glVertex2f(i, 9.1843);
        glEnd();
    }

    //Seventh floor
    for (float i = 3.85164; i <= 4.25015; i += 0.084)
    {
        glLineWidth(2.2);
        glBegin(GL_LINES);
        glColor3ub(175, 161, 97); // Building rgb(175, 161, 97)
        glVertex2f(i, 9.02349);
        glVertex2f(i, 9.08503);
        glEnd();
    }

    //8th floor
    for (float i = 3.86231; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(174, 160, 82); // Building rgb(174, 160, 82)
        glVertex2f(i, 8.91063);
        glVertex2f(i, 8.97637);
        glEnd();
    }


    //9th floor
    for (float i = 3.84753; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(135, 120, 49); // Building rgb(135, 120, 49)
        glVertex2f(i, 8.81608);
        glVertex2f(i, 8.87739);
        glEnd();
    }

    //10th floor
    for (float i = 3.85049; i <= 4.25015; i += 0.084)
    {
        glLineWidth(2.2);
        glBegin(GL_LINES);
        glColor3ub(104, 94, 64); // Building rgb(104, 94, 64)
        glVertex2f(i, 8.7);
        glVertex2f(i, 8.7725);
        glEnd();
    }

}

void policeBuilding() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(124, 63, 44);
    glVertex2f(4.47239, 2.20322);
    glVertex2f(3.76, 2.32);
    glColor3ub(48, 33, 34);
    glVertex2f(3.76, 1.06);
    glVertex2f(3.826, 1.04718);
    glEnd();
    //roofboxroof
    glBegin(GL_QUADS);
    glColor3ub(136, 79, 55);
    glVertex2f(4.24392, 3.01404);
    glVertex2f(3.56628, 3.0946);
    glVertex2f(3.76, 2.71);
    glVertex2f(4.01694, 2.68053);
    glEnd();
    //roofbox
    glBegin(GL_QUADS);
    glColor3ub(19, 28, 38);
    glVertex2f(3.76, 2.71);
    glVertex2f(3.76, 1.88);
    glVertex2f(4.02621, 1.85602);
    glVertex2f(4.01694, 2.68053);
    glEnd();
    //roofboxside
    glBegin(GL_QUADS);
    glColor3ub(64, 40, 36);
    glVertex2f(4.23422, 3.00754);
    glVertex2f(4.01639, 2.68);
    glColor3ub(51, 34, 35);
    glVertex2f(4.0245, 1.845);
    glVertex2f(4.26099, 2.2379);
    glEnd();

    //roofbox2roof
    glBegin(GL_QUADS);
    glColor3ub(66, 37, 27);
    glVertex2f(2.78904, 3.89236);
    glVertex2f(2.38865, 3.93822);
    glColor3ub(171, 95, 43);
    glVertex2f(2.15984, 3.73458);
    glVertex2f(2.59458, 3.70026);
    glEnd();
    //roofbox2front
    glBegin(GL_QUADS);
    glColor3ub(140, 56, 37);
    glVertex2f(2.59458, 3.70026);
    glVertex2f(2.15984, 3.73458);
    glColor3ub(137, 52, 32);
    glVertex2f(2.16343, 3.21424);
    glVertex2f(2.58951, 3.15239);
    glEnd();
    //roofbox2side
    glBegin(GL_QUADS);
    glColor3ub(140, 56, 37);
    glVertex2f(2.59458, 3.70026);
    glVertex2f(2.15984, 3.73458);
    glColor3ub(137, 52, 32);
    glVertex2f(2.16343, 3.21424);
    glVertex2f(2.58951, 3.15239);
    glEnd();
    //billboard
    glBegin(GL_QUADS);
    glColor3ub(29, 27, 32);
    glVertex2f(3.75885, 3.03858);
    glVertex2f(0.57507, 3.4297);
    glVertex2f(0.55727, 1.56055);
    glVertex2f(3.76, 1.06);
    glEnd();
    //sidewall
    glBegin(GL_QUADS);
    glColor3ub(40, 25, 22);
    glVertex2f(2.78904, 3.89236);
    glVertex2f(2.59458, 3.70026);
    glColor3ub(80, 35, 29);
    glVertex2f(2.58951, 3.15239);
    glVertex2f(2.79822, 3.15112);
    glEnd();


    //ledge
    glBegin(GL_QUADS);
    glColor3ub(73, 45, 44);
    glVertex2f(0.50014, 1.58612);
    glVertex2f(0.41848, 1.52634);
    glVertex2f(3.7814, 0.96076);
    glVertex2f(3.826, 1.05);
    glEnd();

    //front below
    glBegin(GL_QUADS);
    glColor3ub(38, 35, 38);
    glVertex2f(0.7, 1.29);
    glVertex2f(0.70938, -0.00055);
    glVertex2f(3.77315, 0.00238);
    glVertex2f(3.76303, 0.78);
    glEnd();
    //1st window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(1.02909, 0.83457);
    glVertex2f(0.83844, 0.85121);
    glVertex2f(0.83833, 0.35357);
    glVertex2f(1.02542, 0.33415);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(0.84, 0.61);
    glVertex2f(1.03, 0.58);
    glEnd();
    //2nd window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(1.36419, 0.77159);
    glVertex2f(1.17216, 0.79384);
    glVertex2f(1.1663, 0.2997);
    glVertex2f(1.36068, 0.26809);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(1.17, 0.55);
    glVertex2f(1.36, 0.52);
    glEnd();
    //3rd window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(2.03434, 0.64471);
    glVertex2f(1.86108, 0.67719);
    glVertex2f(1.85747, 0.17907);
    glVertex2f(2.03073, 0.15741);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(1.86, 0.43);
    glVertex2f(2.03, 0.4);
    glEnd();

    //4th window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(2.74097, 0.52306);
    glVertex2f(2.55001, 0.55084);
    glVertex2f(2.54306, 0.05433);
    glVertex2f(2.74097, 0.02309);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(2.55, 0.3);
    glVertex2f(2.74, 0.28);
    glEnd();

    //4th window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(3.09512, 0.46056);
    glVertex2f(2.9111, 0.49528);
    glVertex2f(2.9, 0);
    glVertex2f(3.1, 0);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(2.91, 0.24);
    glVertex2f(3.09, 0.2071);
    glEnd();
    //side
    glBegin(GL_QUADS);
    glColor3ub(28, 26, 30);
    glVertex2f(4.47349, 2.02625);
    glVertex2f(3.755, 1);
    glVertex2f(3.77364, 0);
    glVertex2f(4.48, 0);
    glEnd();

    //ledge
    glBegin(GL_QUADS);
    glColor3ub(43, 37, 41);
    glVertex2f(0.41848, 1.52634);
    glVertex2f(0.39982, 1.33326);
    glVertex2f(3.78498, 0.77462);
    glVertex2f(3.7814, 0.96076);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(38, 30, 32);
    glVertex2f(3.7814, 0.98);
    glVertex2f(3.78498, 0.77462);
    glVertex2f(4.48108, 2.02938);
    glVertex2f(4.47239, 2.20322);
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

    buildingNextTobuildingWithVerticleWindows();
    buildingWithVerticleWindows();
    wayneTower();
    Buildinginfrontbatman();
    batmanBuilding();
    policeBuilding();
    buildingBeforeverticleWindows();
    buildingAboveBottomRight();
    bottomRightbuilding();

    policeBlimp();
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
    // sndPlaySound("bat.wav", SND_ASYNC);
    // sndPlaySound("instrumental.wav", SND_ASYNC);
    // PlaySound("instrumental.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
