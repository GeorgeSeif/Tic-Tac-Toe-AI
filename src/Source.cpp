#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "utils.cpp"

using std::cout;
using std::cin;
using std::endl;

#define WIN 1000
#define	DRAW 0
#define LOSS -1000

#define AI_MARKER 'O'
#define PLAYER_MARKER 'X'
#define EMPTY_SPACE '-'

#define START_DEPTH 0


int main()
{
	char board[3][3] = { EMPTY_SPACE };

	cout << "********************************\n\n\tTic Tac Toe AI\n\n********************************" << endl << endl;
	cout << "Player = X\t AI Computer = O" << endl << endl;

	print_board(board);

	while (!game_is_done(board))
	{
		int row, col;
		
		
		try {
		    row = get_row();
		} catch (std::runtime_error& e) {
		        std::cerr << "Error in row number" << endl;
		        return 1;
		}
		
		
		try {
		    col = get_col();
		} catch (std::runtime_error& e) {
		        std::cerr << "Error in column number" << endl;
		        return 1;
		}

		cout << endl << endl;
		

		if (position_occupied(board, std::make_pair(row, col)))
		{
			cout << "The position (" << row << ", " << col << ") is occupied. Try another one..." << endl;
			continue;
		}
		else
		{
			board[row][col] = PLAYER_MARKER;
		}

		std::pair<int, std::pair<int, int>> ai_move = minimax_optimization(board, AI_MARKER, START_DEPTH, LOSS, WIN);

		board[ai_move.second.first][ai_move.second.second] = AI_MARKER;

		print_board(board);
	}

	cout << "********** GAME OVER **********" << endl << endl;

	int player_state = get_board_state(board, PLAYER_MARKER);

	cout << "PLAYER "; print_game_state(player_state);

	return 0;

}
