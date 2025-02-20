#include "hardware.h"

namespace Hardware
{
bool
isNewModel ()
{
  bool res = false;
  APT_CheckNew3DS (&res);
  return res;
}

s8
toRelativeCircle (const s16 &x)
{
  return (x * 100 / Hardware::MAX_STICK_VALUE);
}

void
readCirclePad (circlePosition &c)
{
  hidCircleRead (&c);
  c.dx = toRelativeCircle(c.dx);
  c.dy = toRelativeCircle(c.dy);
};
}
