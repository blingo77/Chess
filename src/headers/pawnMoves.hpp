#include <iostream>

bool whitePawnMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	
	std::string enemyPiece;

	//check for valid kill
	//RIGHT KILL
	if (board[pieceRow - 1][pieceCol + 1] != "-"  && pieceCol + 1 < 8) {

		enemyPiece = board[pieceRow - 1][pieceCol + 1];
		if (enemyPiece[0] == 'B' && board[moveRow][moveCol] != enemyPiece) {
			/*
			checks if enemy is in right diagnol, but if the move spot is not the enemy, 
			function will continue to move conditions
			*/
		}
		else{

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";
			std::cout << "in right kill func";
			return true;
		}
	}
	//LEFT KILL
	else if (board[pieceRow - 1][pieceCol - 1] != "-" && pieceCol - 1 >= 0 ) {
		std::cout << pieceCol - 1 << std::endl;
		enemyPiece = board[pieceRow - 1][pieceCol - 1];

		if (enemyPiece[0] == 'B' && board[moveRow][moveCol] != enemyPiece) {
			/*
			checks if enemy is in left diagnol, but if the move spot is not the enemy,
			function will continue to move conditions
			*/
		}
		else {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";
			std::cout << "in left kill func";
			return true;
		}
	}

	// Check if they want to move to much forward and diagnol
	if (pieceRow - moveRow > 2 || moveCol != pieceCol) {
		std::cout << "Invalid Pawn Move!" << std::endl;
		return false;
	}

	//std::cout << board[pieceRow - 1][pieceCol] << std::endl;

	// Checks if their is a piece in front of the pawn
	if(board[pieceRow - 1][pieceCol] != "-"){
		std::cout << "Their is a piece there!" << std::endl;
		return false;
	}

	//std::cout << board[pieceRow - 2][pieceCol] << std::endl;
	//std::cout << pieceRow - moveRow << std::endl;

	// Checks if their is a piece 2 spots in front of the pawn
	if (board[pieceRow - 2][pieceCol] != "-" && pieceRow - moveRow > 1) {
		std::cout << "Their is a piece there!" << std::endl;
		return false;
	}
	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";

	return true;
}

bool blackPawnMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {

	std::string enemyPiece;

	//check for valid kill
	//RIGHT KILL
	if (board[pieceRow + 1][pieceCol + 1] != "-" && pieceCol - 1 >= 0 && pieceCol + 1 < 8) {

		enemyPiece = board[pieceRow + 1][pieceCol + 1];
		if (enemyPiece[0] == 'W' && board[moveRow][moveCol] != enemyPiece) {

			/*
			checks if enemy is in right diagnol, but if the move spot is not the enemy,
			function will continue to move conditions
			*/
		}
		else {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";
	
			std::cout << "in right kill func";
			return true;
		}
	}
	//LEFT KILL
	else if (board[pieceRow + 1][pieceCol - 1] != "-" && pieceCol - 1 >= 0) {
		enemyPiece = board[pieceRow + 1][pieceCol - 1];
		if (enemyPiece[0] == 'W' && board[moveRow][moveCol] != enemyPiece) {

			/*
			checks if enemy is in left diagnol, but if the move spot is not the enemy,
			function will continue to move conditions
			*/
		}
		else {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";
			std::cout << "in left kill func";
			return true;
		}
	}
	// Check if they want to move to much forward and diagnol
	if (moveRow - pieceRow > 2 || moveCol != pieceCol) {
		std::cout << "Invalid Pawn Move!" << std::endl;
		return false;
	}
	std::cout << board[pieceRow - 1][pieceCol] << std::endl;

	// Checks if their is a piece in front of the pawn
	if (board[pieceRow + 1][pieceCol] != "-") {
		std::cout << "Their is a piece there!" << std::endl;
		return false;
	}

	//std::cout << moveRow - moveCol;
	// 
	// Checks if their is a piece 2 spots in front of the pawn
	if (board[pieceRow + 2][pieceCol] != "-" && moveRow - moveCol < 1) {
		std::cout << "Their is a piece theress!" << std::endl;
		return false;
	}

	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";

	return true;
}