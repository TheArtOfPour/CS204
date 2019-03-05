// ttt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>

using namespace std;

int const boardSize = 3;

struct Move {
	int row; // 0 - 2
	int col; // 0 - 2
	char symbol; // X or O
};

class Board {
public:
	Board();
	void display();
	bool place(Move move);
	bool isFull();
	bool didWin();
private:
	char board[boardSize][boardSize];
};

char players[] = { 'X', 'O' };

int main()
{
	// build board
	Board myBoard;
	// choose who goes first
	srand(time(NULL));
	int turn = rand() % 2;
	Move move;
	// loop until game over or win
	do {
		// show the board
		myBoard.display();
		// get user input 
		cout << "It's " << players[turn] << "'s turn" << endl;
		cout << "Input a row and column (1 2): ";
		// generate a move
		move.symbol = players[turn];
		cin >> move.row >> move.col;
		// put the move on the board
		if (!myBoard.place(move)) {
			continue;
		}
		if (myBoard.didWin()) {
			myBoard.display();
			cout << endl << players[turn] << " a winner are you!\n";
			break;
		}
		if (myBoard.isFull()) {
			myBoard.display();
			cout << "\nDraw!\n";
			break;
		}
		turn = !turn;
	} while (true);

	system("pause");
	return 0;
}

Board::Board()
{
	for (int j = 0; j < boardSize; j++) {
		for (int i = 0; i < boardSize; i++) {
			board[i][j] = ' ';
		}
	}
}

void Board::display()
{
	cout << flush;
	system("CLS");
	// for board[i][j]
	// @todo : add labels around the board for the coordinates
	for (int j = 0; j < boardSize; j++) {
		for (int i = 0; i < boardSize; i++) {
			if (i == 0) {
				cout << " ";
			}
			cout << board[i][j];
			if (i < boardSize - 1) {
				cout << '|';
			}
		}
		cout << endl;
		if (j < boardSize - 1) {
			cout << "--+-+--" << endl;
		}
	}
}

bool Board::place(Move move)
{
	if (move.row > boardSize - 1 || move.col > boardSize - 1) {
		return false;
	}
	if (board[move.row][move.col] != ' ') {
		return false;
	}
	board[move.row][move.col] = move.symbol;
	return true;
}

bool Board::isFull()
{
	for (int j = 0; j < boardSize; j++) {
		for (int i = 0; i < boardSize; i++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

bool Board::didWin()
{
	char rowSymbol, colSymbol, diagSymbol, revDiagSymbol;
	bool rowWin, colWin, diagWin = true, revDiagWin = true;
	for (int i = 0; i < boardSize; i++) {
		rowWin = true;
		colWin = true;
		if (i == 0)
			colSymbol = board[i][0];
		for (int j = 0; j < boardSize; j++) {
			// check for rev diag win
			// @ todo : can we use sum of coords % for diagonal traversal
			if (i == 0 && j == boardSize - 1)
				revDiagSymbol = board[i][j];
			if (i + j == boardSize - 1 && (board[i][j] == ' ' || board[i][j] != revDiagSymbol))
				revDiagWin = false;

			// check for diag win
			if (i == 0 && j == 0)
				diagSymbol = board[i][j];
			if (i == j && (board[i][j] == ' ' || board[i][j] != diagSymbol))
				diagWin = false;

			// check for col win
			if (board[i][j] == ' ' || board[i][j] != colSymbol)
				colWin = false;

			// check for row win
			if (j == 0)
				rowSymbol = board[j][i];
			if (board[j][i] == ' ' || board[j][i] != rowSymbol)
				rowWin = false;
		}
		if (rowWin || colWin) {
			return true;
		}
	}
	return diagWin || revDiagWin;
}
