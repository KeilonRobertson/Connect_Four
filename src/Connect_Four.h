//This is the header file for Connect Four
#include <iostream>
#include <windows.h>

using namespace std;

const int ASIZE = 6 ;


class Connect_Four{
public:

    Connect_Four();

    void play();
    void displayBoard();
    void gameWon(string nm);
    void player1_turn();
    void player2_turn();

    void verticalCheck(char tok, string name);
    void horizontalCheck(char tok, string name);

    void diagonalCheck_NW_SE(char tok, string name);
    void diagonalCheck_NE_SW(char tok, string name);
};
