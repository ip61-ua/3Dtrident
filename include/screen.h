#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "constants.h"
#include <3ds.h>
#include <citro2d.h>
#include <math.h>

extern C3D_RenderTarget *top;
extern C3D_RenderTarget *bottom;
extern C2D_TextBuf g_staticBuf;
extern C2D_Font font;

/**
 * @brief Inicializa las variables globales top, bottom, g_staticBuf y font.
 */
void Screen_init ();

/**
 * @brief Selecciona la pantalla en la se vaya a dibujar contenido.
 * @param target Puntero de C3D_RenderTarget de pantalla deseada.
 */
void Screen_atScreen (C3D_RenderTarget *target);

void Screen_setBackground (C3D_RenderTarget *, const int);

void Screen_drawLine (const float, const float, const float, const float,
                      const float, const u32);

void Screen_drawCircle (const float, const float, const float, const u32);

void Screen_drawJoystick (const circlePosition *, const float, const float,
                          const float);

const char *Screen_initText (C2D_Text *, C2D_TextBuf, const char *);

void Screen_drawText (const C2D_Text *, const u32, const float, const float,
                      const float, const float, const u32);

void Screen_drawRect (const float, const float, const float, const float,
                      const u32);

void Screen_drawTriangle (const float, const float, const float, const float,
                          const float, const float, const u32);

void Screen_rotatePoint (float *, float *, const float, const float,
                         const float, const float, const float, const float);

void Screen_drawDPadArrow (const bool, const float, const float, const float);

#endif
