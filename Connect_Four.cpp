/*
    Program Name: Connect Four
    Purpose: Enjoy a game of Connect Four
    Programmer Name: Keilon Robertson
    Date Created: 22/12/17
*/
//This is the program file for Connect Four
#include <iostream>
#include <windows.h>
#include "Connect_Four.h"

using namespace std;

int main()
{
    system("title Connect Four Game") ;
    system("COLOR 0B");
    //Declaring The Variables
    char option = ' ';

    bool exitProg = false, gamewon = false;
    Connect_Four game;

    cout << "\nConnect Four Game by \nKetastix Studios" << endl ;

    cout << "\n\t----------------------"<< endl;

    while(!exitProg)
    {
        //start main loop
        cout << "\n\tCONNECT FOUR GAME";
        cout << "\n\tA. START" ;
        cout << "\n\tB. Help/How to Play" ;
        cout << "\n\tX. EXIT" << endl;
        cout << "\n Enter an option to continue, A, B or X" << endl;
        cin >> option ;
        system("pause") ;
        system("cls") ;

        switch(option)
        {
        //start switch option
        case 'A' :
        case 'a' :
            game.play();//function call
            break ;

        case 'B' :// This is the help menu
        case 'b' :
            cout << "\nThis is a two (2) player game which features a 6 x 6 grid layout. ";
            Sleep(1000);
            cout  <<"\nEach player enters their name, and chooses a symbol, letter, or number, to be used as their game token.";
            Sleep(1000);
            cout  <<"\nThe first player selects a column in which to drop their game token. ";
            Sleep(1000);
            cout <<"\nThe token drops to the lowest empty position in the selected column. ";
            Sleep(1000);
            cout <<"\nThe second player also selects a column in which to drop their game token.";
            Sleep(1000);
            cout <<"\nThe objective of the game is to connect 4 game tokens in a row, either horizontally, vertically, or diagonally. ";
            Sleep(1000);
            cout << "\nGame playing cycles between the two (2) players until someone wins the game, or the game draws.";
            Sleep(1000);
            cout<<"\nEach player also seeks to block the plays of the other player, while advancing their own plays." << endl ;
            Sleep(1000);
            system("pause");
            system("cls");
            break;

        case 'X' :
        case 'x' :
            cout << " Good-bye " << endl ;
            exitProg = true ;
            break ;

        default :
            cout << "Invalid option !!!" << endl ;
            break;

        }//end switch option

    }//end main loop

    return 0 ;

}//end main
