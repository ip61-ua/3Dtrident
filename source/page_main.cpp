#include "page_main.h"

namespace PAGE_MAIN
{
void showPage () {
  C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

  C2D_TargetClear(console.top, C2D_Color32(0x68, 0xB0, 0xD8, 0xFF));
  C2D_SceneBegin(console.top);
  C3D_FrameEnd(0);
}
};
