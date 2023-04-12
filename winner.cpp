#include "winner.h"
#include "define.h"

// konstruktor obiektu pokazuj�cego plansz� zwyci�stwa
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
	// zmie� stan je�eli ekran by� prezentowany ponad sekund�
	if (counter++ > 100)
	{
		Reset();
		*gameState = *mainGameState;
	}
}

// rysuje plansz�
void WinnerBoard::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, winTexture, 0, &boardRect);
}