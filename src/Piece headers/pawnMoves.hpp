#include <iostream>
#include <algorithm>

/*
 PAWN STRUCTURE: 

 CHECK RIGHT KILL -> CHECK LEFT KILL -> CHECK VALID MOVE -> CHECK FOR PIECES IN FRONT OF PAWN
*/

bool whitePawnMove(int moveRow, int moveCol, int pieceRow, int pieceCol, std::string board[][9]) {
	
	std::string enemyPiece;
	int startRow = 6;

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
		else if(enemyPiece[0] == 'B' && (moveRow == pieceRow - 1 || moveCol == pieceCol + 1)){

			std::cout << board[moveRow][moveCol] << " " + enemyPiece << std::endl;

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
		else if (enemyPiece[0] == 'B' && (moveRow == pieceRow - 1 || moveCol == pieceCol - 1)) {

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";
			std::cout << "in left kill func";
			return true;
		}
	}

	// Check if they want to move to much forward and diagnol
	if (pieceRow == startRow) {
		if (pieceRow - moveRow > 2 || moveCol != pieceCol) {
			std::cout << "Invalid Pawn Move!" << std::endl;
			return false;
		}
	}
	else {
		if (pieceRow - moveRow > 1 || moveCol != pieceCol) {
			std::cout << "Invalid Pawn Move!" << std::endl;
			return false;
		}
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
	int startRow = 1;

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
		else if (enemyPiece[0] == 'W' && (moveRow == pieceRow + 1 || moveCol == pieceCol + 1)) { //BUG HERE - pawn can take another pawn two tiles in front, when one is diagnol to it

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
		else if (enemyPiece[0] == 'W' && (moveRow == pieceRow + 1 || moveCol == pieceCol - 1)) { //BUG HERE - pawn can take another pawn two tiles in front, when one is diagnol to it

			board[moveRow][moveCol] = board[pieceRow][pieceCol];
			board[pieceRow][pieceCol] = "-";
			std::cout << "in left kill func";
			return true;
		}
	}
	// Check if they want to move to much forward and diagnol
	if (pieceRow == startRow) {
		if (moveRow - pieceRow > 2 || moveCol != pieceCol) {
			std::cout << "Invalid Pawn Move!" << std::endl;
			return false;
		}
	}
	else {
		if (moveRow - pieceRow > 1 || moveCol != pieceCol) {
			std::cout << "Invalid Pawn Move!" << std::endl;
			return false;
		}
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
	if (board[pieceRow + 2][pieceCol] != "-" && moveRow - pieceRow < 1) {
		std::cout << "Their is a piece theress!" << std::endl;
		return false;
	}

	std::cout << "here";
	board[moveRow][moveCol] = board[pieceRow][pieceCol];
	board[pieceRow][pieceCol] = "-";

	return true;
}