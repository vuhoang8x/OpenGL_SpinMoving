#ifndef COGLDRAWPIXEL_H
#define COGLDRAWPIXEL_H
#include "GL/glu.h"
#include "GL/glut.h"

class COGLDrawPixel
{
    public:
        COGLDrawPixel();
        virtual ~COGLDrawPixel();
        void GLInit();
        void Draw (GLdouble x, GLdouble y);
        static void Resize(GLsizei width, GLsizei height);
    protected:
    private:
};

#endif // COGLDRAWPIXEL_H
