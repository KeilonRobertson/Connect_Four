//This is the implementation file for Connect Four
#include <iostream>
#include "Connect_Four.h"

using namespace std;

bool gamedone= false ;
    char p1tok = ' ', p2tok = ' ';
    string p1name = " ", p2name = " " ;
    char board[ASIZE] [ASIZE] ;

    int col = 0;
    int row = 0;

Connect_Four :: Connect_Four()
{
    //initializing array
    for(int row = 0 ; row < ASIZE; row++)
        for (int col = 0 ; col <ASIZE; col++)
        {
            board[row][col] = ' ' ;
        }
}

/** FUCNTION TO CONTROL GAME FLOW **/
void Connect_Four :: play()
{
        cout << "\n Welcome to Connect Four!! " << endl ;
    cout << "\n Player one enter your first name, leave a space and choose your token, it must be a symbol, letter or number : " << endl ;
    cin >>p1name >> p1tok ;
    cout << "\n" << p1name<< "'s token is : " <<p1tok << endl;
    cout << "\n Player two enter your first name, leave a space and choose your token, it must be a symbol, letter or number : " << endl;
    cin >>p2name >> p2tok ;
    cout << "\n"<< p2name <<"'s token is : " <<p2tok << endl;
    cout << "Please remember your player tokens" <<endl ;
    system("pause") ;
    system("cls") ;
    cout <<" Choose a column to place your player token " << endl ;

    displayBoard();//Display the board for players to see

    while(!gamedone)
    {
        player1_turn();
        if(!gamedone)
            player2_turn();
    }//end while loop to loop the entering of tokens

}//end void function

void Connect_Four :: player1_turn()
{
        cout << p1name <<", enter a column: " ;
        cin >>  col;
        if(col>6 || col <1)
        {
            cout <<"\nInvalid move!! If you choose an invalid column AGAIN you will lose your turn!!!"<< endl;
            cout<< "Enter a valid column, 1-6 that is not full: ";
            cin >> col;
        }//end check if input is a valid column selection

        else if (board[0][col-1] != ' ')
        {
            cout <<"\nThat column is full!! You cannot place your token there!!! If you choose a full column AGAIN you will lose your turn!!!"<< endl;
            cout<< "Enter a valid column, 1-6 that is not full: ";
            cin >> col;
        }//end check if column is full

        if(col>6 || col <1 || board[0][col-1] != ' ')
        {
            cout<< "YOU HAVE LOST YOUR TURN!!!! ";
            return;
        }


        system("cls");
        // the check to see if array is filled
        if (board[5][col-1] == ' ')
            board[5][col-1] = p1tok;
        else if(board[4][col-1]== ' ')
            board[4][col-1] = p1tok;
        else if(board[3][col-1]== ' ')
            board[3][col-1] = p1tok;
        else if(board[2][col-1]== ' ')
            board[2][col-1] = p1tok;
        else if(board[1][col-1]== ' ')
            board[1][col-1] = p1tok;
        else if(board[0][col-1]== ' ')
            board[0][col-1] = p1tok;

        displayBoard();

        string name = p1name;
        char tok = p1tok;

        checkwin(tok, name);
}

void Connect_Four :: player2_turn()
{
    cout << p2name <<", enter a column,1-6 : " ;
        cin >>  col;
        if(col>6 || col <1)
        {
            cout <<"\nInvalid move!! If you choose an invalid column AGAIN you will lose your turn!!!"<< endl;
            cout<< "Enter a valid column, 1-6 that is not full: ";
            cin >> col;
        }
        else if (board[0][col-1] != ' ')
        {
            cout <<"\nThat column is full!! You cannot place your token there!!! If you choose a full column AGAIN you will lose your turn!!!"<< endl;
            cout<< "Enter a valid column, 1-6 that is not full: ";
            cin >> col;
        }

        if(col>6 || col <1 || board[0][col-1] != ' ')
        {
            cout<< "YOU HAVE LOST YOUR TURN!!!! ";
            return;
        }

        // check if array is filled
        if (board[5][col-1] == ' ')
            board[5][col-1] = p2tok;
        else if(board[4][col-1]== ' ')
            board[4][col-1] = p2tok;
        else if(board[3][col-1]== ' ')
            board[3][col-1] = p2tok;
        else if(board[2][col-1]== ' ')
            board[2][col-1] = p2tok;
        else if(board[1][col-1]== ' ')
            board[1][col-1] = p2tok;
        else if(board[0][col-1]== ' ')
            board[0][col-1] = p2tok;
        system("cls");

        displayBoard();

        string name = p2name;
        char tok = p2tok;
         checkwin(tok,name);

}

/** FUCNTION TO CHECK FOR THE WINNER **/
void Connect_Four :: checkwin(char tok, string name)
{
    for(int i = -1 ; i<5 ; i ++)
        {
            //First Vertical Check
            if(board[5][i+1]==tok && board[4][i+1]==tok && board[3][i+1]==tok &&board[2][i+1] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
            //Second Vertical Check
            if(board[4][i+1]==tok && board[3][i+1]==tok && board[2][i+1] ==tok && board[1][i+1] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
            //Third Vertical Check

            if(board[3][i+1]==tok && board[2][i+1]==tok && board[1][i+1]==tok && board[0][i+1] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }

            //First Horizontal Check
            if(board[i+1][5] == tok && board[i+1][4]==tok && board[i+1][3]==tok && board[i+1][2] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }

            //Second Horizontal Check
            if(board[i+1][4] == tok && board[i+1][3]==tok && board[i+1][2]==tok && board[i+1][1] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }

            //Third Horizontal Check
            if(board[i+1][3] == tok && board[i+1][2]==tok && board[i+1][1]==tok && board[i+1][0] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }

        //The Following are Left to Right Diagonal Checks
        for (int z = 2; z<3 ; z++)
        {
            //First Diagonal  Check
            if(board[3+z][0+z] == tok && board[2+z][1+z]==tok && board[1+z][2+z]==tok && board[0+z][3+z] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }


        for(int b = 0; b<1; b++)
        {
            //Second Diagonal Check Number 1

            if(board[4-b][0+b] == tok && board[3-b][1+b]==tok && board[2-b][2+b]==tok && board[1-b][3+b] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
            //Second Diagonal  Check Number 2

            if(board[5-b][1+b] == tok && board[4-b][2+b]==tok && board[3-b][3+b]==tok && board[2-b][4+b] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }

        for (int c = 0 ; c<2 ; c++)
        {
            //Third Diagonal  Check
            if(board[5-c][0+c] == tok && board[4-c][1+c]==tok && board[3-c][2+c]==tok && board[2-c][3+c] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }
        //The Following are Right to Left DiagonalChecks

        for (int z = 2; z<3 ; z++)
        {
            //First Diagonal Check

            if(board[3+z][0+z] == tok && board[2+z][1+z]==tok && board[1+z][2+z]==tok && board[0+z][3+z] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }

        for(int b = 0; b<1; b++)
        {
            //Second Diagonal Check Number 1
            if(board[0+b][1+b] == tok && board[1+b][2+b]==tok && board[2+b][3+b]==tok && board[3+b][4+b] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
            //Second Diagonal  Check Number 2

            if(board[1+b][0+b] == tok && board[2+b][1+b]==tok && board[3+b][2+b]==tok && board[4+b][3+b] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }
        for (int c = 0 ; c<2 ; c++)
        {
            //Third Diagonal Check
            if(board[0+c][0+c] == tok && board[1+c][1+c]==tok && board[2+c][2+c]==tok && board[3+c][3+c] == tok)
            {
                cout << name << "\nYou have won!!" ;
                system("pause");
                system("cls");
                gamedone = true;
                break;
            }
        }
}

/** FUCNTION TO DISPLAY THE BOARD **/
void Connect_Four :: displayBoard()
{
cout <<"  1    2    3    4    5    6    " << endl;
        for(int row = 0; row < ASIZE ; row++)
        {
            for(int col = 0; col < ASIZE ; col++)
                cout << " {"<<board[row][col] << "} " ;
            cout << "\n" ;
        }
}

