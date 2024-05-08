#include <iostream>
#include <cctype>
#include <string>

#include "pawnMoves.hpp";
#include "knightMoves.hpp"
#include "bishopMoves.hpp"
#include "rookMoves.hpp"
#include "queenMoves.hpp"
#include "kingMoves.hpp"
#include "../check headers/inCheck.hpp"

class Chess {

public:

	Chess(){
		
	}

	void drawBoard() {

		std::cout << '\n';

		for (int i = 0; i < 9; i++) {
			std::cout << "---------------------------------" << std::endl;
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "-") {
					std::cout << "| " << board[i][j] << " ";
					continue;
				}
				else {
					std::cout << "|" << board[i][j] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << '\n';
	}

	void whiteMove() {

		int pieceRow;
		int pieceCol;
		int count;
		std::string charPieceCol;
		std::string piece;
		int moveRow;
		int moveCol;
		std::string charMoveCol;
		bool skip = false;
		bool validPiece = false;
		bool validMove = false;

		while (!validPiece) {
			do {

				count = 0;
				skip = false;

				std::cout << "White Players Turn!" << std::endl;
				std::cout << "Enter Colum: ";
				std::cin >> charPieceCol;

				for (int i = 0; i < charPieceCol.length(); i++) {
					if (isalpha(charPieceCol[i])) {
						charPieceCol[i] = tolower(charPieceCol[i]);
					}
				}

				for (char i : charPieceCol) {

					count++;

					if (count > 1) {
						skip = true;
						pieceRow = 0;
						pieceCol = 0;
						break;
					}

					if (isdigit(i)) {
						std::cout << " Type a letter!" << std::endl;
						skip = true;
						pieceRow = 0;
						pieceCol = 0;
						break;
					}
				}

				if (skip) {
					pieceRow = 0;
					pieceCol = 0;
					continue;
				}

				std::cout << "Enter Row: ";
				std::cin >> pieceRow;

				switch (charPieceCol[0]) {
				case 'a':
					pieceCol = 1;
					break;

				case 'b':
					pieceCol = 2;
					break;

				case 'c':
					pieceCol = 3;
					break;

				case 'd':
					pieceCol = 4;
					break;

				case 'e':
					pieceCol = 5;
					break;

				case 'f':
					pieceCol = 6;
					break;

				case 'g':
					pieceCol = 7;
					break;

				case 'h':
					pieceCol = 8;
					break;

				}

				pieceRow--;
				pieceCol--;

			} while (pieceRow < 0 || pieceRow > 8 && pieceCol < 0 || pieceCol > 8);
			
			piece = board[pieceRow][pieceCol];

			if (piece[0] != 'W') {
				std::cout << "Not a valid piece! " << std::endl;
			}
			else {
				validPiece = true;
				std::cout << piece + " Selected" << std::endl;
			}
		}

		while(!validMove) {

			do {

				count = 0;
				skip = false;

				std::cout << "Now enter spot to move to! " << std::endl;
				std::cout << "Enter Col to move: ";
				std::cin >> charMoveCol;

				for (int i = 0; i < charMoveCol.length(); i++) {
					if (isalpha(charMoveCol[i])) {
						charMoveCol[i] = tolower(charMoveCol[i]);
					}
				}

				for (char i : charMoveCol) {

					count++;

					if (count > 1) {
						skip = true;
						moveRow = 0;
						moveCol = 0;
						break;
					}

					if (isdigit(i)) {
						std::cout << " Type a letter!" << std::endl;
						skip = true;
						skip = true;
						moveRow = 0;
						moveCol = 0;
						break;
					}
				}

				if (skip) {
					moveRow = 0;
					moveCol = 0;
					continue;
				}

				std::cout << "Enter Row: ";
				std::cin >> moveRow;

				switch (charMoveCol[0]) {
				case 'a':
					moveCol = 1;
					break;

				case 'b':
					moveCol = 2;
					break;

				case 'c':
					moveCol = 3;
					break;

				case 'd':
					moveCol = 4;
					break;

				case 'e':
					moveCol = 5;
					break;

				case 'f':
					moveCol = 6;
					break;

				case 'g':
					moveCol = 7;
					break;

				case 'h':
					moveCol = 8;
					break;
				}

				moveRow--;
				moveCol--;

				std::string friendlyPiece = board[moveRow][moveCol];

				if (friendlyPiece[0] == 'W') {
					std::cout << "That is a friendly Piece!" << std::endl;
					moveRow = 9;
					moveCol = 9;
				}

			} while (moveRow < 0 || moveRow > 8 && moveCol < 0 || moveCol > 8);

			if (piece[1] == 'p') {
				validMove = whitePawnMove(moveRow , moveCol, pieceRow , pieceCol , board);
			}
			else if (piece[1] == 'k') {
				validMove = whiteKnightMove(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'b') {
				validMove = whiteBishopMove(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'r') {
				validMove = whiteRookMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'Q') {
				std::cout << "WQ Selected" << std::endl;
				validMove = whiteQueenMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'K') {
				std::cout << "WK Selected" << std::endl;
				validMove = whiteKingMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
		}
	}

	void blackMove() {

		int pieceRow;
		int pieceCol;
		int count;
		std::string charPieceCol;
		std::string piece;
		int moveRow;
		int moveCol;
		std::string charMoveCol;
		bool skip = false;
		bool validPiece = false;
		bool validMove = false;

		while (!validPiece) {
			do {

				count = 0;
				skip = false;

				std::cout << "Black Players Turn!" << std::endl;
				std::cout << "Enter Column: ";
				std::cin >> charPieceCol;

				for (int i = 0; i < charPieceCol.length(); i++) {
					if (isalpha(charPieceCol[i])) {
						charPieceCol[i] = tolower(charPieceCol[i]);
					}
				}

				for (char i : charPieceCol) {

					count++;

					if (count > 1) {
						skip = true;
						pieceRow = 9;
						pieceCol = 9;
						break;
					}

					if (isdigit(i)) {
						std::cout << " Type a letter!" << std::endl;
						skip = true;
						pieceRow = 9;
						pieceCol = 9;
						break;
					}
				}

				if (skip) {
					std::cout << " ASd" << std::endl;
					validPiece = false;
					pieceRow = 9;
					pieceCol = 9;
					continue;
				}

				std::cout << "Enter Row: ";
				std::cin >> pieceRow;

				switch (charPieceCol[0]) {
				case 'a':
					pieceCol = 1;
					break;

				case 'b':
					pieceCol = 2;
					break;

				case 'c':
					pieceCol = 3;
					break;

				case 'd':
					pieceCol = 4;
					break;

				case 'e':
					pieceCol = 5;
					break;

				case 'f':
					pieceCol = 6;
					break;

				case 'g':
					pieceCol = 7;
					break;

				case 'h':
					pieceCol = 8;
					break;
				}

				pieceRow--;
				pieceCol--;

			} while (pieceRow < 0 || pieceRow > 8 && pieceCol < 0 || pieceCol > 8);

			piece = board[pieceRow][pieceCol];

			if (piece[0] != 'B') {
				std::cout << "Not a valid piece! " << std::endl;
			}
			else {
				validPiece = true; 
				std::cout << piece + " Selected" << std::endl;

			}
		}

		while (!validMove) {
			do {

				count = 0;
				skip = false;
				charMoveCol = "";

				std::cout << "Now enter spot to move to! " << std::endl;
				std::cout << "Enter Col to move: ";
				std::cin >> charMoveCol;

				for (int i = 0; i < charMoveCol.length(); i++) {
					if (isalpha(charMoveCol[i])) {
						charMoveCol[i] = tolower(charMoveCol[i]);
					}
				}

				for (char i : charMoveCol) {

					count++;

					if (count > 1) {
						skip = true;
						moveRow = 8;
						moveCol = 8;
						break;
					}

					if (isdigit(i)) {
						std::cout << " Type a letter!" << std::endl;
						skip = true;
						moveRow = 8;
						moveCol = 8;
						break;
					}
				}

				if (skip) {
					moveRow = 8;
					moveCol = 8;
					continue;
				}

				std::cout << "Enter Row: ";
				std::cin >> moveRow;

				switch (charMoveCol[0]) {
				case 'a':
					moveCol = 1;
					break;

				case 'b':
					moveCol = 2;
					break;

				case 'c':
					moveCol = 3;
					break;

				case 'd':
					moveCol = 4;
					break;

				case 'e':
					moveCol = 5;
					break;

				case 'f':
					moveCol = 6;
					break;

				case 'g':
					moveCol = 7;
					break;

				case 'h':
					moveCol = 8;
					break;
				}

				moveRow--;
				moveCol--;

				std::string friendlyPiece = board[moveRow][moveCol];

				if (friendlyPiece[0] == 'B') {
					std::cout << "That is a friendly Piece!" << std::endl;
					moveRow = 9;
					moveCol = 9;
				}

			} while (moveRow < 0 || moveRow > 8 && moveCol < 0 || moveCol > 8);

			if (piece[1] == 'p') {
				validMove = blackPawnMove(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'k') {
				validMove = blackKnightMove(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'b') {
				validMove = blackBishopMove(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'r') {
				validMove = blackRookMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'Q') {
				validMove = blackQueenMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
			else if (piece[1] == 'K') {
				validMove = blackKingMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
		}
	}

	void run() {

		bool whiteInCheck = false;
		bool blackInCheck = false;

		while (running) {

			drawBoard();
			whiteInCheck = whiteCheck(board);
			if (whiteInCheck) {

				while (whiteInCheck) {

					whiteMove();
					whiteInCheck = whiteCheck(board);
				}
			}
			else {
				whiteMove();
			}

			drawBoard();
			blackInCheck = blackCheck(board);
			if (blackInCheck) {

				while (blackInCheck) {

					blackMove();
					blackInCheck = blackCheck(board);
				}
			}
			else {
				blackMove();
			}
		}
	}

private:
	std::string board[9][9] = {{"Br", "Bk", "Bb", "BQ", "BK", "Bb", "Bk","Br", "1"},
								{"Bp", "Bp", "Bp", "Bp", "Bp", "Bp", "Bp","Bp", "2"},
								{"-", "-", "-", "-", "-", "-", "-","-", "3"},
								{"-", "-", "-", "-", "-", "-", "-","-", "4"},
								{"-", "-", "-", "-", "-", "-", "-","-", "5"},
								{"-", "-", "-", "-", "-", "-", "-","-", "6"},
								{"Wp", "Wp", "Wp", "Wp", "Wp", "Wp", "Wp","Wp", "7"},
								{"Wr", "Wk", "Wb", "WQ", "WK", "Wb", "Wk","Wr", "8"},
								{" A", " B", " C", " D", " E", " F", " G", " H", ""}};

	int boardSize = sizeof(board)/sizeof(char);
	bool running = true;
	bool wPlayerMove = true;
};