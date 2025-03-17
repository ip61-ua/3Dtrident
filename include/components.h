#ifndef _COMPONENTS_H_
#define _COMPONENTS_H_

#include "hardware.h"
#include "screen.h"

const static unsigned RADIUS_DRAW = 2, Y_ONACTIVE = 2, X_DIST_YA = 30,
                      BTN_RADIUS = 11, Y_DIFFCENTER = 25, DIFF_Y_OPTIONS = 25,
                      DIFF_X_PARAM = 14, RADIUS_OPTIONS = 7, RADIUS_BTN = 15,
                      MARGIN_BTN = 5;

/**
  * @brief Función auxiliar para dibujar cuando un componente esté activo.
  * @param cond Condición para asignar el color de activo.
  * @param c Puntero de color destino.
  */
void Component_Generic_active (const bool cond, u32 *c);

/**
 * @brief Inicializador de componente. Debe llamarse cuando el componente esté
 * a punto de renderizarse.
 */
void Component_newABXY ();

/**
 * @brief Dibuja los botones ABXY.
 * @param x Componente X de posición absoluta del centro.
 * @param y Componente Y de posición absoluta del centro.
 */
void Component_ABXY (const float x, const float y);

/**
 * @brief Asignación de parámetros para mostrar que un botón del tipo ABXY está
 * pulsado.
 * @param y_dst Puntero destino de posición de la componente Y del botón a mover.
 * @param c_dst Puntero destino de color de fondo del botón.
 * @param c_font_dst Puntero destino de color del texto. Lo asigna a blanco.
 * @param new_rel_y Valor a añadir a y_dst.
 * @param new_c Color a asignar a c_dst.
 */
void Component_ABXY_active (unsigned *y_dst, u32 *c_dst, u32 *c_font_dst,
                            const int new_rel_y, const u32 new_c);

/**
 * @brief Desinicializador de componente. Debe llamarse cuando el componente no
 * se vaya a renderizar.
 */
void Component_deleteABXY ();

/**
 * @brief Inicializador de componente. Debe llamarse cuando el componente esté
 * a punto de renderizarse.
 */
void Component_newStartSelect ();

/**
 * @brief Dibuja los botones Start y Select.
 * @param x Componente X de posición absoluta de la esquina superior izquierda.
 * @param y Componente Y de posición absoluta de la esquina superior izquierda.
 */
void Component_StartSelect (const float x, float y);

/**
 * @brief Desinicializador de componente. Debe llamarse cuando el componente no
 * se vaya a renderizar.
 */
void Component_deleteStartSelect ();

/**
 * @brief Inicializador de componente. Debe llamarse cuando el componente esté
 * a punto de renderizarse.
 */
void Component_newRZRLZL ();

/**
 * @brief Dibuja el conjunto de botones laterales y gatillos de la consola.
 * @param x Componente X de posición absoluta del lateral izquierda.
 * @param y Componente Y de posición absoluta del lateral izquierda.
 */
void Component_RZRLZL (const float x, const float y);

/**
 * @brief Desinicializador de componente. Debe llamarse cuando el componente no
 * se vaya a renderizar.
 */
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

/**
 * @brief Dibuja una cruceta en pantalla.
 * @param x Coordenada X del centro de la cruceta.
 * @param y Coordenada Y del centro de la cruceta.
 */
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

/**
 * @brief Dibuja el *joystick* (o palanca) grande de la izquierda.
 * @param x Componente X de la posición absoluta de dibujado.
 * @param y Componente Y de la posición absoluta de dibujado.
 * @param p Puntero de posición de entrada de la palanca.
 */
void Component_CirclePad (const float x, const float y,
                          const circlePosition *p);

/**
 * @brief Dibuja el *joystick* (o palanca) pequeño de la derecha.
 * @param x Componente X de la posición absoluta de dibujado.
 * @param y Componente Y de la posición absoluta de dibujado.
 * @param p Puntero de posición de entrada de la palanca.
 */
void Component_CStick (const float x, const float y, const circlePosition *p);

/**
 * @brief Renderiza un botón en la pantalla con texto.
 * @param x_i Componente X de la posición absoluta de dibujado de la esquina
 * superior izquerda.
 * @param y_i Componente Y de la posición absoluta de dibujado de la esquina
 * superior izquerda.
 * @param x_inc_f Componente X de la posición relativa de dibujado de la
 * esquina inferior derecha.
 * @param y_inc_f Componente Y de la posición relativa de dibujado de la
 * esquina inferior derecha.
 * @param text Puntero del texto a renderizar como etiqueta del botón.
 * @remarks Este componente no tiene la responsabilidad gestionar la memoria
 * del texto.
 * @param onclick Puntero a la función que se llama al pulsar el botón. Si es
 * NULL, el botón pasa a un estado desabilitado.
 * @param touch_valid Puntero a booleano que indica si es válida la pulsación
 * de la posición del panel táctil p.
 * @remarks Si touch_valid o p son NULL, el componente administra la entrada
 * automáticamente.
 * @param p Puntero de posición de la entrada táctil.
 */
void Component_TouchBtn (const float x_i, const float y_i, const float x_inc_f,
                         const float y_inc_f, const C2D_Text *text,
                         void (*onclick) (), bool *touch_valid,
                         touchPosition *p);

#endif
