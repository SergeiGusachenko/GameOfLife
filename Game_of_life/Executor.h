#pragma once
#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <string>
#include <iostream>
#include "Parser.h"
#include "World.h"
#include "ConsoleView.h"
#include "Strategy.h"


namespace controller
{
	class Executor
	{
	private:
		Parser	parser;
	public:
		void call_operation( ConsoleView& cons_view, Strategy& field) const;
	};
}

#endif // EXECUTOR_H
