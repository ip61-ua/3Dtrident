#include "page_about.h"


void
PAGE_ABOUT_showPage ()
{
  Hardware_listenInput();
  Screen_setBackground (top, C2D_Color32 (243, 74, 125, 255));
  Screen_setBackground (bottom, C2D_Color32 (243, 74, 125, 255));
  if (Hardware_R ())
    PAGE_CURRENT = PAGE_MAIN;
}
