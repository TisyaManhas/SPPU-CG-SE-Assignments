#include<GL/glut.h>

void triangle1() {
   glClear(GL_COLOR_BUFFER_BIT);// Clears the buffer
   glClearColor(1.0,1.0,0.0,0.0);
   glBegin(GL_TRIANGLES);        // Graphics Primitive used- GL_POLYGON
   glColor3f(0.0, 1.0, 0.0);   // Used for coloring object
    glVertex2f(-0.6, -0.75); // Used to draw vertex
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.6, -0.75);
   glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0, 0.75);
   glEnd();
  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
}


int main(int argc, char** argv)
{
  glutInit(&argc, argv); // Initializes GLUT
  glutInitDisplayMode(GLUT_RGB);// Initializes the display mode
  glutCreateWindow(" updated trianle ");// Crates Output Window
  glutInitWindowPosition(0,0); //Initializes Windows initial position
 // glutInitWindowSize(500,600);   // Defines dimensions of  Output Window
   glutReshapeWindow(800,800);  // Change the size of the current window

  glutDisplayFunc(triangle1); // Registers callback function

  glutMainLoop(); //Enters the main event loop

  return 0;

}
