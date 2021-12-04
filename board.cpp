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
#define ONE_Y 49

// Declare Functions here
void startGame();
void instructions();
void endGame();
void gameFunction();
void playerOne(int, int);
void bot(int, int);
int throwDice();
void moveFromLadderAndSnake(char, int, int, char);
void moveToNextNumber(char, int, int);

// Global Variable Declarations
static int playerOnePosition = 1;
static int botPosition = 1;
static int playerOne_XCord = 120;
static int playerOne_YCord = 618;
static int bot_XCord = 120;
static int bot_YCord = 640;

int main()
{
// Output Window set to full width
    initwindow(screenWidth+3, screenHeight+1, "",-6,-4);

    POINT CursorPosition;
    int cursorX, cursorY;
    int choice;

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
   setcolor(WHITE);
   rectangle(570,340,630,375);
//    outtextxy(655,350,"START");
//
   setcolor(9);
//    settextstyle(8,4,4);
   bgiout << "INSTRUCTIONS" << endl;
   outstreamxy(550,400);
   setcolor(WHITE);
   rectangle(540,390,660,425);
//    outtextxy(725,450,"INSTRUCTIONS");
//
   setcolor(9);
//    settextstyle(8,4,4);
   bgiout << "END GAME" << endl;
   outstreamxy(565,450);
   setcolor(WHITE);
   rectangle(550,440,650,475);
//    outtextxy(695,550,"QUIT GAME");

    while(cursorX != 0 && cursorY != 0)
    {
        cursorX = CursorPosition.x;
        cursorY = CursorPosition.y;
        GetCursorPos(&CursorPosition);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(cursorX > 570 && cursorY > 340 && cursorX < 630 && cursorY < 375)
            {
                choice = 1;
                break;
            }
            else if(cursorX > 540 && cursorY > 390 && cursorX < 660 && cursorY < 425)
            {
                choice = 2;
                break;
            }
            else if(cursorX > 550 && cursorY > 440 && cursorX < 650 && cursorY < 475)
            {
                choice = 3;
                break;
            }
        }
    }

    cleardevice();

    switch (choice)
    {
        case 1 :
            startGame();
            playerOne(playerOne_XCord, playerOne_YCord);
            bot(bot_XCord, bot_YCord);
            gameFunction();
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
            for(int num = 1; num <= 10; num++)
            {
                bgiout<<"          "<< setw(2) << setfill('0') << i ;
                i--;
            }
        }
        else
        {
            for(int num = -9; num <= 9; num++) // even
            {
                bgiout<<"          "<< setw(2) << setfill('0') << i+num;
                i--;
                num++;
            }
        }
        bgiout << endl << endl << endl;
        reverseLine++;
    }
    outstreamxy(95, 200);

    // vertical outline and inline from left to right
    setlinestyle(0,0,3);
    setcolor(WHITE);

    line(106,167,106,652);
    line(162,167,162,652);
    line(216,167,216,652);
    line(272,167,272,652);
    line(328,167,328,652);
    line(384,167,384,652);
    line(441,167,441,652);
    line(497,167,497,652);
    line(552,167,552,652);
    line(609,167,609,652);
    line(668,167,668,652);

    // horizontal outline and inline from down to up
    line(106,652,668,652);
    line(106,602,668,602);
    line(106,552,668,552);
    line(106,504,668,504);
    line(106,456,668,456);
    line(106,408,668,408);
    line(106,360,668,360);
    line(106,312,668,312);
    line(106,263,668,263);
    line(106,215,668,215);
    line(106,164,668,164);

    // Created ladders here
    setcolor(GREEN);
    line(252,295,420,195);//95
    line(535,240,645,433);//88
    line(185,583,466,292);//19
    line(422,485,635,630);//35

    // Created Snakes here
    setcolor(RED);
    line(186,200,533,531);//32
    line(295,340,128,480);//64
    line(408,623,292,436);//06
    line(532,382,636,236);//53

}// END OF startGame()


void instructions()
{
    bgiout << "This is a Snake and ladder game" << endl;
    bgiout << "Only 1 player can play this game" << endl;
    bgiout << "Thank you!!" << endl;
    outstreamxy(120, 200);
    getch();
}// END OF instructions()

void endGame()
{
    bgiout << "You Ended the Game!!" << endl;
    bgiout << "Press any key to exit." << endl;
    outstreamxy(120, 200);
    getch();
}// END OF endGame()

void gameFunction()
{
// CONDITION FOR 1st SIX ON DICE
//    while(playerOnePosition != 6)
//    {
//        playerOnePosition = throwDice();
//        cout << "throw dice = " << playerOnePosition << endl;
//        getch();
//    }

    cout << "\n* Player position at start : " << playerOnePosition << endl;
    cout << "* Bot position at start : " << botPosition << endl;
    getch();

    while (playerOnePosition != 100 || botPosition != 100)
    {
        // WHEN USER CLICK ON THROW DICE FOR 1st TIME
        int randomNumberForPlayerOne = throwDice();
        cout << "\n-> Random Number for PlayerOne : " << randomNumberForPlayerOne << endl;
        getch();
        int randomNumberForBot = throwDice();
        cout << "-> Random Number for Bot : " << randomNumberForBot << endl << endl;
        getch();

        if(randomNumberForPlayerOne + playerOnePosition > 100){} // FOR number greater than 100(will never be true)
        else if(randomNumberForPlayerOne + playerOnePosition == 100) // WHEN dice is thrown and requireed num to win comes
        {
            cout << "randomNumberForPlayerOne + playerOnePosition = " << (randomNumberForPlayerOne + playerOnePosition) << endl;
            cout << "player won" << endl;
            getch();
            break;
        }
        else  // num is less than 100
        {
            moveToNextNumber('P', randomNumberForPlayerOne, playerOnePosition);
            playerOnePosition += randomNumberForPlayerOne;

            switch(randomNumberForPlayerOne)
            {
                case 1 :
                    cout <<"INSIDE case 1\n\n";
                    if(playerOnePosition == 10) {moveFromLadderAndSnake('P',1,10,'L');}
                    else if(playerOnePosition == 19) {moveFromLadderAndSnake('P',1,19,'L');}
                    else if(playerOnePosition == 50) {moveFromLadderAndSnake('P',1,50,'L');}
                    else if(playerOnePosition == 78) {moveFromLadderAndSnake('P',1,78,'L');}
                    else if(playerOnePosition == 44) {moveFromLadderAndSnake('P',1,44,'S');} // SNAKE
                    else if(playerOnePosition == 64) {moveFromLadderAndSnake('P',1,64,'S');}
                    else if(playerOnePosition == 90) {moveFromLadderAndSnake('P',1,90,'S');}
                    else if(playerOnePosition == 99) {moveFromLadderAndSnake('P',1,99,'S');}

                case 2 :
                    cout <<"INSIDE case 2\n\n";
                    if(playerOnePosition == 10) {moveFromLadderAndSnake('P',2,10,'L');}
                    else if(playerOnePosition == 19) {moveFromLadderAndSnake('P',2,19,'L');}
                    else if(playerOnePosition == 50) {moveFromLadderAndSnake('P',2,50,'L');}
                    else if(playerOnePosition == 78) {moveFromLadderAndSnake('P',2,78,'L');}
                    else if(playerOnePosition == 44) {moveFromLadderAndSnake('P',2,44,'S');} // SNAKE
                    else if(playerOnePosition == 64) {moveFromLadderAndSnake('P',2,64,'S');}
                    else if(playerOnePosition == 90) {moveFromLadderAndSnake('P',2,90,'S');}
                    else if(playerOnePosition == 99) {moveFromLadderAndSnake('P',2,99,'S');}

                case 3 :
                    cout <<"INSIDE case 3\n\n";
                    if(playerOnePosition == 10) {moveFromLadderAndSnake('P',3,10,'L');}
                    else if(playerOnePosition == 19) {moveFromLadderAndSnake('P',3,19,'L');}
                    else if(playerOnePosition == 50) {moveFromLadderAndSnake('P',3,50,'L');}
                    else if(playerOnePosition == 78) {moveFromLadderAndSnake('P',3,78,'L');}
                    else if(playerOnePosition == 44) {moveFromLadderAndSnake('P',3,44,'S');} // SNAKE
                    else if(playerOnePosition == 64) {moveFromLadderAndSnake('P',3,64,'S');}
                    else if(playerOnePosition == 90) {moveFromLadderAndSnake('P',3,90,'S');}
                    else if(playerOnePosition == 99) {moveFromLadderAndSnake('P',3,99,'S');}

                case 4 :
                    cout <<"INSIDE case 4\n\n";
                    if(playerOnePosition == 10) {moveFromLadderAndSnake('P',4,10,'L');}
                    else if(playerOnePosition == 19) {moveFromLadderAndSnake('P',4,19,'L');}
                    else if(playerOnePosition == 50) {moveFromLadderAndSnake('P',4,50,'L');}
                    else if(playerOnePosition == 78) {moveFromLadderAndSnake('P',4,78,'L');}
                    else if(playerOnePosition == 44) {moveFromLadderAndSnake('P',4,44,'S');} // SNAKE
                    else if(playerOnePosition == 64) {moveFromLadderAndSnake('P',4,64,'S');}
                    else if(playerOnePosition == 90) {moveFromLadderAndSnake('P',4,90,'S');}
                    else if(playerOnePosition == 99) {moveFromLadderAndSnake('P',4,99,'S');}

                case 5 :
                    cout <<"INSIDE case 5\n\n";
                    if(playerOnePosition == 10) {moveFromLadderAndSnake('P',5,10,'L');}
                    else if(playerOnePosition == 19) {moveFromLadderAndSnake('P',5,19,'L');}
                    else if(playerOnePosition == 50) {moveFromLadderAndSnake('P',5,50,'L');}
                    else if(playerOnePosition == 78) {moveFromLadderAndSnake('P',5,78,'L');}
                    else if(playerOnePosition == 44) {moveFromLadderAndSnake('P',5,44,'S');} // SNAKE
                    else if(playerOnePosition == 64) {moveFromLadderAndSnake('P',5,64,'S');}
                    else if(playerOnePosition == 90) {moveFromLadderAndSnake('P',5,90,'S');}
                    else if(playerOnePosition == 99) {moveFromLadderAndSnake('P',5,99,'S');}

                case 6 :
                    cout <<"INSIDE case 6\n\n";
                    if(playerOnePosition == 10) {moveFromLadderAndSnake('P',6,10,'L');}
                    else if(playerOnePosition == 19) {moveFromLadderAndSnake('P',6,19,'L');}
                    else if(playerOnePosition == 50) {moveFromLadderAndSnake('P',6,50,'L');}
                    else if(playerOnePosition == 78) {moveFromLadderAndSnake('P',6,78,'L');}
                    else if(playerOnePosition == 44) {moveFromLadderAndSnake('P',6,44,'S');} // SNAKE
                    else if(playerOnePosition == 64) {moveFromLadderAndSnake('P',6,64,'S');}
                    else if(playerOnePosition == 90) {moveFromLadderAndSnake('P',6,90,'S');}
                    else if(playerOnePosition == 99) {moveFromLadderAndSnake('P',6,99,'S');}

            }// END OF SWTICH CASE FOR PLAYER ONE
            cout << "Player position after adding with above Random Number : " << playerOnePosition << endl;
        }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BOT - MEGENTA COLOUR

        if(randomNumberForBot + botPosition > 100){}
        else if(randomNumberForBot + botPosition == 100)
        {
            cout << "randomNumberForBot + botPosition = " << (randomNumberForBot + botPosition) << endl;
            cout << "bot won" << endl;
            getch();
            break;
        }
        else
        {
            moveToNextNumber('B',randomNumberForBot, botPosition);
            botPosition += randomNumberForBot;

            switch(randomNumberForBot)
            {
                case 1 :
                    if(botPosition == 10) {moveFromLadderAndSnake('B',1,10,'L');}
                    else if(botPosition == 19) {moveFromLadderAndSnake('B',1,19,'L');}
                    else if(botPosition == 50) {moveFromLadderAndSnake('B',1,50,'L');}
                    else if(botPosition == 78) {moveFromLadderAndSnake('B',1,78,'L');}
                    else if(botPosition == 44) {moveFromLadderAndSnake('B',1,44,'S');} // SNAKE
                    else if(botPosition == 64) {moveFromLadderAndSnake('B',1,64,'S');}
                    else if(botPosition == 90) {moveFromLadderAndSnake('B',1,90,'S');}
                    else if(botPosition == 99) {moveFromLadderAndSnake('B',1,99,'S');}

                case 2 :
                    if(botPosition == 10) {moveFromLadderAndSnake('B',2,10,'L');}
                    else if(botPosition == 19) {moveFromLadderAndSnake('B',2,19,'L');}
                    else if(botPosition == 50) {moveFromLadderAndSnake('B',2,50,'L');}
                    else if(botPosition == 78) {moveFromLadderAndSnake('B',2,78,'L');}
                    else if(botPosition == 44) {moveFromLadderAndSnake('B',2,44,'S');} // SNAKE
                    else if(botPosition == 64) {moveFromLadderAndSnake('B',2,64,'S');}
                    else if(botPosition == 90) {moveFromLadderAndSnake('B',2,90,'S');}
                    else if(botPosition == 99) {moveFromLadderAndSnake('B',2,99,'S');}

                case 3 :
                    if(botPosition == 10) {moveFromLadderAndSnake('B',3,10,'L');}
                    else if(botPosition == 19) {moveFromLadderAndSnake('B',3,19,'L');}
                    else if(botPosition == 50) {moveFromLadderAndSnake('B',3,50,'L');}
                    else if(botPosition == 78) {moveFromLadderAndSnake('B',3,78,'L');}
                    else if(botPosition == 44) {moveFromLadderAndSnake('B',3,44,'S');} // SNAKE
                    else if(botPosition == 64) {moveFromLadderAndSnake('B',3,64,'S');}
                    else if(botPosition == 90) {moveFromLadderAndSnake('B',3,90,'S');}
                    else if(botPosition == 99) {moveFromLadderAndSnake('B',3,99,'S');}

                case 4 :
                    if(botPosition == 10) {moveFromLadderAndSnake('B',4,10,'L');}
                    else if(botPosition == 19) {moveFromLadderAndSnake('B',4,19,'L');}
                    else if(botPosition == 50) {moveFromLadderAndSnake('B',4,50,'L');}
                    else if(botPosition == 78) {moveFromLadderAndSnake('B',4,78,'L');}
                    else if(botPosition == 44) {moveFromLadderAndSnake('B',4,44,'S');} // SNAKE
                    else if(botPosition == 64) {moveFromLadderAndSnake('B',4,64,'S');}
                    else if(botPosition == 90) {moveFromLadderAndSnake('B',4,90,'S');}
                    else if(botPosition == 99) {moveFromLadderAndSnake('B',4,99,'S');}

                case 5 :
                    if(botPosition == 10) {moveFromLadderAndSnake('B',5,10,'L');}
                    else if(botPosition == 19) {moveFromLadderAndSnake('B',5,19,'L');}
                    else if(botPosition == 50) {moveFromLadderAndSnake('B',5,50,'L');}
                    else if(botPosition == 78) {moveFromLadderAndSnake('B',5,78,'L');}
                    else if(botPosition == 44) {moveFromLadderAndSnake('B',5,44,'S');} // SNAKE
                    else if(botPosition == 64) {moveFromLadderAndSnake('B',5,64,'S');}
                    else if(botPosition == 90) {moveFromLadderAndSnake('B',5,90,'S');}
                    else if(botPosition == 99) {moveFromLadderAndSnake('B',5,99,'S');}

                case 6 :
                    if(botPosition == 10) {moveFromLadderAndSnake('B',6,10,'L');}
                    else if(botPosition == 19) {moveFromLadderAndSnake('B',6,19,'L');}
                    else if(botPosition == 50) {moveFromLadderAndSnake('B',6,50,'L');}
                    else if(botPosition == 78) {moveFromLadderAndSnake('B',6,78,'L');}
                    else if(botPosition == 44) {moveFromLadderAndSnake('B',6,44,'S');} // SNAKE
                    else if(botPosition == 64) {moveFromLadderAndSnake('B',6,64,'S');}
                    else if(botPosition == 90) {moveFromLadderAndSnake('B',6,90,'S');}
                    else if(botPosition == 99) {moveFromLadderAndSnake('B',6,99,'S');}
            }// END OF SWTICH CASE FOR BOT
            cout << "Bot position after adding with above Random Number : " << botPosition << endl;
        }// END OF ELSE ABOVE SWITCH CASE
    }// END OF WHILE LOOP
}// END OF gameFunction()

void playerOne(int X_cord, int Y_cord)
{
    setcolor(WHITE);
    circle(X_cord, Y_cord, 7);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(X_cord, Y_cord, 15);
}// END OF playerOne()

void bot(int X_cord, int Y_cord)
{
    setcolor(WHITE);
    circle(X_cord, Y_cord, 7);
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(X_cord, Y_cord, 15);
}// END OF bot()

int throwDice()
{
    srand(time(0));
    int dice = (int) (1+rand()%6);
    return dice;
}// END OF throwDice()

void moveFromLadderAndSnake(char ch, int numberOnDice, int obsNumber, char obs)// P 6 18 L
{
    // FOR LADDER
    if(obs == 'L')
    {
        if(ch == 'P' && obsNumber == 10) // for player with any dice num but at LADDER 10
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout <<"X CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
                playerOnePosition = 35;
                playerOne_XCord = 400;
                playerOne_YCord = 471;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);

                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 10) // for bot with any dice num but at LADDER 10
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 35;
                bot_XCord = 400;
                bot_YCord = 493;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
        else if(ch == 'P' && obsNumber == 19) // for player with any dice num but at LADDER 19
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 74;
                cout << "X CORD : " << playerOne_XCord << endl;
                cout << "Y CORD : " << playerOne_YCord <<endl;
                playerOne_XCord = 456;
                playerOne_YCord = 275;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 19) // for bot with any dice num but at LADDER 19
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 74;
                bot_XCord = 456;
                bot_YCord = 297;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
        else if(ch == 'P' && obsNumber == 50) // for player with any dice num but at LADDER 50
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 88;
                cout <<"X CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
                playerOne_XCord = 512;
                playerOne_YCord = 226;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 50) // for bot with any dice num but at LADDER 50
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 88;
                bot_XCord = 512;
                bot_YCord = 248;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
        else if(ch == 'P' && obsNumber == 78) // for player with any dice num but at LADDER 78
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 95;
                cout <<"X CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
                playerOne_XCord = 400;
                playerOne_YCord = 177;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 78) // for bot with any dice num but at LADDER 78
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 95;
                bot_XCord = 400;
                bot_YCord = 199;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
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
                cout << "X CORD : " << playerOne_XCord << endl;
                cout << "Y CORD : " << playerOne_YCord <<endl;
                playerOne_XCord = 400;
                playerOne_YCord = 618;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 44) // for bot with any dice num but at SNAKE 44
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 6;
                bot_XCord = 400;
                bot_YCord = 640;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
        else if(ch == 'P' && obsNumber == 64) // for player with any dice num but at SNAKE 64
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 40;
                cout << "X CORD : " << playerOne_XCord << endl;
                cout << "Y CORD : " << playerOne_YCord <<endl;
                playerOne_XCord = 120;
                playerOne_YCord = 471;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 64) // for bot with any dice num but at SNAKE 64
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 40;
                bot_XCord = 120;
                bot_YCord = 493;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
        else if(ch == 'P' && obsNumber == 90) // for player with any dice num but at SNAKE 90
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 53;
                cout << "X CORD : " << playerOne_XCord << endl;
                cout << "Y CORD : " << playerOne_YCord <<endl;
                playerOne_XCord = 512;
                playerOne_YCord = 373;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord <<endl;
            }
        }
        else if(ch == 'B' && obsNumber == 90) // for bot with any dice num but at SNAKE 90
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 53;
                bot_XCord = 512;
                bot_YCord = 395;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
        else if(ch == 'P' && obsNumber == 99) // for player with any dice num but at SNAKE 99
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                playerOnePosition = 28;
                cout << "X CORD : " << playerOne_XCord << endl;
                cout << "Y CORD : " << playerOne_YCord << endl;
                playerOne_XCord = 512;
                playerOne_YCord = 520;
                cleardevice();
                startGame();
                playerOne(playerOne_XCord,playerOne_YCord);
                cout <<"AFTER, PLAYER : \nX CORD : " << playerOne_XCord << endl;
                cout <<"Y CORD : " << playerOne_YCord << endl;
            }
        }
        else if(ch == 'B' && obsNumber == 99) // for bot with any dice num but at SNAKE 99
        {
            if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
            {
                cout << "X CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
                botPosition = 28;
                bot_XCord = 512;
                bot_YCord = 542;
                cleardevice();
                startGame();
                bot(bot_XCord,bot_YCord);
                cout << "AFTER, BOT : \nX CORD : " << bot_XCord << endl;
                cout << "Y CORD : " << bot_YCord << endl;
            }
        }
    }
}// END OF moveFromLadderOrLadder()

void moveToNextNumber(char dine, int numberAtDice, int position)
{
    //player
    if(dine == 'P')
    {
        int reach = numberAtDice+position;
        cout << "ADDITION OF " << numberAtDice << " & " << position << "= " << numberAtDice+position << endl;
        getch();
        while(position != reach)
        {
            if((playerOne_XCord < 623 && (playerOne_YCord == 618 || playerOne_YCord == 520 || playerOne_YCord == 422 || playerOne_YCord == 324|| playerOne_YCord == 226 || playerOne_YCord == 128)))// FOR X COORDINATE
            {
                cout << "\n\nSTARTING \n\nX IS : " << playerOne_XCord << endl << "Y IS : " << playerOne_YCord << endl <<endl;
                for(int i = 1; i <= ONE; i++)
                {
                    playerOne_XCord += 1;
                    cleardevice();
                    startGame();
                    playerOne(playerOne_XCord,playerOne_YCord);
                    delay(20);
                    cout << "1st LOOP : " << i << "  :  " << playerOne_XCord << endl;
                }
                cout << "\n\nX IS : " << playerOne_XCord << endl << "Y IS : " << playerOne_YCord << endl <<endl;
                position++;
            }
            else if(playerOne_XCord == 624 && (playerOne_YCord == 618 || playerOne_YCord == 520 ||  playerOne_YCord == 422 || playerOne_YCord == 324|| playerOne_YCord == 226 || playerOne_YCord == 128)) // FOR MAX Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    cleardevice();
                    startGame();
                    playerOne_YCord -= 1;
                    playerOne(playerOne_XCord,playerOne_YCord);
                    delay(20);
                    cout << "2nd LOOP : " << i << "  :  " << playerOne_YCord << endl;
                }
                cout << "\n\nX IS : " << playerOne_XCord << endl << "Y IS : " << playerOne_YCord << endl <<endl;
                position++;
            }
            else if((playerOne_XCord > 120 && (playerOne_YCord == 569 || playerOne_YCord == 471 || playerOne_YCord == 373 || playerOne_YCord == 275 || playerOne_YCord == 177 || playerOne_YCord == 79))) // NEGATIVE X COORDINATE
            {
                for(int i = 1; i <= ONE; i++)
                {
                    cleardevice();
                    startGame();
                    playerOne_XCord -= 1;
                    playerOne(playerOne_XCord,playerOne_YCord);
                    delay(20);
                    cout << "3rd LOOP : " << i << "  :  " << playerOne_XCord << endl;
                }
                cout << "\n\nX IS : " << playerOne_XCord << endl << "Y IS : " << playerOne_YCord << endl <<endl;
                position++;
            }
            else if((playerOne_XCord == 120 && (playerOne_YCord == 569 || playerOne_YCord ==  471 || playerOne_YCord == 373 || playerOne_YCord == 275 || playerOne_YCord == 177 || playerOne_YCord == 79))) // FOR MIN Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    cleardevice();
                    startGame();
                    playerOne_YCord -= 1;
                    playerOne(playerOne_XCord,playerOne_YCord);
                    delay(20);
                    cout << "4rd LOOP : " << i << "  :  " << playerOne_YCord << endl;
                }
                cout << "\n\nX IS : " << playerOne_XCord << endl << "Y IS : " << playerOne_YCord << endl <<endl;
                position++;
            }
        }// END OF while loop
    }// END OF if
    // bot
    else if(dine == 'B')
    {
        cout << "This is BOT \n\n";
        cout << "BOT X = " << bot_XCord << endl;
        cout << "BOT Y = " << bot_YCord << endl;
        int reach = numberAtDice+position;
        cout << "ADDITION OF "<<numberAtDice <<" & " << position << "= " << numberAtDice+position << endl;
        getch();
        cout << "position is : " << position << "reach is " << reach << endl;
        while(position != reach)
        {
            cout << "inside while\n";
            cout << "BOT X = " << bot_XCord << endl;
            cout << "BOT Y = " << bot_YCord << endl;

            if((bot_XCord < 623 && (bot_YCord == 640 || bot_YCord == 542 || bot_YCord == 444 || bot_YCord == 346 || bot_YCord == 248 || bot_YCord == 150)))// FOR X COORDINATE
            {
                cout << "\n\nSTARTING \n\nX IS : " << bot_XCord << endl << "Y IS : " << bot_YCord << endl <<endl;
                for(int i = 1; i <= ONE; i++)
                {
                    cleardevice();
                    startGame();
                    bot_XCord += 1;
                    bot(bot_XCord,bot_YCord);
                    delay(20);
                    cout << "1st LOOP : " << i << "  :  " << bot_XCord << endl;
                }
                cout << "\n\nX IS : " << bot_XCord << endl << "Y IS : " << bot_YCord << endl <<endl;
                position++;
            }
            else if((bot_XCord == 624 && (bot_YCord == 640 || bot_YCord == 542 || bot_YCord == 444 || bot_YCord == 346 || bot_YCord == 248 || bot_YCord == 150))) // FOR MAX Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    cleardevice();
                    startGame();
                    bot_YCord -= 1;
                    bot(bot_XCord,bot_YCord);
                    delay(20);
                    cout << "2nd LOOP : " << i << "  :  " << bot_YCord << endl;
                }
                cout << "\n\nX IS : " << bot_XCord << endl << "Y IS : " << bot_YCord << endl <<endl;
                position++;
            }
            else if((bot_XCord > 120 && (bot_YCord == 591 || bot_YCord == 493 || bot_YCord == 395 || bot_YCord == 297 || bot_YCord == 199 || bot_YCord == 101))) // NEGATIVE X COORDINATE
            {
                for(int i = 1; i <= ONE; i++)
                {
                    cleardevice();
                    startGame();
                    bot_XCord -= 1;
                    bot(bot_XCord,bot_YCord);
                    delay(20);
                    cout << "3rd LOOP : " << i << "  :  " << bot_XCord << endl;
                }
                cout << "\n\nX IS : " << bot_XCord << endl << "Y IS : " << bot_YCord << endl <<endl;
                position++;
            }
            else if((bot_XCord == 120 && (bot_YCord == 591 || bot_YCord == 493 || bot_YCord == 395 || bot_YCord == 297 || bot_YCord == 199 || bot_YCord == 101))) // FOR MIN Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    cleardevice();
                    startGame();
                    bot_YCord -= 1;
                    bot(bot_XCord,bot_YCord);
                    delay(20);
                    cout << "4rd LOOP : " << i << "  :  " << bot_YCord << endl;
                }
                cout << "\n\nX IS : " << bot_XCord<< endl << "Y IS : " << bot_YCord << endl <<endl;
                position++;
            }
        }// END OF while loop
    }// END OF else if
// END OF moveToNextNumber FUNCTION


// PLAYER ONE WILL DISAPPER BCOZ OF CLEAR DEICE IN BOT FUNC, NEW POS OF PLAYER ONE WILL GET CLEAR
// move and end when player is near to 100
// adjust the delay

    
    
