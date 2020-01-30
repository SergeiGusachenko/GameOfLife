#include <gtest/gtest.h>
#include "../Game_of_life/serializer.h"
#include "../Game_of_life/Desirializer.h"
#include "../Game_of_life/ConsoleView.h"

class De_SerializationTest :public testing::Test
{

};

TEST_F(De_SerializationTest, save_load_succeed)
{
	model::World world;
	Serializer::save(world.get_field(), "qwert.txt");
	Desirializer::load("qwert.txt",world.get_field());
	SUCCEED(serializer.save('file.txt'));
	SUCCEED(desirializer.load("d", world.get_field()));
}

TEST_F(De_SerializationTest, throw_test_desirializer)
{
	model::World world;
	Desirializer desirializer;
	
	ASSERT_THROW(desirializer.load("d", world.get_field()),std::logic_error);
}

TEST_F(De_SerializationTest,no_throw_save )
{
	model::World world;
	ConsoleView console;
	Strategy strag(world);
	strag.set_cell_state(0, 9, true);
	strag.set_cell_state(9, 0, true);
	Serializer::save(world.get_field(), "file");
	ASSERT_NO_THROW(Serializer::save(world.get_field(), "fghjk"));
	Desirializer::load("test_file.txt", world.get_field());
	console.print_field(world.get_field(),3);
	system("pause");
	std::cout << "Now filed will change on downloded" << std::endl;
	Desirializer::load("file", world.get_field());
	console.print_field(world.get_field(), 3);

}