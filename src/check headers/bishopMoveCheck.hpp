#include <iostream>

/*
	CHECKS IF THE KING WILL BE IN CHECK BEFORE THEY MOVE TO THE SPOT
*/

/*
TODO:

- find if the moveRow and moveCol are in the attack path of a enemy bishop
*/

bool whiteBishopCheck(int moveRow, int moveCol, std::string board[][9]) {

	int bishopRow;
	int bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRow = i;
				bishopCol = j;
			}
		}
	}

	return true;
}

bool blackBishopCheck(int moveRow, int moveCol, std::string board[][9]) {

	int bishopRow;
	int bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRow = i;
				bishopCol = j;
			}
		}
	}

	return true;
}