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


	}
	void run() {

		drawBoard();
		
		
	}

private:
	int rows = 8;
	int cols = 8;
	std::string board[8][8] = {{"Br", "Bk", "Bb", "BQ", "BK", "Bb", "Bk","Br"},
								{"Bp", "Bp", "Bp", "Bp", "Bp", "Bp", "Bp","Bp"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"-", "-", "-", "-", "-", "-", "-","-"},
								{"Wp", "Wp", "Wp", "Wp", "Wp", "Wp", "Wp","Wp"},
								{"Wr", "Wk", "Wb", "WQ", "WK", "Wb", "Wk","Wr"}};
	int boardSize = sizeof(board)/sizeof(char);
};