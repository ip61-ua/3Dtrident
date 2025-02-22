#include "screen.h"

namespace Screen
{
C3D_RenderTarget *top = C2D_CreateScreenTarget (GFX_TOP, GFX_LEFT);
C3D_RenderTarget *bottom = C2D_CreateScreenTarget (GFX_BOTTOM, GFX_LEFT);
C2D_TextBuf g_staticBuf = C2D_TextBufNew (4096);
C2D_Font font = C2D_FontLoad ("romfs:/cascadia.bcfnt");
}
