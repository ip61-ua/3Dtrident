#include "screen.h"

u8 PAGE_CURRENT;

C3D_RenderTarget *top;
C3D_RenderTarget *bottom;
C2D_TextBuf g_staticBuf;
C2D_Font font;

void
Screen_init ()
{
  PAGE_CURRENT = PAGE_MAIN;
  g_staticBuf = C2D_TextBufNew (4096);
  top = C2D_CreateScreenTarget (GFX_TOP, GFX_LEFT);
  bottom = C2D_CreateScreenTarget (GFX_BOTTOM, GFX_LEFT);
  font = C2D_FontLoad ("romfs:/InterVariable.bcfnt");
}

void
Screen_setupPage (bool *cond, void (*start) ())
{
  if (!(*cond))
    {
      if (start != NULL)
        start ();

      *cond = true;
    }
}

void
Screen_changePage (const enum PAGE_STATE page, void (*quit) ())
{
  if (quit != NULL)
    quit ();
  PAGE_CURRENT = page;
}

void
Screen_setBackground (C3D_RenderTarget *target, const int color)
{
  C2D_TargetClear (target, color);
  C2D_SceneBegin (target);
}

void
Screen_drawCircle (const float x, const float y, const float radius,
                   const u32 color)
{
  C2D_DrawCircleSolid (x, y, 0, radius, color);
};

void
Screen_drawJoystick (const circlePosition *p, const float x, const float y,
                     const float r)
{
  u32 stick_color = Color_grey;
  float _r = r;

  if (p->dx != 0 || p->dy != 0)
    {
      Screen_drawCircle (x, y, _r + 100 / 5.0f, stick_color);
      stick_color = Color_light_blue;
      _r -= 1;
    }

  Screen_drawCircle (x + p->dx / 5.0f, y - p->dy / 5.0f, _r, stick_color);
};

const char *
Screen_initText (C2D_Text *text, C2D_TextBuf buf, const char *str)
{
  const char *res = C2D_TextFontParse (text, font, buf, str);
  C2D_TextOptimize (text);
  return res;
}

void
Screen_drawText (const C2D_Text *srctxt, const float x, const float y,
                 const float scaleX, const float scaleY, const u32 c)
{
  C2D_DrawText (srctxt, C2D_WithColor, x, y, 1, scaleX, scaleY, c);
}

void
Screen_drawRect (const float x, const float y, const float w, const float h,
                 const u32 c)
{
  C2D_DrawRectSolid (x, y, 0, w, h, c);
}

void
Screen_drawTriangle (const float x0, const float y0, const float x1,
                     const float y1, const float x2, const float y2,
                     const u32 c)
{
  C2D_DrawTriangle (x0, y0, c, x1, y1, c, x2, y2, c, 0);
}

void
Screen_rotatePoint (float *x_dst, float *y_dst, const float x, const float y,
                    const float offset_x, const float offset_y,
                    const float factor_sin, const float factor_cos)
{
  *x_dst = x * factor_cos - y * factor_sin + offset_x;
  *y_dst = x * factor_sin + y * factor_cos + offset_y;
}

void
Screen_drawDPadArrow (const float x, const float y, const float radians)
{
  float factor_sin = sin (radians), factor_cos = cos (radians),

        x0 = +10, y0 = -10,

        x1 = -10, y1 = -10,

        x2 = -10, y2 = -30,

        x3 = +10, y3 = -30;

  Screen_rotatePoint(&x0, &y0, x0, y0, x, y, factor_sin, factor_cos);
  Screen_rotatePoint(&x1, &y1, x1, y1, x, y, factor_sin, factor_cos);
  Screen_rotatePoint(&x2, &y2, x2, y2, x, y, factor_sin, factor_cos);
  Screen_rotatePoint(&x3, &y3, x3, y3, x, y, factor_sin, factor_cos);

  Screen_drawTriangle (x, y, x0, y0, x1, y1, Color_white);
  Screen_drawTriangle (x0, y0, x1, y1, x2, y2, Color_white);
  Screen_drawTriangle (x0, y0, x2, y2, x3, y3, Color_white);
}
