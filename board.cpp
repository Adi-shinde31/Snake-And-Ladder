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
#define ONE 56
#define TWO 112
#define THREE 168
#define FOUR 224
#define FIVE 280
#define SIX 336

// Declare Functions here
void startGame();
void instructions();
void endGame();
void gameFunction();
void playerOne();
void bot();
int throwDice();

// Global Variable Declarations
static int playerOnePosition = 1;
static int botPosition = 1;

int main()
{
// Output Window set to full width
    initwindow(screenWidth+3, screenHeight+1, "",-6,-4);
    int opt;

// STYLED
//    setcolor(10);
//    settextstyle(3,4,5);
////    bgiout << "SNAKE AND LADDER " << endl;
////    outstreamxy(500, 190);
//    outtextxy(870,190,"SNAKE AND LADDER");
//
//    setcolor(9);
//   settextstyle(8,4,4);
////    bgiout << "START" << endl;
////    outstreamxy(655,350);
//    outtextxy(655,350,"START");
//
//    setcolor(9);
//    settextstyle(8,4,4);
////    bgiout << "INSTRUCTIONS" << endl;
////    outstreamxy(725,450);
//    outtextxy(725,450,"INSTRUCTIONS");
//
//    setcolor(9);
//    settextstyle(8,4,4);
////    bgiout << "END GAME" << endl;
////    outstreamxy(695,550);
//    outtextxy(695,550,"QUIT GAME");


// NORMALIZE
   setcolor(10);
//    settextstyle(3,4,5);
   bgiout << "SNAKE AND LADDER " << endl;
   outstreamxy(535, 250);
//    outtextxy(870,190,"SNAKE AND LADDER");

   setcolor(9);
//    settextstyle(8,4,4);

   bgiout << "START" << endl;
   outstreamxy(580,350);
//    outtextxy(655,350,"START");
//
   setcolor(9);
//    settextstyle(8,4,4);
   bgiout << "INSTRUCTIONS" << endl;
   outstreamxy(550,400);
//    outtextxy(725,450,"INSTRUCTIONS");
//
   setcolor(9);
//    settextstyle(8,4,4);
   bgiout << "END GAME" << endl;
   outstreamxy(565,450);
//    outtextxy(695,550,"QUIT GAME");


    cout << "Enter 1: New Game." << endl;
    cout << "Enter 2: Instructions" << endl;
    cout << "Enter 3: Exit Game" << endl;
    cin >> opt;

    getch();
    cleardevice();

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
    setcolor(WHITE);
    int i = 100;
    int reverseLine = 1;

    while(i >= 10)
    {
        if(reverseLine % 2 != 0) // odd
        {
            setcolor(WHITE);
            for(int num = 1; num <= 10; num++)
            {
                setcolor(WHITE);
                bgiout<<"          "<< setw(2) << setfill('0') << i ;
                i--;
            }
        }
        else
        {
            for(int num = -9; num <= 9; num++) // even
            {
                setcolor(WHITE);
                bgiout<< "          " << setw(2) << setfill('0') << i+num;
                i--;
                num++;
            }
        }
        bgiout << endl << endl << endl;
        reverseLine++;
    }
    outstreamxy(95, 200);

    setcolor(WHITE);
    line(90,160,90,652);
    line(218,160,218,652);
    line(162,160,162,652);
    line(274,160,274,652);
    line(332,160,332,652);
    line(387,160,387,652);
    line(443,160,443,652);
    line(500,160,500,652);
    line(555,160,555,652);
    line(612,160,612,652);
    line(670,160,670,652);
    setcolor(WHITE);
    line(90,652,670,652);
    line(90,600,670,600);
    line(90,552,670,552);
    line(90,504,670,504);
    line(90,456,670,456);
    line(90,408,670,408);
    line(90,360,670,360);
    line(90,312,670,312);
    line(90,264,670,264);
    line(90,216,670,216);
    line(90,160,670,160);

    // Created ladders here
    setcolor(GREEN);
    setlinestyle(0,0,3);
    line(252,295,420,195);//95
    line(535,240,645,433);//88
    line(185,583,466,292);//19
    line(422,485,635,630);//35

    // Created Snakes here
    setcolor(RED);
    setlinestyle(0,0,3);
    line(186,200,533,531);//32
    line(295,340,128,480);//64
    line(408,623,292,436);//06
    line(532,382,636,236);//53


    // Created Demo Players

    playerOne();
    bot();

    setcolor(WHITE);
    setbkcolor(WHITE);
    rectangle(90,160,670,652);
    setbkcolor(WHITE);

    gameFunction();

}


void instructions()
{
    bgiout << "This is a Snake and ladder game" << endl;
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
// CONDITION FOR 1st SIX ON DICE
//    while(playerOnePosition != 6)
//    {
//        playerOnePosition = throwDice();
//        cout << "throw dice = " << playerOnePosition << endl;
//        getch();
//    }

// FOR PLAYER TO MOVE
//    for(int i = 1; i <= 56;i ++)
//    {
//        cleardevice();
//        setcolor(YELLOW);
//        circle(110+i, 640, 7);
//        delay(70);
//    }


    cout << "player position at start : " << playerOnePosition << endl;
    while (playerOnePosition != 100)
    {
        // WHEN USER CLICK ON THROW DICE FOR 1st TIME
        int randomNumber = throwDice();
        cout << "Random Number : " << randomNumber << endl;
        playerOnePosition += randomNumber;
        cout << "Player position after adding with above Random Number : " << playerOnePosition << endl;

//        randomNumber = 1;
//        playerOnePosition =99;

        switch(randomNumber)
        {
            case 1 :
                if(playerOnePosition == 10)
                {
                    playerOnePosition = 35;
                    setcolor(10);
                    circle(400, 492, 7);
                }
                else if(playerOnePosition == 19)
                {
                    playerOnePosition = 74;
                    setcolor(10);
                    circle(460, 300, 7);
                }
                else if(playerOnePosition == 50)
                {
                    playerOnePosition = 88;
                    setcolor(10);
                    circle(515, 252, 7);
                }
                else if(playerOnePosition == 78)
                {
                    playerOnePosition = 95;
                    setcolor(10);
                    circle(402, 205, 7);
                }
// SNAKE
                else if(playerOnePosition == 44)
                {
                    playerOnePosition = 4;
                    setcolor(10);
                    circle(400, 640, 7);
                }
                else if(playerOnePosition == 64)
                {
                    playerOnePosition = 40;
                    setcolor(10);
                    circle(110, 492, 7);
                }
                else if(playerOnePosition == 90)
                {
                    playerOnePosition = 53;
                    setcolor(10);
                    circle(515, 397, 7);
                }
                else if(playerOnePosition == 99)
                {
                    playerOnePosition = 28;
                    setcolor(10);
                    circle(513, 542, 7);
                }

            case 2 :
                if(playerOnePosition == 10)
                {
                    playerOnePosition = 35;
                    setcolor(10);
                    circle(400, 492, 7);
                }
                else if(playerOnePosition == 19)
                {
                    playerOnePosition = 74;
                    setcolor(10);
                    circle(460, 300, 7);
                }
                else if(playerOnePosition == 50)
                {
                    playerOnePosition = 88;
                    setcolor(10);
                    circle(515, 252, 7);
                }
                else if(playerOnePosition == 78)
                {
                    playerOnePosition = 95;
                    setcolor(10);
                    circle(402, 205, 7);
                }

                else if(playerOnePosition == 44)
                {
                    playerOnePosition = 4;
                    setcolor(10);
                    circle(400, 640, 7);
                }
                else if(playerOnePosition == 64)
                {
                    playerOnePosition = 40;
                    setcolor(10);
                    circle(110, 492, 7);
                }
                else if(playerOnePosition == 90)
                {
                    playerOnePosition = 53;
                    setcolor(10);
                    circle(515, 397, 7);
                }
                else if(playerOnePosition == 99)
                {
                    playerOnePosition = 28;
                    setcolor(10);
                    circle(513, 542, 7);
                }

            case 3 :
                if(playerOnePosition == 10)
                {
                    playerOnePosition = 35;
                    setcolor(10);
                    circle(400, 492, 7);
                }
                else if(playerOnePosition == 19)
                {
                    playerOnePosition = 74;
                    setcolor(10);
                    circle(460, 300, 7);
                }
                else if(playerOnePosition == 50)
                {
                    playerOnePosition = 88;
                    setcolor(10);
                    circle(515, 252, 7);
                }
                else if(playerOnePosition == 78)
                {
                    playerOnePosition = 95;
                    setcolor(10);
                    circle(402, 205, 7);
                }

                else if(playerOnePosition == 44)
                {
                    playerOnePosition = 4;
                    setcolor(10);
                    circle(400, 640, 7);
                }
                else if(playerOnePosition == 64)
                {
                    playerOnePosition = 40;
                    setcolor(10);
                    circle(110, 492, 7);
                }
                else if(playerOnePosition == 90)
                {
                    playerOnePosition = 53;
                    setcolor(10);
                    circle(515, 397, 7);
                }
                else if(playerOnePosition == 99)
                {
                    playerOnePosition = 28;
                    setcolor(10);
                    circle(513, 542, 7);
                }

            case 4 :
                if(playerOnePosition == 10)
                {
                    playerOnePosition = 35;
                    setcolor(10);
                    circle(400, 492, 7);
                }
                else if(playerOnePosition == 19)
                {
                    playerOnePosition = 74;
                    setcolor(10);
                    circle(460, 300, 7);
                }
                else if(playerOnePosition == 50)
                {
                    playerOnePosition = 88;
                    setcolor(10);
                    circle(515, 252, 7);
                }
                else if(playerOnePosition == 78)
                {
                    playerOnePosition = 95;
                    setcolor(10);
                    circle(402, 205, 7);
                }

                else if(playerOnePosition == 44)
                {
                    playerOnePosition = 4;
                    setcolor(10);
                    circle(400, 640, 7);
                }
                else if(playerOnePosition == 64)
                {
                    playerOnePosition = 40;
                    setcolor(10);
                    circle(110, 492, 7);
                }
                else if(playerOnePosition == 90)
                {
                    playerOnePosition = 53;
                    setcolor(10);
                    circle(515, 397, 7);
                }
                else if(playerOnePosition == 99)
                {
                    playerOnePosition = 28;
                    setcolor(10);
                    circle(513, 542, 7);
                }

            case 5 :
                if(playerOnePosition == 10)
                {
                    playerOnePosition = 35;
                    setcolor(10);
                    circle(400, 492, 7);
                }
                else if(playerOnePosition == 19)
                {
                    playerOnePosition = 74;
                    setcolor(10);
                    circle(460, 300, 7);
                }
                else if(playerOnePosition == 50)
                {
                    playerOnePosition = 88;
                    setcolor(10);
                    circle(515, 252, 7);
                }
                else if(playerOnePosition == 78)
                {
                    playerOnePosition = 95;
                    setcolor(10);
                    circle(402, 205, 7);
                }

                else if(playerOnePosition == 44)
                {
                    playerOnePosition = 4;
                    setcolor(10);
                    circle(400, 640, 7);
                }
                else if(playerOnePosition == 64)
                {
                    playerOnePosition = 40;
                    setcolor(10);
                    circle(110, 492, 7);
                }
                else if(playerOnePosition == 90)
                {
                    playerOnePosition = 53;
                    setcolor(10);
                    circle(515, 397, 7);
                }
                else if(playerOnePosition == 99)
                {
                    playerOnePosition = 28;
                    setcolor(10);
                    circle(513, 542, 7);
                }

            case 6 :
                if(playerOnePosition == 10)
                {
                    playerOnePosition = 35;
                    setcolor(10);
                    circle(400, 492, 7);
                }
                else if(playerOnePosition == 19)
                {
                    playerOnePosition = 74;
                    setcolor(10);
                    circle(460, 300, 7);
                }
                else if(playerOnePosition == 50)
                {
                    playerOnePosition = 88;
                    setcolor(10);
                    circle(515, 252, 7);
                }
                else if(playerOnePosition == 78)
                {
                    playerOnePosition = 95;
                    setcolor(10);
                    circle(402, 205, 7);
                }

                else if(playerOnePosition == 44)
                {
                    playerOnePosition = 4;
                    setcolor(10);
                    circle(400, 640, 7);
                }
                else if(playerOnePosition == 64)
                {
                    playerOnePosition = 40;
                    setcolor(10);
                    circle(110, 492, 7);
                }
                else if(playerOnePosition == 90)
                {
                    playerOnePosition = 53;
                    setcolor(10);
                    circle(515, 397, 7);
                }
                else if(playerOnePosition == 99)
                {
                    playerOnePosition = 28;
                    setcolor(10);
                    circle(513, 542, 7);
                }
        } // END OF SWTICH CASE
    } // END OF WHILE LOOP
}// END OF gameFunction

void playerOne()
{
    setcolor(BLUE);
    circle(110, 618, 7);

    // difference is of 56 between 1st and 2nd number
}
void bot()
{
    setcolor(YELLOW);
    circle(110, 640, 7);
}

int throwDice()
{
    srand(time(0));
    int dice = (int) (1+rand()%6);
    getch();
    return dice;
}
