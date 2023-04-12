#ifndef BASE_H
#define BASE_H

#include<SDL_image.h>
#include "define.h"

class ItemBase
{
public:
	ItemBase();
	ItemBase(SDL_Renderer* renderer, int startX, int direction, double speed);

	~ItemBase();

	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filePath) {
		SDL_Surface* surface = IMG_Load(filePath); // za³adowanie obrazka do powierzchni
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // stworzenie tekstury z powierzchni
		SDL_FreeSurface(surface); // zwolnienie powierzchni
		return texture; // zwrócenie utworzonej tekstury
	}

	void Reset();

	virtual void Update(int* gameState);

	void Render(SDL_Renderer* renderer);

	SDL_Rect* GetRect();

protected:
	// przechowuje teksturê obiektu
	SDL_Texture* texture;

	SDL_Rect rect;

	// przechowuje prêdkoœæ pojazdu
	double speed;

	// przechowuje kierunek poruszania siê pojazdu (-1 - w lewo, 1 - w prawo)
	int direction;

	double startX;
};

#endif

