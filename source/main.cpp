#include <3ds.h>
#include <stdio.h>
#include "hardware.h"

int main(int argc, char **argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	u32 oldPressed = 0;

	printf("\x1b[1;1HPress Start to exit.");
	printf("\nCirclePad position:");

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		if (Hardware::A()) break; // break in order to return to hbmenu

		u32 newPressed = Hardware::rawButtons();

		if (oldPressed != newPressed)
		{
			//Clear console
			consoleClear();

			//These two lines must be rewritten because we cleared the whole console
			printf("\x1b[1;1HPress Start to exit.");
			printf("\nCirclePad position:");

			printf("\x1b[4;1H"); //Move the cursor to the fourth row because on the third one we'll write the circle pad position

			if(Hardware::B()) printf("Pulsando B");
			if(Hardware::X()) printf("Pulsando X");
			if(Hardware::Y()) printf("Pulsando Y");

		}

		//Set keys old values for the next frame
		oldPressed = newPressed;

		circlePosition pos;

		//Read the CirclePad position
		Hardware::CirclePad(pos);

		//Print the CirclePad position
		printf("\x1b[3;1H%04d; %04d", pos.dx, pos.dy);

		circlePosition cstick;
		Hardware::CStick(cstick);
		printf("   CSTICK: %04d; %04d", cstick.dx, cstick.dy);

		printf("   NEW 3DS? %d", Hardware::isNewModel());


		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	// Exit services
	gfxExit();
	return 0;
}
