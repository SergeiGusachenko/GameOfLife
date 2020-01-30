#include "Strategy.h"

using namespace model;

Strategy::Strategy(World& world) : wrld(world)
{
	history_ = std::make_shared<std::map<int, List>>();
	/*try {
	list_ = new List;
	}

	catch (std::bad_alloc&)
	{
		delete list_;
		list_ = nullptr;
	}*/
	step_ = 0;
	flag_exit = false;
}

void Strategy::back_step( int n)
{
	if (step_ == 0)
	{
		throw std::invalid_argument("It is first step,you can't go back ");
	}
	if (step_ - n < 0)
	{
		throw std::invalid_argument("You can't go back for this n ");
	}
	int current = step_ - n;
	clear_field(current);
	std::list<differens>& point_list = (*history_)[current];
	for (auto it = point_list.begin(); it != point_list.end(); ++it)
	{
		set_cell_state(it->x, it->y, it->old_state);
	}
}

void Strategy::step(int n)
{
	for (int i = 0; i < n; i++)
	{
		next_step();
		step_++;
	}
}

void Strategy::next_step()
{
	/*if (history_[step_]->empty())
	{
		delete[] history_[step_];
	}*/
	List newList;
	tmp = field;
	int count_neighbors = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			count_neighbors = neighbors(tmp, i, j);
			if (tmp[i][j].get_state() && (count_neighbors < 2 || count_neighbors > 3))
			{
				field[i][j].set_state(false);
				differs.x = i;
				differs.y = j;
				differs.old_state = true;
				newList.push_back(differs);
			}
			else if (!tmp[i][j].get_state() && count_neighbors == 3)
			{
				field[i][j].set_state(true);
			}
			else if (tmp[i][j].get_state() && (count_neighbors == 2 || count_neighbors == 3))
			{
				differs.x = i;
				differs.y = j;
				differs.old_state = true;
				newList.push_back(differs);
			}
		}
	}
	
	history_->insert(std::pair<int, List>(step_, newList));
	if (compare(tmp, field))
	{
		throw std::invalid_argument("You lose, the live configuration does not change its state");
	}
}

int Strategy::neighbors(Field& field, int xCoord, int yCoord)
{
	int _neighbors = 0;
	int x = xCoord;
	int y = yCoord;

	for (int i = -1; i != 2; ++i)
	{
		for (int j = -1; j != 2; ++j)
		{
			if (i == 0 && j == 0) { continue; }
			if (field[(10 + xCoord + j) % 10][(10 + yCoord + i) % 10].get_state())
			{
				_neighbors++;
			}
		}
	}
	return _neighbors;
}

void Strategy::set_exit()
{
	flag_exit = true;
}

bool Strategy::get_exit()
{
	return flag_exit;
}


void Strategy::set_cell_state(int xCoord, int yCoord, bool state)
{
	field[xCoord][yCoord].set_state(state);
}

void Strategy::clear_field(int n)
{
	step_ = n;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			field[i][j].set_state(false);
		}
	}
}

bool Strategy::compare(Field& tmp, Field& field)
{
	if (tmp.size() != field.size())
	{
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j].get_state() != tmp[i][j].get_state())
			{
				return false;
			}
		}
	}
	return true;
}

int Strategy::get_step()
{
	return step_;
}

Field& Strategy::get_field()
{
	return field;
}

void Strategy::check_for_empty(Field& field)
{
	if (step_ != 0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (field[i][j].get_state() != false)
				{
					return;
				}
			}
		}
		reset();
		clear_field();
		throw std::invalid_argument("Live is dead, you lose");

	}
}

void Strategy::reset()
{
	step_ = 0;
}


Strategy::~Strategy()
{

	
}
