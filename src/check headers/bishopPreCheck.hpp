#include <iostream>
#include <vector>

bool lowerLeftKingCheck(int bishopRow, int bishopCol, int kingRow, int kingCol, std::string board[][9]) {

	// FIND A WAY TO CHECK BOTH BLACK AND WHITE KING

	int i = 1;
	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i > 9) {
			break;
		}

		if (board[bishopRow + i][bishopCol - i] == "WK") {
			std::cout << "You are in check! MOVE" << std::endl;
			return true;
			break;
		}
		i++;
	}

	return false;
}

bool whiteBishopPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	int bishopRow;
	int bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRow = i;
				bishopCol = j;

				if (lowerLeftKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
			}
		}
	}

	return false;

}

bool blackBishopPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	int bishopRow;
	int bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRow = i;
				bishopCol = j;

				if (lowerLeftKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}