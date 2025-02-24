#include "page_about.h"
#include "screen.h"

bool PAGE_ABOUT_active = false;

void
PAGE_ABOUT_showPage ()
{
  Screen_setupPage(&PAGE_ABOUT_active, NULL);

  Hardware_listenInput();
  Screen_setBackground (top, C2D_Color32 (243, 74, 125, 255));
  Screen_setBackground (bottom, C2D_Color32 (243, 74, 125, 255));
  if (Hardware_R ())
    Screen_changePage(PAGE_MAIN, NULL);
}
