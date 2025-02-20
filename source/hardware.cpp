#include "hardware.h"
#include <string>

namespace Hardware
{
bool
isNewModel ()
{
  bool res = false;
  APT_CheckNew3DS (&res);
  return res;
};

s8
toRelativeCircleRange (const s16 &x)
{
  return (x * 100 / Hardware::MAX_STICK_VALUE);
};

void
toRelativeCirclePosition (circlePosition &c)
{
  c.dx = toRelativeCircleRange (c.dx);
  c.dy = toRelativeCircleRange (c.dy);
};

void
CirclePad (circlePosition &c)
{
  hidCircleRead (&c);
  toRelativeCirclePosition (c);
};

void
CStick (circlePosition &c)
{
  hidCstickRead (&c);
  toRelativeCirclePosition (c);
};

u32
rawButtons ()
{
  return hidKeysHeld ();
};

bool
isHeldButton (const unsigned &k)
{
  return Hardware::rawButtons () & k;
};

bool
A ()
{
  return isHeldButton (KEY_A);
};

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

bool
DUp ()
{
  return isHeldButton (KEY_DUP);
};

bool
DDown ()
{
  return isHeldButton (KEY_DDOWN);
};

bool
DRight ()
{
  return isHeldButton (KEY_DRIGHT);
};

bool
DLeft ()
{
  return isHeldButton (KEY_DLEFT);
};

bool
L ()
{
  return isHeldButton (KEY_L);
};

bool R ()
{
  return isHeldButton (KEY_R);
};

bool
ZR ()
{
  return isHeldButton (KEY_ZR);
};

bool
ZL ()
{
  return isHeldButton (KEY_ZL);
};

bool
OptStart ()
{
  return isHeldButton (KEY_START);
};

bool OptSelect ()
{
  return isHeldButton (KEY_SELECT);
};

void
listenInput ()
{
  hidScanInput ();
}

std::string
toString (const circlePosition &pos)
{
  std::string result = "(";

  result += pos.dx;
  result.append(", ");
  result += pos.dy;
  result.append(")");

  return result;
}

std::string
toString()
{
  std::string result = "";

  if(Hardware::A()) result.append("A ");
  if(Hardware::B()) result.append("B ");
  if(Hardware::X()) result.append("X ");
  if(Hardware::Y()) result.append("Y ");

  if(Hardware::DUp()) result.append("^ ");
  if(Hardware::DDown()) result.append("v ");
  if(Hardware::DRight()) result.append("> ");
  if(Hardware::DLeft()) result.append("< ");

  if(Hardware::L()) result.append("L ");
  if(Hardware::ZL()) result.append("ZL ");
  if(Hardware::R()) result.append("R ");
  if(Hardware::ZR()) result.append("ZR ");

  if(Hardware::OptSelect()) result.append("SELECT ");
  if(Hardware::OptStart()) result.append("START ");

  return result;
}
}
