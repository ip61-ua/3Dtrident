#include "page_main.h"
#include "colors.h"

bool PAGE_MAIN_active = false;

C2D_Text text_a, text_b, text_x, text_y,

    text_r, text_zr, text_l, text_zl,

    text_start, text_select;

void
displayABXY_updateVars (unsigned *y_dst, u32 *c_dst, u32 *c_font_dst, const int new_rel_y,
                        const u32 new_c)
{
  *y_dst += new_rel_y;
  *c_dst = new_c;
  *c_font_dst = Color_white;
}

void
displayABXY (float x_param, float y_param)
{
  u32 color_a, color_b, color_y, color_x,

      color_text_a = Color_red, color_text_b = Color_yellow,
      color_text_y = Color_green, color_text_x = Color_blue;

  unsigned y_a = y_param, y_b = y_param + 25, y_x = y_param - 25,
           y_y = y_param;

  color_a = color_b = color_y = color_x = Color_white;

  if (Hardware_A ())
    displayABXY_updateVars (&y_a, &color_a, &color_text_a, +2, Color_red);
  if (Hardware_B ())
    displayABXY_updateVars (&y_b, &color_b, &color_text_b, +2, Color_yellow);
  if (Hardware_Y ())
    displayABXY_updateVars (&y_y, &color_y, &color_text_y, +2, Color_green);
  if (Hardware_X ())
    displayABXY_updateVars (&y_x, &color_x, &color_text_x, +2, Color_blue);

  Screen_drawCircle (x_param + 30, y_a, 11, color_a);
  Screen_drawCircle (x_param, y_b, 11, color_b);
  Screen_drawCircle (x_param, y_x, 11, color_x);
  Screen_drawCircle (x_param - 30, y_y, 11, color_y);

  Screen_drawText (&text_a, x_param + 23, y_a - 15.7, 1, 1, color_text_a);
  Screen_drawText (&text_b, x_param - 6.5, y_b - 15.5, 1, 1, color_text_b);
  Screen_drawText (&text_x, x_param - 6.5, y_x - 15.5, 1, 1, color_text_x);
  Screen_drawText (&text_y, x_param - 37, y_y - 15.7, 1, 1, color_text_y);

}

void
PAGE_MAIN_startPage ()
{
  Screen_initText (&text_a, g_staticBuf, "A");
  Screen_initText (&text_b, g_staticBuf, "B");
  Screen_initText (&text_x, g_staticBuf, "X");
  Screen_initText (&text_y, g_staticBuf, "Y");

  Screen_initText (&text_r, g_staticBuf, "R");
  Screen_initText (&text_zr, g_staticBuf, "ZR");
  Screen_initText (&text_l, g_staticBuf, "L");
  Screen_initText (&text_zl, g_staticBuf, "ZL");

  Screen_initText (&text_start, g_staticBuf, "START");
  Screen_initText (&text_select, g_staticBuf, "SELECT");
}

void
PAGE_MAIN_quitPage ()
{
}

void
PAGE_MAIN_showPage ()
{
  Screen_setupPage (&PAGE_MAIN_active, PAGE_MAIN_startPage);

  Hardware_listenInput ();
  Screen_setBackground (top, Color_dark_grey);

  circlePosition circle_pos, cstick_pos;
  Hardware_CirclePad (&circle_pos);
  Hardware_CStick (&cstick_pos);

  displayABXY (330, 125);

  Screen_drawJoystick (&circle_pos, 60.0f, 80.0f, 20);
  Screen_drawJoystick (&cstick_pos, 300.0f, 70.0f, 10);

  if (Hardware_OptStart ())
    Screen_changePage (PAGE_ABOUT, PAGE_MAIN_quitPage);
}
