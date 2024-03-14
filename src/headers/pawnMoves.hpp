#include <iostream>

bool whitePawnMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	

	// Check if their is any pieces in front of pawn
	/*if (board[pieceRow + 1][pieceCol] != "-") {
		std::cout << "Their is a piece in front of that pawn!" << std::endl;
		return false;
	}*/

	// Check if they want to move to much forward and diagnol
	if (pieceRow - moveRow > 2 || moveCol != pieceCol) {
		std::cout << "Invalid Pawn Move!" << std::endl;
		return false;
	}

	return true;
}

bool blackPawnMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {


	// Check if their is any pieces in front of pawn
	/*if (board[pieceRow + 1][pieceCol] != "-") {
		std::cout << "Their is a piece in front of that pawn!" << std::endl;
		return false;
	}*/

	// Check if they want to move to much forward and diagnol
	if (moveRow - pieceRow > 2 || moveCol != pieceCol) {
		std::cout << "Invalid Pawn Move!" << std::endl;
		return false;
	}

	return true;
}