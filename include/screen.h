#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <3ds.h>
#include <citro2d.h>

namespace Screen
{
extern C3D_RenderTarget *top;
extern C3D_RenderTarget *bottom;
extern C2D_TextBuf g_staticBuf;
extern C2D_Font font;


void setBackground (C3D_RenderTarget *, int);
}

#endif
