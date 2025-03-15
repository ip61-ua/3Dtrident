#include "page_draw.h"

static bool active = false;
static void startPage ();
static void quitPage ();
static EntryPage entry ();

static void displayPaint ();

static void drawTopScreen ();
static void drawBottomScreen ();

Page PAGE_DRAW = entry;

EntryPage
entry ()
{
  Page_setup (&active, startPage);
  Hardware_listenInput ();

  drawTopScreen ();
  drawBottomScreen ();

  if (Hardware_OptStart())
    Page_changeTo(PAGE_MAIN, quitPage);
}

void
drawTopScreen ()
{
  Screen_setBackground (top, Color_dark_grey);
}

void
drawBottomScreen ()
{
  Screen_atScreen (bottom);
  displayPaint ();
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
}

void
quitPage ()
{
  active = false;
}
