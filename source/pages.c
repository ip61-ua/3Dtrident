#include "pages.h"

Page PAGE_CURRENT;

void
Page_setup (bool *cond, void (*start) ())
{
  if (!(*cond))
    {
      if (start != NULL)
        start ();

      *cond = true;
    }
}

void
Page_changeTo (Page page, void (*quit) ())
{
  if (quit != NULL)
    quit ();
  PAGE_CURRENT = page;
}
