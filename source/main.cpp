#include <3ds.h>
#include "screen.h"
#include "main_menu.h"

int
main ()
{
  Screen::initProgram();
  setupControls();

  while (aptMainLoop ())
    {
      showControls();
    }

  Screen::endProgram();
  return 0;
}
