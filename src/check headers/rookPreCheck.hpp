#include <iostream>

bool rookRHorizontalCheck(int rookRow, int rookCol, int kingRow, int kingCol, std::string board[][9]) {

	int i = 1;

	while (true) {

		if (i < 0 || i > 8) {
			break;
		}
		
		if (board[rookRow][rookCol] == "Br") {

			std::string notKingPiece = board[rookRow][rookCol + i];
			
			if (board[rookRow][rookCol + i] == "WK") {

				std::cout << "Rook puts king in cehck" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		else if (board[rookRow][rookCol] == "Wr") {

			std::string notKingPiece = board[rookRow][rookCol + i];

			if (board[rookRow][rookCol + i] == "BK") {

				std::cout << "White Rook Puts Black in Check" << std::endl;
				return true;
				break;
			}
			else if ((notKingPiece[1] != 'K' && notKingPiece[0] == 'W') || (notKingPiece[1] != 'K' && notKingPiece[0] == 'B')) {

				return false;
				break;
			}
		}
		i++;
	}

	return false;
}

bool whiteRookPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	int rookRow;
	int rookCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "Br") {

				rookRow = i;
				rookCol = j;

				if (rookRHorizontalCheck(rookRow, rookCol, kingRow, kingCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}

bool blackRookPreCheck(int kingRow, int kingCol , std::string board[][9]) {

	int rookRow;
	int rookCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == "Wr") {

				rookRow = i;
				rookCol = j;

				if (rookRHorizontalCheck(rookRow, rookCol, kingRow, kingCol, board)) {

					return true;
				}
			}
		}
	}

	return false;
}