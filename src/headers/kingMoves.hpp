#include <iostream>

bool whiteKingMoves(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string moveSpot = board[moveRow][moveCol];

	if (moveSpot[0] != 'W' && moveSpot[1] != 'K') {

	}
	else {
		std::cout << "That is a friendly piece!";
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