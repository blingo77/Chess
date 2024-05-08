#include <iostream>

bool leftHorizontalCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow == moveRow) && (pieceCol + i == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow][pieceCol + i] != "-") {
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool rightHorizontalCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow == moveRow) && (pieceCol - i == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow][pieceCol - i] != "-") {
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool verticalUpCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow - i == moveRow) && (pieceCol == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow - i][pieceCol] != "-") {
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool verticalDownCheck(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	int i = 1;
	while (true) {

		if ((pieceRow + i == moveRow) && (pieceCol == moveCol)) {
			return true;
			break;
		}
		else if (board[pieceRow + i][pieceCol] != "-") {
			std::cout << "There is a piece in your way!" << std::endl;
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool whiteRookMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	int rookRow = pieceRow - moveRow;
	int rookCol = pieceCol - moveCol;
	bool validCheck;

	if (moveSpot[0] != 'W' && moveSpot[1] != 'K') {

		//Check for horizontal movement

		if (rookRow == 0 && rookCol < 0) {

			validCheck = leftHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (rookRow == 0 && rookCol > 0) {

			validCheck = rightHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		// Check for vertical movement
		if (rookRow > 0 && rookCol == 0) {

			validCheck = verticalUpCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (rookRow < 0 && rookCol == 0) {

			validCheck = verticalDownCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		if (validCheck) {
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
	bool validCheck;

	if (moveSpot[0] != 'B' && moveSpot[1] != 'K') {

		//Check for horizontal movement

		if (rookRow == 0 && rookCol < 0) {

			validCheck = leftHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (rookRow == 0 && rookCol > 0) {

			validCheck = rightHorizontalCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		// Check for vertical movement
		if (rookRow > 0 && rookCol == 0) {

			validCheck = verticalUpCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}
		else if (rookRow < 0 && rookCol == 0) {

			validCheck = verticalDownCheck(moveRow, moveCol, pieceRow, pieceCol, board);
		}

		if (validCheck) {
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
