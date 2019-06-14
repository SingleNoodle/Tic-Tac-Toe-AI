#include <iostream>

using namespace std;

class TicTac
{
public:

    char board[3][3] = {{'-', '-', '-'},{'-', '-', '-'},{'-', '-', '-'}};
    char winner;
    char player;
    int isfull = 3;
    int turn = 0;
    int opponent;
    int AI;
    int spot = 0;
    int xplace;
    int yplace;
    int x;
    int y;



    int CheckWin();
    int filled(int, int);
    void display();
    void Checkfull();
    void FindSpotAI();
    void GenerateTree();
    int fillBoard();
    int Win ();
    void IntializeBoard();
    void place();
    int OX();
};


int TicTac::OX()
 {
     if(player == 'X')
     {
         AI = 'O';
     }
     else
     {
         AI = 'X';
     }
 }

void TicTac::place()
 {
     if(board[xplace][yplace] == '-')
     {
         board[xplace][yplace] = player;
     }

 }


int TicTac::Win()
{

 if(player != winner)
    {
        cout << "Lose" << endl;
    }
    else
    {
        cout << "Win" << endl;
    }
    cout << winner << " Wins" << endl;
    return 0;
}

int TicTac::filled(int x, int y)
{
    if(board[x][y] == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
    //check x
    for(x=0; x<3; x++)
    {
        if(board[x][0] == board[x][1] && board[x][1] == board[x][2])
        {
            if(board[x][0] == AI)
                return +10;
            else if(board[x][0] == player)
                return -10;
        }

    }


    //The following is a test to see if I can find best possible outcomes earlier
    //check y
    for(y=0; y<3; y++)
    {
        if(board[0][y] == board[1][y] && board[1][y] == board[2][y])
        {
            if(board[0][y] == AI)
                return +10;
            else if(board[0][y] == player)
                return -10;
        }
    }

    if(board[0][0]==board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == AI)
            return +10;
        else if(board[0][0] == player)
            return -10;
    }
    if(board[0][2]==board[1][1] && board[1][1] == board[2][0])
    {
        if(board[0][2] == AI)
            return +10;
        else if (board[0][2] == player)
            return -10;
    }
    //if no one there
    return 0;

}
int TicTac::fillBoard()
{
    int x, y;
    //int best x;
    //int best y;
    //int bestmove;

    if(winner != '-')
    {
            if(winner == player)
            {
                return 10;
            }
            else if(winner == opponent)
            {
                return -10;
            }
            else
            {
                return 0;
            }
    }

    for(x = 0; x < 3; x++)
    {
        for(y = 0; y< 3; y++)
        {
            if(board[x][y] == '-')
            {
                board[x][y] = turn;
                if (turn == 'x')
                {
                    turn = '0';
                    GenerateTree();
                    return board[x][y] = 'x';
                }
                else
                {
                    turn = 'x';
                    GenerateTree();
                    return board[x][y] = '0';
                }

            }
        }
    }
}

void TicTac::display()
{
    cout << board [0][0];
    cout << board [0][1];
    cout << board [0][2];
    cout << endl;
    cout << board [1][0];
    cout << board [1][1];
    cout << board [1][2];
    cout << endl;
    cout << board [2][0];
    cout << board [2][1];
    cout << board [2][2];
    cout << endl;
}

void TicTac::Checkfull()
{
    int x = 0;
    int y = 0;

    for(x=0; x<3; x++)
    {
        for(y=0; y<3; y++)
        {
            if(board[x][y] == '-')
            {
                cout << "board not full" << endl;
                return;
            }
        }
    }
    cout << "board is full" << endl;
    return;
}

int TicTac::CheckWin()
{
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) //top
    {
        winner = board[0][0];
    }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) //middle
    {
        winner = board[0][1];
    }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) //bottom
    {
        winner = board[0][2];
    }
    else if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) //left
    {
        winner = board[0][0];
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) //middle-down
    {
        winner = board[1][0];
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) //right
    {
        winner = board[2][0];

    }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) //
    {
        winner = board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        winner = board[0][2];
    }
}
/*
void TicTac::FindSpotAI()
{
    turn =0;

    if(turn < 9)
    {
        return;
    }
    else
    {
        return GenerateTree(board, turn-1)
    }

}
*/

void TicTac::GenerateTree()
{
        for (x=0;x>3;x++)
        {
            for (y=0;y>3;y++)
            {
                if(board[x][y] == '-')
                {
                    board[x][y] = turn;

                    if(turn == 'X')
                    {
                        turn = '0';
                    }
                    else
                    {
                        turn = 'x';
                    }
                }
            }
        }
}



int main()
{
    TicTac player;

    cout << "Choose either X, or O" << endl;
    cin >> player.player;

    cout << endl;

    cout << "Choose a x co-ordinate" << endl;
    cin >> player.xplace;

    cout << "Choose a y co-ordinate" << endl;
    cin >> player.yplace;

    player.place();

    player.GenerateTree();

    player.fillBoard();

    player.display();

    cout << endl;

    player.Checkfull();
    //cout << endl;
    /*
    if (isfull == 1)
    {
        cout << "board is full" << endl;
    }
    */

    player.CheckWin();

    player.Win();

}
