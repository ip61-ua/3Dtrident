#include "page_main.h"

namespace PAGE_MAIN
{
void
showPage ()
{
  Hardware_listenInput ();
  Screen::setBackground (Screen::top, C2D_Color32 (29, 34, 39, 255));

  circlePosition pos;
  Hardware_CirclePad(&pos);

  u32 gray = C2D_Color32 (85, 88, 91, 255);
  C2D_DrawCircle (100.0f + pos.dx/5.0f, 100.0f - pos.dy/5.0f, 0, 20, gray, gray, gray, gray);

  Screen::setBackground (Screen::bottom, C2D_Color32 (29, 34, 39, 255));
  if (Hardware_A ()) Application::PAGE_CURRENT = Application::PAGE_ABOUT;
}
};
