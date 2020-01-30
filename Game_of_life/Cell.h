#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>

class Cell
{
private:
	bool state;
public:
	Cell(int xCoord=0, int yCoord=0);
	bool get_state() const;
	void set_state(bool new_state);
	~Cell();
};


#endif //CELL_H
