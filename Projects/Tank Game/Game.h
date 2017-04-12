#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP_ARROW 72
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define DOWN_ARROW 80
#define SPACE 32

#define TANK_SYMBOL 84
#define TARGET_SYMBOL 52
#define SHELL_SYMBOL 111
#define BORDER 219
#define HEIGHT 25
#define WIDTH 100
#define FPS 20

#define POWER_MODIFIER 2

#include "Tank.h"

class Game
{
public:
	Game();
	void Start();


private:
	char frame[HEIGHT][WIDTH];
	char BottomBorder[WIDTH + 1];
	char spaces[WIDTH];
	Tank tank;
	size_t TargetPos;

private:
	void MainLoop();
	void drawScreen();
	void Update();
	void Fire();
	void Init();
};

#endif // !GAME_H_INCLUDED