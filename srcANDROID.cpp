#include <iostream>
#include <vector>
using namespace std;
class XO
{
    public:
    vector<string> value = {" "," "," "," "," "," "," "," "," "};
    int player = 1;
    bool end = false;
    const string delimiter = "  -------------------      \n";

    void init()
    {
        system("clear");//clear screen
        for (int i = 0; i<9; i+=3)
        {
        cout <<"    "<< value[i]<< "  #  "<<value[i+1]<<"  #  "<<value[i+2]<< endl;
        if (i<7)
        {
            cout << delimiter;
        }
        }
        if (!end)
        {
            check();
        }
        else
        {
            cout << "PLAYER 1 = X\nPLAYER 2 = 0" << endl;
            cout << "PLAYER "<<player<<" WIN!"<<endl;
            system("pause");
        }
    }
    void move()
    {
        string tmp;
        int i;
        cin >> tmp;
        i = stoi(tmp);
        int used = isPosUsed(i);
        if (!(used))
        {
        if (player == 1)
        {
            value[i-1] = "X";
            player++;
        }
        else
        {
            value[i-1] = "0";
            player--;
        }
        init();
        }
        else 
        {
            cout <<endl<< "This position already used!" << endl;
            move();
        }
    }
    int isPosUsed(int pos)
    {
        if (value[pos-1] != " ")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void check()
    {
        for (int i = 0; i<3; i++)
        {
            if (value[i*3] == value[i*3+1] && value[i*3+1] == value[i*3+2] && value[i*3] != " ")
            {
                end = true;
            }
            else if (value[i] == value[i+3] && value[i+3] == value[i+6] && value[i] != " ")
            {
                end = true;
            }
            else if ((value[2] == value[4] && value[4] == value[6] && value[2] != " ") || (value[0] == value[4] && value[4] == value[8] && value[0] != " "))
            {
                end = true;
            }
        }
        if (end)
        {
        if (player==1)
        {
            player++;
        }
        else
        {
            player--;
        }
            init();
        }
        else
        {
            move();
        }
    }

};
int main()
{
    XO x;
    x.init();
    return 0;
}