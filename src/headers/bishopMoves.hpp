#include <iostream>

bool whiteBishopMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];
	int bishopRow = abs(moveRow - pieceRow);
	int bishopCol = abs(moveCol - pieceCol);

	if (moveSpot[0] != 'W' && moveSpot[1] != 'K') {

		//std::cout << "Valid knight move 1" << std::endl;

		// Checks if the spot is a valid move spot
		if (bishopRow == bishopCol) {

			//std::cout << "Valid knight move 2" << std:: endl;

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
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

	std::string friendlyPiece = board[moveRow][moveCol];
	int bishopRow = abs(moveRow - pieceRow);
	int bishopCol = abs(moveCol - pieceCol);

	if (friendlyPiece[0] != 'B') {

		//std::cout << "Valid knight move 1" << std::endl;

		// Checks if the spot is a valid move spot
		if (bishopRow == bishopCol) {

			//std::cout << "Valid knight move 2" << std:: endl;

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
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