#include "application.h"

int
main ()
{
  Application::start ();
  Application::loop ();
  Application::end ();
  return 0;
}
