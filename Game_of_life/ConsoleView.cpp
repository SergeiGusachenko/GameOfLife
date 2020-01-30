#include "ConsoleView.h"

ConsoleView::ConsoleView()
{
}


//using namespace model;
//using namespace std;
void ConsoleView::print_help()
{
	
	std::cout << "THE GAME OF LIFE" << std::endl;
	std::cout << "RULES" << std::endl;
	std::cout << "The cell gave two possible states,life or dead" << std::endl;
	std::cout << "The universe of the Game of life is an infinite two-dimensional orthogonal grid of square cells" << std::endl;;
	std::cout << "the cell interacts with its eight neighbors, which are cells that are located horizontally, vertically or diagonally. " << std::endl;;
	std::cout << "At each step in time, the following transitions occur:" << std::endl;
	std::cout << "1. Any living cell with less than two living neighbors dies, as if it is caused by an incomplete population. " << std::endl;;
	std::cout << "2. Any living cell with two or three living neighbors lives next generation." << std::endl;;
	std::cout << "3. Any live cell with more than three live neighbours dies, as if by over-population." << std::endl;;
	std::cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << std::endl;
	std::cout << "* - live cell" << std::endl;
	std::cout << ". - dead cell" << std::endl;
	std::cout << "COMMANDS" << std::endl;
	std::cout << "When your set some cells you can use step for next step" << std::endl;
	std::cout << "Max size of step is 2 147 483 647" << std::endl;
	std::cout << "You can use step with num of steps (Example:step 1000 , the game show you step before 1000 cycles)" << std::endl;
	std::cout << "<back>, before <step> you can do one step back(ONLY ONE STEP BACK)" << std::endl;
	std::cout << "<set XY> this command change state of cell to alive,X it is number on virtical stone,Y on gorizontal stone" << std::endl;
	std::cout << "<clear XY> this command change state of cell to dead(X it is number on virtical stone,Y on gorizontal stone)" << std::endl;
	std::cout << "if you want show this message again call comand <help>" << std::endl;
	std::cout << "You lose if all cells is dead" << std::endl;
	std::cout << "You lose if field have static configuration" << std::endl;
	
}

void ConsoleView::print_field(const model::Field &field, int step_count)
{
	system("cls");
	std::cout << "Step Number: " << step_count << std::endl;
	std::cout << "  ";

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < 10; j++)
		{

			print_cell(field, i, j);
		}
		std::cout << " " << std::endl;
	}

}

void ConsoleView::print_cell(const model::Field &field, int xCoord, int yCoord)
{

	if (field[xCoord][yCoord].get_state())
	{
		std::cout << "* ";
	}
	else { std::cout << ". "; }
}



ConsoleView::~ConsoleView()
{
}