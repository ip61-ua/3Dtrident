#include "page_draw.h"

static bool active = false;
static void startPage ();
static void quitPage ();
static EntryPage entry ();

static void displayPaint ();
static void resetPaint ();

static void drawTopScreen ();
static void drawBottomScreen ();

static C2D_TextBuf this_TextBuf;
static C2D_Text help_text;
static float radius_draw = 2;

Page PAGE_DRAW = entry;

EntryPage
entry ()
{
  Hardware_listenInput ();

  drawBottomScreen ();
  if (!active && Hardware_isTouching ())
    startPage ();
  else
    Page_setup (&active, startPage);
  drawTopScreen ();

  if (Hardware_B ())
    Page_changeTo (PAGE_MAIN, &active, quitPage);
}

void
drawTopScreen ()
{
  Screen_setBackground (top, Color_dark_grey);

  float x, y;
  Screen_getTextDimensions (&help_text, FONT_SCALE_MID, FONT_SCALE_MID, &x,
                            &y);

  Screen_drawText (&help_text, C2D_WithColor, (SCREEN_TOP_WIDTH / 2.0) - x / 2,
                   (SCREEN_TOP_HEIGHT / 2.0) - y / 2, FONT_SCALE_MID,
                   FONT_SCALE_MID, Color_white);
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
  if (Hardware_DUp () && radius_draw <= 100)
    radius_draw += 0.5;

  if (Hardware_DDown () && radius_draw >= 1.5)
    radius_draw -= 0.5;

  if (Hardware_X ())
    resetPaint ();

  touchPosition pos;
  if (Hardware_Touch (&pos))
    {
      const touchPosition *last = Hardware_TouchLast ();
      Screen_drawLine (last->px, last->py, pos.px, pos.py, radius_draw,
                       Color_yellow);
      Screen_drawCircle (last->px, last->py, radius_draw / 2.0, Color_yellow);
    }
}

void
resetPaint ()
{
  Screen_setBackground (bottom, Color_dark_grey);
}

void
startPage ()
{
  this_TextBuf = Screen_newBufText (255);
  Screen_initText (&help_text, this_TextBuf, PAGE_HELP_TEXT);
  resetPaint ();
}

void
quitPage ()
{
  Screen_deleteBufText (this_TextBuf);
  resetPaint ();
}
