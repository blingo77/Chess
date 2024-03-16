#include <iostream>
#include <cmath>

bool whiteKnightMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string friendlyPiece = board[moveRow][moveCol];
	int knightRow = abs(moveRow - pieceRow);
	int knightCol = abs(moveCol - pieceCol);

	std::cout << pieceRow - moveRow << std::endl;
	std::cout << pieceCol - moveCol << std::endl;

	// Checks if the move spot has a friendly piece on it
	if (friendlyPiece[0] != 'W') {

		//std::cout << "Valid knight move 1" << std::endl;

		// Checks if the spot is a valid move spot
		if (knightRow + knightCol == 3) {

			//std::cout << "Valid knight move 2" << std:: endl;

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else {
			std::cout << "Not a valid Knight move!" << std::endl;
			return false;
		}
	}

	return false;
}

bool blackKnightMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	
	std::string friendlyPiece = board[moveRow][moveCol];
	int knightRow = abs(moveRow - pieceRow);
	int knightCol = abs(moveCol - pieceCol);

	std::cout << pieceRow - moveRow << std::endl;
	std::cout << pieceCol - moveCol << std::endl;

	// Checks if the move spot has a friendly piece on it
	if (friendlyPiece[0] != 'B') {

		// Checks if the spot is a valid move spot
		if (knightRow + knightCol == 3) {

			//std::cout << "Valid knight move 2" << std:: endl;

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else {
			std::cout << "Not a valid Knight move!" << std::endl;
			return false;
		}
	}

	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";
	return true;
}