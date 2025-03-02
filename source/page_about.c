#include "page_about.h"

static bool active = false;
static float r_init = 1;

static EntryPage entry ();
static void quitPage ();

Page PAGE_ABOUT = entry;

EntryPage
entry ()
{
  r_init = 5;
  Page_setup (&active, NULL);

  Hardware_listenInput ();

  Screen_setBackground (top, Color_red);
  Screen_setBackground (bottom, Color_blue);
  if (Hardware_R ())
    Page_changeTo (PAGE_MAIN, quitPage);
}

void
quitPage ()
{
  while (true)
    {
      Screen_drawCircle (50, 50, r_init, Color_grey);
      if (r_init >= 1000)
        break;
      r_init += 1;
    }
}
