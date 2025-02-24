#include "page_about.h"

static bool PAGE_ABOUT_active = false;
static float r_init = 1;

void
PAGE_ABOUT_quitPage ()
{
  while (true)
    {
      Screen_drawCircle (50, 50, r_init, Color_grey);
      if (r_init >= 1000)
        break;
      r_init += 1;
    }
}

void
PAGE_ABOUT_showPage ()
{
  r_init = 5;
  Screen_setupPage (&PAGE_ABOUT_active, NULL);

  Hardware_listenInput ();

  Screen_setBackground (top, Color_red);
  Screen_setBackground (bottom, Color_blue);
  if (Hardware_R ())
    Screen_changePage (PAGE_MAIN, PAGE_ABOUT_quitPage);
}
