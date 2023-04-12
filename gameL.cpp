using namespace std;

#include "gameL.h"
#include "main.h"
#include "gameB.h"
#include "lose.h"
#include "winner.h"
#include "define.h"
#include <iostream>
#include <cstdlib>
#include "AI.h"

// konstruktor obiektu logiki gry
GameLogic::GameLogic()
{
}

// destruktor obiektu logiki gry
GameLogic::~GameLogic()
{
}

// uruchamia gr? i implementuje g?ówn? p?tl? komunikatów
int GameLogic::Run()
{
	// zmienne lokalne
	SDL_Event e;
	int gameState;
	int mainGameState;
	AI ai;
	int counter = 0;

	// inicjalizacja SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// utworzenie okna i renderera
	window = SDL_CreateWindow(GAME_TITLE, 100, 100, GAME_WIDTH, GAME_HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (window == NULL)
	{
		cout << "Could not create window: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG))
	{
		cout << "Failde to initialise IMG_Image for PNG: " << IMG_GetError() << endl;
		return EXIT_FAILURE;
	}
	// utworzenie obiektów gry:
	// - menu g?ównego
	// - planszy gry
	// - planszy z komunikatem o przegranej
	// - planszy z komunikatem o wygranej
	MainMenu mainMenu(renderer);
	GameBoard gameBoard(renderer);
	LoserBoard loserBoard(renderer);
	WinnerBoard winnerBoard(renderer);

	// pocz?tkowo jeste?my w menu g?ównym
	gameState = GAME_STATE_MAIN_MENU;
	mainGameState = GAME_STATE_RUNNING;

	// g?ówna p?tla komunikatów (dopóki u?ytkownik nie zako?czy, poprzez wybór z menu)
	while (gameState != GAME_STATE_QUIT)
	{
		// "pompuj" kolejny komunikat
		if (SDL_PollEvent(&e) && gameState == GAME_STATE_RUNNING)
		{
			// je?eli wyj?cie 
			if (e.type == SDL_QUIT)
			{
				// zako?cz g?ówn? p?tl?
				break;
			}

			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_LEFT)
			{
				gameBoard.DoLeft();
			}

			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_RIGHT)
			{
				gameBoard.DoRight();
			}

			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_UP)
			{
				gameBoard.DoUp(&gameState);
			}

			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_DOWN)
			{
				gameBoard.DoDown();
			}
		}
		else if (gameState == GAME_STATE_AUTO)
		{
			counter++;
			if (counter > 25) {
				MoveType move = ai.GetNextMove(gameBoard);

				if (move == GoUp) {
					gameBoard.DoUp(&gameState);
				}

				else if (move == GoDown)
				{
					gameBoard.DoDown();
				}

				else if (move == GoLeft)
				{
					gameBoard.DoLeft();
				}

				else if (move == GoRight)
				{
					gameBoard.DoRight();
				}
				counter = 0;
			}

		}

		SDL_RenderClear(renderer);


		if (gameState == GAME_STATE_MAIN_MENU)
		{
			mainMenu.Update(&gameState, &mainGameState);
			mainMenu.Render(renderer);
		}

		else if (gameState == GAME_STATE_RUNNING || gameState == GAME_STATE_AUTO)
		{
			gameBoard.Update(&gameState);
			gameBoard.Render(renderer);
		}

		else if (gameState == GAME_STATE_LOSER)
		{
			loserBoard.Splash = gameBoard.Splash;
			loserBoard.Update(&gameState);
			loserBoard.Render(renderer);
		}
		// wygrana
		else if (gameState == GAME_STATE_WINNER)
		{
			winnerBoard.win = gameBoard.win;
			winnerBoard.Update(&gameState, &mainGameState);
			winnerBoard.Render(renderer);
		}

		// prezentacja wyniku renderowania
		SDL_RenderPresent(renderer);
		// czekaj 10 milisekund (?eby gra dzia?a?a z takim samym tempem na ka?dej maszynie)
		SDL_Delay(10);
	}

	// zniszcz renderer i okno
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}