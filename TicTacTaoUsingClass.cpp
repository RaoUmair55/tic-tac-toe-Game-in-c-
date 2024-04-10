#include <iostream>

using namespace std;

class TicTacToe {
	private:
		char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
		char currentPlayer;
		string player1, player2;

	public:
		TicTacToe(string p1, string p2) : player1(p1), player2(p2), currentPlayer('x') {}

		void printBoard() {
			cout << "   |   |   \n";
			for (int i = 0; i < 3; ++i) {
				cout << " " << space[i][0] << " | " << space[i][1] << " | " << space[i][2] << " \n";
				cout << "___|___|___\n";
			}
			cout << "   |   |   \n";
		}

		bool placeMarker(int digit) {
			int row = (digit - 1) / 3;
			int col = (digit - 1) % 3;

			if (space[row][col] == 'x' || space[row][col] == '0') {
				cout << "This space is already occupied. Please choose another one.\n";
				return false;
			}

			space[row][col] = currentPlayer;
			return true;
		}

		bool checkWin() {
			for (int i = 0; i < 3; ++i) {
				if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
				        (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
					return true;
			}

			if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
			        (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
				return true;

			return false;
		}

		bool checkTie() {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (space[i][j] != 'x' && space[i][j] != '0')
						return false;
				}
			}
			return true;
		}

		void switchPlayer() {
			currentPlayer = (currentPlayer == 'x') ? '0' : 'x';
		}

		void play() {
			int move;
			cout << player1 << " is player 1, he will play as 'x'.\n";
			cout << player2 << " is player 2, he will play as '0'.\n";

			printBoard();

			while (!checkWin() && !checkTie()) {
				int move;
				string currentPlayerName = (currentPlayer == 'x') ? player1 : player2;

				cout << currentPlayerName << ", please enter your move (1-9): ";
				cin >> move;

				if (move < 1 || move > 9) {
					cout << "Invalid input! Please enter a number between 1 and 9.\n";
					continue;
				}

				if (placeMarker(move)) {
					printBoard();
					if (checkWin()) {
						cout << currentPlayerName << " wins!\n";
						break;
					} else if (checkTie()) {
						cout << "It's a tie!\n";
						break;
					} else {
						switchPlayer();
					}
				}
			}
		}
};

int main() {
	string name1, name2;
	cout << "Enter the name of the first player: ";
	cin >> name1;
	cout << "Enter the name of the second player: ";
	cin >> name2;

	TicTacToe game(name1, name2);
	game.play();

	return 0;
}
