#ifndef CGLTEXTUREBASICLOAD_H
#define CGLTEXTUREBASICLOAD_H
#include "GL/glu.h"
#include "GL/glut.h"
#include "CTargaImage.h"
#include "CBMPImage.h"
#include "timer.h"

class CGLTextureBasicLoad
{
    public:
        CGLTextureBasicLoad();
        virtual ~CGLTextureBasicLoad();
        void LoadTexture();
        void LoadSpindle();
        void GLInit();
        void Draw (GLdouble x, GLdouble y);
        static void Idle();
        static void Resize (GLsizei width, GLsizei height);
        static void key(unsigned char key, int x, int y);
    protected:
        CTargaImage *m_textureOne;
        CTargaImage *m_textureSpindle;
        Bitmap *m_textureBMP;
        static CHiResTimer *g_hiResTimer;
        static float slice;
        unsigned int m_textureObjectOne;
        unsigned int m_textureObjectSpindle;
        //static unsigned int m_textureObjectOne;
    private:
};
//unsigned int CGLTextureBasicLoad::m_textureObjectOne;
#endif // CGLTEXTUREBASICLOAD_H
