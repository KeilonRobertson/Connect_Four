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
    void player1_turn();
    void player2_turn();
    void checkwin(char tok, string name);

};
