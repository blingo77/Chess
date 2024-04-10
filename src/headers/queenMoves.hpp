#include <iostream>

bool whiteQueenMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	bool validCheck;

	// variables for diagnol movement
	int diagRow = abs(moveRow - pieceRow);
	int diagCol = abs(moveCol - pieceCol);

	if (moveSpot[0] != 'W' && moveSpot[0] != 'K') {

		if (diagRow == diagCol) {

		}
		else {
			std::cout << "Not a diag queen movement" << std::endl;
		}

		if (validCheck) {
			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
	}

	return true;
}


bool blackQueenMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	bool validCheck;

	// variables for diagnol movement
	int diagRow = abs(moveRow - pieceRow);
	int diagCol = abs(moveCol - pieceCol);

	if (moveSpot[0] != 'W' && moveSpot[0] != 'K') {

		if (diagRow == diagCol) {

		}
		else {
			std::cout << "Not a diag queen movement" << std::endl;
		}

		if (validCheck) {
			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
	}

	return true;
}
