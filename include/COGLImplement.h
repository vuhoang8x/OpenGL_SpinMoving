#ifndef COGLIMPLEMENT_H
#define COGLIMPLEMENT_H
#include "GL/glu.h"
#include "GL/glut.h"
#include "COGLDrawPixel.h"
#include "CGLTextureBasicLoad.h"
#include "CGLTextureSprite.h"

class COGLImplement
{
    public:
        COGLImplement();
        ~COGLImplement();
        void GLCreateWindow(int argc, char** argv);
        static void Display();
    protected:
        static COGLDrawPixel *pixel;
        static CGLTextureBasicLoad *texture;
        static CGLTextureSprite *sprite;
    private:
};

#endif // COGLIMPLEMENT_H
