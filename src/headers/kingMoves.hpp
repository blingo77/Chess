#include <iostream>

bool whiteKingMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];

	int kingRow = abs(moveRow - pieceRow);
	int kingCol = abs(moveCol - pieceCol);

	// Checks if the spot is friendly or king piece
	if (moveSpot[0] != 'W' && moveSpot[1] != 'K') {
		// Checks if the king has a valid move
		if ((kingRow == 1 || kingRow == 0) && (kingCol == 1 || kingCol == 0)) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";

			return true;
		}
		else {
			std::cout << "That is not a valid King move!" << std::endl;
			return false;
		}

	}
	else {
		std::cout << "That is a friendly piece!" << std::endl;
		return false;
	}

	return true;
}

bool blackKingMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];

	if(moveSpot[0] != 'B' && moveSpot[1] != 'K') {

	}
	else {
		std::cout << "That is a friendly piece!";
		return false;
	}

	return true;
}