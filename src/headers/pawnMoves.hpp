#include <iostream>

bool whitePawnMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	
	std::string enemyPiece;

	//check for valid kill
	//RIGHT KILL
	if (board[pieceRow - 1][pieceCol + 1] != "-") {

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
			//std::cout << "in right kill func";
			return true;
		}
	}
	//LEFT KILL
	else if (board[pieceRow - 1][pieceCol - 1] != "-") {
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
			//std::cout << "in left kill func";
			return true;
		}
	}

	// Check if they want to move to much forward and diagnol
	if (pieceRow - moveRow > 2 || moveCol != pieceCol) {
		std::cout << "Invalid Pawn Move!" << std::endl;
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
	if (board[pieceRow + 1][pieceCol + 1] != "-") {

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
			//std::cout << "in right kill func";
			return true;
		}
	}
	//LEFT KILL
	else if (board[pieceRow + 1][pieceCol - 1] != "-") {
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
			//std::cout << "in left kill func";
			return true;
		}
	}
	// Check if they want to move to much forward and diagnol
	if (moveRow - pieceRow > 2 || moveCol != pieceCol) {
		std::cout << "Invalid Pawn Move!" << std::endl;
		return false;
	}

	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";

	return true;
}