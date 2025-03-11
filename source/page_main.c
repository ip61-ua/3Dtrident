#include "page_main.h"
#include "components.h"

static bool active = false;
static void startPage ();
static void quitPage ();
static EntryPage entry ();

static C2D_Text text_a, text_b, text_x, text_y, text_r, text_zr, text_l,
    text_zl, text_start, text_select;

static void displayGenericActive (const bool cond, u32 *c);
static void displayDPad (const float x, const float y);
static void displayPaint ();

const static unsigned RADIUS_DRAW = 2, Y_ONACTIVE = 2, X_DIST_YA = 30,
                      BTN_RADIUS = 11, Y_DIFFCENTER = 25, DIFF_Y_OPTIONS = 25,
                      DIFF_X_PARAM = 14, RADIUS_OPTIONS = 7;

static void drawTopScreen ();
static void drawBottomScreen ();

Page PAGE_MAIN = entry;

EntryPage
entry ()
{
  Page_setup (&active, startPage);
  Hardware_listenInput ();

  drawTopScreen ();

  drawBottomScreen ();

  if (Hardware_L () && Hardware_A ())
    Page_changeTo (PAGE_ABOUT, quitPage);
}

void
drawTopScreen ()
{
  Screen_setBackground (top, Color_dark_grey);
  circlePosition circle_pos, cstick_pos;
  Hardware_CirclePad (&circle_pos);
  Hardware_CStick (&cstick_pos);

  Component_ABXY (330, 140);
  Component_StartSelect (300, 200);

  Screen_drawJoystick (&circle_pos, 60, 95, 20);
  Screen_drawJoystick (&cstick_pos, 300, 80, 10);

  Component_DPad (60, 180);

  Component_RZRLZL(30, 30);
}

void
drawBottomScreen ()
{
  //Screen_atScreen (bottom);
  Screen_setBackground (bottom, Color_dark_grey);

  Screen_drawRect(10, 10, SCREEN_BOTTOM_WIDTH/2.f, SCREEN_BOTTOM_HEIGHT/2.f, Color_grey);
}

void
displayPaint ()
{
  touchPosition pos;
  if (Hardware_Touch (&pos))
    {
      const touchPosition *last = Hardware_TouchLast ();
      Screen_drawLine (last->px, last->py, pos.px, pos.py, RADIUS_DRAW,
                       Color_yellow);
      Screen_drawCircle (last->px, last->py, RADIUS_DRAW / 2.0, Color_yellow);
    }
}

void
startPage ()
{
  Screen_setBackground (bottom, Color_dark_grey);
  Component_newABXY();
  Component_newStartSelect();
  Component_newRZRLZL();
}

void
quitPage ()
{
}
