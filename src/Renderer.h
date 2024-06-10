#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Entity.h"

class Renderer
{
public:
	Renderer(const char* title, int w, int h);
	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Display();
	void CleanUp();
	void render(int x, int y, SDL_Texture* tex);
	void render(Entity& entity);
	void renderText(int x, int y, const char* text, TTF_Font* font);
	void renderColor(SDL_Color color);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

