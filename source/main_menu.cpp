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
  C2D_TextFontParse(&buf, fuente, bufstatic, "Selecciona en el panel táctil");
  C2D_TextOptimize(&buf);
}

void
showControls ()
{
  //rgba(103, 175, 215, 1)
  C2D_TargetClear(top, C2D_Color32(30, 34, 39, 255));
  C2D_SceneBegin(top);
  C2D_DrawText(&buf, C2D_WithColor, 50, 210, 0.5, 0.5, 0.5, C2D_Color32(95, 204, 227, 255));
}
