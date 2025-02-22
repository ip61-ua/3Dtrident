#include "application.h"

namespace Application
{
u8 current = 0;

void
start ()
{
  romfsInit ();
  cfguInit (); // Allow C2D_FontLoadSystem to work
  // Initialize the libs
  gfxInitDefault ();
  C3D_Init (C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init (C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare ();
};

bool mainLoop () {
  return aptMainLoop();
}

void load (ACTIVITY_STATE a) {

};

void end () {
 	C2D_Fini();
	C3D_Fini();
	romfsExit();
	cfguExit();
	gfxExit();
};
}
