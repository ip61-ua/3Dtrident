#ifndef _APP_H_
#define _APP_H_

#include <3ds.h>
#include <citro2d.h>
#include "screen.h"
#include "page_main.h"

namespace Application
{
enum PAGE_STATE
{
  PAGE_MAIN,
  PAGE_ABOUT,
  PAGE_PAINT,
  PAGE_3D,
  PAGE_GYRO,
  PAGE_AUDIO
};

C2D_TextBuf getTextBuf ();
C2D_Font getFont ();

void start ();
void loop ();
void load (PAGE_STATE);
void end ();
}

#endif
