#include "screen.h"

C3D_RenderTarget *top;
C3D_RenderTarget *bottom;
C2D_TextBuf g_staticBuf;
C2D_Font font;

void
Screen_init ()
{
  top = C2D_CreateScreenTarget (GFX_TOP, GFX_LEFT);
  bottom = C2D_CreateScreenTarget (GFX_BOTTOM, GFX_LEFT);
  font = C2D_FontLoad ("romfs:/InterVariable.bcfnt");
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
  u32 stick_color = C2D_Color32 (85, 88, 91, 255);
  float _r = r;

  if (p->dx != 0 || p->dy != 0)
  {
    stick_color = C2D_Color32 (94, 205, 228, 255);
    _r -= 1;
  }

  Screen_drawCircle (x + p->dx / 5.0f, y - p->dy / 5.0f, _r, stick_color);
};
