#include "Cell.h"

Cell::Cell(int xCoord,int yCoord)
{
	this->state = false;
}

bool Cell::get_state() const
{
	return this->state;
}

void Cell::set_state(bool new_state)
{
	this->state = new_state;
}

Cell::~Cell()
{
}

