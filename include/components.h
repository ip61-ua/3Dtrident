#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include "hardware.h"
#include "screen.h"

static C2D_Text text_a, text_b, text_x, text_y, text_r, text_zr, text_l,
    text_zl, text_start, text_select;

static void displayABXY_updateVars (unsigned *y_dst, u32 *c_dst,
                                    u32 *c_font_dst, const int new_rel_y,
                                    const u32 new_c);

static void displayGenericActive (const bool cond, u32 *c);

void Component_newABXY ();
void Component_ABXY (const float x, const float y);
void Component_deleteABXY ();

void Component_newStartSelect ();
void Component_StartSelect (const float x, float y);
void Component_deleteStartSelect ();

void Component_newRZRLZL ();
void Component_RZRLZL (const float x, const float y);
void Component_deleteRZRLZL ();

void Component_DPad (const float x, const float y);

#endif
