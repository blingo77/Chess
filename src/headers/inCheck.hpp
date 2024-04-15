#include <iostream>

bool pawnCheck(int kingRow, int kingCol) {

	return true;
}

bool whiteCheck(std::string board[][9]) {

	int kingRow;
	int kingCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "WK") {
				kingRow = i + 1;
				kingCol = j + 1;
				break;
			}
		}
	}

	std::cout << kingRow << std::endl;
	std::cout << kingCol << std::endl;

	if (pawnCheck(kingRow, kingCol)) {

		return true;
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