#include "hardware.h"

bool
Hardware::isNewModel ()
{
  bool res = false;

  APT_CheckNew3DS(&res);

  return res;
}
