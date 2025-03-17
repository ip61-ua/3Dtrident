#ifndef _PAGE_DRAW_H_
#define _PAGE_DRAW_H_

#include "components.h"
#include "constants.h"
#include "hardware.h"
#include "pages.h"
#include "screen.h"
#include <3ds.h>
#include <citro2d.h>

#define PAGE_HELP_TEXT_MINUS EMOJI_D_PAD_U "Aumentar radio/grosor de dibujado."
#define PAGE_HELP_TEXT_PLUS EMOJI_D_PAD_D "Reducir radio/grosor de dibujado."
#define PAGE_HELP_TEXT_BGCO                                                   \
  EMOJI_D_PAD_LR "Alternar tema de dibujo."
#define PAGE_HELP_TEXT_TRACE                                                  \
  EMOJI_A_BUTTON "Mostrar/Ocultar trazado entre toques."
#define PAGE_HELP_TEXT_HIDE EMOJI_Y_BUTTON "Mostrar/Ocultar este texto."
#define PAGE_HELP_TEXT_CLEAN EMOJI_X_BUTTON "Limpiar pantalla táctil."
#define PAGE_HELP_TEXT_BACK EMOJI_B_BUTTON "Volver al menú."

#define PAGE_HELP_TEXT                                                        \
  PAGE_HELP_TEXT_MINUS "\n" PAGE_HELP_TEXT_PLUS "\n" PAGE_HELP_TEXT_BGCO      \
                       "\n" PAGE_HELP_TEXT_TRACE "\n" PAGE_HELP_TEXT_HIDE     \
                       "\n" PAGE_HELP_TEXT_CLEAN "\n" PAGE_HELP_TEXT_BACK

extern Page PAGE_DRAW;

#endif
