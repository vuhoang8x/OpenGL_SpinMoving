#include "COGLImplement.h"

COGLImplement::COGLImplement()
{
    //ctor
    //display = &COGLImplement::Display;
    pixel = new COGLDrawPixel();
    texture = new CGLTextureBasicLoad();
    sprite = new CGLTextureSprite();
}

COGLImplement::~COGLImplement()
{
    //dtor
}


void COGLImplement::Display()
{
    //pixel->Draw(0.1, 0);
    texture->Draw(0.1, 0.1);
    //sprite->Draw();

}

void COGLImplement::GLCreateWindow(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(640, 480);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("SPIN-SPINDLE");  // Create window with the given title
    glutDisplayFunc(COGLImplement::Display);       // Register callback handler for window re-paint event
    //glutReshapeFunc(COGLDrawPixel::Resize);                      // Our own OpenGL initialization
    glutReshapeFunc(CGLTextureBasicLoad::Resize);
    //glutReshapeFunc(CGLTextureSprite::Resize);
    glutKeyboardFunc(CGLTextureBasicLoad::key);
    glutIdleFunc(CGLTextureBasicLoad::Idle);
    //pixel->GLInit();
    texture->GLInit();
    texture->LoadTexture();
    //sprite->GLInit();
    //sprite->LoadTexture();
    glutMainLoop();                 // Enter the infinite event-processing loop
}

