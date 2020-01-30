#pragma once
#ifndef GAME_H
#define  GAME_H

#include "Strategy.h"
#include "Executor.h"

class Game
{
private:
	ConsoleView console_view;
	Parser parser;
	controller::Executor executor;
	model::World world;
	Strategy strategy;
public:
	Game();
	void game();
	~Game();
};



#endif //GAME_H
