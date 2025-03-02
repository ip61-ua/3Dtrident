#include "page_main.h"

static bool active = false;
static void startPage ();
static void quitPage ();

static C2D_Text text_a, text_b, text_x, text_y, text_r, text_zr, text_l,
    text_zl, text_start, text_select;

static void displayABXY_updateVars (unsigned *y_dst, u32 *c_dst,
                                    u32 *c_font_dst, const int new_rel_y,
                                    const u32 new_c);
static void displayABXY (float x_param, float y_param);
static void displayGenericActive (const bool cond, u32 *c);
static void displayStartSelect (float x_param, float y_param);
static void displayDPad (const float x, const float y);
static void displayBackButton (const float x, const float y,
                               const enum HARDWARE_BACK_BUTTONS btn);
static EntryPage entry ();

Page PAGE_MAIN = entry;

EntryPage
entry ()
{
  Page_setup (&active, startPage);

  Screen_setBackground (top, Color_dark_grey);
  Hardware_listenInput ();

  circlePosition circle_pos, cstick_pos;
  Hardware_CirclePad (&circle_pos);
  Hardware_CStick (&cstick_pos);

  displayABXY (330, 140);

  displayStartSelect (300, 200);

  Screen_drawJoystick (&circle_pos, 60, 95, 20);
  Screen_drawJoystick (&cstick_pos, 300, 80, 10);

  displayDPad (60, 180);

  displayBackButton (370, 30, SHOULDER_R);
  displayBackButton (30, 30, SHOULDER_L);

  displayBackButton (300, 30, TRIGGER_ZR);
  displayBackButton (100, 30, TRIGGER_ZL);

  Screen_setBackground (bottom, Color_dark_grey);

  if (Hardware_L () && Hardware_A ())
    Page_changeTo (PAGE_ABOUT, quitPage);
}

void
displayABXY_updateVars (unsigned *y_dst, u32 *c_dst, u32 *c_font_dst,
                        const int new_rel_y, const u32 new_c)
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

  Screen_drawText (&text_a, C2D_AlignCenter, x_param + 30, y_a - 15.7, 1, 1,
                   color_text_a);
  Screen_drawText (&text_b, C2D_AlignCenter, x_param, y_b - 15.5, 1, 1,
                   color_text_b);
  Screen_drawText (&text_x, C2D_AlignCenter, x_param, y_x - 15.5, 1, 1,
                   color_text_x);
  Screen_drawText (&text_y, C2D_AlignCenter, x_param - 30, y_y - 15.7, 1, 1,
                   color_text_y);
}

void
displayGenericActive (const bool cond, u32 *c)
{
  if (cond)
    *c = Color_light_blue;
}

void
displayStartSelect (float x_param, float y_param)
{
  u32 color_select, color_start;

  color_start = color_select = Color_white;

  displayGenericActive (Hardware_OptStart (), &color_start);
  Screen_drawCircle (x_param, y_param, 7, color_start);
  Screen_drawText (&text_start, 0, x_param + 14, y_param - 11, 0.75, 0.75,
                   Color_white);

  displayGenericActive (Hardware_OptSelect (), &color_select);
  Screen_drawCircle (x_param, y_param + 25, 7, color_select);
  Screen_drawText (&text_select, 0, x_param + 14, y_param + 14, 0.75, 0.75,
                   Color_white);
}

void
startPage ()
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
quitPage ()
{
}

void
displayDPad (const float x, const float y)
{
  Screen_drawDPadArrow (Hardware_DUp (), x, y, 0);
  Screen_drawDPadArrow (Hardware_DRight (), x, y, .5);
  Screen_drawDPadArrow (Hardware_DLeft (), x, y, -0.5);
  Screen_drawDPadArrow (Hardware_DDown (), x, y, 1);
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

  Screen_drawText (text_curr, flags, x + width / 10.0f, y - 15, 1, 1,
                   Color_grey);
}
