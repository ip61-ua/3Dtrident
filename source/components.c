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
