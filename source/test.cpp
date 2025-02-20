#include "hardware.h"
#include <3ds.h>
#include <stdio.h>

int
__main (int argc, char **argv)
{
  gfxInitDefault ();
  consoleInit (GFX_TOP, NULL);

  u32 oldPressed = 0;

  printf ("\x1b[1;1HPress Start to exit.");
  printf ("\nCirclePad position:");

  // Main loop
  while (aptMainLoop ())
    {
      Hardware::listenInput();

      if (Hardware::OptSelect () && Hardware::R())
        break; // break in order to return to hbmenu

      u32 newPressed = Hardware::rawButtons ();

      if (oldPressed != newPressed)
        {
          // Clear console
          consoleClear ();

          // These two lines must be rewritten because we cleared the whole
          // console
          printf ("\x1b[1;1HPress Start to exit.");
          printf ("\nCirclePad position:");

          printf (
              "\x1b[4;1H"); // Move the cursor to the fourth row because on the
                            // third one we'll write the circle pad position

          std::cout << Hardware::toString () << std::endl;
        }

      // Set keys old values for the next frame
      oldPressed = newPressed;

      circlePosition circle;
      circlePosition cstick;

      Hardware::CirclePad (circle);
      Hardware::CStick (cstick);

      printf ("\x1b[5;1H");

      std::cout << "Circle pad: " << Hardware::toString(circle) << std::endl
                << "C-Stick: " << Hardware::toString(cstick) << std::endl
                << "Is NEW 3DS? " << (Hardware::isNewModel () ? "true" : "false");

      // Flush and swap framebuffers
      gfxFlushBuffers ();
      gfxSwapBuffers ();

      // Wait for VBlank
      gspWaitForVBlank ();
    }

  // Exit services
  gfxExit ();
  return 0;
}
