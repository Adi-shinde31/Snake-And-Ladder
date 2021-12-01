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
void moveFromLadderOrLadder(char, int, int, char);

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

    cout << "player position at start : " << playerOnePosition << endl;
    cout << "Bot position at start : " << botPosition << endl;
    getch();

    while (playerOnePosition != 100 || botPosition != 100)
    {
        // WHEN USER CLICK ON THROW DICE FOR 1st TIME
        int randomNumberForPlayerOne = throwDice();
        cout << "Random Number for PlayerOne : " << randomNumberForPlayerOne << endl;
        getch();
        int randomNumberForBot = throwDice();
        cout << "Random Number for Bot : " << randomNumberForBot << endl << endl;
        getch();


        if(randomNumberForPlayerOne + playerOnePosition > 100){}
        else if(randomNumberForPlayerOne + playerOnePosition == 100)
        {
            cout << "player won" << endl;
            getch();
            break;
        }
        else
        {
            playerOnePosition += randomNumberForPlayerOne;
            cout << "Player position after adding with above Random Number : " << playerOnePosition << endl;
        }

//        randomNumberForPlayerOne = 1;
//        playerOnePosition = 99;

        switch(randomNumberForPlayerOne)
        {
            case 1 :
                if(playerOnePosition == 10) {moveFromLadderOrLadder('P',1,10,'L');}
                else if(playerOnePosition == 19){moveFromLadderOrLadder('P',1,19,'L');}
                else if(playerOnePosition == 50){moveFromLadderOrLadder('P',1,50,'L');}
                else if(playerOnePosition == 78){moveFromLadderOrLadder('P',1,78,'L');}
// SNAKE
                else if(playerOnePosition == 44) {moveFromLadderOrLadder('P',1,44,'S');}
                else if(playerOnePosition == 64) {moveFromLadderOrLadder('P',1,64,'S');}
                else if(playerOnePosition == 90) {moveFromLadderOrLadder('P',1,90,'S');}
                else if(playerOnePosition == 99) {moveFromLadderOrLadder('P',1,99,'S');}

            case 2 :
                if(playerOnePosition == 10) {moveFromLadderOrLadder('P',2,10,'L');}
                else if(playerOnePosition == 19){moveFromLadderOrLadder('P',2,19,'L');}
                else if(playerOnePosition == 50){moveFromLadderOrLadder('P',2,50,'L');}
                else if(playerOnePosition == 78){moveFromLadderOrLadder('P',2,78,'L');}
// SNAKE
                else if(playerOnePosition == 44) {moveFromLadderOrLadder('P',2,44,'S');}
                else if(playerOnePosition == 64) {moveFromLadderOrLadder('P',2,64,'S');}
                else if(playerOnePosition == 90) {moveFromLadderOrLadder('P',2,90,'S');}
                else if(playerOnePosition == 99) {moveFromLadderOrLadder('P',2,99,'S');}

            case 3 :
                if(playerOnePosition == 10) {moveFromLadderOrLadder('P',3,10,'L');}
                else if(playerOnePosition == 19){moveFromLadderOrLadder('P',3,19,'L');}
                else if(playerOnePosition == 50){moveFromLadderOrLadder('P',3,50,'L');}
                else if(playerOnePosition == 78){moveFromLadderOrLadder('P',3,78,'L');}
// SNAKE
                else if(playerOnePosition == 44) {moveFromLadderOrLadder('P',3,44,'S');}
                else if(playerOnePosition == 64) {moveFromLadderOrLadder('P',3,64,'S');}
                else if(playerOnePosition == 90) {moveFromLadderOrLadder('P',3,90,'S');}
                else if(playerOnePosition == 99) {moveFromLadderOrLadder('P',3,99,'S');}

            case 4 :
                if(playerOnePosition == 10) {moveFromLadderOrLadder('P',4,10,'L');}
                else if(playerOnePosition == 19){moveFromLadderOrLadder('P',4,19,'L');}
                else if(playerOnePosition == 50){moveFromLadderOrLadder('P',4,50,'L');}
                else if(playerOnePosition == 78){moveFromLadderOrLadder('P',4,78,'L');}
// SNAKE
                else if(playerOnePosition == 44) {moveFromLadderOrLadder('P',4,44,'S');}
                else if(playerOnePosition == 64) {moveFromLadderOrLadder('P',4,64,'S');}
                else if(playerOnePosition == 90) {moveFromLadderOrLadder('P',4,90,'S');}
                else if(playerOnePosition == 99) {moveFromLadderOrLadder('P',4,99,'S');}

            case 5 :
                if(playerOnePosition == 10) {moveFromLadderOrLadder('P',5,10,'L');}
                else if(playerOnePosition == 19){moveFromLadderOrLadder('P',5,19,'L');}
                else if(playerOnePosition == 50){moveFromLadderOrLadder('P',5,50,'L');}
                else if(playerOnePosition == 78){moveFromLadderOrLadder('P',5,78,'L');}
// SNAKE
                else if(playerOnePosition == 44) {moveFromLadderOrLadder('P',5,44,'S');}
                else if(playerOnePosition == 64) {moveFromLadderOrLadder('P',5,64,'S');}
                else if(playerOnePosition == 90) {moveFromLadderOrLadder('P',5,90,'S');}
                else if(playerOnePosition == 99) {moveFromLadderOrLadder('P',5,99,'S');}

            case 6 :
                if(playerOnePosition == 10) {moveFromLadderOrLadder('P',6,10,'L');}
                else if(playerOnePosition == 19){moveFromLadderOrLadder('P',6,19,'L');}
                else if(playerOnePosition == 50){moveFromLadderOrLadder('P',6,50,'L');}
                else if(playerOnePosition == 78){moveFromLadderOrLadder('P',6,78,'L');}
// SNAKE
                else if(playerOnePosition == 44) {moveFromLadderOrLadder('P',6,44,'S');}
                else if(playerOnePosition == 64) {moveFromLadderOrLadder('P',6,64,'S');}
                else if(playerOnePosition == 90) {moveFromLadderOrLadder('P',6,90,'S');}
                else if(playerOnePosition == 99) {moveFromLadderOrLadder('P',6,99,'S');}

        }// END OF SWTICH CASE FOR PLAYER ONE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BOT - MEGENTA COLOUR

        if(randomNumberForBot + botPosition > 100)
        {}
        else if(randomNumberForBot + botPosition == 100)
        {
            cout << "bot won" << endl;
            getch();
            break;
        }
        else
        {
            botPosition += randomNumberForBot;
            cout << "Bot position after adding with above Random Number : " << botPosition << endl;
        }

//    randomNumberForBot = 1;
//    botPosition = 99;

        switch(randomNumberForBot)
        {
            case 1 :
                if(botPosition == 10) {moveFromLadderOrLadder('B',1,10,'L');}
                else if(botPosition == 19){moveFromLadderOrLadder('B',1,19,'L');}
                else if(botPosition == 50){moveFromLadderOrLadder('B',1,50,'L');}
                else if(botPosition == 78){moveFromLadderOrLadder('B',1,78,'L');}
                else if(botPosition == 44) {moveFromLadderOrLadder('B',1,44,'S');} // SNAKE
                else if(botPosition == 64) {moveFromLadderOrLadder('B',1,64,'S');}
                else if(botPosition == 90) {moveFromLadderOrLadder('B',1,90,'S');}
                else if(botPosition == 99) {moveFromLadderOrLadder('B',1,99,'S');}

            case 2 :
                if(botPosition == 10) {moveFromLadderOrLadder('B',2,10,'L');}
                else if(botPosition == 19){moveFromLadderOrLadder('B',2,19,'L');}
                else if(botPosition == 50){moveFromLadderOrLadder('B',2,50,'L');}
                else if(botPosition == 78){moveFromLadderOrLadder('B',2,78,'L');}
                else if(botPosition == 44) {moveFromLadderOrLadder('B',2,44,'S');} // SNAKE
                else if(botPosition == 64) {moveFromLadderOrLadder('B',2,64,'S');}
                else if(botPosition == 90) {moveFromLadderOrLadder('B',2,90,'S');}
                else if(botPosition == 99) {moveFromLadderOrLadder('B',2,99,'S');}

            case 3 :
                if(botPosition == 10) {moveFromLadderOrLadder('B',3,10,'L');}
                else if(botPosition == 19){moveFromLadderOrLadder('B',3,19,'L');}
                else if(botPosition == 50){moveFromLadderOrLadder('B',3,50,'L');}
                else if(botPosition == 78){moveFromLadderOrLadder('B',3,78,'L');}
                else if(botPosition == 44) {moveFromLadderOrLadder('B',3,44,'S');} // SNAKE
                else if(botPosition == 64) {moveFromLadderOrLadder('B',3,64,'S');}
                else if(botPosition == 90) {moveFromLadderOrLadder('B',3,90,'S');}
                else if(botPosition == 99) {moveFromLadderOrLadder('B',3,99,'S');}

            case 4 :
                if(botPosition == 10) {moveFromLadderOrLadder('B',4,10,'L');}
                else if(botPosition == 19){moveFromLadderOrLadder('B',4,19,'L');}
                else if(botPosition == 50){moveFromLadderOrLadder('B',4,50,'L');}
                else if(botPosition == 78){moveFromLadderOrLadder('B',4,78,'L');}
                else if(botPosition == 44) {moveFromLadderOrLadder('B',4,44,'S');} // SNAKE
                else if(botPosition == 64) {moveFromLadderOrLadder('B',4,64,'S');}
                else if(botPosition == 90) {moveFromLadderOrLadder('B',4,90,'S');}
                else if(botPosition == 99) {moveFromLadderOrLadder('B',4,99,'S');}

            case 5 :
                if(botPosition == 10) {moveFromLadderOrLadder('B',5,10,'L');}
                else if(botPosition == 19){moveFromLadderOrLadder('B',5,19,'L');}
                else if(botPosition == 50){moveFromLadderOrLadder('B',5,50,'L');}
                else if(botPosition == 78){moveFromLadderOrLadder('B',5,78,'L');}
                else if(botPosition == 44) {moveFromLadderOrLadder('B',5,44,'S');} // SNAKE
                else if(botPosition == 64) {moveFromLadderOrLadder('B',5,64,'S');}
                else if(botPosition == 90) {moveFromLadderOrLadder('B',5,90,'S');}
                else if(botPosition == 99) {moveFromLadderOrLadder('B',5,99,'S');}

            case 6 :
                if(botPosition == 10) {moveFromLadderOrLadder('B',6,10,'L');}
                else if(botPosition == 19){moveFromLadderOrLadder('B',6,19,'L');}
                else if(botPosition == 50){moveFromLadderOrLadder('B',6,50,'L');}
                else if(botPosition == 78){moveFromLadderOrLadder('B',6,78,'L');}
                else if(botPosition == 44) {moveFromLadderOrLadder('B',6,44,'S');} // SNAKE
                else if(botPosition == 64) {moveFromLadderOrLadder('B',6,64,'S');}
                else if(botPosition == 90) {moveFromLadderOrLadder('B',6,90,'S');}
                else if(botPosition == 99) {moveFromLadderOrLadder('B',6,99,'S');}

        }// END OF SWTICH CASE FOR BOT
    }// END OF WHILE LOOP
}// END OF gameFunction

void playerOne()
{
    setcolor(WHITE);
    circle(110, 618, 7);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(110,618,15);

    // difference is of 56 between 1st and 2nd number
}
void bot()
{
    setcolor(WHITE);
    circle(110, 640, 7);
    setfillstyle(SOLID_FILL,MAGENTA);
    floodfill(110,640,15);
}

int throwDice()
{
    srand(time(0));
    int dice = (int) (1+rand()%6);
    return dice;
}


void moveFromLadderOrLadder(char ch, int numberOnDice, int obsNumber, char obs)
{
    // FOR LADDER
    if(obs == 'L')
    {
        if(ch == 'P' && obsNumber == 10) // for player with any dice num but at LADDER 10
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 35;
                setcolor(15);
                circle(400, 470, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(400, 470, 15);
            }
        }
        else if(ch == 'B' && obsNumber == 10) // for bot with any dice num but at LADDER 10
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 35;
                setcolor(15);
                circle(400, 492, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(400, 492, 15);
            }
        }
        else if(ch == 'P' && obsNumber == 19) // for player with any dice num but at LADDER 19
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 74;
                setcolor(15);
                circle(460, 278, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(460, 278, 15);
            }
        }
        else if(ch == 'B' && obsNumber == 19) // for bot with any dice num but at LADDER 19
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 74;
                setcolor(15);
                circle(460, 300, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(460, 300, 15);
            }
        }
        else if(ch == 'P' && obsNumber == 50) // for player with any dice num but at LADDER 50
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 88;
                setcolor(15);
                circle(515, 230, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(515, 230, 15);
            }
        }
        else if(ch == 'B' && obsNumber == 50) // for bot with any dice num but at LADDER 50
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 88;
                setcolor(15);
                circle(515, 252, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(515, 252,15);
            }
        }
        else if(ch == 'P' && obsNumber == 78) // for player with any dice num but at LADDER 78
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 95;
                setcolor(15);
                circle(402, 183, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(402, 183, 15);
            }
        }
        else if(ch == 'B' && obsNumber == 78) // for bot with any dice num but at LADDER 78
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 95;
                setcolor(15);
                circle(402, 205, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(402, 205,15);
            }
        }
    }
    // FOR SNAKES
    else if(obs == 'S')
    {

        if(ch == 'P' && obsNumber == 44) // for player with any dice num but at SNAKE 44
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 6;
                setcolor(15);
                circle(400, 618, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(400, 618, 15);
            }
        }
        else if(ch == 'B' && obsNumber == 44) // for bot with any dice num but at SNAKE 44
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 6;
                setcolor(15);
                circle(400, 640, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(400, 640,15);
            }
        }
        else if(ch == 'P' && obsNumber == 64) // for player with any dice num but at SNAKE 64
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 40;
                setcolor(15);
                circle(110, 470, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(110, 470,15);
            }
        }
        else if(ch == 'B' && obsNumber == 64) // for bot with any dice num but at SNAKE 64
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 40;
                setcolor(15);
                circle(110, 492, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(110, 492,15);
            }
        }
        else if(ch == 'P' && obsNumber == 90) // for player with any dice num but at SNAKE 90
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 53;
                setcolor(15);
                circle(515, 375, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(515, 375, 15);
            }
        }
        else if(ch == 'B' && obsNumber == 90) // for bot with any dice num but at SNAKE 90
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 53;
                setcolor(15);
                circle(515, 397, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(515, 397,15);
            }
        }
        else if(ch == 'P' && obsNumber == 99) // for player with any dice num but at SNAKE 99
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 28;
                setcolor(15);
                circle(513, 520, 7);
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(513, 520,15);
            }
        }
        else if(ch == 'B' && obsNumber == 99) // for bot with any dice num but at SNAKE 99
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                botPosition = 28;
                setcolor(15);
                circle(513, 542, 7);
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(513, 542,15);
            }
        }
    }
}
