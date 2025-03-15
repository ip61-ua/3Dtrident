#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "constants.h"
#include <3ds.h>
#include <citro2d.h>
#include <math.h>

#define SCREEN_TOP_WIDTH 400
#define SCREEN_TOP_HEIGHT 240
#define SCREEN_BOTTOM_WIDTH 320
#define SCREEN_BOTTOM_HEIGHT 240

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

/**
 * @brief Selecciona la pantalla con la que posteriormente se vaya a trabajar,
 * además de establecer un color de fondo.
 * @param target Puntero de C3D_RenderTarget de pantalla deseada.
 * @param color A establecer el fondo.
 */
void Screen_setBackground (C3D_RenderTarget *target, const u32 color);

/**
 * @brief Dibuja un segmento de línea recta entre dos puntos.
 * @param x0 Componente abscisa de origen.
 * @param y0 Componente ordenada de origen.
 * @param x1 Componente abscisa final.
 * @param y1 Componente ordenada final.
 * @param g Grosor de la línea.
 * @param c Color de relleno.
 */
void Screen_drawLine (const float x0, const float y0, const float x1,
                      const float y1, const float g, const u32 c);

/**
 * @brief Dibuja un círculo tomando como centro una coordenada.
 * @param x Componente abscisa del centro del círculo.
 * @param y Componente ordenada del centro del círculo.
 * @param radius Radio del círculo desde el centro.
 * @param color Color de relleno.
 */
void Screen_drawCircle (const float x, const float y, const float radius,
                        const u32 color);

/**
 * @brief Inicializa el dibujado de texto en pantalla. Cargando los glifos
 * necesarios, además de optimizarlos para su dibujado.
 *
 * @remarks Esta función debería llamarse una vez. NO en cada fotograma
 * de dibujado si no se va cambiar.
 *
 * @remarks Internamente se hacen uso de C2D_TextFontParse y C2D_TextOptimize.
 *
 * @param text Puntero C2D_Text de destino.
 * @param buf Buffer de texto a manejar glifos.
 * @param str Cadena de caracteres a transformar texto dibujable.
 * @returns Puntero del último carácter que se ha podido transformar.
 *  Si el puntero apunta a un carácter nulo => Transformación correcta.
 *  Si el puntero apunta a otro carácter => El buffer buf está lleno.
 *  Si el puntero es NULL => Fracaso en la transformación.
 */
const char *Screen_initText (C2D_Text *text, C2D_TextBuf buf, const char *str);

/**
 * @brief Dibuja el texto en pantalla.
 * @param srctxt Puntero C2D_Text del objeto de texto a dibujar.
 * @param flags Bits de personalización del dibujado de texto. Estos flags
 * empiezan por C2D_ y son parte de la text.h.
 * @param x Componente X de posición de dibujado.
 * @param y Componente Y de posición de dibujado.
 * @param scaleX Factor de escalado horizontal.
 * @param scaleY Factor de escalado vertical.
 * @param c Color del texto.
 */
void Screen_drawText (const C2D_Text *srctxt, const u32 flags, const float x,
                      const float y, const float scaleX, const float scaleY,
                      const u32 c);

/**
 * @brief Obtiene las dimensiones de un texto.
 * @param srctxt Puntero C2D_Text del texto a examinar.
 * @param scaleX Factor de escalado horizontal.
 * @param scaleY Factor de escalado vertical.
 * @param outX Destino de anchura.
 * @param outY Destino de altura.
 */
void Screen_getTextDimensions (const C2D_Text *srctxt, const float scaleX,
                               const float scaleY, float *outX, float *outY);
/**
 * @brief Dibuja un rectángulo sólido dado un punto, anchura y altura.
 * @param srctxt Puntero C2D_Text del objeto de texto a dibujar.
 * @param x Componente X de origen.
 * @param y Componente Y de origen.
 * @param w Anchura del rectángulo (width).
 * @param w Altura del rectángulo (height).
 * @param c Color de relleno.
 */
void Screen_drawRect (const float x, const float y, const float w,
                      const float h, const u32 c);

/**
 * @brief Dibuja un triángulo sólido dados los puntos de vértices..
 * @param srctxt Puntero C2D_Text del objeto de texto a dibujar.
 * @param x0 Componente X de punto 0.
 * @param y0 Componente Y de punto 0.
 * @param x1 Componente X de punto 1.
 * @param y1 Componente Y de punto 1.
 * @param x2 Componente X de punto 2.
 * @param y2 Componente Y de punto 2.
 * @param c Color de relleno.
 */
void Screen_drawTriangle (const float x0, const float y0, const float x1,
                          const float y1, const float x2, const float y2,
                          const u32 c);

/**
 * @brief Recalcula la nueva posición absoluta rotada de un punto relativo.
 * La rotación se produce suponiendo que el origen es (0, 0). Luego, se suma la
 * diferencia de posición absoluta y relativa para obtener la posición absoluta
 * nueva ya rotada.
 *
 * @param x_dst Puntero destino del resultado de la componente X.
 * @param y_dst Puntero destino del resultado de la componente Y.
 *
 * @param x Componente X fuente relativa a (0, 0) a rotar.
 * @param y Componente Y fuente relativa a (0, 0) a rotar.
 *
 * @param offset_x Diferencia entre la posición relativa y absoluta de X.
 * @param offset_y Diferencia entre la posición relativa y absoluta de Y.
 *
 * @param factor_sin Factor precalculado de seno: sin (pi_rad * M_PI).
 * @param factor_cos Factor precalculado de coseno: cos (pi_rad * M_PI).
 */
void Screen_rotatePoint (float *x_dst, float *y_dst, const float x,
                         const float y, const float offset_x,
                         const float offset_y, const float factor_sin,
                         const float factor_cos);

#endif
