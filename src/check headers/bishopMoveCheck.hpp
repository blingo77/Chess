#include <iostream>

/*
	CHECKS IF THE KING WILL BE IN CHECK BEFORE THEY MOVE TO THE SPOT
*/

/*
TODO:

- find if the moveRow and moveCol are in the attack path of a enemy bishop
*/

bool lowerLeftMoveCheck(int moveRow, int moveCol, int bishopRow, int bishopCol, std::string board[][9]){

	int i = 1;
	
	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i >= 9) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {
			if (board[bishopRow + i][bishopCol - i] == "BK") {
				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {
			board[moveRow][moveCol] = "WK";

			if (board[bishopRow + i][bishopCol - i] == "WK") {
				std::cout << "White is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
		}

		i++;
	}

	return false;
}

bool whiteBishopCheck(int moveRow, int moveCol, std::string board[][9]) {

	int bishopRow;
	int bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRow = i;
				bishopCol = j;

				if (lowerLeftMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}

bool blackBishopCheck(int moveRow, int moveCol, std::string board[][9]) {

	int bishopRow;
	int bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRow = i;
				bishopCol = j;

				if (lowerLeftMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}