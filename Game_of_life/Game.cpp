#include "Game.h"
#include "ConsoleView.h"
#include "Executor.h"

Game::Game():strategy(world)
{

}

void Game::game()
{
	console_view.print_help();
	system("pause");
	console_view.print_field(world.get_field(), strategy.get_step());
	while (true)
	{
		try
		{
			console_view.print_field(world.get_field(), strategy.get_step());

			executor.call_operation(console_view, strategy);
			strategy.check_for_empty(world.get_field());
		}
		catch (std::logic_error & e)
		{
			std::cerr << e.what() << std::endl;
			system("pause");
			
		}
		catch(std::invalid_argument & e)
		{
			std::cerr << e.what() << std::endl;
			system("pause");
			
		}
		catch (std::out_of_range&)
		{
			std::cerr << "Wrong arguments, step num is too bigger than the maximum permissible" << std::endl;
			system("pause");
			
		}
		if(strategy.get_exit())
		{
			std::cout << "Goodbye" << std::endl;
			system("pause");
			break;
		}
	
	}
}

Game::~Game()
{
}


