#include <iostream>

bool whiteKnightPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	// Variables to check if the knight and king are in the same path
	int checkRow;
	int checkCol;

	int knightRow;
	int knightCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "Bk") {

				knightRow = i;
				knightCol = j;

				checkRow = abs(knightRow - kingRow);
				checkCol = abs(knightCol - kingCol);

				//std::cout << knightRow << " " << kingRow << std::endl;
				//std::cout << checkRow << std::endl;
				//std::cout << checkCol << std::endl;


				if (checkRow + checkCol == 3) {

					std::cout << "You are in check 2!" << std::endl;

					return true;
				}
			}
		}
	}

	return false;
}

bool blackKnightPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	// Variables to check if the knight and king are in the same path
	int checkRow;
	int checkCol;

	int knightRow;
	int knightCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "Wk") {

				knightRow = i;
				knightCol = j;

				checkRow = abs(knightRow - kingRow);
				checkCol = abs(knightCol - kingCol);

				//std::cout << knightRow << " " << kingRow << std::endl;
				//std::cout << checkRow << std::endl;
				//std::cout << checkCol << std::endl;


				if (checkRow + checkCol == 3) {

					std::cout << "You are in check 1!" << std::endl;

					return true;
				}
			}
		}
	}

	return false;
}