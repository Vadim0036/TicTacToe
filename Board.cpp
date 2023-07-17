#include <iostream>
#include <string>
#include <stdlib.h>

#include "Cordinat.cpp"

using namespace std;

class Board
{
    private:
    char board[3][3];
    int count;

    public:
    Board()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j <3; j++)
            {
                this->board[i][j] = '-';
            }
        }
        this->count = 0;
    }

    bool checkWinner()
    {
        // cheking winner by rows 
        for(int row = 0; row < 3; row ++)
        {
            if(this->board[row][0] == 'X' && this->board[row][1] == 'X' && this->board[row][2] == 'X')
            {
                cout << "X won this game!!! Nice!!!" << endl;
                return true;
            }
            else if(this->board[row][0] == 'O' && this->board[row][1] == 'O' && this->board[row][2] == 'O')
            {
                cout << "O won this game!!! Nice!!!" << endl;
                return true;
            }
        }
        //checking winner by columns
        for(int col = 0; col < 3; col++)
        {
            if(this->board[0][col] == 'X' && this->board[1][col] == 'X' && this->board[2][col] == 'X')
            {
                cout << "X won this game!!! Nice!!!" << endl;
                return true;
            }
            else if(this->board[0][col] == 'O' && this->board[1][col] == 'O' && this->board[2][col] == 'O')
            {
                cout << "O won this game!!! Nice!!!" << endl;
                return true;
            }
        }
        // cheking winner by diagonals
        if((this->board[0][0] == 'X' && this->board[1][1] == 'X' && this->board[2][2] == 'X') || (this->board[0][2] == 'X' && this->board[1][1] == 'X' && this->board[2][0] == 'X'))
        {
            cout << "X won this game!!! Nice!!!" << endl;
            return true;
        }
        else if((this->board[0][0] == 'O' && this->board[1][1] == 'O' && this->board[2][2] == 'O') || (this->board[0][2] == 'O' && this->board[1][1] == 'O' && this->board[2][0] == 'O'))
        {
            cout << "O won this game!!! Nice!!!" << endl;
            return true;
        }
        return false;
    }

    bool isDraw()
    {
        if(count < 9)
            return false;
        else 
        {
            cout << "This is draw!!!" << endl;
            return true;
        }
    }

    void updateBoard(Cordinat cor, char sign)
    {
        int row = cor.getRow();
        int col = cor.getCol();

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == row && j == col)
                {
                    this->board[i][j] = sign;
                }
            }
        }
        this->count++;
    }

    void displayBoard()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << "     " << board[i][j];
                if(j == 2)
                    cout << endl;
            }
        }
    }

    bool isAvailable(Cordinat cord)
    {
        int row = cord.getRow();
        int col = cord.getCol();

        if(this->board[row][col] == 'X' || this->board[row][col] == 'O')
        {
            cout << "This spot is already occupied!!! Try again!!!" << endl;
            return false;
        }
        else 
            return true;
    }
};