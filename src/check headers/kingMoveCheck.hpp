#include <iostream>

// Check if theyre moving into a space that would put them into check

bool whitePawnCheck(int moveRow, int moveCol, std::string board[][9]) {

	// ################################

	/*
		If a user was to input 1 as a row or col, the program subracts it by one already.
		meaning the program is checking at indexes of [-1].

		The if statements offset those bugs by setting moveRow or moveCol to 1.
		Which the program would then be checking indexs [0]
	*/

	if (moveRow == 0) {
		moveRow = 1;
	}

	if (moveCol == 0) {
		moveCol = 1;
	}
	//################################

	std::string rightDiag = board[moveRow - 1][moveCol + 1];
	std::string leftDiag = board[moveRow - 1][moveCol - 1];

	if (rightDiag == "Bp" || leftDiag == "Bp") {
		return true;
	}
	else {
		return false;
	}

	return true;
}

bool blackPawnCheck(int moveRow, int moveCol, std::string board[][9]) {

	std::string rightDiag = board[moveRow + 1][moveCol + 1];
	std::string leftDiag = board[moveRow + 1][moveCol - 1];

	if (rightDiag == "Wp" || leftDiag == "Wp") {
		return true;
	}
	else {
		return false;
	}

	return true;
}