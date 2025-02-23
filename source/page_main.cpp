#include "page_main.h"

namespace PAGE_MAIN
{
void
showPage ()
{
  Hardware_listenInput ();
  Screen_setBackground (top, C2D_Color32 (29, 34, 39, 255));

  circlePosition circle_pos, cstick_pos;
  Hardware_CirclePad(&circle_pos);
  Hardware_CStick(&cstick_pos);
  Screen_drawJoystick (&circle_pos, 60.0f, 80.0f, 20);
  Screen_drawJoystick (&cstick_pos, 300.0f, 70.0f, 10);

  //Screen::setBackground (Screen::bottom, C2D_Color32 (29, 34, 39, 255));
  if (Hardware_A ()) Application::PAGE_CURRENT = Application::PAGE_ABOUT;
}
};
