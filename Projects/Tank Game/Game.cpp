#include "Game.h"

#include <Windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>

static void cls();

Game::Game() : tank("Player", 50, 5, 0)
{
	srand(time(NULL));
	TargetPos = 60 + rand() % 40;
	Init();
}

void Game::Init()
{
	memset(spaces, 32, WIDTH);
	spaces[WIDTH - 1] = 0;
	memset(frame, 32, HEIGHT * WIDTH);
	for (int i = 0; i < HEIGHT; ++i)
		frame[i][WIDTH - 1] = 0;
	memset(BottomBorder, BORDER, sizeof(BottomBorder));

	frame[0][tank.getPos()] = TANK_SYMBOL;
	frame[0][TargetPos] = TARGET_SYMBOL;
}

void Game::Start()
{
	MainLoop();
}

void Game::Update()
{
	//cls();
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { 0,0 };
	SetConsoleCursorPosition(hOut, coord);

	drawScreen();
}

void Game::MainLoop()
{
	time_t t0;
	char key;
	bool arrow;
	bool up_to_date;
	bool fired = false;

	Update();

	while (true)
	{
		Sleep(1);
		arrow = false;
		up_to_date = false;
		t0 = time(NULL);
		if (_kbhit())
		{
			key = _getch();
			if (key == -32 || key == 0)
			{
				arrow = true;
				key = _getch();
			}
			
			// Movement

			if (arrow && key == RIGHT_ARROW)
			{
				static size_t currPos;
				currPos = tank.getPos();
				if (frame[0][currPos + 1] != TARGET_SYMBOL)
				{
					if (tank.MoveRight())
					{
						frame[0][currPos] = SPACE;
						frame[0][tank.getPos()] = TANK_SYMBOL;
						up_to_date = false;
					}
				}
			}

			if (arrow && key == LEFT_ARROW)
			{
				static size_t currPos;
				currPos = tank.getPos();
				if (tank.MoveLeft())
				{
					frame[0][currPos] = SPACE;
					frame[0][tank.getPos()] = TANK_SYMBOL;
					up_to_date = false;
				}
			}

			// Setting arguments

			if (arrow && key == UP_ARROW)
			{
				if (tank.AdjustAngle(1))
				{
					up_to_date = false;
				}
			}

			if (arrow && key == DOWN_ARROW)
			{
				if (tank.AdjustAngle(-1))
				{
					up_to_date = false;
				}
			}

			if (key == 'a')
			{
				if (tank.AdjustPower(-1))
				{
					up_to_date = false;
				}
			}
			
			if (key == 'd')
			{
				if (tank.AdjustPower(1))
				{
					up_to_date = false;
				}
			}

			if (key == 'A')
			{
				if (tank.AdjustPower(-5))
				{
					up_to_date = false;
				}
			}

			if (key == 'D')
			{
				if (tank.AdjustPower(5))
				{
					up_to_date = false;
				}
			}

			// Firing
			if (key == SPACE)
			{

				if (fired)
				{
					Init();
					fired = false;
				}
				else 
				{
					Fire(); 
					fired = true;
				}
				up_to_date = false;
			}

			// UPDATE THE SCREEN
			if (!up_to_date)
			{
				Update();
				up_to_date = true;
				Sleep(1000 / FPS - difftime(time(NULL), t0));
			}
		}
	}
}

void Game::drawScreen()
{
	for (int i = HEIGHT - 1; i >= 0; --i)
	{
		putchar(219);
		//if (strcmp(spaces, frame[i]))
			fwrite(frame[i], WIDTH, 1, stdout);
		putchar('\n');
	}
	fwrite(BottomBorder, WIDTH + 1, 1, stdout);
	putchar('\n');
	putchar('\n');

	printf_s("Shot Power:\t%u\n", tank.getSP());
	printf_s("Shell Weight:\t%u\n", tank.getSW());
	printf_s("Shot Angle:\t%u", tank.getAngle());

}

void Game::Fire()
{
	#include <cmath>

	size_t startX = tank.getPos();
	size_t shellX = 0;
	double shellY = 0;
	size_t angle = tank.getAngle();
	double speed = POWER_MODIFIER * tank.getSP() / tank.getSW();

	double tan_angle = tan(3.14 / 180 *angle);	// in radians
	double cos_angle = cos(3.14 / 180 *angle);

	double help = 2 * (speed*cos_angle) * (speed*cos_angle);

	time_t t0;
	do
	{
		t0 = time(NULL);

		shellX++;
		if (shellX + startX + 1> WIDTH) return;
		if (shellY + 1 < HEIGHT)
		{
			frame[(int)(shellY)+1][startX + shellX] = SHELL_SYMBOL;
			Update();
			frame[(int)(shellY)+1][startX + shellX] = SPACE;
			Sleep(1000 / FPS - difftime(time(NULL), t0));
			Update();

		}
		shellY = shellX*tan_angle - 10 * shellX * shellX / help;

	} while (shellY > 0);

	// here shellY must be 0 or negative, so shellX where the shell falls

	frame[0][startX + shellX] = 'X';
	Update();

	srand(time(NULL));
	// if(startX + shellX == TargetPos)
	TargetPos = 60 + rand() % 40;
}

//////////////////////////////////////////////////////////////////////

static void cls()
{
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}