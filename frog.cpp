#include "frog.h"
#include "define.h"

// konstruktor
Frog::Frog(SDL_Renderer* renderer)
{
	// wczytanie tekstury i reset obiektu
	frogTexture = LoadTexture(renderer, FROG_TEXTURE_FILE_PATH);
	Reset();
}

// destruktor
Frog::~Frog()
{
}

// resetuje obiekt
void Frog::Reset()
{
	// przyróæ na pocz¹tek
	frogRect.x = (GAME_WIDTH - FROG_SIZE_W) / 2;
	frogRect.y = (GAME_HEIGHT - FROG_SIZE_H) - 8;
	frogRect.w = FROG_SIZE_W;
	frogRect.h = FROG_SIZE_H;
	currentRow = 0;
	startX = frogRect.x;
}

// aktualizuje dane obiektu
void Frog::Update(int* gameState)
{
	startX += speed * direction;
	frogRect.x = (int)startX;
}

// renderuje obiekt
void Frog::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, frogTexture, 0, &frogRect);
}

// obs³uguje przycisk klawiatury W LEWO
void Frog::DoLeft()
{
	if (frogRect.x > FROG_SIZE_W)
	{
		frogRect.x -= FROG_JUMP_OFFSET;
		startX = frogRect.x;
	}
}

// obs³uguje przycisk klawiatury W PRAWO
void Frog::DoRight()
{
	if (frogRect.x + FROG_SIZE_H < GAME_WIDTH - FROG_JUMP_OFFSET)
	{
		frogRect.x += FROG_JUMP_OFFSET;
		startX = frogRect.x;
	}
}

// obs³uguje przycisk klawiatury W GORÊ
void Frog::DoUp(int newY)
{
	frogRect.y = newY;
	currentRow++;
}

// obs³uguje przycisk klawiatury W DOL
void Frog::DoDown(int newY)
{
	frogRect.y = newY;
	currentRow--;
}

// zwraca prostok¹t u¿ywany do sprawdzania kolizji obiektu (¿aba z pojazdem)
SDL_Rect* Frog::GetRect()
{
	return &frogRect;
}

int Frog::GetCurrentRow()
{
	return currentRow;
}

void Frog::SetDirection(int direction)
{
	this->direction = direction;
}


void Frog::SetSpeed(double speed)
{
	this->speed = speed;
}