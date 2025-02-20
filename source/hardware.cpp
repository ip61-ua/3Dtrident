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
toRelativeCircleRange (const s16 &x)
{
  return (x * 100 / Hardware::MAX_STICK_VALUE);
}

void
toRelativeCirclePosition (circlePosition &c)
{
  c.dx = toRelativeCircleRange (c.dx);
  c.dy = toRelativeCircleRange (c.dy);
}

void
readCirclePad (circlePosition &c)
{
  hidCircleRead (&c);
  toRelativeCirclePosition (c);
}

void
readCStick (circlePosition &c)
{
  hidCstickRead (&c);
  toRelativeCirclePosition (c);
}
}
