#include "CGLTextureSprite.h"

CGLTextureSprite::CGLTextureSprite()
{
    //ctor
    _spriteWidth = _spriteHeight = 96;
    m_textureOne = new CTargaImage();
    m_textureOne->Load("king_test.tga");
}

CGLTextureSprite::~CGLTextureSprite()
{
    //dtor
}
void CGLTextureSprite::GLInit()
{
   // Enable 2D texturing
	glEnable(GL_TEXTURE_2D);
	// Choose a smooth shading model
    glShadeModel(GL_SMOOTH);
	// Set the clear color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Enable the alpha test. This is needed
	// to be able to have images with transparent
	// parts.
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.0f);
}
void CGLTextureSprite::LoadTexture()
{
    glGenTextures(1, &m_textureObjectOne);

    glBindTexture(GL_TEXTURE_2D, m_textureObjectOne);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // Sets drawing mode to GL_MODULATE
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //Using load 24 bit (support transparency)
    //glTexImage2D(GL_TEXTURE_2D, 0, 3, m_textureOne->GetWidth(), m_textureOne->GetHeight(),
	//			 0, GL_RGB, GL_UNSIGNED_BYTE, m_textureOne->GetImage());
    //Using load 32 bit (support transparency)
    //Tested with tga file
    glTexImage2D(GL_TEXTURE_2D, 0, 4, m_textureOne->GetWidth(), m_textureOne->GetHeight(),
				 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureOne->GetImage());


}
void CGLTextureSprite::Resize(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(0.0,width,height,0.0,-1.0,1.0);

    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }

	glMatrixMode(GL_MODELVIEW);

}
void CGLTextureSprite::Draw()
{
    // clear screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load the identity matrix (clear to default position and orientation)
    //glLoadIdentity();
    // draw the left polygon
    //glPushMatrix();

    //glTranslatef(-5, -5, 1.0f);

    glBindTexture(GL_TEXTURE_2D, m_textureObjectOne);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    // draw the plane at the world origin
    float xT	 = 0;
    float yB = (float)(96/m_textureOne->GetHeight());
    float yL   = 0;
    float xR  = (float)(96/m_textureOne->GetWidth());

    float Top	 = ((float)0)/m_textureOne->GetHeight();
    float Bottom = ((float)96)/m_textureOne->GetHeight();
    float Left   = ((float)0)/m_textureOne->GetWidth();
    float Right  = ((float)96)/m_textureOne->GetWidth();

    GLint iXOffset = 0;
    GLint iYOffset = 0;


    CSpriteSheet sprite(m_textureObjectOne, m_textureOne->GetWidth(), m_textureOne->GetWidth(), 60, 60);

    glBegin(GL_QUADS);
        //sprite.drawSprite(-5, -5, 0);
        sprite.drawSprite(0, 6);
    glEnd();

    // Draw the textured rectangle.
    /*
    glBegin(GL_QUADS);
        glTexCoord2f(Left,Top);		glVertex3i(iXOffset,iYOffset,0);
        glTexCoord2f(Left,Bottom);	glVertex3i(iXOffset,iYOffset+1,0);
        glTexCoord2f(Right,Bottom);	glVertex3i(iXOffset+1,iYOffset+1,0);
        glTexCoord2f(Right,Top);	glVertex3i(iXOffset+1,iYOffset,0);
    glEnd();
    */
    /*
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    */

    glFlush();  // Swap front and back buffers (of double buffered mode)
}
