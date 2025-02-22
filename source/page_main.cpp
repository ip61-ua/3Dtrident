#include "page_main.h"

namespace PAGE_MAIN
{
void
showPage ()
{
  Hardware::listenInput();
  Screen::setBackground (Screen::top, C2D_Color32 (29, 34, 39, 255));
  Screen::setBackground (Screen::bottom, C2D_Color32 (29, 34, 39, 255));
  if (Hardware::A())
    Application::PAGE_CURRENT = Application::PAGE_ABOUT;
}
};
