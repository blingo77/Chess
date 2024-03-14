#include <iostream>

class Chess {

public:
	bool running = true;

	Chess(){
		
	}

	void drawBoard() {

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				
				if (board[i][j] == "-") {
					std::cout << " " << board[i][j] << " ";
					continue;
				}

				std::cout << board[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	void whiteMove() {

		int pieceRow;
		int pieceCol;
		int moveRow;
		int moveCol;

		std::cout << "White Players Turn!" << std::endl;
		std::cout << "Enter Row: ";
		std::cin >> pieceRow;
		std::cout << "Enter Colum: ";
		std::cin >> pieceCol;
		std::cout << "Now enter spot to move to! " << std::endl;
		std:: cout << "Enter Row: ";
		std::cin >> moveRow;
		std::cout << "Enter Col to move: ";
		std::cin >> moveCol;

		board[moveRow][moveCol] = board[pieceRow][pieceCol];
		board[pieceRow][pieceCol] = "-";

	}
	void run() {

		drawBoard();
		if (wPlayerMove) {
			whiteMove();
		}
		drawBoard();
		
	}

private:
	std::string board[8][8] = {{"Br", "Bk", "Bb", "BQ", "BK", "Bb", "Bk","Br"},
								{"Bp", "Bp", "Bp", "Bp", "Bp", "Bp", "Bp","Bp"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"Wp", "Wp", "Wp", "Wp", "Wp", "Wp", "Wp","Wp"},
								{"Wr", "Wk", "Wb", "WQ", "WK", "Wb", "Wk","Wr"}};
	int boardSize = sizeof(board)/sizeof(char);
	bool wPlayerMove = true;
};