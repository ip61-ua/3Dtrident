#include "page_main.h"

namespace PAGE_MAIN
{
void
showPage ()
{
  Hardware_listenInput ();
  Screen::setBackground (Screen::top, C2D_Color32 (29, 34, 39, 255));

  circlePosition circle_pos, cstick_pos;
  Hardware_CirclePad(&circle_pos);
  Hardware_CStick(&cstick_pos);

  u32 gray = C2D_Color32 (85, 88, 91, 255);
  C2D_DrawCircle (60.0f + circle_pos.dx/5.0f, 80.0f - circle_pos.dy/5.0f, 0, 20, gray, gray, gray, gray);
  C2D_DrawCircle (300.0f + cstick_pos.dx/5.0f, 70.0f - cstick_pos.dy/5.0f, 0, 10, gray, gray, gray, gray);

  //Screen::setBackground (Screen::bottom, C2D_Color32 (29, 34, 39, 255));
  if (Hardware_A ()) Application::PAGE_CURRENT = Application::PAGE_ABOUT;
}
};
