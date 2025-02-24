#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <3ds.h>
#include <citro2d.h>
#include <stdlib.h>

extern C3D_RenderTarget *top;
extern C3D_RenderTarget *bottom;
extern C2D_Font font;

void Screen_init ();
void Screen_setBackground (C3D_RenderTarget *, const int);
void Screen_drawCircle (const float, const float, const float, const u32);
void Screen_drawJoystick (const circlePosition *, const float, const float, const float);
void Screen_drawText ();

#endif
