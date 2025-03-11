#include "page_main.h"
#include "components.h"

static bool active = false;
static void startPage ();
static void quitPage ();
static EntryPage entry ();


static void displayPaint ();


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

  Component_CirclePad (60, 95, &circle_pos);
  Component_CStick (300, 80, &cstick_pos);

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
  Component_newABXY();
  Component_newStartSelect();
  Component_newRZRLZL();
}

void
quitPage ()
{
}
