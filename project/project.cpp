#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int choice;
int row, colume;
char turn = 'X';
bool draw = false;
bool game_over();
void display();
void play_turn();
int main()
{  
    while (!game_over())
    {
        display();
        play_turn();
    }
    display();
    if (turn == 'X' && draw == false)
    {
        cout << "Congratulations! Player 'O' Has Won The Game";
    }
    else if (turn == 'O' && draw == false)
    {
        cout << "Congratulations! Player 'X' Has Won The Game";
    }
    else
        cout << "Match Draw";
}
void display()
{   system("cls");
    cout << " _________________" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |" << endl;
    cout << "|_____|_____|_____|" << endl;
}
void play_turn()
{
    if (turn == 'X')
    {
        cout << "Player 1[x] Turn" << endl;
    }
    else if (turn == 'O')
    {
        cout << "Player 2[O] Turn" << endl;
    }
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        colume = 0;
        break;
    case 2:
        row = 0;
        colume = 1;
        break;
    case 3:
        row = 0;
        colume = 2;
        break;
    case 4:
        row = 1;
        colume = 0;
        break;
    case 5:
        row = 1;
        colume = 1;
        break;
    case 6:
        row = 1;
        colume = 2;
        break;
    case 7:
        row = 2;
        colume = 0;
        break;
    case 8:
        row = 2;
        colume = 1;
        break;
    case 9:
        row = 2;
        colume = 2;
        break;
    default:
        cout << "Invalid Move";
        play_turn();
    }
    if (turn == 'X' && board[row][colume] != 'X' && board[row][colume] != 'O')
    {
        board[row][colume] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][colume] != 'X' && board[row][colume] != 'O')
    {
        board[row][colume] = 'O';
        turn = 'X';
    }
}
bool game_over()
{
    for (int i = 0; i <= 2; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    }
    draw = true;
    return true;
}
