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
  C2D_DrawCircle (x, y, 0, radius, color, color, color, color);
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

// Screen_drawText (const C2D_Text *text, u32 flags, float x, float y, float z,
// float scaleX, float scaleY, ...)
