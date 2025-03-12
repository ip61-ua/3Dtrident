#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <3ds.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

extern const unsigned MAX_STICK_VALUE;

// Info
/**
 * @brief Comprueba si el sistema es NEW o OLD.
 * @returns Para NEW, true. En otro caso, false.
 */
bool Hardware_isNewModel ();

// Joystics
/**
 * @brief Calcula el valor relativo para un valor del eje
 * de un joystick.
 * @param x Valor de eje a relativizar.
 * @returns Valor relativizado a [-MAX_STICK_VALUE, +MAX_STICK_VALUE].
 */
s8 Hardware_toRelativeCircleRange (const s16 x);
/**
 * @brief Relativizar los valores de un objeto circlePosition.
 * @param c Puntero de circlePosition a modificar.
 */
void Hardware_toRelativeCirclePosition (circlePosition *c);
/**
 * @brief Leer la entrada del Pad circular izquierdo.
 * @param c Puntero de circlePosition destino.
 */
void Hardware_CirclePad (circlePosition *c);
/**
 * @brief Leer la entrada de la palanca c derecha.
 * @param c Puntero de circlePosition destino.
 */
void Hardware_CStick (circlePosition *c);

// Touch
/**
 * @brief Detectar si la pantalla táctil se toca.
 * @returns true si se toca, false en otro caso.
 */
bool Hardware_isTouching ();
/**
 * @brief Obtener la última posición donde se haya tocado.
 * @returns Objeto constante touchPosition*.
 * @remarks Debe usarse conjuntamente con Hardware_Touch.
 */
const touchPosition * Hardware_TouchLast ();
/**
 * @brief Lee la entrada de la posición actual tocada en el panel
 * táctil. Además, guarda la posición anterior.
 * @param t Puntero de touchPosition destino.
 * @returns true si la posición guardada en t es válida.
 */
bool Hardware_Touch (touchPosition *t);
/**
 * @brief Lee la entrada de la posición actual tocada en el panel
 * táctil exclusivamente.
 * @param t Puntero de touchPosition destino.
 * @returns true si la posición guardada en t es válida.
 */
bool Hardware_CurrentTouch (touchPosition *t);

// Buttons
/**
 * @brief Obtiene la entrada en bruto de que teclas están activas.
 * @returns Entero en bruto.
 */
u32 Hardware_rawButtons ();
/**
 * @brief Lógica de verificación para una tecla k en concreto.
 * @param k Tecla a comprobar.
 * @returns true si está activa dicha tecla k, false en otro.
 */
bool Hardware_isHeldButton (const unsigned k);
/**
 * @brief Comprueba si el botón A está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_A ();
/**
 * @brief Comprueba si el botón B está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_B ();
/**
 * @brief Comprueba si el botón X está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_X ();
/**
 * @brief Comprueba si el botón Y está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_Y ();

/**
 * @brief Comprueba si el botón ⬆️ está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_DUp ();
/**
 * @brief Comprueba si el botón ⬇️ está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_DDown ();
/**
 * @brief Comprueba si el botón ➡️ está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_DRight ();
/**
 * @brief Comprueba si el botón ⬅️ está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_DLeft ();

/**
 * @brief Comprueba si el botón L está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_L ();
/**
 * @brief Comprueba si el botón R está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_R ();
/**
 * @brief Comprueba si el botón ZR está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_ZR ();
/**
 * @brief Comprueba si el botón ZL está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_ZL ();

/**
 * @brief Comprueba si el botón START está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_OptStart ();
/**
 * @brief Comprueba si el botón SELECT está presionado.
 * @return true si está presionado, false en otro caso.
 */
bool Hardware_OptSelect ();

// Misc
/**
 * @brief Habilitar la lectura de entrada.
 */
void Hardware_listenInput ();
/**
 * @brief Transcribir a cadena la posición.
 * @param dst Cadena destino.
 * @param x Entero eje X
 * @param y Entero eje Y
 */
void Hardware_toStringPosition (char *dst, const int x, const int y);

#endif
