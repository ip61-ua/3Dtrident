#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <3ds.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

extern unsigned MAX_STICK_VALUE;

enum HARDWARE_BACK_BUTTONS
{
  SHOULDER_R,
  SHOULDER_L,

  TRIGGER_ZR,
  TRIGGER_ZL,
};

// Info
bool Hardware_isNewModel ();

// Joystics
s8 Hardware_toRelativeCircleRange (const s16);
void Hardware_toRelativeCirclePosition (circlePosition *);
void Hardware_CirclePad (circlePosition *);
void Hardware_CStick (circlePosition *);

// Touch
bool Hardware_isTouching ();
bool Hardware_Touch (touchPosition *);

// Buttons
u32 Hardware_rawButtons ();
bool Hardware_isHeldButton (const unsigned);
bool Hardware_A ();
bool Hardware_B ();
bool Hardware_X ();
bool Hardware_Y ();

bool Hardware_DUp ();
bool Hardware_DDown ();
bool Hardware_DRight ();
bool Hardware_DLeft ();

bool Hardware_L ();
bool Hardware_R ();
bool Hardware_ZR ();
bool Hardware_ZL ();

bool Hardware_OptStart ();
bool Hardware_OptSelect ();

// Misc
void Hardware_listenInput ();
void Hardware_toStringPosition (char *, const int, const int);
void Hardware_toString (char *);

#endif
