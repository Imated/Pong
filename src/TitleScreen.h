#pragma once
#include "Screen.h"
#include "Button.h"

class TitleScreen : public Screen
{
public:
	TitleScreen(Renderer* window, TTF_Font* pixelFont, void* play);
	void render();
	void update(float deltaTime, SDL_Event event);
private:
	SDL_Texture* startBtn;
	Button startBtnEntity;
	void* playFunc;
};