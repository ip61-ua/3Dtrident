#include "page_draw.h"
#include "c2d/text.h"
#include "constants.h"
#include "hardware.h"
#include "screen.h"

static bool active = false;
static void startPage ();
static void quitPage ();
static EntryPage entry ();

static void displayPaint ();

static void drawTopScreen ();
static void drawBottomScreen ();

static C2D_TextBuf this_TextBuf;
static C2D_Text help_text;

Page PAGE_DRAW = entry;

EntryPage
entry ()
{
  Page_setup (&active, startPage);
  Hardware_listenInput ();

  drawTopScreen ();
  drawBottomScreen ();

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
  this_TextBuf = Screen_newBufText (255);
  Screen_initText (&help_text, this_TextBuf, PAGE_HELP_TEXT);
  Screen_setBackground (bottom, Color_dark_grey);
}

void
quitPage ()
{
  Screen_deleteBufText (this_TextBuf);
}
