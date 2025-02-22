#include "application.h"
#include "page_main.h"

namespace Application
{

u8 PAGE_CURRENT;
C2D_TextBuf g_staticBuf;
C2D_Font font;

C3D_RenderTarget *top;
C3D_RenderTarget *bottom;

C3D_RenderTarget *
topScreen ()
{
  return top;
};
C3D_RenderTarget *
bottomScreen ()
{
  return bottom;
};

void
start ()
{
  romfsInit ();
  cfguInit ();
  gfxInitDefault ();
  C3D_Init (C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init (C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare ();

  top = C2D_CreateScreenTarget (GFX_TOP, GFX_LEFT);
  bottom = C2D_CreateScreenTarget (GFX_BOTTOM, GFX_LEFT);

  g_staticBuf = C2D_TextBufNew (4096);
  font = C2D_FontLoad ("romfs:/cascadia.bcfnt");
};

C2D_TextBuf
getTextBuf ()
{
  return g_staticBuf;
};
C2D_Font
getFont ()
{
  return font;
};

void
loop ()
{
  PAGE_CURRENT = PAGE_MAIN;
  while (aptMainLoop ())
    {
      switch (PAGE_CURRENT)
        {
        default:
          PAGE_MAIN::showPage ();
          break;
        }
    };
};

void
end ()
{
  C2D_Fini ();
  C3D_Fini ();
  romfsExit ();
  cfguExit ();
  gfxExit ();
};
}
