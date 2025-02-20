#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <3ds.h>
#include <iostream>

namespace Hardware
{
const u8 MAX_STICK_VALUE = 154;
// Info
bool isNewModel ();

// Joystics
s8 toRelativeCircleRange (const s16 &);
void toRelativeCirclePosition (circlePosition &);
void CirclePad (circlePosition &);
void CStick (circlePosition &);

// Buttons
u32 rawButtons ();
bool isHeldButton (const unsigned &);
bool A ();
bool B ();
bool X ();
bool Y ();

bool DUp ();
bool DDown ();
bool DRight ();
bool DLeft ();

bool L ();
bool R ();
bool ZR ();
bool ZL ();

bool OptStart ();
bool OptSelect ();

// Misc
void listenInput ();
std::string toString (const circlePosition &);
std::string toString ();
}

#endif
