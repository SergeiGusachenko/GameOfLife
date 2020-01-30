#include "Parser.h"
#include <string>
#include <iostream>

std::string Parser::get_operation() const
{
	std::string  str;//ISSUE парсер считывает и обрабатывает строки
	std::getline(std::cin, str);
	if (!str.size())
	{
		throw std::invalid_argument("String is empty.Set few states to state <live> for the start of the game ");
	}
	return str;
}

commands Parser::split(const std::string& s, char space) const
{
	std::vector<std::string> result;
	std::string tmp;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == space) {
			if (tmp.size()) {
				result.push_back(tmp);
				tmp = "";
			}
		}
		else {
			tmp += s[i];
		}
	}
	if (tmp.size()) {
		result.push_back(tmp);
	}
	return result;
}

commands Parser::parse(const std::string& str) const
{
	commands result;
	result = this->split(str, ' ');
	int  size_str = result.size();
	std::string part_str = result[0];

	if (!is_operation(part_str))
	{
		throw std::invalid_argument("Unexpected command");
		//throw some sentence about err
	}

	if (part_str == "reset" || part_str == "help")
	{
		if (size_str > 1)
		{
			throw std::invalid_argument("Too many arguments");
		}
		return result;
	}
	 if(part_str=="back")
	 {
		 if(size_str > 2 || (size_str > 1 && !is_int(result[1])) && is_int(result[1]) <1000 )
		 {
			 throw std::invalid_argument("Wrong arguments");
		 }
		 return result;
	 }
	if (part_str == "set" || part_str == "clear")
	{
		if (size_str != 3 || !is_arg(result[1]) || !is_arg(result[2]))
		{
			throw std::invalid_argument("Wrong arguments");
		}
		if (is_int(result[1]) > 9 || is_int(result[2]) > 9)
		{
			throw std::invalid_argument("Wrong argument,X and Y can't be more then 9");
		}
		return result;
	}
	if (part_str == "save" || part_str == "load")
	{
		if (size_str != 2) {
			throw std::invalid_argument("Wrong arguments");
		}
		return result;
	}
	if (part_str == "step")
	{
		if (size_str > 2 || (size_str > 1 && !is_int(result[1])) && is_int(result[1]) < INT_MAX)
		{
			throw std::invalid_argument("Wrong arguments step");
		}
		return result;
	}
	if (part_str == "exit")
	{
		if (size_str > 1)
		{
			throw std::invalid_argument("Wrong arguments");
		}
		return result;
	}
}

int Parser::is_int(const std::string& s) const
{
	return std::stoi(s);
}

bool Parser::is_arg(const std::string& s) const
{
	return s.find_first_not_of("0123456789") == std::string::npos;
}

bool Parser::is_operation(const std::string &str) const
{
	for (int i = 0; i < operations.size(); i++)
	{
		if (str == operations[i])
		{
			return true;
		}
	}
	return false;
}
