#include "page_main.h"
#include "pages.h"

static bool active = false;
static void startPage ();
static void quitPage ();
static EntryPage entry ();

C2D_Text tactil, na_text, acerca_de;
static void drawTopScreen ();
static void drawBottomScreen ();

Page PAGE_MAIN = entry;

static void
changeToDraw ()
{
  Page_changeTo (PAGE_DRAW, quitPage);
}

static void
changeToAbout ()
{
  Page_changeTo (PAGE_ABOUT, quitPage);
}

EntryPage
entry ()
{
  Page_setup (&active, startPage);
  Hardware_listenInput ();

  drawTopScreen ();
  drawBottomScreen ();
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

  Component_RZRLZL (30, 30);
}

void
drawBottomScreen ()
{
  // Screen_atScreen (bottom);
  touchPosition p;
  bool a = Hardware_CurrentTouch (&p);

  Screen_setBackground (bottom, Color_dark_grey);

  const float GRID_HEIGHT = SCREEN_BOTTOM_HEIGHT - 40,
              GRID_BLOCK_HEIGHT = GRID_HEIGHT / 3.0,
              GRID_BLOCK_WIDTH = SCREEN_BOTTOM_WIDTH / 2.0;

  Component_TouchBtn (0, 0, GRID_BLOCK_WIDTH, GRID_BLOCK_HEIGHT, &tactil,
                      changeToDraw, &a, &p);

  Component_TouchBtn (GRID_BLOCK_WIDTH, 0, 2 * GRID_BLOCK_WIDTH,
                      GRID_BLOCK_HEIGHT, &na_text, NULL, &a, &p);

  Component_TouchBtn (0, GRID_BLOCK_HEIGHT, GRID_BLOCK_WIDTH,
                      2 * GRID_BLOCK_HEIGHT, &na_text, NULL, &a, &p);

  Component_TouchBtn (GRID_BLOCK_WIDTH, GRID_BLOCK_HEIGHT,
                      2 * GRID_BLOCK_WIDTH, 2 * GRID_BLOCK_HEIGHT, &na_text,
                      NULL, &a, &p);

  Component_TouchBtn (0, 2 * GRID_BLOCK_HEIGHT, GRID_BLOCK_WIDTH,
                      3 * GRID_BLOCK_HEIGHT, &na_text, NULL, &a, &p);

  Component_TouchBtn (GRID_BLOCK_WIDTH, 2 * GRID_BLOCK_HEIGHT,
                      2 * GRID_BLOCK_WIDTH, 3 * GRID_BLOCK_HEIGHT, &acerca_de,
                      changeToAbout, &a, &p);

  Component_TouchBtn (0, GRID_HEIGHT, SCREEN_BOTTOM_WIDTH,
                      SCREEN_BOTTOM_HEIGHT, &na_text, NULL, &a, &p);
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
  Component_newABXY ();
  Component_newStartSelect ();
  Component_newRZRLZL ();
  Screen_initText (&tactil, g_staticBuf, "Táctil");
  Screen_initText (&acerca_de, g_staticBuf, "Acerca de");
  Screen_initText (&na_text, g_staticBuf, "(no disponible)");
}

void
quitPage ()
{
}
