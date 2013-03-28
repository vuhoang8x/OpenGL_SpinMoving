#include "CSpriteSheet.h"

void CSpriteSheet::drawSprite(float posX, float posY, int frameIndex)
{
    const float verts[] = {
        posX, posY,
        posX + spriteWidth, posY,
        posX + spriteWidth, posY + spriteHeight,
        posX, posY + spriteHeight
    };
    const float tw = float(spriteWidth) / texWidth;
    const float th = float(spriteHeight) / texHeight;
    const int numPerRow = texWidth / spriteWidth;
    const float tx = (frameIndex % numPerRow) * tw;
    const float ty = (frameIndex / numPerRow + 1) * th;
    const float texVerts[] = {
        tx, ty,
        tx + tw, ty,
        tx + tw, ty + th,
        tx, ty + th
    };

    // ... Bind the texture, enable the proper arrays

    glTexCoord2f(texVerts[0], texVerts[1]); glVertex3f(texVerts[0], texVerts[1], 0.0);
    glTexCoord2f(texVerts[2], texVerts[3]); glVertex3f(texVerts[2], texVerts[3], 0.0);
    glTexCoord2f(texVerts[4], texVerts[5]); glVertex3f(texVerts[4], texVerts[5], 0.0);
    glTexCoord2f(texVerts[6], texVerts[7]); glVertex3f(texVerts[6], texVerts[7], 0.0);


}
void CSpriteSheet::drawSprite(int frameIndex, int numPerRow)
{
    const float tw = float(spriteWidth) / texWidth;
    const float th = float(spriteHeight) / texHeight;
    const float ty = (frameIndex % numPerRow) * tw;
    const float tx = (frameIndex / numPerRow + 1) * th;
    const float texVerts[] = {
        tx, ty,
        tx + tw, ty,
        tx + tw, ty + th,
        tx, ty + th
    };

    glTexCoord2f(texVerts[0], texVerts[1]); glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(texVerts[2], texVerts[3]); glVertex3f(1.0, 0.0, 0.0);
    glTexCoord2f(texVerts[4], texVerts[5]); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(texVerts[6], texVerts[7]); glVertex3f(0.0, 1.0, 0.0);
}
