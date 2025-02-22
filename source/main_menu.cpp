#include "main_menu.h"

C3D_RenderTarget* top;

C2D_TextBuf bufstatic;
C2D_Font fuente;
C2D_Text buf;

void
setupControls ()
{

  bufstatic = C2D_TextBufNew(1024);
  top = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);
  fuente = C2D_FontLoad("romfs:/cascadia.bcfnt");
  C2D_TextFontParse(&buf, fuente, bufstatic, "Hola mundo");
  C2D_TextOptimize(&buf);
}

void
showControls ()
{
  C2D_TargetClear(top, C2D_Color32(0x68, 0xB0, 0xD8, 0xFF));
  C2D_SceneBegin(top);
  C2D_DrawText(&buf, C2D_AtBaseline, 50, 210.0f, 0.5f, 1, 1);
}
