#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include "hardware.h"
#include "screen.h"

static C2D_Text text_a, text_b, text_x, text_y, text_r, text_zr, text_l,
    text_zl, text_start, text_select;

static void Component_Generic_active (const bool cond, u32 *c);

void Component_newABXY ();
void Component_ABXY (const float x, const float y);
void Component_deleteABXY ();
static void Component_ABXY_active (unsigned *y_dst, u32 *c_dst,
                                   u32 *c_font_dst, const int new_rel_y,
                                   const u32 new_c);

void Component_newStartSelect ();
void Component_StartSelect (const float x, float y);
void Component_deleteStartSelect ();

void Component_newRZRLZL ();
void Component_RZRLZL (const float x, const float y);
void Component_deleteRZRLZL ();

void Component_DPad (const float x, const float y);

/**
 * @brief Dibuja el estado de un *joystick* (o palanca) en función de la
 * entrada del mismo.
 * @param p Puntero circlePosition que contiene los valores de entrada.
 * @param x Componente X de la posición absoluta de dibujado.
 * @param y Componente Y de la posición absoluta de dibujado.
 * @param r Radio del círculo de la palanca.
 */
void Component_Joystick (const float x, const float y, const circlePosition *p,
                         const float r);
void Component_CirclePad (const float x, const float y,
                          const circlePosition *p);
void Component_CStick (const float x, const float y, const circlePosition *p);

#endif
