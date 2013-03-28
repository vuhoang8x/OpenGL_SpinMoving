#include "CGLTextureBasicLoad.h"
float CGLTextureBasicLoad::slice;
CHiResTimer *CGLTextureBasicLoad::g_hiResTimer;
CGLTextureBasicLoad::CGLTextureBasicLoad()
{
    //ctor
    g_hiResTimer = new CHiResTimer();
    g_hiResTimer->Init();
    g_hiResTimer->InitPassSecond();
    m_textureOne = new CTargaImage();
    m_textureOne->Load(/*"c:\\test_tree_1.tga"*/"c:\\spin.tga");
    m_textureSpindle = new CTargaImage();
    m_textureSpindle->Load("c:\\spindle_1.tga");
    m_textureBMP = new Bitmap();
    m_textureBMP->loadBMP("c:\\spindle.bmp");
    m_textureBMP->SetColorKey(255, 255, 255);
    slice = 0.55;
}

CGLTextureBasicLoad::~CGLTextureBasicLoad()
{
    //dtor
}
void CGLTextureBasicLoad::GLInit()
{
    glClearColor(0.3, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);


    // draw the left polygon
    //glPushMatrix();
}
void CGLTextureBasicLoad::Idle()
{
    static float sign = 1;
    float t = g_hiResTimer->GetPassedSeconds();
    if (t >= 0.05)
    {
        if (slice > 0.7)
            sign = -1;
        else if (slice < 0.55)
            sign = 1;
        slice += sign * 0.01;
        glutPostRedisplay();
        g_hiResTimer->InitPassSecond();
    }
}
void CGLTextureBasicLoad::Resize(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);		// reset the viewport to new dimensions
	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
    glLoadIdentity();						// reset projection matrix

	// calculate perspective
	gluPerspective(54.0f,(GLfloat)width/(GLfloat)height,1.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);				// set modelview matrix

}
void CGLTextureBasicLoad::key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'a':
        case 'A':
            slice += 0.01;
            break;

        case 'f':
        case 'F':
            if (slice > 0.55)
            {
                slice -= 0.01;
            }
            break;
    }
    glutPostRedisplay();
}
void CGLTextureBasicLoad::LoadTexture()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    // retrieve "unused" texture object
	glGenTextures(1, &m_textureObjectOne);

	// bind the texture object
	glBindTexture(GL_TEXTURE_2D, m_textureObjectOne);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_textureOne->GetWidth(), m_textureOne->GetHeight(),
	//			 0, GL_RGB, GL_UNSIGNED_BYTE, m_textureOne->GetImage());
	//Using for Targe Image
	glTexImage2D(GL_TEXTURE_2D, 0, 4, m_textureOne->GetWidth(), m_textureOne->GetHeight(),
				 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureOne->GetImage());


    glGenTextures(1, &m_textureObjectSpindle);

    glBindTexture(GL_TEXTURE_2D, m_textureObjectSpindle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, m_textureSpindle->GetWidth(), m_textureSpindle->GetHeight(),
				 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureSpindle->GetImage());

    //Using for BMP Image
    //glTexImage2D(GL_TEXTURE_2D, 0, 3, m_textureBMP->width, m_textureBMP->height, 0,
	//	  GL_RGB, GL_UNSIGNED_BYTE, m_textureBMP->data);
}
void CGLTextureBasicLoad::Draw(GLdouble x, GLdouble y)
{
    // clear screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // load the identity matrix (clear to default position and orientation)
    glLoadIdentity();
     glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);

    glTranslatef(0.0, 0, -1.7f);
    //glRotatef(90.0, 1.0, 0.0, 0.0);
    // bind the texture
    glBindTexture(GL_TEXTURE_2D, m_textureObjectOne);
    // draw the plane at the world origin
    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.8, 0.2, 0.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(0.2, 0.2, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(0.8, 0.8, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(0.2, 0.8, 0.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_textureObjectSpindle);
     glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(1.0, 0.0); glVertex3f(0.55, slice, 0.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(0.4, slice, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(0.55, slice + 0.15, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(0.4, slice + 0.15, 0.0);
    glEnd();

    glFlush();  // Swap front and back buffers (of double buffered mode)
}
