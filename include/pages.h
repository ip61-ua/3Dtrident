#ifndef _PAGE_H_
#define _PAGE_H_

#include <stdbool.h>
#include <stdlib.h>

typedef void EntryPage;
typedef EntryPage (*Page) ();
extern Page PAGE_CURRENT;

// interface
extern Page PAGE_MAIN;
extern Page PAGE_ABOUT;
// end

void Page_setup (bool *, void (*) ());
void Page_changeTo (Page, void (*) ());

#endif
