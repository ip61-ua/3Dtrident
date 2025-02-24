#include "page_about.h"

bool PAGE_ABOUT_active = false;

void
PAGE_ABOUT_showPage ()
{
  Screen_setupPage(&PAGE_ABOUT_active, NULL);

  Hardware_listenInput();
  Screen_setBackground (top, Color_red);
  Screen_setBackground (bottom, Color_blue);
  if (Hardware_R ())
    Screen_changePage(PAGE_MAIN, NULL);
}
