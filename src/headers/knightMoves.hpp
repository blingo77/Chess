#include <iostream>

bool whiteKnightMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string friendlyPiece = board[moveRow][moveCol];

	std::cout << pieceRow - moveRow << std::endl;
	std::cout << pieceCol - moveCol << std::endl;

	// Checks if the move spot has a friendly piece on it
	if (friendlyPiece[0] == 'W') {

		// Checks for a knight move to the left off of spawn tile
		if ((pieceRow - moveRow != 2 || pieceCol - moveCol != 1) && (pieceRow - moveRow != 2 || pieceCol - moveCol != -1)) {
			std::cout << "Invalid Knight move! " << std::endl;
			return false;
		}
	}

	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";

	return true;
}

bool blackKnightMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	
	std::string friendlyPiece = board[moveRow][moveCol];

	std::cout << pieceRow - moveRow << std::endl;
	std::cout << pieceCol - moveCol << std::endl;

	// Checks if the move spot has a friendly piece on it
	if (friendlyPiece[0] == 'B') {

		// Checks for a knight move to the left off of spawn tile
		if ((moveRow - pieceRow != 2 || pieceCol - moveCol != 1) && (pieceRow - moveRow != -2 || pieceCol - moveCol != -1)) {
			std::cout << "Invalid Knight move! " << std::endl;
			return false;
		}
	}

	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";
	return true;
}