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

  u32 btn_c = C2D_Color32 (253, 253, 253, 255),
      color_a, color_b, color_y, color_x;

  color_a = color_b = color_y = color_x = btn_c;

  if (Hardware_A()) color_a = C2D_Color32(247, 56, 0, 255);
  if (Hardware_B()) color_b = C2D_Color32(248, 183, 2, 255);
  if (Hardware_Y()) color_y = C2D_Color32(0, 184, 0, 255);
  if (Hardware_X()) color_x = C2D_Color32(2, 87, 247, 255);

  Screen_drawCircle(330, 100, 11, color_x);
  Screen_drawCircle(360, 125, 11, color_a);
  Screen_drawCircle(330, 150, 11, color_b);
  Screen_drawCircle(300, 125, 11, color_y);

  //Screen::setBackground (Screen::bottom, C2D_Color32 (29, 34, 39, 255));
  if (Hardware_OptStart ()) Application::PAGE_CURRENT = Application::PAGE_ABOUT;
}
};
