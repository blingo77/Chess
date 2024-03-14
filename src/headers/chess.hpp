#include <iostream>
#include <cctype>

#include "pawnMoves.hpp";

class Chess {

public:

	Chess(){
		
	}

	void drawBoard() {

		std::cout << '\n';

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == "-") {
					std::cout << " " << board[i][j] << " ";
					continue;
				}

				std::cout << board[i][j] << " ";
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
			} while (pieceRow < 1 || pieceRow > 8 && pieceCol < 1 || pieceCol > 8);
			


			piece = board[pieceRow][pieceCol];

			if (piece[0] != 'W') {
				std::cout << "Not a valid piece! " << std::endl;
			}
			else {
				validPiece = true;
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
			} while (moveRow < 1 || moveRow > 8 && moveCol < 1 || moveCol > 8);


			if (piece[1] == 'p') {
				validMove = whitePawnMove(moveRow , moveCol, pieceRow , pieceCol , board);
			}
			break;
		}


		board[moveRow][moveCol] = board[pieceRow][pieceCol];
		board[pieceRow][pieceCol] = "-";

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
			} while (pieceRow < 1 || pieceRow > 8 && pieceCol < 1 || pieceCol > 8);

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
			} while (moveRow < 1 || moveRow > 8 && moveCol < 1 || moveCol > 8);

			if (piece[1] == 'p') {
				validMove = blackPawnMove(moveRow, moveCol, pieceRow, pieceCol, board);
			}
		}

		board[moveRow][moveCol] = board[pieceRow][pieceCol];
		board[pieceRow][pieceCol] = "-";
	}
	void run() {

		while (running) {

			drawBoard();
			whiteMove();
			drawBoard();
			blackMove();

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
								{" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", ""}};

	int boardSize = sizeof(board)/sizeof(char);
	bool running = true;
	bool wPlayerMove = true;
};