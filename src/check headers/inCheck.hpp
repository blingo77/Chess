#include <iostream>
#include <vector>

#include "bishopPreCheck.hpp"
#include "rookPreCheck.hpp"
#include "queenPreCheck.hpp"
#include "knightPreCheck.hpp"

bool whitePawnPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	// check diagnols one space ahead for a black pawn

	std::string rightDiag = board[kingRow - 1][kingCol + 1];
	std::string leftDiag = board[kingRow - 1][kingCol - 1];

	if (rightDiag == "Bp" || leftDiag == "Bp") {

		std::cout << "White player is In check" << std::endl;
		return true;
	}
	else {
		return false;
	}

	return true;
}

bool blackPawnPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	// Checks diagnols for white pawns 

	std::string rightDiag = board[kingRow + 1][kingCol + 1];
	std::string leftDiag = board[kingRow + 1][kingCol - 1];

	if (rightDiag == "Wp" || leftDiag == "Wp") {

		std::cout << "Black Player Is In Check!" << std::endl;
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

	if (whitePawnPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (whiteBishopPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (whiteRookPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (whiteQueenPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (whiteKnightPreCheck(kingRow, kingCol, board)) {

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
				kingRow = i;
				kingCol = j;
				break;
			}
		}
	}

	if (blackPawnPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (blackBishopPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (blackRookPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (blackQueenPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else if (blackKnightPreCheck(kingRow, kingCol, board)) {

		return true;
	}
	else {
		return false;
	}

	return true;
}