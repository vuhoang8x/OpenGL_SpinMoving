#include "COGLDrawPixel.h"

COGLDrawPixel::COGLDrawPixel()
{
    //ctor
}

COGLDrawPixel::~COGLDrawPixel()
{
    //dtor
}
void COGLDrawPixel::GLInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    //glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glEnable(GL_TEXTURE_2D);
}
void COGLDrawPixel::Resize(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix

   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}
void COGLDrawPixel::Draw(GLdouble x, GLdouble y)
{
    glPointSize(4.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}
