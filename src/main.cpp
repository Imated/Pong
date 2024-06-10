#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <map>
#include "Renderer.h"
#include "Button.h"
#include "TitleScreen.h"
#include "CRTOverlay.h"

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL has failed to init. Error: " << SDL_GetError() << std::endl;
	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG has failed to init images. Error: " << SDL_GetError() << std::endl;
	if (TTF_Init() < 0)
		std::cout << "TTF has failed and is now completely useless. Please delete this project. Error: " << TTF_GetError() << std::endl;
	return true;
}

Renderer window = Renderer("SDL Game 8.0", 720, 540);
bool hasInitialized = init();
bool gameRunning = true;
SDL_Event event;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
float deltaTime = 0;

int gameState = 0; // 0 = Menu, 1 = Gameplay

std::map<SDL_Keycode, bool> keyStates;

SDL_Texture* background = window.LoadTexture("res/background.png");

TTF_Font* pixelFont48 = TTF_OpenFont("res/pixel.ttf", 54);

void play()
{
	gameState = 1;
}

TitleScreen* titleScreen = new TitleScreen(&window, pixelFont48, play);
CRTOverlay* crtOverlay = new CRTOverlay(&window);

void update()
{
	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick) / (double)SDL_GetPerformanceFrequency());

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_KEYDOWN:
			keyStates[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			keyStates[event.key.keysym.sym] = false;
			break;
		}
	}

	if (gameState == 0)
		titleScreen->update(deltaTime, event);
	crtOverlay->update(deltaTime, event);
}



void render()
{
	window.Clear();
	window.render(0, 0, background);
	if (gameState == 0) 
	{
		titleScreen->render();
	}
	else if (gameState == 1) 
	{
		
	}
	crtOverlay->render();
	window.Display();
}

void game()
{
	update();
	render();
}

int main(int argc, char* argv[])
{
	while (gameRunning)
	{
		game();
	}

	window.CleanUp();
	TTF_CloseFont(pixelFont48);
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
	return 0;
}