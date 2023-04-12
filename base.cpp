#include "base.h"

#include <SDL_image.h>

ItemBase::ItemBase()
{

}

ItemBase::ItemBase(SDL_Renderer* renderer, int startX, int direction, double speed)
{
	this->startX = startX;
	this->direction = direction;
	this->speed = speed == 0.0 ? .1 : speed;
}

ItemBase::~ItemBase()
{
}

void ItemBase::Reset()
{
	rect.x = startX;
}

void ItemBase::Update(int* gameState)
{
	startX += speed * direction;
	rect.x = (int)startX;

	// sprawdzenie czy pojazd wyjecha³ poza ekran i je¿eli tak to Reset()
	if (direction == 1 && rect.x + rect.w >= GAME_WIDTH + 74)
	{
		int x = (rect.x + rect.w) - (GAME_WIDTH + 74);
		rect.x = x - rect.w;
		startX = rect.x;
	}
	else if (direction == -1 && rect.x < -74)
	{
		rect.x = GAME_WIDTH - (rect.x - 74);
		startX = rect.x;
	}
}

void ItemBase::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, 0, &rect, direction > 0 ? 180.0 : 0.0, NULL, SDL_FLIP_NONE);
}

SDL_Rect* ItemBase::GetRect()
{
	return &rect;
}