#ifndef _APP_H_
#define _APP_H_

#include <3ds.h>
#include <citro2d.h>
#include "screen.h"
#include "page_main.h"
#include "page_about.h"

extern u8 PAGE_CURRENT;

enum PAGE_STATE
{
  PAGE_MAIN,
  PAGE_ABOUT,
  PAGE_PAINT,
  PAGE_3D,
  PAGE_GYRO,
  PAGE_AUDIO
};

void Application_start ();
void Application_loop ();
void Application_load (enum PAGE_STATE);
void Application_end ();

#endif
