#include"World.h"

model::World::World() : field(10)
{

	for (int i = 0; i < field.size(); ++i)
	{
		this->field[i].resize(10);
		for (int j = 0; j < 10; ++j)
		{
			this->field[i][j] = Cell(i, j);
		}
	}
}

model::Field & model::World::get_field()
{
	return field;
}

model::World::~World()
{

}
