#include "page_main.h"

namespace PAGE_MAIN
{
void showPage () {
  C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

  C2D_TargetClear(Screen::top, C2D_Color32(29, 34, 39, 255));
  C2D_SceneBegin(Screen::top);
  C3D_FrameEnd(0);
}
};
