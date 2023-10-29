#include <gtest/gtest.h>
#include <../src/utils.cpp>
#include <iostream>
#include <vector>
#include <array>

// TEST(ExceptionTests, Invalidcin) {
// 	EXPECT_THROW(get_row(), std::runtime_error);
//}

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

TEST(AlgorythmTest, minimaxtest) {
	std::pair<int, std::pair<int, int>> res;
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	res = minimax_optimization(board, AI_MARKER, 2, 1, 1);
	EXPECT_EQ(res.first, 950);
	EXPECT_EQ(res.second.first, 0);
	EXPECT_EQ(res.second.second, 0);
}

TEST(BoardStateTest, occupied_positions_empty) {
	std::vector<std::pair<int, int>> occupied_positions;
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	occupied_positions = get_occupied_positions(board, PLAYER_MARKER);
	EXPECT_EQ(occupied_positions.size(), 0);
}

TEST(BoardStateTest, occupied_positions) {
	std::vector<std::pair<int, int>> occupied_positions;
	char board[3][3] = {{'X', ' ', ' '}, {' ', 'X', ' '}, {' ', ' ', 'O'}};
	occupied_positions = get_occupied_positions(board, AI_MARKER);
	EXPECT_EQ(occupied_positions.size(), 1);
	EXPECT_EQ(occupied_positions[0].first, 2);
	EXPECT_EQ(occupied_positions[0].second, 2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
