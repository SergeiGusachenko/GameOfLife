#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <vector>

typedef std::vector<std::string> commands;

class Parser
{
private:
	std::vector<std::string	> operations= { "set", "reset", "step", "clear", "back", "save", "load", "help","exit" };
	
public:
	std::string get_operation() const;
	commands split(const std::string &, char) const;
	commands parse(const std::string &)const;
	int is_int(const std::string&) const;
	bool is_arg(const std::string&) const;
	bool is_operation(const std::string&)const;
	//add new function
};
#endif // PARSER_H
