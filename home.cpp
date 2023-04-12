#include "home.h"
#include "frog.h"

Home::Home(SDL_Renderer* renderer, int x, int y, int weight, int height)
	: ItemBase(renderer, x, 0.0, 0)
{
	texture = LoadTexture(renderer, FROG_TEXTURE_FILE_PATH);
	rect.x = x;
	rect.y = y;
	rect.w = weight;
	rect.h = height;

	Free = true;
}

void Home::Render(SDL_Renderer* renderer)
{
	if (!Free)
	{
		SDL_Rect frog;
		frog.w = FROG_SIZE_W;
		frog.h = FROG_SIZE_H;
		frog.x = rect.x + (rect.w - FROG_SIZE_W) / 2;
		frog.y = rect.y + (rect.h - FROG_SIZE_H) / 2;

		SDL_RenderCopyEx(renderer, texture, 0, &frog, 180.0, NULL, SDL_FLIP_NONE);
	}
}

void Home::Reset()
{
	Free = true;
}
