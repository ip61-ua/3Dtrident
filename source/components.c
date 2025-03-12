#include "components.h"
#include "constants.h"

static C2D_Text text_a, text_b, text_x, text_y, text_r, text_zr, text_l,
    text_zl, text_start, text_select;

enum HARDWARE_BACK_BUTTONS
{
  SHOULDER_R,
  SHOULDER_L,

  TRIGGER_ZR,
  TRIGGER_ZL,
};

void
Component_newABXY ()
{
  Screen_initText (&text_a, g_staticBuf, "A");
  Screen_initText (&text_b, g_staticBuf, "B");
  Screen_initText (&text_x, g_staticBuf, "X");
  Screen_initText (&text_y, g_staticBuf, "Y");
}

void
Component_ABXY_active (unsigned *y_dst, u32 *c_dst, u32 *c_font_dst,
                       const int new_rel_y, const u32 new_c)
{
  *y_dst += new_rel_y;
  *c_dst = new_c;
  *c_font_dst = Color_white;
}

void
Component_Generic_active (const bool cond, u32 *c)
{
  if (cond)
    *c = Color_light_blue;
}

void
Component_ABXY (float x_param, float y_param)
{
  u32 color_a, color_b, color_y, color_x,

      color_text_a = Color_red, color_text_b = Color_yellow,
      color_text_y = Color_green, color_text_x = Color_blue;

  unsigned y_a = y_param, y_b = y_param + Y_DIFFCENTER,
           y_x = y_param - Y_DIFFCENTER, y_y = y_param;

  color_a = color_b = color_y = color_x = Color_white;

  if (Hardware_A ())
    Component_ABXY_active (&y_a, &color_a, &color_text_a, Y_ONACTIVE,
                           Color_red);
  if (Hardware_B ())
    Component_ABXY_active (&y_b, &color_b, &color_text_b, Y_ONACTIVE,
                           Color_yellow);
  if (Hardware_Y ())
    Component_ABXY_active (&y_y, &color_y, &color_text_y, Y_ONACTIVE,
                           Color_green);
  if (Hardware_X ())
    Component_ABXY_active (&y_x, &color_x, &color_text_x, Y_ONACTIVE,
                           Color_blue);

  Screen_drawCircle (x_param + X_DIST_YA, y_a, BTN_RADIUS, color_a);
  Screen_drawCircle (x_param, y_b, BTN_RADIUS, color_b);
  Screen_drawCircle (x_param, y_x, BTN_RADIUS, color_x);
  Screen_drawCircle (x_param - X_DIST_YA, y_y, BTN_RADIUS, color_y);

  Screen_drawText (&text_a, C2D_AlignCenter | C2D_AtBaseline,
                   x_param + X_DIST_YA, y_a + FONT_Y_DIFF_BASELINE,
                   FONT_SCALE_STANDARD, FONT_SCALE_STANDARD, color_text_a);
  Screen_drawText (&text_b, C2D_AlignCenter | C2D_AtBaseline, x_param,
                   y_b + FONT_Y_DIFF_BASELINE, FONT_SCALE_STANDARD,
                   FONT_SCALE_STANDARD, color_text_b);
  Screen_drawText (&text_x, C2D_AlignCenter | C2D_AtBaseline, x_param,
                   y_x + FONT_Y_DIFF_BASELINE, FONT_SCALE_STANDARD,
                   FONT_SCALE_STANDARD, color_text_x);
  Screen_drawText (&text_y, C2D_AlignCenter | C2D_AtBaseline,
                   x_param - X_DIST_YA, y_y + FONT_Y_DIFF_BASELINE,
                   FONT_SCALE_STANDARD, FONT_SCALE_STANDARD, color_text_y);
}

void
Component_newStartSelect ()
{
  Screen_initText (&text_start, g_staticBuf, "START");
  Screen_initText (&text_select, g_staticBuf, "SELECT");
}

void
Component_StartSelect (const float x, const float y)
{
  u32 color_select, color_start;

  color_start = color_select = Color_white;

  Component_Generic_active (Hardware_OptStart (), &color_start);
  Screen_drawCircle (x, y, RADIUS_OPTIONS, color_start);
  Screen_drawText (&text_start, C2D_AtBaseline, x + DIFF_X_PARAM,
                   y + FONT_Y_DIFF_BASELINE, FONT_SCALE_STANDARD,
                   FONT_SCALE_STANDARD, Color_white);

  Component_Generic_active (Hardware_OptSelect (), &color_select);
  Screen_drawCircle (x, y + DIFF_Y_OPTIONS, RADIUS_OPTIONS, color_select);
  Screen_drawText (&text_select, C2D_AtBaseline, x + DIFF_X_PARAM,
                   y + DIFF_Y_OPTIONS + FONT_Y_DIFF_BASELINE,
                   FONT_SCALE_STANDARD, FONT_SCALE_STANDARD, Color_white);
}

void
displayBackButton (const float x, const float y,
                   const enum HARDWARE_BACK_BUTTONS btn)
{
  u32 color_btn = Color_white, flags = 0;
  short int width = 0;
  bool cond = false;
  C2D_Text *text_curr = NULL;

  if (btn == SHOULDER_R)
    {
      cond = Hardware_R ();
      flags = C2D_AlignRight;
      text_curr = &text_r;
      width = -50;
    }
  else if (btn == SHOULDER_L)
    {
      cond = Hardware_L ();
      flags = C2D_AlignLeft;
      text_curr = &text_l;
      width = +50;
    }
  else if (btn == TRIGGER_ZR)
    {
      cond = Hardware_ZR ();
      flags = C2D_AlignRight;
      text_curr = &text_zr;
      width = -32;
    }
  else if (btn == TRIGGER_ZL)
    {
      cond = Hardware_ZL ();
      flags = C2D_AlignLeft;
      text_curr = &text_zl;
      width = +32;
    }

  Component_Generic_active (cond, &color_btn);
  if (btn == SHOULDER_R || btn == SHOULDER_L)
    Screen_drawCircle (x, y, 10, color_btn);
  Screen_drawLine (x, y, x + width, y, 20, color_btn);

  Screen_drawText (text_curr, flags | C2D_AtBaseline, x + width / 10.0f,
                   y + FONT_Y_DIFF_BASELINE, FONT_SCALE_STANDARD,
                   FONT_SCALE_STANDARD, Color_grey);
}

void
Component_newRZRLZL ()
{
  Screen_initText (&text_r, g_staticBuf, "R");
  Screen_initText (&text_zr, g_staticBuf, "ZR");
  Screen_initText (&text_l, g_staticBuf, "L");
  Screen_initText (&text_zl, g_staticBuf, "ZL");
}
void
Component_RZRLZL (const float x, const float y)
{
  displayBackButton (340 + x, y, SHOULDER_R);
  displayBackButton (x, y, SHOULDER_L);

  displayBackButton (270 + x, y, TRIGGER_ZR);
  displayBackButton (70 + x, y, TRIGGER_ZL);
}

void
Component_DPadArrow (const float x, const float y, const bool cond,
                      const float pi_rad)
{
  u32 btn_color = Color_white, pill_color = Color_grey;

  Component_Generic_active(cond, &btn_color);

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
void
Component_DPad (const float x, const float y)
{
  Component_DPadArrow (x, y, Hardware_DUp (), 0);
  Component_DPadArrow (x, y, Hardware_DRight (), .5);
  Component_DPadArrow (x, y, Hardware_DLeft (), -0.5);
  Component_DPadArrow (x, y, Hardware_DDown (), 1);
}

void
Component_Joystick (const float x, const float y, const circlePosition *p,
                    const float r)
{
  u32 stick_color = Color_grey;

  const bool cond = p->dx != 0 || p->dy != 0;

  if (cond)
    {
      const float expanded_relative = 100 / 5.0f;
      Screen_drawCircle (x, y, r + expanded_relative, stick_color);

      Screen_drawLine (x - r - expanded_relative, y, x + r + expanded_relative,
                       y, 1, Color_white);

      Screen_drawLine (x, y - r - expanded_relative, x,
                       y + r + expanded_relative, 1, Color_white);
    }

  const float x_center_relative = x + p->dx / 5.0f,
              y_center_relative = y - p->dy / 5.0f;

  Component_Generic_active (cond, &stick_color);
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

void
Component_CirclePad (const float x, const float y, const circlePosition *p)
{
  Component_Joystick (x, y, p, 20);
}

void
Component_CStick (const float x, const float y, const circlePosition *p)
{
  Component_Joystick (x, y, p, 10);
}
