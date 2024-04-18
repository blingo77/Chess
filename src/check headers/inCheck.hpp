#include <iostream>

bool pawnCheck(int kingRow, int kingCol, std::string board[][9]) {

	// check diagnols one space ahead for a black pawn

	std::string rightDiag = board[kingRow - 1][kingCol + 1];
	std::string leftDiag = board[kingRow - 1][kingCol - 1];

	std::cout << leftDiag << std::endl;

	if (rightDiag == "Bp" || leftDiag == "Bp") {

		std::cout << "In check" << std::endl;

		return true;
	}
	else {
		return false;
	}

	return true;
}

bool whiteCheck(std::string board[][9]) {

	int kingRow;
	int kingCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "WK") {
				kingRow = i;
				kingCol = j;
				break;
			}
		}
	}

	std::cout << kingRow  + 1<< std::endl;
	std::cout << kingCol + 1<< std::endl;

	if (pawnCheck(kingRow, kingCol, board)) {

		return true;
	}
	else {
		return false;
	}

	return true;
}

bool blackCheck(std::string board[][9]) {

	int kingRow;
	int kingCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "BK") {
				kingRow = i + 1;
				kingCol = j + 1;
				break;
			}
		}
	}

	return false;
}