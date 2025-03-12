#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include "hardware.h"
#include "screen.h"

const static unsigned RADIUS_DRAW = 2, Y_ONACTIVE = 2, X_DIST_YA = 30,
                      BTN_RADIUS = 11, Y_DIFFCENTER = 25, DIFF_Y_OPTIONS = 25,
                      DIFF_X_PARAM = 14, RADIUS_OPTIONS = 7;

void Component_Generic_active (const bool cond, u32 *c);

void Component_newABXY ();
void Component_ABXY (const float x, const float y);
void Component_deleteABXY ();
void Component_ABXY_active (unsigned *y_dst, u32 *c_dst, u32 *c_font_dst,
                            const int new_rel_y, const u32 new_c);

void Component_newStartSelect ();
void Component_StartSelect (const float x, float y);
void Component_deleteStartSelect ();

void Component_newRZRLZL ();
void Component_RZRLZL (const float x, const float y);
void Component_deleteRZRLZL ();

/**
 * @brief Dibuja un botón de flecha de cruceta.
 * @param x Componente X de origen.
 * @param y Componente Y de origen.
 * @param cond Resultado de condición de activación o pulsación.
 * @param pi_rad Pi radianes para efactuar rotación. Suponer que dentro de la
 * función se calcula pi_rad * M_PI.
 */
void Component_DPadArrow (const float x, const float y, const bool cond,
                          const float pi_rad);

void Component_DPad (const float x, const float y);

/**
 * @brief Dibuja el estado de un *joystick* (o palanca) en función de la
 * entrada del mismo.
 * @param x Componente X de la posición absoluta de dibujado.
 * @param y Componente Y de la posición absoluta de dibujado.
 * @param p Puntero circlePosition que contiene los valores de entrada.
 * @param r Radio del círculo de la palanca.
 */
void Component_Joystick (const float x, const float y, const circlePosition *p,
                         const float r);
void Component_CirclePad (const float x, const float y,
                          const circlePosition *p);
void Component_CStick (const float x, const float y, const circlePosition *p);

void Component_TouchBtn (const float x_i, const float y_i, const float x_f,
                         const float y_f, const C2D_Text *text,
                         void (*onclick) (), bool *touch_valid,
                         touchPosition *p);

#endif
