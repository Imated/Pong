#pragma once
#include "Renderer.h"

class Screen
{
public:
	Screen(Renderer* window, TTF_Font* pixelFont);
	void render();
	void update(float deltaTime, SDL_Event event);
	void exit();
protected:
	Renderer* window;
	TTF_Font* pixelFont;
};

