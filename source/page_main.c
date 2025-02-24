#include "page_main.h"

bool PAGE_MAIN_active = false;

char *label_a = "A", *label_b = "B", *label_x = "X", *label_y = "Y";

C2D_Text text_a, text_b, text_x, text_y;

void
displayABXY_updateVars (unsigned *y_dst, u32 *c_dst, const int new_rel_y,
                        const u32 new_c)
{
  *y_dst += new_rel_y;
  *c_dst = new_c;
}

void
displayABXY (float x, float y)
{
  u32 color_a, color_b, color_y, color_x,
      btn_default = C2D_Color32 (253, 253, 253, 255);

  unsigned y_a = 125, y_b = 150, y_x = 100, y_y = 125;

  color_a = color_b = color_y = color_x = btn_default;

  if (Hardware_A ())
    {
      displayABXY_updateVars (&y_a, &color_a, +2, C2D_Color32 (247, 56, 0, 255));
      C2D_TextFontParse (&text_a, font, g_staticBuf, "dddd");
      C2D_TextOptimize (&text_a);

    }
  if (Hardware_B ())
    displayABXY_updateVars (&y_b, &color_b, +2,
                            C2D_Color32 (248, 183, 2, 255));
  if (Hardware_Y ())
    displayABXY_updateVars (&y_y, &color_y, +2, C2D_Color32 (0, 184, 0, 255));
  if (Hardware_X ())
    displayABXY_updateVars (&y_x, &color_x, +2, C2D_Color32 (2, 87, 247, 255));

  C2D_DrawText (&text_a, C2D_WithColor, 330, 100, 0.5, 1, 1,
                C2D_Color32 (2, 87, 247, 255));

  Screen_drawCircle (330, y_x, 11, color_x);
  Screen_drawCircle (360, y_a, 11, color_a);
  Screen_drawCircle (330, y_b, 11, color_b);
  Screen_drawCircle (300, y_y, 11, color_y);
}

void
PAGE_MAIN_startPage ()
{
  C2D_TextFontParse (&text_a, font, g_staticBuf, label_a);
  C2D_TextOptimize (&text_a);
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
  Screen_setBackground (top, C2D_Color32 (29, 34, 39, 255));

  circlePosition circle_pos, cstick_pos;
  Hardware_CirclePad (&circle_pos);
  Hardware_CStick (&cstick_pos);

  displayABXY (100, 100);

  Screen_drawJoystick (&circle_pos, 60.0f, 80.0f, 20);
  Screen_drawJoystick (&cstick_pos, 300.0f, 70.0f, 10);

  if (Hardware_OptStart ())
    Screen_changePage (PAGE_ABOUT, PAGE_MAIN_quitPage);
}
