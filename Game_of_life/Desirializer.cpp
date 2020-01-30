#include "Desirializer.h"
#include <fstream>

void Desirializer::load(const std::string file_string, model::Field& field)
{
	const model::Field old_field=field;
	std::ifstream file(file_string);
	char tmp;
	if (!file.is_open())
	{
		throw std::logic_error("Can't open this file, check the spelling");
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(file.eof())
			{
				file.close();
				throw std::invalid_argument("file is broken");
			}	
			file >> tmp;
			if(tmp!='1' &&tmp!='0')
			{
				file.close();
				field = old_field;
				throw std::invalid_argument("file is broken");
			}
			if(tmp=='1')
			{
				field[i][j].set_state(true);
			}
			if(tmp=='0')
			{
				field[i][j].set_state(false);
			}
			
		}
	}
	file.close();
}
