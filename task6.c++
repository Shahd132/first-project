//Author:Shahd Abdelalim Qorani Gomaa    ID:20231086      Section does not be recorded untill now     Date:29/2/2024
//Programe:Tic Tac Toe
// Description: This program implements a simple two-player Tic Tac Toe game where players take turns making moves on a 3x3 board.
//              The game checks for win conditions based on rows, columns, and diagonals. Players are restricted to making valid
//              moves, and the program displays the board after each move. The game continues until the board is not full.n
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
int board[3][3];
// Function to initialize the Tic Tac Toe board with -1 
void Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            board[i][j] = -1;
    }
}
// Function to display the current state of the Tic Tac Toe board
void make_board() {
    system("cls");
    cout << "Tic Tac Toe\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool rules() {
    //check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != -1 && board[i][0] + board[i][1] + board[i][2] == 15)
            return true;
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != -1 && board[0][j] + board[1][j] + board[2][j] == 15)
            return true;
    }
    // check diagonals
    if (board[0][0] != -1 && board[0][0] + board[1][1] + board[2][2] == 15) {
        return true;
    }
    if (board[0][2] != -1 && board[0][2] + board[1][1] + board[2][0] == 15) {
        return true;
    }
    // check if board full
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (board[i][j] == -1)
                return false;
    }
    //this return when draw
    return true;
}
string check_winner() {
    //this function be called when only function rules return true then this function return the winner 
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != -1 && board[i][0] + board[i][1] + board[i][2] == 15) {
            return"There is awinner";

        }
    }
    // columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != -1 && board[0][j] + board[1][j] + board[2][j] == 15) {
            return "There is a winner";
        }
    }
    // diagonals
    if (board[0][0] != -1 && board[0][0] + board[1][1] + board[2][2] == 15) {
        return "There is awinner";
    }
    if (board[0][2] != -1 && board[0][2] + board[1][1] + board[2][0] == 15) {
        return "There is a winner";
    }
    // return It's a draw when only there is no winner
    return "It's a draw";
}
void makemove(int position, int num) {
    //this function update the board with player's move if the position is not alreadey taken
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] == -1)
        board[row][col] = num;
    else {
        cout << "This position already taken,try again:";
        cin >> position;
        makemove(position, num);
    }
}
int main() {
    int turn = 1;
    int  position, x, move;
    string  currentplayer;
    Board();
    // Vectors to store available odd and even numbers for moves
    vector<int>odd_num = { 1,3,7,9,5 };
    vector<int>even_num = { 0,2,4,6,8 };
    // Game loop continues until there is a winner or a draw
    while (!rules()) {
        make_board();
        if (turn % 2 != 0) {
            // Determine the current player based on the turn
            currentplayer = "Player1";
        }
        else {
            currentplayer = "Player2";
        }
        cout << currentplayer << " should insert the position the first row its positions is(1:3) the second(4:6) the third(7:9) ";
        cin >> position;
        // Validate the position input
        if (position > 9 || position <= 0) {
            while (true) {
                cout << "Invalid move,try again:";
                cin >> position;
                if (position <= 9 && position > 0)
                    break;
            }
        }
        cout << "Now you should insert your move:";
    x:
        cin >> move;
        if (currentplayer == "Player1") {
            // check the validity of the move to check it is an odd number
            if (move % 2 == 0 || move > 9) {
                cout << "invalid move,try again";
                goto x;
            }
            //check if the move is in the odd number in the vector
            auto it = find(odd_num.begin(), odd_num.end(), move);
            if (it != odd_num.end())
                // Update available odd numbers vector
                odd_num.erase(it);
            else {
                cout << "This number already taked,try again\n";
                goto x;

            }
        }
        if (currentplayer == "Player2") {
            // check the validity of the move to check it is an odd number
            if (move % 2 != 0 || move > 8) {
                cout << "invalid move,try again\n";
                goto x;
            }
            //check if the move is in the even number in the vector
            auto it = find(even_num.begin(), even_num.end(), move);
            if (it != even_num.end())
                // Update available odd numbers vector
                even_num.erase(it);
            else {
                cout << "This number already taked,try again\n";
                goto x;
            }
        }
        makemove(position, move);
        // Increment the turn count 
        turn++;
        make_board();
        // Check for a winner or draw after each move
        if (rules()) {
            string winner = check_winner();
            if (winner == "It's a draw")
                cout << "It's a draw\n";
            else {
                if (move % 2 == 0) {
                    cout << "Player2 is the winner";
                }
                else
                    cout << "Player1 is the winner";
            }
        }
    }
    return 0;
}