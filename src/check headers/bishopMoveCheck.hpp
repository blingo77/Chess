#include <iostream>

/*
	CHECKS IF THE KING WILL BE IN CHECK BEFORE THEY MOVE TO THE SPOT
*/

/*
TODO:

- find if the moveRow and moveCol are in the attack path of a enemy bishop
*/

bool upperRightMoveCheck(int moveRow, int moveCol, int bishopRow, int bishopCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i >= 9) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow - i][bishopCol - 1];

			if (board[bishopRow - i][bishopCol + i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";

		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow - i][bishopCol + 1];

			if (board[bishopRow - i][bishopCol + i] == "WK") {

				//std::cout << "White is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}

		i++;
	}

	return false;
}

bool uperLeftMoveCheck(int moveRow, int moveCol, int bishopRow, int bishopCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i >= 9) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow - i][bishopCol - 1];

			if (board[bishopRow - i][bishopCol - i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";

		}
		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow - i][bishopCol - 1];

			if (board[bishopRow - i][bishopCol - i] == "WK") {

				//std::cout << "White is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}

		i++;
	}

	return false;
}

bool lowerRightMoveCheck(int moveRow, int moveCol, int bishopRow, int bishopCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i >= 9) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow + i][bishopCol + 1];

			if (board[bishopRow + i][bishopCol + i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";

		}

		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow + i][bishopCol + 1];

			if (board[bishopRow + i][bishopCol + i] == "WK") {

				//std::cout << "White is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}

		i++;
	}

	return false;
}

bool lowerLeftMoveCheck(int moveRow, int moveCol, int bishopRow, int bishopCol, std::string board[][9]){

	int i = 1;
	
	while (true) {

		// Catches the bug of reading memeory address out of bounds
		if (i < 0 || i >= 9) {
			break;
		}

		// Checks if white bishop has black in check
		if (board[bishopRow][bishopCol] == "Wb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow + i][bishopCol - 1];

			if (board[bishopRow + i][bishopCol - i] == "BK") {

				std::cout << "Black is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}

		// checks if black bishop has white in check
		else if (board[bishopRow][bishopCol] == "Bb") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[bishopRow + i][bishopCol - 1];

			if (board[bishopRow + i][bishopCol - i] == "WK") {

				//std::cout << "White is in check! Move" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
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
				else if (lowerRightMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
				else if (uperLeftMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
				else if (upperRightMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

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
				else if (lowerRightMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
				else if (uperLeftMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
				else if (upperRightMoveCheck(moveRow, moveCol, bishopRow, bishopCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}