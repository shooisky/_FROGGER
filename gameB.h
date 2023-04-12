#ifndef GAMEBOARD_H
#define GAMEBOARD_H

using namespace std;

#include "SDL.h"
#include "frog.h"
#include "row.h"
#include "base.h"
#include "home.h"


#include <SDL_image.h>
#include <list>

#define ROW_COUNT 13
#define HOME_COUNT 5
#define MAX_CARS 50
#define BOARD_TEXTURE_FILE_PATH "background.png"

class GameBoard
{
public:
	// konstruktor
	GameBoard(SDL_Renderer* renderer);

	// destruktor
	~GameBoard();

	// resetuje stan obiektu
	void Reset();

	// aktualizuje stan obiektu
	void Update(int* gameState);

	// renderuje obiekt
	void Render(SDL_Renderer* renderer);

	// zwraca wska?nik na ?ab?
	void DoLeft();
	void DoRight();
	void DoUp(int* gameState);
	void DoDown();

	Frog* GetFrog();

	bool Splash = false;
	bool win = false;

	list<ItemBase> cars;

	int GetYLocation(int hight, int rowIndex);

private:
	// tekstura planszy
	SDL_Texture* boardTexture;

	// ¿aba
	Frog frog;
	// funkcja do ?adowania tekstury
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filePath) {
		SDL_Surface* surface = IMG_Load(filePath); // za?adowanie obrazka do powierzchni
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // stworzenie tekstury z powierzchni
		SDL_FreeSurface(surface); // zwolnienie powierzchni
		return texture; // zwrócenie utworzonej tekstury
	}

	void CreateVechicles(SDL_Renderer* renderer);
	void CheckFrogIsHome(int* gameState);

	// drogi i pojazdy
	Row* rows[ROW_COUNT];
	Home* home[HOME_COUNT];



};

#endif // GAMEBOARD_H