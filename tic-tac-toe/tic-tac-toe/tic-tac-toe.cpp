// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void ShowTheBoard(string board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "\t" << board[i][j];
		cout << "\n";
	}
}

//mark turn player1 (mark X)
void PlayChessPlayer1(string location, string board[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (location.compare(board[i][j]) == 0) {
				board[i][j] = "X";
			}
	}
}
//mark turn player2 (mark Y)
void PlayChessPlayer2(string location, string board[3][3]) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (location.compare(board[i][j]) == 0) {
				board[i][j] = "O";
			}
	}
}
// win return -1 ; draw return 0
int checkwin(string board[3][3]) {
	// check win in a row
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])

		return 1;
	else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])

		return 1;
	else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])

		return 1;//true
	// check win in a collump
	else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])

		return 1;
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])

		return 1;
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])

		return 1;//true
	//check win in a diagonal
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])

		return 1;
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])

		return 1;
	//check draw
	else if (board[0][0] != "11" && board[0][1] != "12"  && board[0][2] != "13"
		&& board[1][0] != "21" && board[1][1] != "22" && board[1][2] != "23"
		&& board[2][0] != "31" && board[2][1] != "32" && board[2][2] != "33")
		return 0;
	else
		return -1;
	return 0;
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
	string  board[3][3] = { {"11","12","13"},{"21","22","23"},{"31","32","33"} };
	ShowTheBoard(board);
	do
	{
		
		player = (player % 2) ? 1 : 2;
		if (player == 1) {			
			do {
				cout << "Your Turn  " << namePlayer1 << ":";
				cin >> chess;
			} while (board[(int)chess[0]-'1'][(int)chess[1]-'1'] == "X" || board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "O"
				|| (int)chess[0] - '1'<0 || (int)chess[0] - '1' >=3 || (int)chess[1] - '1' <0 || (int)chess[1] - '1' >=3);
			
			PlayChessPlayer1(chess, board);
			ShowTheBoard(board);
			player++;
			checkWin = checkwin(board);
			if (checkWin == 1 || checkWin ==0) break;
		}
		if (player == 2)
		{
			
			do {
				cout << "Your Turn  " << namePlayer2 << ":";
				cin >> chess;
			} while (board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "X" || board[(int)chess[0] - '1'][(int)chess[1] - '1'] == "O"
				|| (int)chess[0] - '1' < 0 || (int)chess[0] - '1' >= 3 || (int)chess[1] - '1' < 0 || (int)chess[1] - '1' >= 3);
			PlayChessPlayer2(chess, board);
			ShowTheBoard(board);
			player--;
		}
		checkWin = checkwin(board);
	} while (checkWin == -1);
	if (checkWin ==1)
	{
		if (player == 1) {
			cout << "player "<<namePlayer2 <<" win";
		}
		else
		{
			cout << "player " << namePlayer1 << " win";
		}
	}
	if (checkWin==0)
	{
		cout << "draw";
	}
		
	
}

