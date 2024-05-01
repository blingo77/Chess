#include <iostream>

bool rookRHorizontalMoveCheck(int rookRow, int rookCol, int moveRow, int moveCol, std::string board[][9]) {
	int i = 1;

	while (true) {

		if (i < 0 || i > 9) {
			break;
		}

		if (rookCol + i > 8 || rookCol + i < 0) {
			break;
		}

		if (board[rookRow][rookCol] == "Br") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[rookRow][rookCol + i];

			if (board[rookRow][rookCol + i] == "WK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		else if (board[rookRow][rookCol] == "Wr") {

			board[moveRow][moveCol] = "BK";
			std::string notKingPiece = board[rookRow][rookCol + i];

			if (board[rookRow][rookCol + i] == "BK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		i++;
	}

	return false;
}

bool rookLHorizonalMoveCheck(int rookRow, int rookCol, int moveRow, int moveCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 9) {
			break;
		}

		if (rookCol - i > 8 || rookCol - i < 0) {
			break;
		}

		if (board[rookRow][rookCol] == "Br") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[rookRow][rookCol - i];

			if (board[rookRow][rookCol - i] == "WK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		else if (board[rookRow][rookCol] == "Wr") {

			board[moveRow][moveCol] = "BK";
			std::string notKingPiece = board[rookRow][rookCol - i];

			if (board[rookRow][rookCol - i] == "BK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		i++;
	}

	return false;
}

bool rookVerticalUpMoveCheck(int rookRow, int rookCol, int moveRow, int moveCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 9) {
			break;
		}

		if (rookRow - i > 8 || rookRow - i < 0) {
			break;
		}

		if (board[rookRow][rookCol] == "Br") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[rookRow - i][rookCol];

			if (board[rookRow - i][rookCol] == "WK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		else if (board[rookRow][rookCol] == "Wr") {

			board[moveRow][moveCol] = "BK";
			std::string notKingPiece = board[rookRow - i][rookCol];

			if (board[rookRow - i][rookCol] == "BK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		i++;
	}

	return false;
}

bool rookVerticalDownMoveCheck(int rookRow, int rookCol, int moveRow, int moveCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 9) {
			break;
		}

		if (rookRow + i > 8 || rookRow + i < 0) {
			break;
		}

		if (board[rookRow][rookCol] == "Br") {

			board[moveRow][moveCol] = "WK";
			std::string notKingPiece = board[rookRow + i][rookCol];

			if (board[rookRow + i][rookCol] == "WK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		else if (board[rookRow][rookCol] == "Wr") {

			board[moveRow][moveCol] = "BK";
			std::string notKingPiece = board[rookRow + i][rookCol];

			if (board[rookRow + i][rookCol] == "BK") {

				std::cout << "You cant move their" << std::endl;
				board[moveRow][moveCol] = "-";
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {
				board[moveRow][moveCol] = "-";
				return false;
				break;
			}
			board[moveRow][moveCol] = "-";
		}
		i++;
	}

	return false;

}

bool whiteRookCheck(int moveRow, int moveCol, std::string board[][9]) {
	int rookRow;
	int rookCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "Br") {

				rookRow = i;
				rookCol = j;

				if (rookRHorizontalMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
				else if (rookLHorizonalMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
				else if (rookVerticalUpMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
				else if (rookVerticalDownMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}

bool blackRookCheck(int moveRow, int moveCol, std::string board[][9]) {
	int rookRow;
	int rookCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "Br") {

				rookRow = i;
				rookCol = j;

				if (rookRHorizontalMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
				else if (rookLHorizonalMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
				else if (rookVerticalUpMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
				else if (rookVerticalDownMoveCheck(rookRow, rookCol, moveRow, moveCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}