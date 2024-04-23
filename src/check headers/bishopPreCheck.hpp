#include <iostream>
#include <vector>


bool whiteBishopPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	std::vector<int> bishopRows;
	std::vector<int> bishopCol;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == "Bb") {
				bishopRows.push_back(i);
				bishopCol.push_back(j);
			}
		}
	}

	return true;

}

bool blackBishopPreCheck(int kingRow, int kingCol, std::string board[][9]) {

	return true;
}