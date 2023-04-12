#ifndef FROG_H
#define FROG_H
#define FROG_TEXTURE_FILE_PATH "frog.png"
#define FROG_JUMP_OFFSET 50
#define FROG_SIZE_H 38
#define FROG_SIZE_W 46
#define FROG_START_Y 10

#include <SDL_image.h>

class Frog
{
public:
	// konstruktor
	Frog(SDL_Renderer* renderer);

	// destruktor
	~Frog();

	// resetuje obiekt
	void Reset();

	// aktualizuje dane obiektu
	void Update(int* gameState);

	// renderuje obiekt
	void Render(SDL_Renderer* renderer);

	// obs?uguje przycisk klawiatury W LEWO
	void DoLeft();

	// obs?uguje przycisk klawiatury W PRAWO
	void DoRight();

	// obs?uguje przycisk klawiatury W GOR?
	void DoUp(int newY);

	// obs?uguje przycisk klawiatury W DOL
	void DoDown(int newY);

	// zwraca prostok?t u?ywany do sprawdzania kolizji obiektu (?aba z pojazdem)
	SDL_Rect* GetRect();

	int GetCurrentRow();

	void SetSpeed(double speed);
	void SetDirection(int direction);

	int currentRow;

private:
	SDL_Texture* frogTexture; // tekstura obiektu

	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filePath)
	{
		SDL_Surface* surface = IMG_Load(filePath); // za?adowanie obrazka do powierzchni
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // stworzenie tekstury z powierzchni
		SDL_FreeSurface(surface); // zwolnienie powierzchni
		return texture; // zwrócenie utworzonej tekstury
	}

	SDL_Rect frogRect; // prostok?t obiektu

	double speed = 0;
	int direction = 0;
	double startX;
};

#endif // FROG_H