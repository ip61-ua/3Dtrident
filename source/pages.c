#include "pages.h"

Page PAGE_CURRENT;

void
Page_setup (bool *cond, void (*start) ())
{
  if (!(*cond) || cond == NULL)
    {
      if (start != NULL)
        start ();

      if (cond != NULL)
        *cond = true;
    }
}

void
Page_changeTo (Page page, bool *cond, void (*quit) ())
{
  *cond = false;

  if (quit != NULL)
    quit ();
  PAGE_CURRENT = page;
}
