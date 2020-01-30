#include  <gtest/gtest.h>
#include "../Game_of_life/Strategy.h"
#include "../Game_of_life/Game.h"
#include "../Game_of_life/serializer.h"
#include "../Game_of_life/Desirializer.h"

class StrategyTest :public testing::Test
{

};

TEST_F(StrategyTest, first_test)
{
   //Game start;
	//start.game();
	//start.game();
	EXPECT_FALSE(5 < 0);
}

TEST_F(StrategyTest,long_liver_test)
{
	model::World world;
	
	model::World test_world;
	Strategy strag(world);
	Strategy test_strag(test_world);
	strag.set_cell_state(3, 4, true);
	strag.set_cell_state(3, 5, true);
	strag.set_cell_state(4, 4, true);
	strag.set_cell_state(4, 3, true);
	strag.set_cell_state(5, 4, true);
	strag.step(108);
	EXPECT_TRUE(strag.compare(world.get_field(), test_world.get_field()));
	strag.back_step();
	EXPECT_EQ(strag.get_step(), 107);
	test_strag.set_cell_state(9, 2, true);
	test_strag.set_cell_state(9, 3, true);
	EXPECT_TRUE(strag.compare(world.get_field(), test_world.get_field()));
	
}

TEST_F(StrategyTest, load_save_test)
{
	model::World world;
	model::World test_world;
	ConsoleView console_view;
	Strategy strag(world);
	Strategy test_strag(test_world);
	Serializer::save(world.get_field(), "qwert.txt");
	EXPECT_TRUE(strag.compare(test_world.get_field(), world.get_field()));
	strag.set_cell_state(3, 4, true);
	strag.set_cell_state(3, 5, true);
	strag.set_cell_state(4, 4, true);
	strag.set_cell_state(4, 3, true);
	strag.set_cell_state(5, 4, true);
	strag.step(107);
	EXPECT_FALSE(strag.compare(test_world.get_field(), world.get_field()));
	SUCCEED();
	system("pause");
}