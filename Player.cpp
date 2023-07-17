#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

class Player
{
    private:
    char sign;
    bool active;

    Board& board;
    
    public:
    Player(char sign, bool active, Board& b) : board(b) 
    {
        this->sign = sign;
        this->active = active;
    }

    void move()
    {
        int input;
        Cordinat* cord;
        do{
            cout << "Enter row and column: " << endl;
            cin >> input;
            cord = new Cordinat(input/10,input%10);

        }while(cord->isValid() == false || this->board.isAvailable(*cord) == false);
    
        board.updateBoard(*cord,this->sign);
    }

    bool getActive()
    {
        return this->active;
    }

    void changeActive()
    {
        if(this->active == true)
            this->active = false;
        else
            this->active = true;
    }
};