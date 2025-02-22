#include "application.h"

int
main ()
{
  Application::start();

  while (Application::mainLoop())
    {
    }

  Application::end();
  return 0;
}
