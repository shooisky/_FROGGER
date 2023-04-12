#include "winner.h"
#include "define.h"

// konstruktor obiektu pokazuj¹cego planszê zwyciêstwa
WinnerBoard::WinnerBoard(SDL_Renderer* renderer)
{
	winTexture = LoadTexture(renderer, WINNER_BOARD_TEXTURE_FILE_PATH);
	boardRect.w = GAME_WIDTH;
	boardRect.h = GAME_HEIGHT;
	Reset();
}

// destruktor
WinnerBoard::~WinnerBoard()
{
}

// resetuje licznik
void WinnerBoard::Reset()
{
	counter = 0;
}

// aktualizuje stan obiektu
void WinnerBoard::Update(int* gameState, int* mainGameState)
{
	// zmieñ stan je¿eli ekran by³ prezentowany ponad sekundê
	if (counter++ > 100)
	{
		Reset();
		*gameState = *mainGameState;
	}
}

// rysuje planszê
void WinnerBoard::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, winTexture, 0, &boardRect);
}