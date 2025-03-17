#include "page_about.h"

static bool active = false;

static EntryPage entry ();
static void quitPage ();

Page PAGE_ABOUT = entry;

EntryPage
entry ()
{
  Page_setup (&active, NULL);

  Hardware_listenInput ();

  Screen_setBackground (top, Color_red);
  Screen_setBackground (bottom, Color_blue);
  if (Hardware_B ())
    Page_changeTo (PAGE_MAIN, &active, quitPage);
}

void
quitPage ()
{
}
