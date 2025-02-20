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
CirclePad (circlePosition &c)
{
  hidCircleRead (&c);
  toRelativeCirclePosition (c);
}

void
CStick (circlePosition &c)
{
  hidCstickRead (&c);
  toRelativeCirclePosition (c);
}

u32
rawButtons ()
{
  return hidKeysHeld ();
}

bool
isHeldButton (const unsigned &k)
{
  return Hardware::rawButtons () & k;
};

bool
A ()
{
  return isHeldButton (KEY_A);
}

bool
B ()
{
  return isHeldButton (KEY_B);
};

bool
X ()
{
  return isHeldButton (KEY_X);
};

bool
Y ()
{
  return isHeldButton (KEY_Y);
};

}
