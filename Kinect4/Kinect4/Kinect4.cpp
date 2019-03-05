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
bool checkForColumnWin();
bool checkForRowWin();
bool checkForDiagonalRightWin();
bool checkForDiagonalLeftWin();

char const player1 = 'X';
char const player2 = 'O';
int const cols = 7;
int const rows = 6;
int const numberToWin = 4;
char grid[rows][cols];

int main()
{
	srand(time(NULL));
	// playerTurn will be 0 for player 1 and 1 for player 2
	int playerTurn = rand() % 2;
	cout << "Player " << playerTurn + 1 << " goes first" << endl;

	int selectedCol;
	while (true) {
		cout << "It's player " << playerTurn + 1 << "'s turn" << endl;
		cout << "Choose your destiny, ex(6)" << endl;
		cin >> selectedCol;
		
		for (int row = 0; row < rows - 1; row++) {
			if (grid[row + 1][selectedCol] == player1 
				|| grid[row + 1][selectedCol] == player2) {
				if (playerTurn) {
					grid[row][selectedCol] = player2;
				}
				else {
					grid[row][selectedCol] = player1;
				}
				cout << "Inserting into " << row << "," << selectedCol << endl;
				break;
			}
			if (row == rows - 2) {
				if (playerTurn) {
					grid[rows-1][selectedCol] = player2;
				}
				else {
					grid[rows-1][selectedCol] = player1;
				}
				cout << "Inserting into " << rows << "," << selectedCol << endl;
			}
		}

		displayGrid();

		if (checkForWinner()){
			cout << " WINNNNNNNNNNNNNNNNNNER " << endl;
			break;
		}
		
		playerTurn = !playerTurn;
	}

	system("pause");
	return 0;
}

void displayGrid()
{
	cout << endl << endl;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cout << grid[row][col] << " ";// << " (" << row << "," << col << ") ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

bool checkIfFull() {
	return false;
}

bool checkForWinner() {
	if (checkForColumnWin()) {
		return true;
	}
	if (checkForRowWin()) {
		return true;
	}
	if (checkForDiagonalRightWin()) {
		return true;
	}
	if (checkForDiagonalLeftWin()) {
		return true;
	}
	return false;
}

bool checkForColumnWin() {
	int inARowCount;
	for (int col = 0; col < cols; col++) {
		inARowCount = 0;
		for (int row = 0; row < rows - 1; row++) {
			if (grid[row][col] == grid[row + 1][col]
				&& (grid[row][col] == player1 || grid[row][col] == player2)) {
				inARowCount++;
			}
			else {
				inARowCount = 0;
			}
			if (inARowCount == numberToWin - 1) {
				return true;
			}
		}
	}
	return false;
}

bool checkForRowWin() {
	int inARowCount;
	for (int row = 0; row < rows; row++) {
		inARowCount = 0;
		for (int col = 0; col < cols - 1; col++) {
			if (grid[row][col] == grid[row][col + 1]
				&& (grid[row][col] == player1 || grid[row][col] == player2)) {
				inARowCount++;
			}
			else {
				inARowCount = 0;
			}
			if (inARowCount == numberToWin - 1) {
				return true;
			}
		}
	}
	return false;
}

bool checkForDiagonalRightWin() {
	int inARowCount;
	for (int col = 0; col < cols - numberToWin + 1; col++) {
		inARowCount = 0;
		for (int diag = 0; diag < rows - 1; diag++) {
			if (grid[diag][diag+col] == grid[diag+1][diag + col + 1]
				&& (grid[diag][diag + col] == player1 || grid[diag][diag + col] == player2)) {
				inARowCount++;
			}
			else {
				inARowCount = 0;
			}
			if (inARowCount == numberToWin - 1) {
				return true;
			}
		}
	}

	for (int row = 0; row < rows - numberToWin + 1; row++) {
		inARowCount = 0;
		for (int diag = 0; diag < cols - 1; diag++) {
			if (grid[diag + row][diag] == grid[diag + row + 1][diag + 1]
				&& (grid[diag + row][diag] == player1 || grid[diag + row][diag] == player2)) {
				inARowCount++;
			}
			else {
				inARowCount = 0;
			}
			if (inARowCount == numberToWin - 1) {
				return true;
			}
		}
	}

	return false;
}

bool checkForDiagonalLeftWin() {
	int inARowCount;
	for (int col = 0; col < cols - numberToWin + 1; col++) {
		inARowCount = 0;
		for (int diag = 0; diag < rows - 1; diag++) {
			if (grid[diag][rows - diag] == grid[diag + 1][rows - diag - 1]
				&& (grid[diag][rows - diag] == player1 || grid[diag][rows - diag] == player2)) {
				inARowCount++;
			}
			else {
				inARowCount = 0;
			}
			if (inARowCount == numberToWin - 1) {
				return true;
			}
		}
	}

	for (int row = rows - 1; row > numberToWin - 1; row--) {
		inARowCount = 0;
		for (int diag = 0; diag < cols - 1; diag++) {
			if (grid[row - diag][diag] == grid[row - diag - 1][diag + 1]
				&& (grid[row - diag][diag] == player1 || grid[row - diag][diag] == player2)) {
				inARowCount++;
			}
			else {
				inARowCount = 0;
			}
			if (inARowCount == numberToWin - 1) {
				return true;
			}
		}
	}

	return false;
}
