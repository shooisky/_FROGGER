#ifndef LOSERBOARD_H
#define LOSERBOARD_H

//#define GREENSPLAT_BOARD_TEXTURE_FILE_PATH "green_splat1.png"
#define GREENSPLAT_BOARD_TEXTURE_FILE_PATH "green_splat1.png"

#include <SDL.h>
#include<SDL_image.h>

class LoserBoard
{
public:
	// konstruktor planszy z komunikatem o przegranej
	LoserBoard(SDL_Renderer* renderer);

	// destruktor
	~LoserBoard();

	// resetuje licznik (opóŸnienie czasowe)
	void Reset();

	// aktualizuje stan obiektu
	void Update(int* gameState);

	// rysuje planszê
	void Render(SDL_Renderer* renderer);

	bool Splash = false;
private:
	SDL_Texture* greenSplatTexture; // tekstura planszy
	//SDL_Texture* splashTexture; // tekstura planszy

	// funkcja do ³adowania tekstury
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filePath) {
		SDL_Surface* surface = IMG_Load(filePath); // za³adowanie obrazka do powierzchni
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // stworzenie tekstury z powierzchni
		SDL_FreeSurface(surface); // zwolnienie powierzchni
		return texture; // zwrócenie utworzonej tekstury
	}

	SDL_Rect boardRect; // prostok¹t planszy
	int counter; // licznik czasu
};

#endif // LOSERBOARD_H