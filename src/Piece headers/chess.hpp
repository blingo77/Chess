#include <iostream>
#include <cctype>

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
		std::string piece;
		int moveRow;
		int moveCol;
		bool validPiece = false;
		bool validMove = false;

		while (!validPiece) {
			do {
				std::cout << "White Players Turn!" << std::endl;
				std::cout << "Enter Row: ";
				std::cin >> pieceRow;
				std::cout << "Enter Colum: ";
				std::cin >> pieceCol;
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
				std::cout << "Now enter spot to move to! " << std::endl;
				std::cout << "Enter Row: ";
				std::cin >> moveRow;
				std::cout << "Enter Col to move: ";
				std::cin >> moveCol;
				moveRow--;
				moveCol--;

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
				std::cout << "WK Selected";
				validMove = whiteKingMoves(moveRow, moveCol, pieceRow, pieceCol, board);
			}
		}
	}

	void blackMove() {
		int pieceRow;
		int pieceCol;
		std::string piece;
		int moveRow;
		int moveCol;
		bool validPiece = false;
		bool validMove = false;

		while (!validPiece) {
			do {

				std::cout << "Black Players Turn!" << std::endl;
				std::cout << "Enter Row: ";
				std::cin >> pieceRow;
				std::cout << "Enter Colum: ";
				std::cin >> pieceCol;
				pieceRow--;
				pieceCol--;

			} while (pieceRow < 0 || pieceRow > 8 && pieceCol < 0 || pieceCol > 8);

			piece = board[pieceRow][pieceCol];

			if (piece[0] != 'B') {
				std::cout << "Not a valid piece! " << std::endl;
			}
			else {
				validPiece = true; 
			}
		}

		while (!validMove) {
			do {

				std::cout << "Now enter spot to move to! " << std::endl;
				std::cout << "Enter Row: ";
				std::cin >> moveRow;
				std::cout << "Enter Col to move: ";
				std::cin >> moveCol;
				moveRow--;
				moveCol--;

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

		bool inCheck = false;

		while (running) {

			drawBoard();
			inCheck = whiteCheck(board);
			if (inCheck) {
				while (inCheck) {
					whiteMove();
					inCheck = whiteCheck(board);

				}
			}
			else {
				whiteMove();
			}

			drawBoard();
			blackCheck(board);
			blackMove();
		}
	}

private:
	std::string board[9][9] = {{"Br", "Bk", "Bb", "BQ", "BK", "Bb", "Bk","Br", "1"},
								{"Bp", "Bp", "Bp", "Bp", "Bp", "Bp", "Bp","Bp", "2"},
								{"-", "-", "-", "BK", "-", "-", "-","-", "3"},
								{"-", "-", "-", "-", "Wb", "-", "-","-", "4"},
								{"-", "-", "-", "-", "-", "-", "-","-", "5"},
								{"-", "-", "-", "-", "-", "-", "-","-", "6"},
								{"Wp", "Wp", "Wp", "Wp", "Wp", "Wp", "Wp","Wp", "7"},
								{"Wr", "Wk", "Wb", "WQ", "WK", "Wb", "Wk","Wr", "8"},
								{" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", ""}};

	int boardSize = sizeof(board)/sizeof(char);
	bool running = true;
	bool wPlayerMove = true;
};