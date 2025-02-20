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
void readCirclePad (circlePosition &);
void readCStick (circlePosition &);

/*s
static const circlePosition &readCStick ();

// Buttons
static bool readA ();
static bool readB ();
static bool readX ();
static bool readY ();

static bool readUp ();
static bool readDown ();
static bool readRight ();
static bool readLeft ();

static bool readL ();
static bool readR ();
static bool readZR ();
static bool readZL ();

static bool readStart ();
static bool readSelect ();
*/
}

#endif
