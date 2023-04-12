#ifndef HOME_H
#define HOME_H

#include "base.h"

class Home : public ItemBase
{
public:
	Home(SDL_Renderer* renderer, int x, int y, int weight, int height);

	void Reset();

	void Render(SDL_Renderer* renderer);

	bool Free;
};

#endif