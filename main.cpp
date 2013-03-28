#include <iostream>
#include "COGLImplement.h"
using namespace std;
COGLDrawPixel *COGLImplement::pixel ;
CGLTextureBasicLoad *COGLImplement::texture;
CGLTextureSprite *COGLImplement::sprite;
int main(int argc, char** argv)
{
    cout << "Hello world!" << endl;
    COGLImplement* window;
    window = new COGLImplement();
    window->GLCreateWindow(argc, argv);

    return 0;
}
