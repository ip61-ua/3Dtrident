#include "page_about.h"

namespace PAGE_ABOUT
{
void
showPage ()
{
  Hardware_listenInput();
  Screen_setBackground (top, C2D_Color32 (243, 74, 125, 255));
  Screen_setBackground (bottom, C2D_Color32 (243, 74, 125, 255));
  if (Hardware_R ())
    Application::PAGE_CURRENT = Application::PAGE_MAIN;
}
};
