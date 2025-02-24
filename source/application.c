#include "application.h"

u8 PAGE_CURRENT;

void
Application_start ()
{
  romfsInit ();
  cfguInit ();
  gfxInitDefault ();
  C3D_Init (C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init (C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare ();
  Screen_init();
};

void
Application_loop ()
{
  PAGE_CURRENT = PAGE_MAIN;
  while (aptMainLoop ())
    {
      C3D_FrameBegin (C3D_FRAME_SYNCDRAW);

      if (PAGE_CURRENT == PAGE_MAIN)
        PAGE_MAIN_showPage ();

      if (PAGE_CURRENT == PAGE_ABOUT)
        PAGE_ABOUT_showPage ();

      C3D_FrameEnd (0);
    };
};

void
Application_load (enum PAGE_STATE p)
{
}

void
Application_end ()
{
  C2D_Fini ();
  C3D_Fini ();
  romfsExit ();
  cfguExit ();
  gfxExit ();
};
