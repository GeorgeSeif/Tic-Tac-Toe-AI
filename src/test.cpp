#include <gtest/gtest.h>
#include "utils.cpp"
#include <iostream>
#include <vector>
#include <array>

// TEST(ExceptionTests, Invalidcin) {
// 	EXPECT_THROW(get_row(), std::runtime_error);
// }

// TEST(ExceptionTests, Invalidcin) {
//     std::ifstream ifs;
//     ifs.open("someFile", std::ifstream::in);
//     // in production code pass std::cin
//     std::cout << "readUserInput from std::cin: " << readUserInput(std::cin) << std::endl;
//     // in testing pass some mock data from the file (or whatever)
//     std::cout << "readUserInput from ifs: " << readUserInput(ifs) << std::endl;
//     ifs.close();
// }

TEST(BoardStateTest, getboardstatetest) {
	std::vector<std::pair<int, int>> legal_moves;
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	legal_moves = get_legal_moves(board);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++) 
		{
			std::pair<int, int> true_pair = std::make_pair(i, j);
			EXPECT_EQ(legal_moves[3*i + j].first, true_pair.first);
		}
	}
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
