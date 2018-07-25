#include "MotherOfAllHeaders.h"

MainLoop *mLoop = nullptr;

int main(int argc, char *argv[])
{
	mLoop = new MainLoop();

	// Here you  name your window, give it possition width and height. But remember if you put bool to true you 
	// will not exit the fullscren easy, then you need to use ALT + SHIFT + DELETE and end proces in task manager.
	//Or before you run the code with full screen on, you can write new switch in MainLoop.cpp.

	mLoop->init("YOUR SDL WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (mLoop -> running())
	{

		mLoop->mainEvents();
		mLoop->update();
		mLoop->render();
	}

	mLoop->clean();

	return 0;
}