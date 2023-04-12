#include "main.h"
#include "define.h"

MainMenu::MainMenu(SDL_Renderer* renderer)
{
	backgroundTexture = LoadTexture(renderer, BACKGROUND_TEXTURE_FILE_PATH);
	startGameMenuItemTexture = LoadTexture(renderer, START_GAME_MENU_ITEM_FILE_PATH);
	quitGameMenuItemTexture = LoadTexture(renderer, QUIT_GAME_MENU_ITEM_FILE_PATH);
	autoGameMenuItemTexture = LoadTexture(renderer, AUTO_GAME_MENU_ITEM_FILE_PATH);
	invStartGameMenuItemTexture = LoadTexture(renderer, INV_START_GAME_MENU_ITEM_FILE_PATH);
	invQuitGameMenuItemTexture = LoadTexture(renderer, INV_QUIT_GAME_MENU_ITEM_FILE_PATH);
	invAutoGameMenuItemTexture = LoadTexture(renderer, INV_AUTO_GAME_MENU_ITEM_FILE_PATH);

	
	
	startGameMenuItemRect.x = (GAME_WIDTH - 300) / 2;
	startGameMenuItemRect.y = (GAME_HEIGHT / 2) - 40;
	startGameMenuItemRect.h = 40;
	startGameMenuItemRect.w = 300;

	autoGameMenuItemRect.x = (GAME_WIDTH - 300) / 2;
	autoGameMenuItemRect.y = (GAME_HEIGHT / 2) + 20;
	autoGameMenuItemRect.h = 40;
	autoGameMenuItemRect.w = 300;


	quitGameMenuItemRect.x = (GAME_WIDTH - 300) / 2;
	quitGameMenuItemRect.y = (GAME_HEIGHT / 2) + 80;
	quitGameMenuItemRect.h = 40;
	quitGameMenuItemRect.w = 300;
}

MainMenu::~MainMenu()
{
}

void MainMenu::Reset()
{

}

void MainMenu::Update(int* gameState, int* mainGameState)
{
	SDL_Point cursor;

	if (SDL_GetMouseState(&cursor.x, &cursor.y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (SDL_PointInRect(&cursor, &startGameMenuItemRect))
		{
			*gameState = GAME_STATE_RUNNING;
			*mainGameState = GAME_STATE_RUNNING;
		}
		else if (SDL_PointInRect(&cursor, &autoGameMenuItemRect))
		{
			*gameState = GAME_STATE_AUTO;
			*mainGameState = GAME_STATE_AUTO;
		}
		else if (SDL_PointInRect(&cursor, &quitGameMenuItemRect))
		{
			*gameState = GAME_STATE_QUIT;
		}
	}
}

void MainMenu::Render(SDL_Renderer* renderer)
{
	SDL_Point cursor;

	SDL_GetMouseState(&cursor.x, &cursor.y);
	SDL_RenderCopy(renderer, backgroundTexture, 0, 0);

	if (!SDL_PointInRect(&cursor, &startGameMenuItemRect))
	{
		SDL_RenderCopy(renderer, startGameMenuItemTexture, NULL, &startGameMenuItemRect);
	}
	else
	{
		SDL_RenderCopy(renderer, invStartGameMenuItemTexture, 0, &startGameMenuItemRect);
	}

	if (!SDL_PointInRect(&cursor, &autoGameMenuItemRect))
	{
		SDL_RenderCopy(renderer, autoGameMenuItemTexture, NULL, &autoGameMenuItemRect);
	}
	else
	{
		SDL_RenderCopy(renderer, invAutoGameMenuItemTexture, 0, &autoGameMenuItemRect);
	}

	if (!SDL_PointInRect(&cursor, &quitGameMenuItemRect))
	{
		SDL_RenderCopy(renderer, quitGameMenuItemTexture, 0, &quitGameMenuItemRect);
	}
	else
	{
		SDL_RenderCopy(renderer, invQuitGameMenuItemTexture, 0, &quitGameMenuItemRect);
	}
}