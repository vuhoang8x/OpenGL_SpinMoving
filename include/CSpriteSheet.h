#ifndef CSPRITESHEET_H
#define CSPRITESHEET_H
#include "GL/glu.h"
#include "GL/glut.h"
#include "GL/gl.h"

class CSpriteSheet {
    int spriteWidth, spriteHeight;
    int texWidth, texHeight;

    int tex;

public:
    CSpriteSheet(int t, int tW, int tH, int sW, int sH)
    : tex(t), texWidth(tW), texHeight(tH), spriteWidth(sW), spriteHeight(sH)
    {}

    void drawSprite(float posX, float posY, int frameIndex);
    void drawSprite(int frameIndex, int numPerRow);
};

#endif // CSPRITESHEET_H
