#include <iostream>


bool whiteQueenMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	bool validCheck = false;

	// variables for diagnol movement
	int diagRow = abs(moveRow - pieceRow);
	int diagCol = abs(moveCol - pieceCol);

	if (moveSpot[0] != 'W' && moveSpot[0] != 'K') {

		// Checks for diagnol movement
		if (diagRow == diagCol) {
			if ((moveRow - pieceRow <= -1) && (moveCol - pieceCol <= -1)) {
				validCheck = upperLeftCheck(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if ((moveRow - pieceRow <= -1) && (moveCol - pieceCol >= 1)) {
				validCheck = upperRightCheck(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if ((moveRow - pieceRow >= 1) && (moveCol - pieceCol >= 1)) {
				validCheck = lowerRightCheck(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if ((moveRow - pieceRow >= 1) && (moveCol - pieceCol <= -1)) {
				validCheck = lowerLeftCheck(moveRow, moveCol, pieceRow, pieceCol, board);
			}
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
	bool validCheck = false;

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
