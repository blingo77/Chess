#include <iostream>

/*

		!!! UTILIZES THE CHECK FUNCTIONS FROM "bishop.hpp" and "rook.hpp" !!!

			CHECK THOSE HEADER FILES FOR QUEEN CONDITION CHECKING LOGIC

*/

bool whiteQueenMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	bool validCheck = false;

	// variables for diagnol movement
	int diagRow = abs(moveRow - pieceRow);
	int diagCol = abs(moveCol - pieceCol);

	// horizotnal and vert variables
	int horzRow = pieceRow - moveRow;
	int vertCol = pieceCol - moveCol;

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

		// Checks for horizontal movement
		if (horzRow == 0 && vertCol < 0) {
			validCheck = leftHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (horzRow == 0 && vertCol > 0) {

			validCheck = rightHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		// Check for vertical movement
		if (horzRow > 0 && vertCol == 0) {

			validCheck = verticalUpCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (horzRow < 0 && vertCol == 0) {

			validCheck = verticalDownCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		if (validCheck) {
			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
	}

	return false;
}


bool blackQueenMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	bool validCheck = false;

	// variables for diagnol movement
	int diagRow = abs(moveRow - pieceRow);
	int diagCol = abs(moveCol - pieceCol);

	// horizotnal and vert variables
	int horzRow = pieceRow - moveRow;
	int vertCol = pieceCol - moveCol;

	if (moveSpot[0] != 'B' && moveSpot[0] != 'K') {

		// Checks for diagnol movement
		if (diagRow == diagCol) {
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
		}
		else {
			std::cout << "Not a diag queen movement" << std::endl;
		}

		// Checks for horizontal movement
		if (horzRow == 0 && vertCol < 0) {
			validCheck = leftHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (horzRow == 0 && vertCol > 0) {

			validCheck = rightHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		// Check for vertical movement
		if (horzRow > 0 && vertCol == 0) {

			validCheck = verticalUpCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (horzRow < 0 && vertCol == 0) {

			validCheck = verticalDownCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		if (validCheck) {
			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
	}

	return false;
}
