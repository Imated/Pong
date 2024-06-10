#include "Screen.h"

Screen::Screen(Renderer* window, TTF_Font* pixelFont)
{
	this->window = window;
	this->pixelFont = pixelFont;
}