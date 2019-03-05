// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

void displayGrid();
bool checkIfFull();
bool checkForWinner();

char const player1 = 'X';
char const player2 = 'O';
char grid[3][3];

int main()
{
	srand(time(NULL));
	// playerTurn will be 0 for player 1 and 1 for player 2
	int playerTurn = rand() % 2;
	cout << "Player " << playerTurn + 1 << " goes first" << endl;
	
	int x, y;
	while (true) {
		cout << "It's player " << playerTurn + 1 << "'s turn" << endl;
		cout << "Choose your coordinates, ex(1 2)" << endl;
		cin >> x >> y;

		if (x == 1337 || y == 1337) {
			cout << "L8r" << endl;
			exit(1);
		}
		if (x < 0 || y < 0 || x > 2 || y > 2) {
			cout << "Tic-Tac-NO!!! That's out of bounds." << endl;
			continue;
		}
		if (grid[x][y] == 'X' || grid[x][y] == 'O') {
			cout << "Seats taken brah." << endl;
			continue;
		}

		// put choice in grid
		if (playerTurn) {
			grid[x][y] = player2;
		}
		else {
			grid[x][y] = player1;
		}
			
		displayGrid();

		if (checkForWinner()) {
			cout << "Player " << playerTurn + 1 << " wins!!!!!!!!!!!!" << endl;
			break;
		}

		if (checkIfFull()) {
			cout << "I'm full ~(x.x)~" << endl;
			break;
		}
		playerTurn = !playerTurn;
	}

	system("pause");
    return 0;
}

void displayGrid()
{
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool checkIfFull() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (grid[i][j] != player1 && grid[i][j] != player2) {
				return false;
			}
		}
	}
	return true;
}

bool checkForWinner() {
	bool horizontalWin;
	for (int i = 0; i <= 2; i++) {
		horizontalWin = true;
		for (int j = 0; j < 2; j++) {
			horizontalWin = horizontalWin 
				&& (grid[i][j] == grid[i][j + 1])
				&& (grid[i][j] == player1 || grid[i][j] == player2);
		}
		if (horizontalWin) {
			return true;
		}
	}

	bool verticalWin;
	for (int j = 0; j <= 2; j++) {
		verticalWin = true;
		for (int i = 0; i < 2; i++) {
			verticalWin = verticalWin
				&& (grid[i][j] == grid[i + 1][j])
				&& (grid[i][j] == player1 || grid[i][j] == player2);
		}
		if (verticalWin) {
			return true;
		}
	}

	bool diagonalWin1 = true, diagonalWin2 = true;
	for (int i = 0; i < 2; i++) {
		diagonalWin1 = diagonalWin1
			&& (grid[i][i] == grid[i + 1][i + 1])
			&& (grid[i][i] == player1 || grid[i][i] == player2);
		diagonalWin2 = diagonalWin2
			&& (grid[2 - i][i] == grid[1 - i][i + 1])
			&& (grid[2 - i][i] == player1 || grid[2 - i][i] == player2);
	}
	if (diagonalWin1 || diagonalWin2) {
		return true;
	}

	return false;
}
