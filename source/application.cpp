#include "application.h"

namespace Application
{
u8 PAGE_CURRENT;

void
start ()
{
  romfsInit ();
  cfguInit ();
  gfxInitDefault ();
  C3D_Init (C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init (C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare ();
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
