#include "CRTOverlay.h"

CRTOverlay::CRTOverlay(Renderer* window)
	: Screen(window, nullptr), crtOverlay(window->LoadTexture("res/crt.png")),
	crtEntity(Vector2(360, 270), crtOverlay), crtEntityClone(Vector2(360, 990), crtOverlay)
{
}

void CRTOverlay::render()
{
	window->render(crtEntity);
	window->render(crtEntityClone);
}

void CRTOverlay::update(float deltaTime, SDL_Event event)
{
	moveCRT(deltaTime);
}

void CRTOverlay::moveCRT(float deltaTime)
{
	crtEntity.setPos(360, crtEntity.getPos().y - 25 * deltaTime);
	crtEntityClone.setPos(360, crtEntityClone.getPos().y - 25 * deltaTime);
	if (crtEntity.getPos().y + crtEntity.getCurrentFrame().h / 2 < 0) {
		crtEntity.setPos(360, 990);
	}
	if (crtEntityClone.getPos().y + crtEntityClone.getCurrentFrame().h / 2 < 0) {
		crtEntityClone.setPos(360, 990);
	}
}