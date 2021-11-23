// All required files are included
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <iomanip>

using namespace std;

// initialize any constant here if you want
#define screenWidth GetSystemMetrics(SM_CXSCREEN)
#define screenHeight GetSystemMetrics(SM_CYSCREEN)

// Declare Functions here
void startGame();
void instructions();
void endGame();
void gameFunction();
void playerOne();
void bot();
int throwDice();

// Global Variable Declarations
int playerOnePosition = 1;
int playerTwoPosition = 1;

int main()
{
// Output Window set to full width
    initwindow(screenWidth+3, screenHeight+1, "",-6,-4);
    int opt;

//        cleardevice();
    cout << "Enter 1: New Game." << endl;
    cout << "Enter 2: Instructions" << endl;
    cout << "Enter 3: Exit Game" << endl;
    cin >> opt;

    switch (opt)
    {
        case 1 :
            startGame();
            getch();
            break;

        case 2 :
            instructions();
            break;

        case 3 :
            endGame();
            getch();
            closegraph();
            return 0;
    }

}

void startGame()
{
    int i = 100;
    int reverseLine = 1;

    while(i >= 10)
    {
        if(reverseLine % 2 != 0) // odd
        {
            setcolor(WHITE);
            for(int num = 1; num <= 10; num++)
            {
                bgiout << setw(2) << setfill('0') << i <<"          ";
                i--;
            }
        }
        else
        {
            for(int num = -9; num <= 9; num++) // even
            {
                bgiout << setw(2) << setfill('0') << i+num << "          ";
                i--;
                num++;
            }
        }
        bgiout << endl << endl << endl;
        reverseLine++;
    }
    outstreamxy(120, 200);

    // Created ladders here
    setcolor(GREEN);
    setlinestyle(0,0,3);
    line(237,299,419,213);
    line(520,260,630,395);
    line(185,584,468,307);
    line(406,502,630,635);

    // Created Snakes here
    setcolor(RED);
    setlinestyle(0,0,3);
    line(190,210,570,490);
    line(293,358,125,540);
    line(408,583,294,406);
    line(630,360,520,540);

    // Created Demo Players
    circle(110, 640, 7);


    gameFunction();
    throwDice();
}


void instructions()
{
    bgiout << "This is a Snake and ladder game" << endl;
//    outtext("Press any key to clear the screen.");
    bgiout << "Only 1 player can play this game" << endl;
    bgiout << "Thank you!!" << endl;
    outstreamxy(120, 200);
    getch();
}

void endGame()
{
    bgiout << "You Ended the Game!!" << endl;
    bgiout << "Press any key to exit." << endl;
    outstreamxy(120, 200);
    getch();
}

void gameFunction()
{
    // 10 19 51 78 ladders
    int randomNumber = throwDice();
    playerOnePosition += randomNumber;

    if(playerOnePosition == 10)
    {
//        circle(250, 200, 8);
    }
    else if(playerOnePosition == 19)
    {

    }
    else if(playerOnePosition == 51)
    {

    }
    else if(playerOnePosition == 78)
    {

    }
}
void playerOne()
{

}
void bot()
{

}

int throwDice()
{

}
