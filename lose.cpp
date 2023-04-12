#include "lose.h"
#include "define.h"

// konstruktor planszy z komunikatem o przegranej
LoserBoard::LoserBoard(SDL_Renderer* renderer)
{
	// wczytanie tekstury i reset
	greenSplatTexture = LoadTexture(renderer, GREENSPLAT_BOARD_TEXTURE_FILE_PATH);
	boardRect.w = GAME_WIDTH;
	boardRect.h = GAME_HEIGHT;
	Reset();
}

// destruktor
LoserBoard::~LoserBoard()
{
}

// resetuje licznik (op�nienie czasowe)
void LoserBoard::Reset()
{
	counter = 0;
}

// aktualizuje stan obiektu
void LoserBoard::Update(int* gameState)
{
	// zmie� stan je�eli ekran by� prezentowany ponad sekund�
	if (counter++ > 100)
	{
		Reset();
		*gameState = GAME_STATE_RUNNING;
	}
}

// rysuje plansz�
void LoserBoard::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, greenSplatTexture, 0, &boardRect);

};