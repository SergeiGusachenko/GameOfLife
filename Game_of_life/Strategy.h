#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H
#include "World.h"
#include <vector>		 
#include <list>
#include <map>
#include <memory>


class Strategy {
	int step_;
	model::World& wrld;
	model::Field& field = wrld.get_field();
	model::Field tmp;
	struct differens
	{
		int x, y;
		bool old_state;
	};

	differens differs;
	using List = std::list<differens>;
	bool flag_exit;
	//List *list_;
	std::shared_ptr<std::map<int, List>> history_;
public:

	Strategy(model::World &);
	
	void back_step( int n = 1);
	void step(int n = 1);
	void next_step();
	int neighbors(model::Field&field, int xCoord, int yCoord);
	void set_exit();
	bool get_exit();
	void set_cell_state(int xCoord, int yCoord, bool state);
	void clear_field(int n = 0);
	bool compare(model::Field& tmp, model::Field& field);
	int get_step();
	model::Field& get_field();
	void check_for_empty(model::Field& field);
	~Strategy();
	void reset();
};

#endif //STRATEGY_H



