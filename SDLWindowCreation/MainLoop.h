#include "MotherOfAllHeaders.h"

class MainLoop
{
public:
	MainLoop();
	~MainLoop();

	void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

	void mainEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:

	bool isRunning;
	
	SDL_Window *window;
	SDL_Renderer *renderer;
};

