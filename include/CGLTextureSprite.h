#ifndef CGLTEXTURESPRITE_H
#define CGLTEXTURESPRITE_H
#include "GL/glu.h"
#include "GL/glut.h"
#include "CTargaImage.h"
#include "timer.h"
#include "CSpriteSheet.h"

class CGLTextureSprite
{
    public:
        CGLTextureSprite();
        virtual ~CGLTextureSprite();
        void GLInit();
        void LoadTexture();
        void Draw();
        static void Resize(GLsizei width, GLsizei height);
    protected:
        GLint _spriteWidth, _spriteHeight;
        CTargaImage *m_textureOne;
        unsigned int m_textureObjectOne;
    private:
};

#endif // CGLTEXTURESPRITE_H
