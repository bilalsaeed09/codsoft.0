#include <iostream>
#include <vector>

using namespace std;



void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}


bool checkWin(const vector<vector<char>>& board, char player) {

    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }


    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}


int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {

        printBoard(board);


        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;


        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid move. Cell already occupied. Try again." << endl;
            continue;
        }


        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }


        if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }


        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
