#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include <vector>
#include"World.h"



//�������� ����� �������� namespace
class ConsoleView
{
private:
	
public:
	ConsoleView();

	static void print_help();
	static void print_field(const model::Field &field,int step_);
	static void print_cell(const model::Field &field, int xCoord, int yCoord);
	
	~ConsoleView();
};

#endif