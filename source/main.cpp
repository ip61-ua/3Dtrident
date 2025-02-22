#include "screen.h"
#include <3ds.h>
#include <citro2d.h>

C2D_TextBuf g_staticBuf;
C2D_Text g_staticText[2];
C2D_Font font[2];

static void
sceneInit (void)
{
  g_staticBuf = C2D_TextBufNew (4096);
  font[0] = C2D_FontLoadSystem (CFG_REGION_USA);
  font[1] = C2D_FontLoadSystem (CFG_REGION_KOR);

  // Parse the text strings
  // Loads system font
  C2D_TextFontParse (&g_staticText[0], font[0], g_staticBuf,
                     "A boring system font.");
  // Uses loaded font
  C2D_TextFontParse (&g_staticText[1], font[1], g_staticBuf,
                     "이 텍스트는 한국어입니다.");
  // Uses other loaded font

  // Optimize the text strings
  C2D_TextOptimize (&g_staticText[0]);
  C2D_TextOptimize (&g_staticText[1]);
}

static void
sceneExit (void)
{
  // Delete the text buffers
  C2D_TextBufDelete (g_staticBuf);
  C2D_FontFree (font[0]);
  C2D_FontFree (font[1]);
}

int
main ()
{
  setupControls ();

  // Main loop
  while (aptMainLoop ())
    {
      hidScanInput ();

      // Render the scene
      C3D_FrameBegin (C3D_FRAME_SYNCDRAW);
      showControls ();
      C3D_FrameEnd (0);
    }

  // Deinitialize the scene
  sceneExit ();

  // Deinitialize the libs
  C2D_Fini ();
  C3D_Fini ();
  romfsExit ();
  cfguExit ();
  gfxExit ();
  return 0;
}
