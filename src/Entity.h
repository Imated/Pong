#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"

class Entity
{
public:
	Entity(Vector2 pos, SDL_Texture* tex);
	void setPos(float x, float y);
	void setScale(float w, float h);
	void setDirection(float direction);
	void update(float deltaTime);
	Vector2& getPos();
	Vector2& getScale();
	float getDirection();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	bool isCollidingWith(Entity& entity);
	bool isCollidingWith(Vector2 point);
private:
	Vector2 pos;
	Vector2 scale = Vector2(1);
	float direction = 0;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};

