using namespace std;

#include "gameB.h"
#include "define.h"
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>

#include "car.h"


// konstruktor g³ównej planszy gry
GameBoard::GameBoard(SDL_Renderer* renderer) : frog(renderer)
{
	time_t t;
	srand((unsigned)time(&t));

	// wczytaj teksturê
	boardTexture = LoadTexture(renderer, BOARD_TEXTURE_FILE_PATH);

	rows[0] = new Row(640, 50); //Start Row
	rows[1] = new Row(590, 50); //Street Lane 1
	rows[2] = new Row(540, 50); //Street Lane 2
	rows[3] = new Row(490, 50); //Street Lane 3
	rows[4] = new Row(440, 50); //Street Lane 4
	rows[5] = new Row(390, 50); //Street Lane 5 
	rows[6] = new Row(335, 55); //Median
	rows[7] = new Row(285, 50); //Water Lane 1
	rows[8] = new Row(235, 50); //Water Lane 2
	rows[9] = new Row(185, 50); //Water Lane3;
	rows[10] = new Row(135, 50); //Water Lane4;
	rows[11] = new Row(85, 50); //Water Lane5;
	rows[12] = new Row(20, 65); // FinishRow;

	CreateVechicles(renderer);

	home[0] = new Home(renderer, 5, 20, 80, 65);
	home[1] = new Home(renderer, 120, 20, 110, 65);
	home[2] = new Home(renderer, 260, 20, 80, 65);
	home[3] = new Home(renderer, 395, 20, 80, 65);
	home[4] = new Home(renderer, 520, 20, 80, 65);

}




// destruktor
GameBoard::~GameBoard()
{
}

// resetuje stan obiektu
void GameBoard::Reset()
{
	// resetuj pojazdy
	list<ItemBase>::iterator it;
	for (it = cars.begin(); it != cars.end(); ++it)
	{
		(*it).Reset();
	}
	for (int i = 0; i < 5; i++)
	{
		home[i]->Reset();
	}

	// resetuj ¿abê
	frog.Reset();
}

// aktualizuje stan obiektu
void GameBoard::Update(int* gameState)
{
	// aktualizuje pojazdy i klody
	list<ItemBase>::iterator it;
	for (it = cars.begin(); it != cars.end(); ++it)
	{
		(*it).Update(gameState);
	}
	// aktualizuje ¿abê
	frog.Update(gameState);

	// sprawdza kolizjê pojazdów z ¿ab¹
	for (it = cars.begin(); it != cars.end(); ++it)
	{
		if (SDL_HasIntersection(frog.GetRect(), (*it).GetRect()))
		{
			Splash = false;
			Reset();
			if (*gameState == GAME_STATE_RUNNING) {
				*gameState = GAME_STATE_LOSER;
			}

			break;
		}
	}


	CheckFrogIsHome(gameState);


	// sprawdza czy ¿aba wygra³a
	for (int i = 0; i < 5; i++)
	{
		if (home[i]->Free)
		{
			return;
		}
	}
	Reset();
	if (*gameState == GAME_STATE_RUNNING || *gameState == GAME_STATE_AUTO) {
		*gameState = GAME_STATE_WINNER;
	}
}

Frog* GameBoard::GetFrog()
{
	return &frog;
}
void GameBoard::CheckFrogIsHome(int* gameState)
{
	if (frog.GetCurrentRow() == 12)
	{

		for (int i = 0; i < 5; i++)
		{
			if (home[i]->Free)
			{
				SDL_Rect* rect = home[i]->GetRect();
				if (frog.GetRect()->x >= rect->x && frog.GetRect()->x + frog.GetRect()->w <= rect->x + rect->w)
				{
					home[i]->Free = false;
					frog.Reset();
					return;
				}
			}
		}
		Reset();
		if (*gameState == GAME_STATE_RUNNING || *gameState == GAME_STATE_AUTO) {
			*gameState = GAME_STATE_WINNER;
		}
	}
}
// renderuje obiekt
void GameBoard::Render(SDL_Renderer* renderer)
{

	// renderuj planszê
	SDL_RenderCopy(renderer, boardTexture, 0, 0);

	// renderuj pojazdy i klody
	list<ItemBase>::iterator it;
	for (it = cars.begin(); it != cars.end(); ++it)
	{
		(*it).Render(renderer);
	}

	for (int i = 0; i < 5; i++)
	{
		home[i]->Render(renderer);
	}
	// renderuj ¿abê
	frog.Render(renderer);
}

void GameBoard::DoLeft()
{
	frog.DoLeft();
}

void GameBoard::DoRight()
{
	frog.DoRight();
}

void GameBoard::DoUp(int* gameState)
{
	if (frog.currentRow == 11 && *gameState == GAME_STATE_RUNNING) {
		if ((frog.GetRect()->x > 60 && frog.GetRect()->x < 120) ||
			(frog.GetRect()->x > 180 && frog.GetRect()->x < 240) ||
			(frog.GetRect()->x > 310 && frog.GetRect()->x < 380) ||
			(frog.GetRect()->x > 440 && frog.GetRect()->x < 500)) {
			return;
		}
	}
	if (frog.GetCurrentRow() >= 12)
	{
		return;
	}
	int newY = GetYLocation(frog.GetRect()->h, frog.GetCurrentRow() + 1);
	frog.DoUp(newY);
}

void GameBoard::DoDown()
{
	if (frog.GetCurrentRow() == 0)
	{
		return;
	}
	int newY = GetYLocation(frog.GetRect()->h, frog.GetCurrentRow() - 1);
	frog.DoDown(newY);
}

void GameBoard::CreateVechicles(SDL_Renderer* renderer)
{
	for (int i = 1; i <= 1; i++)
	{
		if (i == 6) { continue; }
		int rightToLeft = rand() % 2;
		int startX = rand() % 150;
		double speed = (double)(rand() % 10) * .1;

		for (int j = 0; j < 4; j++)
		{
			VehicleType vType = static_cast<VehicleType>(rand() % 5);

			Car car(renderer, vType, startX, rightToLeft == 1 ? -1 : 1, speed);
			if ((startX + car.GetRect()->w) >= GAME_WIDTH) break;

			car.GetRect()->y = GetYLocation(car.GetRect()->h, i);
			int spacing = (rand() % frog.GetRect()->w) + 138;
			cars.insert(cars.end(), car);

			startX += car.GetRect()->w + spacing;
		}
	}
}

int GameBoard::GetYLocation(int hight, int rowIndex)
{
	SDL_Rect rect = rows[rowIndex]->roadRect;
	int top = (double)rect.y;
	double margin = (rect.h - hight) / 2;
	if (margin < 0) margin = 0;
	return top + margin;
}
