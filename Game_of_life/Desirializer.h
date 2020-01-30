#pragma once
#ifndef DESERIALIZER_H
#define DESERIALIZER_H
#include <string>
#include "World.h"


class Desirializer
{
public:
	static void load(const std::string file_string, model::Field & field);
};
#endif //DESERIALIZER_H

