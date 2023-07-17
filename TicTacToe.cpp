#include <iostream>
#include <string>
#include <stdlib.h>

#include "Board.cpp"
#include "Player.cpp"

using namespace std;

class TicTacToe
{
    private:
    Board board;
    Player player1;
    Player player2;

    public:
    TicTacToe() : player1('X', true, board), player2('O',false, board)
    {
        // there is nothing to fill here 
    }

    void runGame()
    {   
        cout << "The game begins!\nHere is the board!!!\n"  ;
        this->board.displayBoard();
        
        while(isGameOver() == false)
        {
            if(this->player1.getActive() == true)
            {
                cout << "This is X move" << endl;
                this->player1.move();
                this->player1.changeActive();
                this->player2.changeActive();
            }
            else
            {
                cout << "This is O move" << endl;
                this->player2.move();
                this->player1.changeActive();
                this->player2.changeActive();
            }
            this->board.displayBoard();
        }
    }

    private:
    bool isGameOver()
    {
        if(this->board.checkWinner())
            return true;
        else if(this->board.isDraw())
            return true;
        else
            return false;
    }
};