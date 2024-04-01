#include <iostream>

bool upperLeftCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		// Checks if a piece is in the path of the moveSpot
		if ((pieceRow - i == moveRow) && (pieceCol - i == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow - i][pieceCol - i] != "-") {
			std::cout << "bishop UL check function";
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool upperRightCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow - i == moveRow) && (pieceCol + i  == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow - i][pieceCol + i] != "-") {
			std::cout << "bishop UR check function";
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool lowerLeftCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow + i == moveRow) && (pieceCol - i == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow + i][pieceCol - i] != "-") {
			std::cout << "bishop LL check function";
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}

	return true;
}

bool lowerRightCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow + i == moveRow) && (pieceCol + i == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow + i][pieceCol + i] != "-") {
			std::cout << "bishop LR check function";
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++; 
	}
	return true;
}

bool whiteBishopMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	int bishopRow = abs(moveRow - pieceRow);
	int bishopCol = abs(moveCol - pieceCol);
	bool validCheck;

	// Player is not allowed to move a spot that has a black piece or enemy king
	if (moveSpot[0] != 'W' && moveSpot[1] != 'K') {

		//std::cout << "Valid knight move 1" << std::endl;

		// Checks if the spot is a valid move spot
		if (bishopRow == bishopCol) {

			//std::cout << "Valid knight move 2" << std:: endl;

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
			if (validCheck) {
				board[moveRow][moveCol] = board[pieceRow][pieceCol];
				board[pieceRow][pieceCol] = "-";

				return true;
			}
		}
		else {
			std::cout << "Not a valid Bishop move!" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "You Cannot Move There!" << std::endl;
		return false;
	}

	return false;
}

bool blackBishopMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	int bishopRow = abs(moveRow - pieceRow);
	int bishopCol = abs(moveCol - pieceCol);
	bool validCheck;

	// Player is not allowed to move a spot that has a black piece or enemy king
	if (moveSpot[0] != 'B' && moveSpot[1] != 'K') {

		//std::cout << "Valid knight move 1" << std::endl;

		// Checks if the spot is a valid move spot
		if (bishopRow == bishopCol) {

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
			if (validCheck) {
				board[moveRow][moveCol] = board[pieceRow][pieceCol];
				board[pieceRow][pieceCol] = "-";

				return true;
			}
		}
		else {
			std::cout << "Not a valid Bishop move!" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Their is a friendly piece there!" << std::endl;
		return false;
	}

	return false;
}