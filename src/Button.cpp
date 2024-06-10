#include "Button.h"
#include <iostream>

Button::Button(Vector2 pos, SDL_Texture* tex) : Entity(pos, tex)
{
	
}

void Button::update(float deltaTime, Vector2 mousePosition, bool mouseDown, void* onClick)
{
	SDL_Point* mousePoint = new SDL_Point { static_cast<int>(mousePosition.x), static_cast<int>(mousePosition.y) };
	SDL_Rect frame = getCurrentFrame();
	
	if (isCollidingWith(mousePosition))
	{
		if(!wasCollidingWithMouse)
			scaleTimer = 0;
		if (scaleTimer <= 0.25f)
		{
			setScale(1 + scaleTimer * 0.8, 1 + scaleTimer * 0.8);
			scaleTimer += deltaTime;
		}
		if (mouseDown && !wasMouseDown)
		{
			if (onClick != nullptr)
				((void(*)())onClick)();
			wasMouseDown = mouseDown;
		}
		if (!mouseDown && wasMouseDown)
		{
			wasMouseDown = mouseDown;
		}

		wasCollidingWithMouse = true;
	}
	else
	{
		if(wasCollidingWithMouse)
			scaleTimer = 0;
		if (scaleTimer <= 0.25f)
		{
			setScale(1.2 - scaleTimer * 0.8, 1.2 - scaleTimer * 0.8);
			scaleTimer += deltaTime;
		}
		wasCollidingWithMouse = false;
	}
}

