#pragma once
#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <string>
#include "World.h"
#include "Strategy.h"


class Serializer
{
private:
	model::World wrld;
	std::string file_string;
public:
	static void save(model::Field &field, std::string filename);
};

#endif //SERIALIZER_H
