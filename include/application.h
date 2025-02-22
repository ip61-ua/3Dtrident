#ifndef _APP_H_
#define _APP_H_

#include <3ds.h>
#include <citro2d.h>

namespace Application
{
enum ACTIVITY_STATE
{
  PAGE_MAIN,
  PAGE_ABOUT,
  PAGE_PAINT,
  PAGE_3D,
  PAGE_GYRO,
  PAGE_AUDIO
};

void start ();
bool mainLoop ();
void load (ACTIVITY_STATE);
void end ();
}

#endif
