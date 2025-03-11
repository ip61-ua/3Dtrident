#include "components.h"

const static unsigned RADIUS_DRAW = 2, Y_ONACTIVE = 2, X_DIST_YA = 30,
                      BTN_RADIUS = 11, Y_DIFFCENTER = 25, DIFF_Y_OPTIONS = 25,
                      DIFF_X_PARAM = 14, RADIUS_OPTIONS = 7;

void
Component_newABXY ()
{
  Screen_initText (&text_a, g_staticBuf, "A");
  Screen_initText (&text_b, g_staticBuf, "B");
  Screen_initText (&text_x, g_staticBuf, "X");
  Screen_initText (&text_y, g_staticBuf, "Y");
}

static void
displayABXY_updateVars (unsigned *y_dst, u32 *c_dst, u32 *c_font_dst,
                        const int new_rel_y, const u32 new_c)
{
  *y_dst += new_rel_y;
  *c_dst = new_c;
  *c_font_dst = Color_white;
}

static void
displayGenericActive (const bool cond, u32 *c)
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
    displayABXY_updateVars (&y_a, &color_a, &color_text_a, Y_ONACTIVE,
                            Color_red);
  if (Hardware_B ())
    displayABXY_updateVars (&y_b, &color_b, &color_text_b, Y_ONACTIVE,
                            Color_yellow);
  if (Hardware_Y ())
    displayABXY_updateVars (&y_y, &color_y, &color_text_y, Y_ONACTIVE,
                            Color_green);
  if (Hardware_X ())
    displayABXY_updateVars (&y_x, &color_x, &color_text_x, Y_ONACTIVE,
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

  displayGenericActive (Hardware_OptStart (), &color_start);
  Screen_drawCircle (x, y, RADIUS_OPTIONS, color_start);
  Screen_drawText (&text_start, C2D_AtBaseline, x + DIFF_X_PARAM,
                   y + FONT_Y_DIFF_BASELINE, FONT_SCALE_STANDARD,
                   FONT_SCALE_STANDARD, Color_white);

  displayGenericActive (Hardware_OptSelect (), &color_select);
  Screen_drawCircle (x, y + DIFF_Y_OPTIONS, RADIUS_OPTIONS,
                     color_select);
  Screen_drawText (&text_select, C2D_AtBaseline, x + DIFF_X_PARAM,
                   y + DIFF_Y_OPTIONS + FONT_Y_DIFF_BASELINE,
                   FONT_SCALE_STANDARD, FONT_SCALE_STANDARD, Color_white);
}

void
displayBackButton (const float x, const float y,
                   const enum HARDWARE_BACK_BUTTONS btn)
{
  u32 color_btn = Color_white, flags;
  short int width;
  bool cond = false;
  C2D_Text *text_curr;

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

  displayGenericActive (cond, &color_btn);
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
Component_DPad (const float x, const float y)
{
  Screen_drawDPadArrow (Hardware_DUp (), x, y, 0);
  Screen_drawDPadArrow (Hardware_DRight (), x, y, .5);
  Screen_drawDPadArrow (Hardware_DLeft (), x, y, -0.5);
  Screen_drawDPadArrow (Hardware_DDown (), x, y, 1);
}

void
Component_CirclePad (const float x, const float y, const circlePosition * p)
{
  Screen_drawJoystick (p, x, y, 20);
}

void
Component_CStick (const float x, const float y, const circlePosition * p)
{
  Screen_drawJoystick (p, x, y, 10);
}
