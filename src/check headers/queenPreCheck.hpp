#include <iostream>

/*
	CHECKS IF THE KINGS POSITION IS IN THE PATH OF A QUEEN BEFORE IT CAN MOVE
*/

bool queenLowerLeftCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i > 9) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (queenRow + i < 0 || queenCol + i > 8) {
			break;
		}

		if (queenRow - i < 0 || queenCol - i > 8) {
			break;
		}


		// Checks if white queen has black in check
		if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow + i][queenCol - i];

			if (board[queenRow + i][queenCol - i] == "BK") {

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
		// checks if black queen has white in check
		else if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow + i][queenCol - i];

			if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
			else if (board[queenRow + i][queenCol - i] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}

		}

		i++;
	}

	return false;

}

bool queenLowerRightCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {
	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (queenRow + i < 0 || queenCol + i > 8) {

			break;
		}

		if (queenRow + i < 0 || queenCol + i > 8) {

			break;
		}

		// Checks if white queen has black in check
		if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow + i][queenCol + i];

			if (board[queenRow + i][queenCol + i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		// checks if black queen has white in check
		else if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow + i][queenCol + i];

			if (board[queenRow + i][queenCol + i] == "WK") {

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

bool queenUpperLeftCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (queenRow - i < 0 || queenCol - i > 8) {
			break;
		}

		if (queenRow - i < 0 || queenCol - i > 8) {
			break;
		}

		// Checks if white queen has black in check
		if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow - i][queenCol - i];

			if (board[queenRow - i][queenCol - i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		// checks if black queen has white in check
		else if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow - i][queenCol - i];

			if (board[queenRow - i][queenCol - i] == "WK") {

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

bool queenUpperRightCheck(int queenRow, int queenCol , int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		// Makes sure that it isnt checking out of bounds
		if (queenRow - i < 0 || queenRow + i > 8) {
			break;
		}

		if (queenCol - i < 0 || queenCol + i > 8) {
			break;
		}

		// Checks if white queen has black in check
		if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow - i][queenCol + i];

			if (board[queenRow - i][queenCol + i] == "BK") {
				std::cout << "Black is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				return false;
				break;
			}
		}
		// checks if black queen has white in check
		else if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow - i][queenCol + i];

			if (board[queenRow - i][queenCol + i] == "WK") {

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

bool queenVerticalDownCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 9) {
			break;
		}

		if (queenRow + i > 8 || queenRow + i < 0) {
			break;
		}

		if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow + i][queenCol];

			if (board[queenRow + i][queenCol] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		else if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow + i][queenCol];

			if (board[queenRow + i][queenCol] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
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

bool queenVerticalUpCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		if (queenRow - i > 8 || queenRow - i < 0) {
			break;
		}

		if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow - i][queenCol];

			if (board[queenRow - i][queenCol] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		else if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow - i][queenCol];

			if (board[queenRow - i][queenCol] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
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

bool queenLHorizontalCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		if (queenCol - i > 8 || queenCol - i < 0) {
			break;
		}

		if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow][queenCol - i];

			if (board[queenRow][queenCol - i] == "WK") {

				std::cout << "White is in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		else if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow][queenCol - i];

			if (board[queenRow][queenCol - i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
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

bool queenRHorizontalCheck(int queenRow, int queenCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}

		if (queenCol + i > 8 || queenCol + i < 0) {
			break;
		}

		if (board[queenRow][queenCol] == "BQ") {

			std::string notKingPiece = board[queenRow][queenCol + i];

			if (board[queenRow][queenCol + i] == "WK") {

				std::cout << "You are in check! Move" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		else if (board[queenRow][queenCol] == "WQ") {

			std::string notKingPiece = board[queenRow][queenCol + i];

			if (board[queenRow][queenCol + i] == "BK") {

				std::cout << "You are in check! Move" << std::endl;
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

bool whiteQueenPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	int queenRow;
	int queenCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "BQ") {
				queenRow = i;
				queenCol = j;

				if (queenUpperRightCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenUpperLeftCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenLowerRightCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenLowerLeftCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenRHorizontalCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenLHorizontalCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenVerticalUpCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
				else if (queenVerticalDownCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}

bool blackQueenPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	int queenRow;
	int queenCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "WQ") {
				queenRow = i;
				queenCol = j;

			if (queenUpperRightCheck(queenRow, queenCol, kingRow, kingCol, board)) {

					return true;
			}
			else if (queenUpperLeftCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			else if (queenLowerRightCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			else if (queenLowerLeftCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			else if (queenRHorizontalCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			else if (queenLHorizontalCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			else if (queenVerticalUpCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			else if (queenVerticalDownCheck(queenRow, queenCol, kingRow, kingCol, board)) {

				return true;
			}
			}
		}
	}

	return false;
}