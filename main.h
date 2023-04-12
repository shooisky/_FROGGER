#ifndef MAINMENU_H
#define MAINMENU_H

#define BACKGROUND_TEXTURE_FILE_PATH "background1.png"
#define START_GAME_MENU_ITEM_FILE_PATH "menu_play.png"
#define QUIT_GAME_MENU_ITEM_FILE_PATH "menu_end.png"
#define AUTO_GAME_MENU_ITEM_FILE_PATH "menu_auto.png"
#define INV_START_GAME_MENU_ITEM_FILE_PATH "menu_play_inv.png"
#define INV_QUIT_GAME_MENU_ITEM_FILE_PATH "menu_end_inv.png"
#define INV_AUTO_GAME_MENU_ITEM_FILE_PATH "menu_auto_inv.png"

#include <SDL_image.h>

class MainMenu
{
public:
	MainMenu(SDL_Renderer* renderer);
	~MainMenu();

	void Reset();
	void Update(int* gameState, int* mainGameState);
	void Render(SDL_Renderer* renderer);

private:
	SDL_Texture* backgroundTexture;
	SDL_Texture* startGameMenuItemTexture;
	SDL_Texture* autoGameMenuItemTexture;
	SDL_Texture* quitGameMenuItemTexture;
	SDL_Texture* invStartGameMenuItemTexture;
	SDL_Texture* invQuitGameMenuItemTexture;
	SDL_Texture* invAutoGameMenuItemTexture;
	

	SDL_Rect startGameMenuItemRect;
	SDL_Rect quitGameMenuItemRect;
	SDL_Rect autoGameMenuItemRect;

	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filePath) 
	{
		SDL_Surface* surface = IMG_Load(filePath); // za³adowanie obrazka do powierzchni
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // stworzenie tekstury z powierzchni
		SDL_FreeSurface(surface); // zwolnienie powierzchni
	return texture; // zwrócenie utworzonej tekstury
	}
};

#endif // MAINMENU_H