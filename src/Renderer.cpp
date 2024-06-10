#include "Renderer.h"
#include <iostream>
#include <windows.h>
#include <SDL_syswm.h>

Renderer::Renderer(const char* title, int w, int h)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL)
		std::cout << "Window failed to initialize. Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
		std::cout << "Renderer failed to initialize. Error: " << SDL_GetError() << std::endl;

	// Apply windows window stuff like curved edges and shadows, borderless style only, otherwise, you will get some weird windows 98 style thing
	//SDL_SysWMinfo wmInfo;
	//SDL_VERSION(&wmInfo.version);
	//SDL_GetWindowWMInfo(window, &wmInfo);
	//HWND hwnd = wmInfo.info.win.window;
	//HRGN hRgn = CreateRoundRectRgn(0, 0, w, h, 25, 25);
	//SetWindowRgn(hwnd, hRgn, TRUE);
}

SDL_Texture* Renderer::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void Renderer::render(int x, int y, SDL_Texture* tex)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w;
	src.h;
	SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, tex, &src, &dst);
}

void Renderer::render(Entity& entity)
{
	SDL_Rect src = entity.getCurrentFrame();
	SDL_Rect dst;
	dst.x = entity.getPos().x - entity.getCurrentFrame().w * entity.getScale().x / 2;
	dst.y = entity.getPos().y - entity.getCurrentFrame().h * entity.getScale().y / 2;
	dst.w = entity.getCurrentFrame().w * entity.getScale().x;
	dst.h = entity.getCurrentFrame().h * entity.getScale().y;
	float angle = entity.getDirection();
	SDL_RenderCopyEx(renderer, entity.getTex(), &src, &dst, entity.getDirection(), 0, SDL_FLIP_NONE);
}

void Renderer::renderText(int x, int y, const char* text, TTF_Font* font)
{
	SDL_Color color = { 255, 255, 255 };
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	if (surface == NULL)
	{
		std::cerr << "Unable to create text surface. Error:" << TTF_GetError() << std::endl;
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		std::cerr << "Unable to create texture from font. Error:" << TTF_GetError() << std::endl;
		return;
	}

	float posX = x - (surface->w / 2);
	float posY = y - (surface->h / 2);
	SDL_Rect renderQuad = { posX, posY, surface->w, surface->h };

	SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Renderer::renderColor(SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Renderer::Clear()
{
	SDL_RenderClear(renderer);
}

void Renderer::Display()
{
	SDL_RenderPresent(renderer);
}

void Renderer::CleanUp()
{
	SDL_DestroyWindow(window);
}
