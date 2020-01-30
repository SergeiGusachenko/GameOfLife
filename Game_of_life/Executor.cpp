#include "Executor.h"
#include "Strategy.h"
#include "serializer.h"
#include "Desirializer.h"


void controller::Executor::call_operation(ConsoleView& cons_view, Strategy& field) const
{
	const std::string str = parser.get_operation();
	commands command;
	command = parser.parse(str);
	
	if (command[0] == "back")
	{
		if (command.size() >= 2)
		{
			field.back_step( parser.is_int(command[1]));
		}
		else if (command.size() == 1)
		{
			field.back_step();
		}
	}

	if (command[0] == "step")
	{
		if (command.size() >= 2)
		{
			field.step( parser.is_int(command[1]));
		}
		else if (command.size() == 1)
		{
			field.step();
		}
	}
	
	if (command[0] == "set")
	{
		field.set_cell_state(parser.is_int(command[1]), parser.is_int(command[2]), true);
	}

	if (command[0] == "clear")
	{
		field.set_cell_state(parser.is_int(command[1]), parser.is_int(command[2]), false);
	}

	if (command[0] == "reset")
	{
		field.clear_field();
	}

	if (command[0] == "exit")
	{
		field.set_exit();
	}

	if (command[0] == "save")
	{
		Serializer::save(field.get_field(), command[1]);
	}

	if (command[0] == "help")
	{
		cons_view.print_help();
	}

	if (command[0] == "load")
	{
		Desirializer::load(command[1], field.get_field());
		field.reset();
	}
}


