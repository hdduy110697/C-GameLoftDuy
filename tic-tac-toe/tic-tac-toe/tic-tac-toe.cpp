// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

#define SIZE_BOARD 9
#define MARK_WIN 3

void ShowTheBoard(string board[SIZE_BOARD][SIZE_BOARD])
{
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
			cout << "\t" << board[i][j];
		cout << "\n";
	}
}

//mark turn player1 (mark X)
void PlayChessPlayer(string location, string board[SIZE_BOARD][SIZE_BOARD], int Player) {
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
			if (location.compare(board[i][j]) == 0) {
				if (Player == 1)
				{
					board[i][j] = "X";
				}
				else
				{
					board[i][j] = "O";
				}

			}
	}
}

bool CheckWinhorizontal(string location, string board[SIZE_BOARD][SIZE_BOARD], int player) {
	string mark = "";

	if (player == 1)
	{
		mark = "X";
	}
	else
	{
		mark = "O";
	}
	int posY = (int)location[0] - '1';
	int posX = (int)location[1] - '1';
	int countLeft = 0;
	int countRight = 0;
	//count left
	for (int i = posX; i >= 0; i--)
	{
		if (board[posY][i] == mark)
		{
			countLeft++;
		}
		else
		{
			break;
		}
	}
	//count Right
	for (int i = posX + 1; i < SIZE_BOARD; i++)
	{
		if (board[posY][i] == mark)
		{
			countRight++;
		}
		else
		{
			break;
		}
	}
	bool result = countLeft + countRight == MARK_WIN;
	return result;
}
bool CheckWinColumn(string location, string board[SIZE_BOARD][SIZE_BOARD], int player) {
	string mark = "";

	if (player == 1)
	{
		mark = "X";
	}
	else
	{
		mark = "O";
	}
	int posY = (int)location[0] - '1';
	cout << posY << endl;
	int posX = (int)location[1] - '1';
	cout << posX << endl;
	int countUp = 0;
	int countDown = 0;
	for (int i = posY; i >= 0; i--)
	{
		if (board[i][posX] == mark)
		{
			countUp++;
		}
		else
		{
			break;
		}
	}
	for (int i = posY + 1; i < SIZE_BOARD; i++)
	{

		if (board[i][posX] == mark)
		{
			countDown++;
		}
		else
		{
			break;
		}
	}
	return countUp + countDown == MARK_WIN;
}
bool CheckWinPriDiagonal(string location, string board[SIZE_BOARD][SIZE_BOARD], int player) {
	string mark = "";

	if (player == 1)
	{
		mark = "X";
	}
	else
	{
		mark = "O";
	}
	int posY = (int)location[0] - '1';
	cout << posY << endl;
	int posX = (int)location[1] - '1';
	cout << posX << endl;
	int countUp = 0;
	int countDown = 0;


	for (int i = 0; i < 100; i++)
	{
		if (posX + i > SIZE_BOARD || posY + i > SIZE_BOARD)
		{
			break;
		}
		else
		{
			if (board[posY + i][posX + i] == mark)
			{
				countUp++;
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 1; i < 25; i++)
	{
		if (posX - i < 0 || posY - i < 0)
		{
			break;
		}
		else
		{
			if (board[posY - i][posX - i] == mark)
			{
				countDown++;
			}
			else
			{
				break;
			}
		}
	}
	return countUp + countDown == MARK_WIN;
}
int CheckWin(string board[SIZE_BOARD][SIZE_BOARD], string location, int player) {
	cout << "ham check in:" << location << endl;
	if (CheckWinhorizontal(location, board, player) == true || CheckWinColumn(location, board, player) == true || CheckWinPriDiagonal(location, board, player) == true)
	{
		return 1;
	}
	return -1;
}
int main()
{

	cout << "Welcome To Tic-tac-toe game! Play with your way!\n";
	cout << "If you find any problem, please contact john.nguyen@gameloft.com";
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):" << endl;
	int player = 1;
	int checkWin = -1;
	int mode = 0;
	cin >> mode;
	string namePlayer1;
	string namePlayer2;

	if (mode == 1) {
		cout << "Enter Player 1 Name:";
		cin >> namePlayer1;
		cout << "Enter Player 2 Name:";
		cin >> namePlayer2;
	}
	else
	{
		return 0;
	}

	string chess = "";
	string  board[SIZE_BOARD][SIZE_BOARD];/* = { {"11","12","13"},{"21","22","23"},{"31","32","33"} };*/
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
		{
			board[i][j] = (char)(i + 1 + 48);
			board[i][j] += +(char)(j + 1 + 48);
		}
	}
	ShowTheBoard(board);
	do
	{
		if (player == 1) {
			do {
				cout << "Your Turn  " << namePlayer1 << ":";
				cin >> chess;
			} while (board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "X" || board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "O"
				|| (int)chess[0] - '1' < 0 || (int)chess[0] - '1' >= SIZE_BOARD || (int)chess[1] - '1' < 0 || (int)chess[1] - '1' >= SIZE_BOARD);

			PlayChessPlayer(chess, board, player);
			ShowTheBoard(board);
			checkWin = CheckWin(board, chess, player);
			player++;
			cout << checkWin;
			if (checkWin == 1 || checkWin == 0) break;
		}
		if (player == 2)
		{

			do {
				cout << "Your Turn  " << namePlayer2 << ":";
				cin >> chess;
			} while (board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "X" || board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "O"
				|| (int)chess[0] - '1' < 0 || (int)chess[0] - '1' >= SIZE_BOARD || (int)chess[1] - '1' < 0 || (int)chess[1] - '1' >= SIZE_BOARD);
			PlayChessPlayer(chess, board, player);
			ShowTheBoard(board);
			checkWin = CheckWin(board, chess, player);
			cout << checkWin;
			player--;
			if (checkWin == 1 || checkWin == 0) break;
		}
	} while (checkWin == -1);
	//show player win
	if (checkWin == 1)
	{
		if (player == 1) {
			cout << "player " << namePlayer2 << " win";
		}
		else
		{
			cout << "player " << namePlayer1 << " win";
		}
	}
	if (checkWin == 0)
	{
		cout << "draw";
	}


}

