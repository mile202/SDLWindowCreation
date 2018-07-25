#include "MotherOfAllHeaders.h"



MainLoop::MainLoop()
{}


MainLoop::~MainLoop()
{}


void MainLoop::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//SDL Initialization

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0 )
	{

		// Uint32 flags


		int flags = 0;

		if (flags)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		std::cout << "SDL is initialized!...." << std::endl;

		//Window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window is initialized!...." << std::endl;

		}

		//Renderer

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			// Renderer draw color (color of your window - white one)
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			
			std::cout << "Renderer is initialized!...." << std::endl;

		}

		// Bool isRunning must be true to create window and renderer!

		isRunning = true;

	}
	else
	{
		// If window or renderer or both of them are not initialized then isRunning is false and code is not working.
		isRunning = false;
	}

}

void MainLoop::mainEvents()
{

	// EVENTS
	SDL_Event event;
	SDL_PollEvent(&event);

	//Switch

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

	/*
	Remove comments for this switch if you want to use fullscreen
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		isRunning = false;
		break;
	default:
		break;
	}
	*/

}

// In here you will enter your code to update window
void MainLoop::update()
{}

// Render
void MainLoop::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

}

// Afer you exit (click on X button) this will clean window and renderer.
void MainLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Window is cleaned!...." << std::endl;
}