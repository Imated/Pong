#include "TitleScreen.h"

TitleScreen::TitleScreen(Renderer* window, TTF_Font* pixelFont, void* playFunc)
	: Screen(window, pixelFont), startBtn(window->LoadTexture("res/playButton.png")),
	startBtnEntity(Vector2(360, 300), startBtn), playFunc(playFunc)
{
}

void TitleScreen::render()
{
	window->renderText(360, 50, "RETRO", pixelFont);
	window->renderText(360, 105, "PONG", pixelFont);

	window->render(startBtnEntity);
}

void TitleScreen::update(float deltaTime, SDL_Event event)
{
	bool mouseDown = event.button.state == SDL_PRESSED;
	int mouseX, mouseY;
	Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	startBtnEntity.update(deltaTime, Vector2(mouseX, mouseY), mouseState & SDL_BUTTON(SDL_BUTTON_LEFT), playFunc);
}