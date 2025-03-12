#include "hardware.h"

const unsigned MAX_STICK_VALUE = 154;
static touchPosition lastest_touch[]
    = { { .px = 0, .py = 0 }, { .px = 0, .py = 0 } };
static bool lastest_touch_is_safe = false;

bool
Hardware_isNewModel ()
{
  bool res = false;
  APT_CheckNew3DS (&res);
  return res;
};

s8
Hardware_toRelativeCircleRange (const s16 x)
{
  return x * 100 / MAX_STICK_VALUE;
};

void
Hardware_toRelativeCirclePosition (circlePosition *c)
{
  c->dx = Hardware_toRelativeCircleRange (c->dx);
  c->dy = Hardware_toRelativeCircleRange (c->dy);
};

void
Hardware_CirclePad (circlePosition *c)
{
  hidCircleRead (c);
  Hardware_toRelativeCirclePosition (c);
};

void
Hardware_CStick (circlePosition *c)
{
  hidCstickRead (c);
  Hardware_toRelativeCirclePosition (c);
};

bool
Hardware_isTouching ()
{
  return Hardware_isHeldButton (KEY_TOUCH);
};

const touchPosition *
Hardware_TouchLast ()
{
  return &lastest_touch[1];
}

bool
Hardware_Touch (touchPosition *t)
{
  if (Hardware_isTouching ())
    {
      lastest_touch[1].px = lastest_touch[0].px;
      lastest_touch[1].py = lastest_touch[0].py;
      hidTouchRead (&lastest_touch[0]);
      t->px = lastest_touch[0].px;
      t->py = lastest_touch[0].py;

      if (!lastest_touch_is_safe)
        {
          lastest_touch[1].px = lastest_touch[0].px;
          lastest_touch[1].py = lastest_touch[0].py;
          lastest_touch_is_safe = true;
        }

      return true;
    }

  lastest_touch_is_safe = false;
  return false;
};

bool
Hardware_CurrentTouch (touchPosition *t)
{
  hidTouchRead (t);
  return Hardware_isTouching ();
}

u32
Hardware_rawButtons ()
{
  return hidKeysHeld ();
};

bool
Hardware_isHeldButton (const unsigned k)
{
  return Hardware_rawButtons () & k;
};

bool
Hardware_A ()
{
  return Hardware_isHeldButton (KEY_A);
};

bool
Hardware_B ()
{
  return Hardware_isHeldButton (KEY_B);
};

bool
Hardware_X ()
{
  return Hardware_isHeldButton (KEY_X);
};

bool
Hardware_Y ()
{
  return Hardware_isHeldButton (KEY_Y);
};

bool
Hardware_DUp ()
{
  return Hardware_isHeldButton (KEY_DUP);
};

bool
Hardware_DDown ()
{
  return Hardware_isHeldButton (KEY_DDOWN);
};

bool
Hardware_DRight ()
{
  return Hardware_isHeldButton (KEY_DRIGHT);
};

bool
Hardware_DLeft ()
{
  return Hardware_isHeldButton (KEY_DLEFT);
};

bool
Hardware_L ()
{
  return Hardware_isHeldButton (KEY_L);
};

bool
Hardware_R ()
{
  return Hardware_isHeldButton (KEY_R);
};

bool
Hardware_ZR ()
{
  return Hardware_isHeldButton (KEY_ZR);
};

bool
Hardware_ZL ()
{
  return Hardware_isHeldButton (KEY_ZL);
};

bool
Hardware_OptStart ()
{
  return Hardware_isHeldButton (KEY_START);
};

bool
Hardware_OptSelect ()
{
  return Hardware_isHeldButton (KEY_SELECT);
};

void
Hardware_listenInput ()
{
  hidScanInput ();
}

void
Hardware_toLinkString (char *dst, const char *str, const bool cond)
{
  if (cond)
    {
      strcat (dst, str);
      strcat (dst, " ");
    }
}

void
Hardware_toStringPosition (char *dst, const int x, const int y)
{
  sprintf (dst, "(%d, %d)", x, y);
}
