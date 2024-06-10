#pragma once
#include "Entity.h"

class Button : public Entity
{
public:
	Button(Vector2 pos, SDL_Texture* tex);
	void update(float deltaTime, Vector2 mousePosition, bool mouseDown, void* onClick);
protected:
	bool wasMouseDown = false;
	bool wasCollidingWithMouse = false;
	float scaleTimer = 0;
};

