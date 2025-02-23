#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <3ds.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const u8 MAX_STICK_VALUE = 154;
// Info
bool Hardware_isNewModel ();

// Joystics
s8 Hardware_toRelativeCircleRange (const s16);
void Hardware_toRelativeCirclePosition (circlePosition *);
void Hardware_CirclePad (circlePosition *);
void Hardware_CStick (circlePosition *);

// Buttons
u32
Hardware_rawButtons ();
bool
Hardware_isHeldButton (const unsigned);
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
//void Hardware_toLinkString (char *, const char *, const bool);
void Hardware_toString (char *, const circlePosition *);
void Hardware_toString (char *);

#endif
