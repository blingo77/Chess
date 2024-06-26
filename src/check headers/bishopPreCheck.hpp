#include <iostream>
#include <vector>

/*
	THE CHECK IS DONE BY FINDING THE BISHOPS POSITION THEN SEEING IF THE KING IS IN ONE OF ITS PATH

	FUNCTION NAMES ARE RELATIVE TO THE BISHOPS POSITION

	TODO:

	-MAKE SURE THE THE CHECK BREAKS IF IT ENCOUNTERS A PIECE THAT ISNT A KING - Test examples on lines 44 & 60
*/

bool lowerLeftKingCheck(int bishopRow, int bishopCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i > 9) {
			break;
		}
	
		// Makes sure that it isnt checking out of bounds
		if (bishopRow + i < 0 || bishopRow + i > 8) {
			break;
		}

		if (bishopCol - i < 0 || bishopCol - i > 8) {
			break;
		}
		

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			std::string notKingPiece = board[bishopRow + i][bishopCol - i];

			if (board[bishopRow + i][bishopCol - i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			// Checks if the path has another piece in it
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			std::string notKingPiece = board[bishopRow + i][bishopCol - i];

			if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
			else if (board[bishopRow + i][bishopCol - i] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			
		}

		i++;
	}

	return false;
}

bool lowerRightKingCheck(int bishopRow, int bishopCol, int kingRow, int kingCol, std::string board[][9]){

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (bishopRow + i < 0 || bishopRow + i > 8) {

			break;
		}

		if (bishopCol + i < 0 || bishopCol + i > 8) {

			break;
		}
	
		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			std::string notKingPiece = board[bishopRow + i][bishopCol + i];

			if (board[bishopRow + i][bishopCol + i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			std::string notKingPiece = board[bishopRow + i][bishopCol + i];

			if (board[bishopRow + i][bishopCol + i] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		i++;
	}

	return false;
}

bool upperLeftKingCheck(int bishopRow, int bishopCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (bishopRow - i < 0 || bishopRow - i > 8) {
			break;
		}

		if (bishopCol - i < 0 || bishopCol - i > 8) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			std::string notKingPiece = board[bishopRow - i][bishopCol - i];

			if (board[bishopRow - i][bishopCol - i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			std::string notKingPiece = board[bishopRow - i][bishopCol - i];

			if (board[bishopRow - i][bishopCol - i] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		i++;
	}

	return false;
}

bool upperRightKingCheck(int bishopRow, int bishopCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (bishopRow - i < 0 || bishopRow - i > 8) {
			break;
		}

		if (bishopCol + i < 0 || bishopCol + i > 8) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			std::string notKingPiece = board[bishopRow - i][bishopCol + i];

			if (board[bishopRow - i][bishopCol + i] == "BK") {
				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				return false;
				break;
			}
		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			std::string notKingPiece = board[bishopRow - i][bishopCol + i];

			if (board[bishopRow - i][bishopCol + i] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				return false;
				break;
			}
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
				else if (lowerRightKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (upperLeftKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (upperRightKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

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
			if (board[i][j] == "Wb") {
				bishopRow = i;
				bishopCol = j;

				if (lowerLeftKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (lowerRightKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (upperLeftKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (upperRightKingCheck(bishopRow, bishopCol, kingRow, kingCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}