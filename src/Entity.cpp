#include "Entity.h"

Entity::Entity(Vector2 pos, SDL_Texture* tex) : pos(pos), tex(tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 16;
	currentFrame.h = 16;
	SDL_QueryTexture(tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

void Entity::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

Vector2& Entity::getPos()
{
	return pos;
}

void Entity::setScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void Entity::setDirection(float dir)
{
	direction = dir;
}

Vector2& Entity::getScale()
{
	return scale;
}

float Entity::getDirection()
{
	return direction;
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

bool Entity::isCollidingWith(Entity& entity)
{
	if (
		((entity.getPos().x >= getPos().x - getCurrentFrame().w / 2 * getScale().x)
			&& (entity.getPos().x < (getPos().x + getCurrentFrame().w / 2 * getScale().x))
			&& (entity.getPos().y >= getPos().y - getCurrentFrame().h / 2 * getScale().y)
			&& (entity.getPos().y < (getPos().y + getCurrentFrame().h / 2 * getScale().y)))
		)
	{
		return true;
	}
	return false;
}

bool Entity::isCollidingWith(Vector2 point)
{
	if (
		((point.x >= getPos().x - getCurrentFrame().w / 2 * getScale().x)
		&& (point.x < (getPos().x + getCurrentFrame().w / 2 * getScale().x))
		&& (point.y >= getPos().y - getCurrentFrame().h / 2 * getScale().y)
		&& (point.y < (getPos().y + getCurrentFrame().h / 2 * getScale().y)))
		)
	{
		return true;
	}
	return false;
}
