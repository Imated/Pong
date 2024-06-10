#pragma once
#include "Screen.h"

class CRTOverlay : public Screen
{
public:
	CRTOverlay(Renderer* window);
	void render();
	void update(float deltaTime, SDL_Event event);
private:
	SDL_Texture* crtOverlay;
	Entity crtEntity;
	Entity crtEntityClone;
	void moveCRT(float deltaTime);
};

