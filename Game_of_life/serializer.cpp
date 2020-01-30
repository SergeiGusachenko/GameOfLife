#include "serializer.h"
#include <fstream>

void Serializer::save(model::Field &field, std::string filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		throw std::invalid_argument("can't open file");
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j].get_state())
			{
				file << 1;
			}
			else { file << 0; }
		}
		if (i != 9)
		{
			file << '\n';
		}
	}
	file.close();
}



