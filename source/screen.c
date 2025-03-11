#include "screen.h"

C3D_RenderTarget *top;
C3D_RenderTarget *bottom;
C2D_TextBuf g_staticBuf;
C2D_Font font;

void
Screen_init ()
{
  g_staticBuf = C2D_TextBufNew (4096);
  top = C2D_CreateScreenTarget (GFX_TOP, GFX_LEFT);
  bottom = C2D_CreateScreenTarget (GFX_BOTTOM, GFX_LEFT);
  // font = C2D_FontLoad ("romfs:/InterVariable.bcfnt");
  font = C2D_FontLoadSystem (CFG_REGION_EUR);
}

void
Screen_atScreen (C3D_RenderTarget *target)
{
  C2D_SceneBegin (target);
}

void
Screen_setBackground (C3D_RenderTarget *target, const u32 color)
{
  C2D_TargetClear (target, color);
  Screen_atScreen (target);
}

void
Screen_drawLine (const float x0, const float y0, const float x1,
                 const float y1, const float g, const u32 c)
{
  C2D_DrawLine (x0, y0, c, x1, y1, c, g, 0);
}

void
Screen_drawCircle (const float x, const float y, const float radius,
                   const u32 color)
{
  C2D_DrawCircleSolid (x, y, 0, radius, color);
};

const char *
Screen_initText (C2D_Text *text, C2D_TextBuf buf, const char *str)
{
  const char *res = C2D_TextFontParse (text, font, buf, str);
  C2D_TextOptimize (text);
  return res;
}

void
Screen_drawText (const C2D_Text *srctxt, const u32 flags, const float x,
                 const float y, const float scaleX, const float scaleY,
                 const u32 c)
{
  C2D_DrawText (srctxt, C2D_WithColor | flags, x, y, 1, scaleX, scaleY, c);
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

// Las clases de trigonometría dieron sus frutos...
void
Screen_rotatePoint (float *x_dst, float *y_dst, const float x, const float y,
                    const float offset_x, const float offset_y,
                    const float factor_sin, const float factor_cos)
{
  *x_dst = x * factor_cos - y * factor_sin + offset_x;
  *y_dst = x * factor_sin + y * factor_cos + offset_y;
}

void
Screen_drawDPadArrow (const bool cond, const float x, const float y,
                      const float pi_rad)
{
  u32 btn_color = Color_white, pill_color = Color_grey;

  if (cond)
    btn_color = Color_light_blue;

  float factor_sin = sin (pi_rad * M_PI), factor_cos = cos (pi_rad * M_PI),
        x0 = +10, y0 = -10, x1 = -10, y1 = -10, x2 = 0, y2 = -10, x3 = 0,
        y3 = -35, x4 = 0, y4 = -15, x5 = 0, y5 = -30;

  Screen_rotatePoint (&x0, &y0, x0, y0, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x1, &y1, x1, y1, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x2, &y2, x2, y2, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x3, &y3, x3, y3, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x4, &y4, x4, y4, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x5, &y5, x5, y5, x, y, factor_sin, factor_cos);

  Screen_drawTriangle (x, y, x0, y0, x1, y1, btn_color);
  Screen_drawLine (x2, y2, x3, y3, 20, btn_color);

  Screen_drawLine (x4, y4, x5, y5, 2, pill_color);
}
