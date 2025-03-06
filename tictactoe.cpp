#include <iostream>

using namespace std;

void printBoard(string board[3][3], int rows, int cols);

int main()
{

    string board [3][3] = {
        {"*", "*", "*"},
        {"*", "*", "*"},
        {"*", "*", "*"}
    };


    int playerRow = 0;
    int playerCol = 0;
    bool gameOver = false;
    bool winX = false;
    bool winY = false;
    bool isDraw = false;

    do{

        // print the board
        printBoard(board, 3, 3);

        // player x goes
        cout << "Player X enter row: " << endl;
        cin >> playerRow;
        cout << "Player X enter col: " << endl;
        cin >> playerCol;
        board[playerRow][playerCol] = "X";

        //  player o goes
        cout << "Player O enter row: " << endl;
        cin >> playerRow;
        cout << "Player O enter col: " << endl;
        cin >> playerCol;
        board[playerRow][playerCol] = "O";

        // check if winner from rows
        for (int row = 0; row < 3; row++)
        {
            if (board[row][0] != "*")
            {
                if (board[row][0] == board[row][1])
                {
                    // somebody won
                    if (board[row][1] == board[row][2])
                    {
                        if (board[row][0] == "X")
                        {
                            winX = true;
                        }
                        else
                        {
                            winY = true;
                        }
                    }
                }
            }
        }

        // check if winner by cols
        for(int col = 0; col < 3; col++)
        {
            if (board[0][col] != "*")
            {
                if (board[0][col] == board[1][col])
                {
                    if (board[1][col] == board[2][col])
                    {
                        if (board[0][col] == "X")
                        {
                            winX = true;
                        }
                        else
                        {
                            winY = true;
                        }
                    }
                }
            }
    
        }

        // check for diagonals
        if (board[0][0] != "*" && board[1][1] == board[0][0] && board[2][2] == board[1][1])
        {
            if (board[0][0] == "X")
            {
                winX = true;
            }
            else
            {
                winY = true;
            }
        }

        if (board[0][2] != "*" && board[1][1] == board[0][2] && board[2][0] == board[1][1])
        {
            if (board[0][2] == "X")
            {
                winX = true;
            }
            else
            {
                winY = true;
            }
        }

        // check for draw
        if (winX == false || winY == false)
        {
            bool unusedSpace = false;
            for (int row = 0; row < 2; row++)
            {
                for (int col = 0; col < 2; col++)
                {
                    if (board[row][col] == "*")
                    {
                        unusedSpace = true;
                    }
                }
            }

            if (unusedSpace == false)
            {
                isDraw = true;
            }
        }

    } while (winX == false && winY == false && isDraw == false);


    cout << endl;
    printBoard(board, 3, 3);
    cout << endl;

    if (isDraw)
    {
        cout << "The game is a draw!" << endl;
    }
    else if (winX)
    {
        cout << "The X Player wins!" << endl;
    }
    else
    {
        cout << "The O Player wins!" << endl;
    }

    return 0;
}

void printBoard(string board[3][3], int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << board[i][j] << " ";
            if (j == cols-1)
            {
                cout << endl;
            }
        }
    }
    cout << endl;
}