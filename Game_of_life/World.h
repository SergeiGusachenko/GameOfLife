#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include"Cell.h"

namespace model {

 using Field=std::vector< std::vector <Cell>> ;

	class World
	{
		std::vector< std::vector <Cell>> field;
		const  int width = 10;
		const  int height = 10;
		
		
	public:
		World();
		
		Field& get_field();
		~World();
	};
}
#endif //WORLD_H