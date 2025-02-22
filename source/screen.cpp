#include "screen.h"

namespace Screen
{
void
initProgram ()
{
  romfsInit ();
  cfguInit (); // Allow C2D_FontLoadSystem to work
  // Initialize the libs
  gfxInitDefault ();
  C3D_Init (C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init (C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare ();
};
};
