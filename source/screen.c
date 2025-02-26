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

void
Screen_drawJoystick (const circlePosition *p, const float x, const float y,
                     const float r)
{
  u32 stick_color = Color_grey;

  const bool cond = p->dx != 0 || p->dy != 0;

  if (cond)
    {
      const float expanded_relative = 100 / 5.0f;
      Screen_drawCircle (x, y, r + expanded_relative, stick_color);
      stick_color = Color_light_blue;

      Screen_drawLine (x - r - expanded_relative, y, x + r + expanded_relative,
                       y, 1, Color_white);

      Screen_drawLine (x, y - r - expanded_relative, x,
                       y + r + expanded_relative, 1, Color_white);
    }

  const float x_center_relative = x + p->dx / 5.0f,
              y_center_relative = y - p->dy / 5.0f;

  Screen_drawCircle (x_center_relative, y_center_relative, r, stick_color);
  if (cond)
    {
      Screen_drawLine (x_center_relative, y_center_relative - r,
                       x_center_relative, y_center_relative + r, 1,
                       Color_white);
      Screen_drawLine (x_center_relative - r, y_center_relative,
                       x_center_relative + r, y_center_relative, 1,
                       Color_white);
    }
};

const char *
Screen_initText (C2D_Text *text, C2D_TextBuf buf, const char *str)
{
  const char *res = C2D_TextFontParse (text, font, buf, str);
  C2D_TextOptimize (text);
  return res;
}

void
Screen_drawText (const C2D_Text *srctxt, const u32 flags, const float x, const float y,
                 const float scaleX, const float scaleY, const u32 c)
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

        x0 = +10, y0 = -10,

        x1 = -10, y1 = -10,

        x2 = -10, y2 = -35,

        x3 = +10, y3 = -35,

        x4 = 0, y4 = -15,

        x5 = 0, y5 = -30;

  Screen_rotatePoint (&x0, &y0, x0, y0, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x1, &y1, x1, y1, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x2, &y2, x2, y2, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x3, &y3, x3, y3, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x4, &y4, x4, y4, x, y, factor_sin, factor_cos);
  Screen_rotatePoint (&x5, &y5, x5, y5, x, y, factor_sin, factor_cos);

  Screen_drawTriangle (x, y, x0, y0, x1, y1, btn_color);
  Screen_drawTriangle (x0, y0, x1, y1, x2, y2, btn_color);
  Screen_drawTriangle (x0, y0, x2, y2, x3, y3, btn_color);

  Screen_drawLine (x4, y4, x5, y5, 2, pill_color);
}
