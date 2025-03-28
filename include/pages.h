#ifndef _PAGE_H_
#define _PAGE_H_

#include <stdbool.h>
#include <stdlib.h>

typedef void EntryPage;
typedef EntryPage (*Page) ();

extern Page PAGE_CURRENT;
// Interfaz para la declaración de las páginas que hay disponibles.
extern Page PAGE_MAIN;
extern Page PAGE_DRAW;
extern Page PAGE_MICS;
extern Page PAGE_VIEW;
extern Page PAGE_NETW;
extern Page PAGE_ABOUT;
// FIN.

/**
 * @brief Mecanismo de actuación para la inicialización de una página.
 * @param cond Puntero de booleano que se actualiza su valor, al ejecutarse
 * la función start. No se actualiza si no se ejecuta.
 * @param start Función "callback" a ejecutar para inicializar la visualización
 * de página.
 */
void Page_setup (bool *cond, void (*start) ());

/**
 * @brief Cambia a la página solicitada, previamente llamando a quit.
 * @param page Página a la que cambiar.
 * @param quit Función "callback" a la que llamar antes del cambio.
 * @remarks La función quit es la responsable que manejar el bool de cond
 * para la función Page_setup.
 */
void Page_changeTo (Page page, bool *cond, void (*quit) ());

#endif
