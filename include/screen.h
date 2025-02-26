#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "colors.h"
#include <math.h>
#include <3ds.h>
#include <citro2d.h>
#include <stdlib.h>

extern u8 PAGE_CURRENT;

enum PAGE_STATE
{
  PAGE_MAIN,
  PAGE_ABOUT,
  PAGE_PAINT,
  PAGE_3D,
  PAGE_GYRO,
  PAGE_AUDIO
};

extern C3D_RenderTarget *top;
extern C3D_RenderTarget *bottom;
extern C2D_TextBuf g_staticBuf;
extern C2D_Font font;

void Screen_init ();

void Screen_setupPage (bool *cond, void (*start) ());

void Screen_changePage (const enum PAGE_STATE page, void (*quit) ());

void Screen_setBackground (C3D_RenderTarget *target, const int color);

void Screen_drawCircle (const float x, const float y, const float radius,
                        const u32 color);

void Screen_drawJoystick (const circlePosition *p, const float x,
                          const float y, const float r);

const char *Screen_initText (C2D_Text *text, C2D_TextBuf buf, const char *str);

void Screen_drawText (const C2D_Text *srctxt, const float x, const float y,
                      const float scaleX, const float scaleY, const u32 c);

void Screen_drawRect (const float x, const float y, const float w,
                      const float h, const u32 c);

void Screen_drawTriangle (const float x0, const float y0, const float x1,
                          const float y1, const float x2, const float y2,
                          const u32 c);

void Screen_drawDPadArrow (const float x, const float y, const float rotation);

#endif
