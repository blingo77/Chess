#include <iostream>

bool whiteRookMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	int rookRow = pieceRow - moveRow;
	int rookCol = pieceCol - moveCol;

	if (moveSpot[0] != 'W' && moveSpot[1] != 'K') {

		//Check for horizontal movement
		std::cout << pieceRow - moveRow << std::endl;
		std::cout << pieceCol - moveCol << std::endl;
		if (rookRow == 0 && rookCol < 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else if (rookRow == 0 && rookCol > 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}

		// Check for vertical movement
		if (rookRow > 0 && rookCol == 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else if (rookRow < 0 && rookCol == 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
	}
	else {
		std::cout << "You cannot take that piece!" << std::endl;
	}

	std::cout << "That is not a valid rook move!" << std::endl;

	return false;
}

bool blackRookMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	
	std::string moveSpot = board[moveRow][moveCol];
	int rookRow = pieceRow - moveRow;
	int rookCol = pieceCol - moveCol;

	if (moveSpot[0] != 'B' && moveSpot[1] != 'K') {

		//Check for horizontal movement
		std::cout << pieceRow - moveRow << std::endl;
		std::cout << pieceCol - moveCol << std::endl;
		if (rookRow == 0 && rookCol < 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else if (rookRow == 0 && rookCol > 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}

		// Check for vertical movement
		if (rookRow > 0 && rookCol == 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else if (rookRow < 0 && rookCol == 0) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
	}
	else {
		std::cout << "You cannot take that piece!" << std::endl;
	}

	std::cout << "That is not a valid rook move!" << std::endl;

	return false;
}
