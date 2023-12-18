#include <GL/glut.h>
#include <iostream>
#include <math.h>

float ellipseX = 2.19;  // Initial x-coordinate of the ellipse
float speed = 0.01;     // Speed of movement

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
    drawEllipse(ellipseX, 14.51, 200, 100, 100, 21, 29, 36);
}

void update(int value) {
    // Update the x-coordinate of the ellipse for left to right movement
    ellipseX += speed;

    // Adjust the speed as needed
    // You can add conditions here to change the direction or stop movement if needed

    glutPostRedisplay(); // Request a redraw to create animation effect
    glutTimerFunc(16, update, 0); // 60 frames per second (1000 ms / 60 frames = 16.66 ms per frame)
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, 0, 17);
    glMatrixMode(GL_MODELVIEW);

    // Objects
    policeBlimp();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT

    glutInitWindowSize(750, 1040);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 750) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 1061) / 2);
    glutCreateWindow("Batman"); // Create a window with the given title
    glutDisplayFunc(display);   // Register display callback handler for window re-paint

    // Initialize update function and timer
    glutTimerFunc(0, update, 0);

    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
