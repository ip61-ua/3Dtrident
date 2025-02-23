#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <3ds.h>
#include <citro2d.h>

extern C3D_RenderTarget *top;
extern C3D_RenderTarget *bottom;
extern C2D_TextBuf g_staticBuf;
extern C2D_Font font;

void Screen_setBackground (C3D_RenderTarget *, const int);
void Screen_drawCircle (const float, const float, const float, const u32);

#endif
