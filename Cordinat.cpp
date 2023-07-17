#include <iostream>
#include <string>

using namespace std;

class Cordinat
{
    private:
    int col;
    int row;

    public:
    Cordinat(int r, int c)
    {
        this->row = r-1;  // (-1) so the users inputs are from 1 to 3(inclusive) NOT 0 to 2 (inclusive)
        this->col = c-1;
    }

    int getRow()
    {
        return this->row;
    }

    int getCol()
    {
        return this->col;
    }

    bool isValid()
    {
        if(this->row > 3 || this->row < 0 || this->col > 3 || this->col < 0)
        {
            cout << "You have entered wrong cordinats, try again!!!" << endl;
            return false;
        }
        else
            return true;
    }
};


