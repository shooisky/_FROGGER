#ifndef WINNER_BOARD_H
#define WINNER_BOARD_H
#define	WINNER_BOARD_TEXTURE_FILE_PATH "you_win.png"

#include <SDL_image.h>

class WinnerBoard
{
public:
	WinnerBoard(SDL_Renderer* renderer); // konstruktor

	~WinnerBoard(); // destruktor

	void Reset(); // resetuje licznik

	void Update(int* gameState, int* mainGameState); // aktualizuje stan obiektu

	void Render(SDL_Renderer* renderer); // rysuje planszê

	bool win = false;

private:
	SDL_Texture* winTexture; // tekstura planszy

	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filePath) {
		SDL_Surface* surface = IMG_Load(filePath); // za³adowanie obrazka do powierzchni
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // stworzenie tekstury z powierzchni
		SDL_FreeSurface(surface); // zwolnienie powierzchni
		return texture; // zwrócenie utworzonej tekstury
	}

	SDL_Rect boardRect = { 0, 0, 800, 600 }; // prostok¹t planszy
	int counter = 0; // licznik czasu wyœwietlania planszy

};

#endif // WINNER_BOARD_H