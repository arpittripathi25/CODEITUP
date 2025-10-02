#include <iostream>
using namespace std;

char board[3][3];

// Reset board with 1–9 numbers
void resetBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
}

// Display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check for winner
bool checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

// Check if all cells are filled
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char current = 'X';
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        resetBoard();
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            int move;
            cout << "Player " << current << " enter position (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Invalid input! Try again.\n";
                continue;
            }

            int r = (move - 1) / 3;
            int c = (move - 1) % 3;

            if (board[r][c] == 'X' || board[r][c] == 'O') {
                cout << "That cell is already taken! Try again.\n";
                continue;
            }

            board[r][c] = current;

            if (checkWin(current)) {
                displayBoard();
                cout << "Player " << current << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                current = (current == 'X') ? 'O' : 'X'; // switch player
            }
        }

        cout << "Play again? (y/n): ";
        cin >> again;
    }

    cout << "Thanks for playing!\n";
    return 0;
}
