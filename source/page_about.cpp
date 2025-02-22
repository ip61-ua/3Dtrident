#include "page_about.h"

namespace PAGE_ABOUT
{
void
showPage ()
{
  Hardware::listenInput();
  Screen::setBackground (Screen::top, C2D_Color32 (243, 74, 125, 255));
  Screen::setBackground (Screen::bottom, C2D_Color32 (243, 74, 125, 255));
  if (Hardware::R ())
    Application::PAGE_CURRENT = Application::PAGE_MAIN;
}
};
