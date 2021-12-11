// All required header files
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <iomanip>

using namespace std;

// initialized constant
#define screenWidth GetSystemMetrics(SM_CXSCREEN)
#define screenHeight GetSystemMetrics(SM_CYSCREEN)
#define ONE 56
#define ONE_Y 49

// Declared Functions
void startGame();
void instructions();
void endGame();
void gameFunction();
void playerOne(int, int);
void bot(int, int);
int throwDice();
void moveFromLadderAndSnake(char, int, int, char);
void moveToNextNumber(char, int, int);
void showUpdate(char, int, int);

// Declared static Variables
static int playerOnePosition = 1;
static int botPosition = 1;
static int playerOne_XCord = 120;
static int playerOne_YCord = 618;
static int bot_XCord = 120;
static int bot_YCord = 640;

// START OF main() FUNCTION
int main()
{
/*  initwindow will create a graphic window and required parameter
 *  helps to set its maximum width and height
 */
    initwindow(screenWidth+3, screenHeight+1, "",-6,-4);

    int maxX = getmaxx(); /* stores maximum windows width */
    int maxY = getmaxy(); /* stores maximum windows height */
    int tWidth, tHeight; /* */

/*  CursorPosition is a object of POINT which will help to apply
 *  onclick event when user click on the following options
 */
    POINT CursorPosition;
    int cursorX, cursorY;
    int choice; /* sets to a relative number when user click on anyone of the option*/

/*  tWidth & tHeight will store the width and length of particular text,
 *  and displays the text at proper place
 */
    tWidth = textwidth("SNAKE AND LADDER");
    tHeight = textheight("SNAKE AND LADDER");
    tWidth = (maxX / 2) - (tWidth / 2);
    tHeight = (int)(maxY / 4) + 50;
    setcolor(10);
    outtextxy(tWidth, tHeight, "SNAKE AND LADDER");

    setcolor(9);
    tWidth = textwidth("START");
    tHeight = textheight("START");
    tWidth = (maxX / 2) - (tWidth / 2);
    tHeight = (maxY / 2) - 50;
    outtextxy(tWidth, tHeight, "START");

    tWidth = textwidth("INSTRUCTIONS");
    tHeight = textheight("INSTRUCTIONS");
    tWidth = (maxX / 2) - (tWidth / 2);
    tHeight = (maxY / 2);
    outtextxy(tWidth, tHeight, "INSTRUCTIONS");

    tWidth = textwidth("END GAME");
    tHeight = textheight("END GAME");
    tWidth = (maxX / 2) - (tWidth / 2);
    tHeight = (maxY / 2) + 50;
    outtextxy(tWidth, tHeight, "END GAME");

/*  Creates 3 rectangle respectively for the above text output
 *  I have set them at the center of the screen with respect to its X axis
 */
    setcolor(WHITE);
    rectangle(((maxX/2)-30),((maxY/2)-60),((maxX/2)+30),((maxY/2)-25)); /* box for START GAME */
    rectangle(((maxX/2)-60),((maxY/2)-10),((maxX/2)+60),((maxY/2)+25)); /* box for INSTRUCTIONS */
    rectangle(((maxX/2)-45),((maxY/2)+40),((maxX/2)+45),((maxY/2)+75)); /* box for END GAME */

    while(1)
    {
        cursorX = CursorPosition.x;
        cursorY = CursorPosition.y;
        GetCursorPos(&CursorPosition);

/*  if user clicks in between any of the coordinates, choice will get assigned to it's respective value
 *  this while will keep on running untill the user clicks on any of the options
 */
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(cursorX > ((maxX/2)-30) && cursorY > ((maxY/2)-60) && cursorX < ((maxX/2)+30) && cursorY < ((maxY/2)-25))
            {
                choice = 1;
                break;
            }
            else if(cursorX > ((maxX/2)-60) && cursorY > ((maxY/2)-10) && cursorX < ((maxX/2)+60) && cursorY < ((maxY/2)+25))
            {
                choice = 2;
                break;
            }
            else if(cursorX > ((maxX/2)-45) && cursorY > ((maxY/2)+40) && cursorX < ((maxX/2)+45) && cursorY < ((maxY/2)+75))
            {
                choice = 3;
                break;
            }
        }
    }

    cleardevice();

/*  Based on the choice screen will get clear and switch case statements will start
 *  getting executed.
 */
    switch (choice)
    {
        case 1 :
            startGame();
            playerOne(playerOne_XCord, playerOne_YCord);
            bot(bot_XCord, bot_YCord);
            gameFunction();
            break;

        case 2 :
            instructions();
            break;

        case 3 :
            endGame();
            break;
    }
} // END OF main() FUNCTION

// START OF startGame() FUNCTION
void startGame()
{
    setcolor(WHITE);
    int i = 100;
    int reverseLine = 1;

/*  This while loop will print all the values from 100 to 1
 *  the if part will print the odd values and the else part
 *  will print the even values.
 *  Kept some space before printing number and set the vacant space to '0'
 */
    while(i >= 10)
    {
        if(reverseLine % 2 != 0)
        {
            for(int num = 1; num <= 10; num++)
            {
                bgiout << "          " << setw(2) << setfill('0') << i ;
                i--;
            }
        }
        else
        {
            for(int num = -9; num <= 9; num++) // even
            {
                bgiout << "          " << setw(2) << setfill('0') << i+num;
                i--;
                num++;
            }
        }
        bgiout << endl << endl << endl;
        reverseLine++;
    }
    outstreamxy(95, 200);

//  vertical outlines and inlines from LEFT to RIGHT
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

//  horizontal outlines and inlines from DOWN to UP
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
    line(106,167,668,167);

    setlinestyle(0,0,3); /* increases thickness by 3px*/

//  Created ladders here
    setcolor(GREEN);
    line(252,295,420,195); //95
    line(535,240,645,433); //88
    line(185,583,466,292); //19
    line(422,485,635,630); //35

//  Created Snakes here
    setcolor(RED);
    line(186,200,533,531); //32
    line(295,340,128,480); //64
    line(408,623,292,436); //06
    line(532,382,636,236); //53

//  PLAYER details
    setcolor(WHITE);
    outtextxy(870, 157, "-  PLAYER");
    circle(855, 165, 7);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(855, 165, 15);

//  BOT details
    setcolor(WHITE);
    outtextxy(870, 182, "-  BOT ");
    circle(855, 190, 7);
    setfillstyle(SOLID_FILL,MAGENTA);
    floodfill(855, 190, 15);

//  LADDER details
    setcolor(GREEN);
    line(1105,165,1120,165);

//  SNAKE details
    setcolor(RED);
    line(1105,190,1120,190);

    setcolor(WHITE);
//  the below text will be displayed above the turn denoter
    outtextxy(1130, 157, "-  LADDERS");
    outtextxy(1130, 182, "-  SNAKES");

//  TURN denoter
    rectangle(870, 215, 1130, 263);

//  UPDATE box
    rectangle(820, 312, 1180, 504);

//  THROW DICE box
    rectangle(900, 552, 1100, 602);
    outtextxy(950,570,"THROW DICE");

//  QUIT game
    rectangle(1120, 30, 1220, 92);
    outtextxy(1130,55,"      QUIT ");

    setlinestyle(0,0,1); /* set thickness to it's default i.e. 1px*/

}// END OF startGame() FUNCTION

// START OF instructions() FUNCTION
void instructions()
{
    POINT CursorPosition;
    int cursorX, cursorY;

    setlinestyle(0,0,3); /* increases thickness by 3px*/

//  Enter game option at top right corner
    setcolor(WHITE);
    rectangle(1120, 30, 1220, 92);
    outtextxy(1128,55,"START GAME");

//  Quit game option at top left corner
    rectangle(120, 30, 220, 92);
    outtextxy(130,55,"      QUIT ");

    setlinestyle(0,0,1); /* set thickness to it's default i.e. 1px*/

/*  store the width of INSTRUCTIONS and place it to the particular positon
 *  also written set of instructions about the game.
 */
    int tWidth = textwidth("INSTRUCTIONS");
    bgiout << "INSTRUCTIONS" << endl << endl << endl;
    outstreamxy((getmaxwidth()/2)-(tWidth/2), 120);

    bgiout << "This game is played between a player & computer." << endl << endl;
    bgiout << "To play game -> Click on 'START'." << endl << endl;
    bgiout << "STATUS BOX displays whose turn it is to play." << endl << endl;
    bgiout << "Click on 'Throw Dice' to roll the die and move."<< endl << endl;
    bgiout << "If players lands at the bottom of a ladder, then the players will move up to the top of the ladder." << endl;
    bgiout << "Ladders in the game are from : " << endl;
    bgiout << "10 to 35" << endl;
    bgiout << "19 to 74" << endl;
    bgiout << "50 to 88" << endl;
    bgiout << "78 to 95" << endl << endl;
    bgiout << "If players lands on the head of a snake, then the players will slide down to the bottom of the snake." << endl;
    bgiout << "Snakes in the game board are from :" << endl;
    bgiout << "44 to 06" << endl;
    bgiout << "64 to 40" << endl;
    bgiout << "90 to 53" << endl;
    bgiout << "99 to 28" << endl << endl;
    bgiout << "UPDATE BOX displays the number on dice and position of the players after every turn." << endl << endl;
    bgiout << "To end game click -> 'QUIT'." << endl << endl;
    bgiout << "Thank you!!" << endl << endl;
    outstreamxy(170, 190);

/*  this loop will run untill the user either clicks on START GAME
 *  or QUIT GAME button
 */
    while(1)
    {
        cursorX = CursorPosition.x;
        cursorY = CursorPosition.y;
        GetCursorPos(&CursorPosition);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(cursorX > 120 && cursorY > 30 && cursorX < 220 && cursorY < 672)
            {
                cleardevice();
                endGame();
                break;
            }
            else if(cursorX > 1120 && cursorY > 30 && cursorX < 1220 && cursorY < 92)
            {
                cleardevice();
                startGame();
                playerOne(playerOne_XCord, playerOne_YCord);
                bot(bot_XCord, bot_YCord);
                gameFunction();
                break;
            }
        }
    }
}// END OF instructions() FUNCTION

// START OF endgame() FUNCTION
void endGame()
{
/*  store the width of QUIT and place it to the particular positon
 *  also written set of instructions about the game.
 */
    int tWidth = textwidth("QUIT");
    bgiout << "QUIT" << endl << endl << endl;
    outstreamxy((getmaxwidth()/2)-(tWidth/2), 120);

    bgiout << "You Ended the Game!!" << endl << endl;
    bgiout << "Press any key to exit." << endl << endl;
    bgiout << "Thanks for playing :)" << endl;
    outstreamxy(120, 250);
    getch();
    closegraph(); /* closed the graph here */
    exit(0);
}// END OF endGame() FUNCTION

// START OF gameFunction() FUNCTION
void gameFunction()
{
    POINT CursorPosition;
    int cursorX, cursorY;
    int choice;
    int randomNumberForPlayerOne;
    int randomNumberForBot;

/*  This loop will run untill player or bot reaches 100
 */
    while (playerOnePosition != 100 || botPosition != 100)
    {
        outtextxy(940,230,"PLAYER'S TURN"); /* Shows player's turn everytime after bot's turn gets over*/

/*  This loop will run untill the USER will click on throw dice button
 */
        while(1)
        {
            cursorX = CursorPosition.x;
            cursorY = CursorPosition.y;
            GetCursorPos(&CursorPosition);
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                if(cursorX > 900 && cursorY > 552 && cursorX < 1100 && cursorY < 602)
                {
/*  Accepts a random number for player and check in which condition it is true
 *  The 'if' part is for number greater than 100 which will never be true
 *  'else if' part will get true only if sum of player's position and dice is
 *  less than or equal to 100
 */
                    randomNumberForPlayerOne = throwDice();
                    if(randomNumberForPlayerOne + playerOnePosition > 100){}
                    else if(randomNumberForPlayerOne + playerOnePosition <= 100)
                    {
                        if(randomNumberForPlayerOne + playerOnePosition == 100) // WHEN dice is thrown and requireed num to win comes
                        {
/*  moveToNextNumber function will run untill the player reaches a new position
 *  then the position will get added with the dice number
 */
                            moveToNextNumber('P', randomNumberForPlayerOne, playerOnePosition);
                            playerOnePosition += randomNumberForPlayerOne;

                            bgiout << "Congratulations!!! Player Won..." <<endl << endl;
                            bgiout << "Press 'E' to exit" << endl;
                            outstreamxy(840,420);
/*  This loop will run untill the user presses on 'E' to exit the game
 */
                            char key;
                            while(1)
                            {
                                key = getch();
                                if(key == 'E' || key == 'e')
                                    break;
                            }
                            exit(0);
                        }
                        else
                        {
                            moveToNextNumber('P', randomNumberForPlayerOne, playerOnePosition);
                            playerOnePosition += randomNumberForPlayerOne;

                            switch(playerOnePosition)
                            {
                                case 10 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'L');
                                    break;
                                case 19 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'L');
                                    break;
                                case 50 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'L');
                                    break;
                                case 78 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'L');
                                    break;
                                case 44 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'S');
                                    break;
                                case 64 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'S');
                                    break;
                                case 90 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'S');
                                    break;
                                case 99 :
                                    moveFromLadderAndSnake('P',randomNumberForPlayerOne,playerOnePosition,'S');
                                    break;
                            }// END OF SWTICH CASE FOR PLAYER ONE
                        }
                    }
                    break;
                }
/*  Quit button if user wants to end the game in between playing
 */
                else if(cursorX > 1120 && cursorY > 30 && cursorX < 1220 && cursorY < 92)
                {
                    cleardevice();
                    endGame();
                }
            }
        }

        // Pauses the screen for 2 seconds
        Sleep(2 * 1000);

        randomNumberForBot = throwDice();
        if(randomNumberForBot + botPosition > 100){}
        else if(randomNumberForBot + botPosition <= 100)
        {
            if(randomNumberForBot + botPosition == 100)
            {
                moveToNextNumber('B',randomNumberForBot, botPosition);
                botPosition += randomNumberForBot;

                bgiout << "Bot Won..." <<endl << endl;
                bgiout << "Press 'E' to exit" << endl;
                outstreamxy(840,420);

                char key;
                while(1)
                {
                    key = getch();
                    if(key == 'E' || key == 'e')
                        break;
                }
                exit(0);
            }
            else
            {
                moveToNextNumber('B',randomNumberForBot, botPosition);
                botPosition += randomNumberForBot;

                switch(botPosition)
                {
                    case 10 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'L');
                        break;
                    case 19 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'L');
                        break;
                    case 50 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'L');
                        break;
                    case 78 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'L');
                        break;
                    case 44 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'S');
                        break;
                    case 64 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'S');
                        break;
                    case 90 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'S');
                        break;
                    case 99 :
                        moveFromLadderAndSnake('B',randomNumberForBot,botPosition,'S');
                        break;
                }// END OF SWTICH CASE FOR BOT
            }
        }// END OF ELSE ABOVE SWITCH CASE
    }// END OF WHILE LOOP
}// END OF gameFunction()

// structure for player
void playerOne(int X_cord, int Y_cord)
{
    setlinestyle(0,0,3);
    setcolor(WHITE);
    circle(X_cord, Y_cord, 7);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(X_cord, Y_cord, 15);
    setlinestyle(0,0,1);
}// END OF playerOne()

// structure for bot
void bot(int X_cord, int Y_cord)
{
    setlinestyle(0,0,3);
    setcolor(WHITE);
    circle(X_cord, Y_cord, 7);
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(X_cord, Y_cord, 15);
    setlinestyle(0,0,1);
}// END OF bot()

/* This function will return a random number everytime user or bot rolls a dice
 */
int throwDice()
{
    srand(time(0));
    int dice = (int) (1+rand()%6);
    return dice;
}// END OF throwDice()

/*  if player or ladder or snake this function will get called and values will get updated repectively
 *  1st 8 if - else if are for player and remaining 8 are for bot
 */
void moveFromLadderAndSnake(char ch, int numberOnDice, int obsNumber, char obs)
{
    if(ch == 'P')
    {
        cleardevice();
        startGame();
        showUpdate('P',numberOnDice,obsNumber);
        if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
        {
            // PLAYERS LADDERS
            if(obsNumber == 10)
            {
                playerOnePosition = 35;
                playerOne_XCord = 400;
                playerOne_YCord = 471;
            }
            else if(obsNumber == 19)
            {
                playerOnePosition = 74;
                playerOne_XCord = 456;
                playerOne_YCord = 275;
            }
            else if(obsNumber == 50)
            {
                playerOnePosition = 88;
                playerOne_XCord = 512;
                playerOne_YCord = 226;
            }
            else if(obsNumber == 78)
            {
                playerOnePosition = 95;
                playerOne_XCord = 400;
                playerOne_YCord = 177;
            }
            // PLAYERS SNAKES
            else if(obsNumber == 44)
            {
                playerOnePosition = 6;
                playerOne_XCord = 400;
                playerOne_YCord = 618;
            }
            else if(obsNumber == 64)
            {
                playerOnePosition = 40;
                playerOne_XCord = 120;
                playerOne_YCord = 471;
            }
            else if(obsNumber == 90)
            {
                playerOnePosition = 53;
                playerOne_XCord = 512;
                playerOne_YCord = 373;
            }
            else if(obsNumber == 99)
            {
                playerOnePosition = 28;
                playerOne_XCord = 512;
                playerOne_YCord = 520;
            }
        }
        playerOne(playerOne_XCord,playerOne_YCord);
        bot(bot_XCord,bot_YCord);
    }
    else if(ch == 'B')
    {
        cleardevice();
        startGame();
        showUpdate('B',numberOnDice,obsNumber);
        if(numberOnDice == 1 || numberOnDice == 2 || numberOnDice == 3 || numberOnDice == 4 || numberOnDice == 5 || numberOnDice == 6)
        {
            if(obsNumber == 10)
            {
                botPosition = 35;
                bot_XCord = 400;
                bot_YCord = 493;
            }
            else if(obsNumber == 19)
            {
                botPosition = 74;
                bot_XCord = 456;
                bot_YCord = 297;
            }
            else if(obsNumber == 50)
            {
                botPosition = 88;
                bot_XCord = 512;
                bot_YCord = 248;
            }
            else if(obsNumber == 78)
            {
                botPosition = 95;
                bot_XCord = 400;
                bot_YCord = 199;
            }
            // BOT SNAKES
            else if(obsNumber == 44)
            {
                botPosition = 6;
                bot_XCord = 400;
                bot_YCord = 640;
            }
            else if(obsNumber == 64)
            {
                botPosition = 40;
                bot_XCord = 120;
                bot_YCord = 493;
            }
            else if(obsNumber == 90)
            {
                botPosition = 53;
                bot_XCord = 512;
                bot_YCord = 395;
            }
            else if(obsNumber == 99)
            {
                botPosition = 28;
                bot_XCord = 512;
                bot_YCord = 542;
            }
        }
        playerOne(playerOne_XCord,playerOne_YCord);
        bot(bot_XCord,bot_YCord);
    }
} // END OF moveFromLadderOrLadder()

/*  This function give direction to the player or bot accordingly rhe dice and new position they get
 *  1st if is for MOVE RIGHT at const Y and X keeps on icreasing
 *  1st else if is for MOVE UP at MAX X axis and const Y axiz
 *  2nd else if is for MOVE LEFT at const Y and X keeps on decreasing
 *  3rd else if is for MOVE UP but at MIN X and const Y axis
 */
void moveToNextNumber(char dine, int numberAtDice, int position)
{
    //player
    if(dine == 'P')
    {
        int reach = numberAtDice+position;
        while(position != reach)
        {
            if((playerOne_XCord < 623 && (playerOne_YCord == 618 || playerOne_YCord == 520 || playerOne_YCord == 422 || playerOne_YCord == 324|| playerOne_YCord == 226 || playerOne_YCord == 128)))// FOR X COORDINATE
            {
                for(int i = 1; i <= ONE; i++)
                {
                    playerOne_XCord += 1;
                    cleardevice();
                    startGame();
                    playerOne(playerOne_XCord,playerOne_YCord);
                    bot(bot_XCord,bot_YCord);
                    showUpdate('P',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
            else if(playerOne_XCord == 624 && (playerOne_YCord == 618 || playerOne_YCord == 520 ||  playerOne_YCord == 422 || playerOne_YCord == 324|| playerOne_YCord == 226 || playerOne_YCord == 128)) // FOR MAX Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    playerOne_YCord -= 1;
                    cleardevice();
                    startGame();
                    playerOne(playerOne_XCord,playerOne_YCord);
                    bot(bot_XCord,bot_YCord);
                    showUpdate('P',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
            else if((playerOne_XCord > 120 && (playerOne_YCord == 569 || playerOne_YCord == 471 || playerOne_YCord == 373 || playerOne_YCord == 275 || playerOne_YCord == 177 || playerOne_YCord == 79))) // NEGATIVE X COORDINATE
            {
                for(int i = 1; i <= ONE; i++)
                {
                    playerOne_XCord -= 1;
                    cleardevice();
                    startGame();
                    playerOne(playerOne_XCord,playerOne_YCord);
                    bot(bot_XCord,bot_YCord);
                    showUpdate('P',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
            else if((playerOne_XCord == 120 && (playerOne_YCord == 569 || playerOne_YCord ==  471 || playerOne_YCord == 373 || playerOne_YCord == 275 || playerOne_YCord == 177 || playerOne_YCord == 79))) // FOR MIN Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    playerOne_YCord -= 1;
                    cleardevice();
                    startGame();
                    playerOne(playerOne_XCord,playerOne_YCord);
                    bot(bot_XCord,bot_YCord);
                    showUpdate('P',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
        }// END OF while loop
    }// END OF if
    // bot
    else if(dine == 'B')
    {
        int reach = numberAtDice+position;
        while(position != reach)
        {
            if((bot_XCord < 623 && (bot_YCord == 640 || bot_YCord == 542 || bot_YCord == 444 || bot_YCord == 346 || bot_YCord == 248 || bot_YCord == 150)))// FOR X COORDINATE
            {
                for(int i = 1; i <= ONE; i++)
                {
                    bot_XCord += 1;
                    cleardevice();
                    startGame();
                    bot(bot_XCord,bot_YCord);
                    playerOne(playerOne_XCord,playerOne_YCord);
                    showUpdate('B',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
            else if((bot_XCord == 624 && (bot_YCord == 640 || bot_YCord == 542 || bot_YCord == 444 || bot_YCord == 346 || bot_YCord == 248 || bot_YCord == 150))) // FOR MAX Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    bot_YCord -= 1;
                    cleardevice();
                    startGame();
                    bot(bot_XCord,bot_YCord);
                    playerOne(playerOne_XCord,playerOne_YCord);
                    showUpdate('B',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
            else if((bot_XCord > 120 && (bot_YCord == 591 || bot_YCord == 493 || bot_YCord == 395 || bot_YCord == 297 || bot_YCord == 199 || bot_YCord == 101))) // NEGATIVE X COORDINATE
            {
                for(int i = 1; i <= ONE; i++)
                {
                    bot_XCord -= 1;
                    cleardevice();
                    startGame();
                    bot(bot_XCord,bot_YCord);
                    playerOne(playerOne_XCord,playerOne_YCord);
                    showUpdate('B',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
            else if((bot_XCord == 120 && (bot_YCord == 591 || bot_YCord == 493 || bot_YCord == 395 || bot_YCord == 297 || bot_YCord == 199 || bot_YCord == 101))) // FOR MIN Y COORDINATE
            {
                for(int i = 1; i <= ONE_Y; i++)
                {
                    bot_YCord -= 1;
                    cleardevice();
                    startGame();
                    bot(bot_XCord,bot_YCord);
                    playerOne(playerOne_XCord,playerOne_YCord);
                    showUpdate('B',numberAtDice,reach);
                    delay(20);
                }
                position++;
            }
        }// END OF while loop
    }// END OF else if
}// END OF moveToNextNumber FUNCTION

/*  This function will display the updates of both the players
 *  Untill Player reaches it new position this function will keep showing update for player
 *  and then it will show bots update untill bot reaches its new position
 *  If player or bot land or ladder or snake it will print a particular statement
 */

void showUpdate(char ch, int randomNumber, int Position)
{
    bgiout << "After Rolling Dice.....\n\n";
    bgiout << "Number on Dice : ";
    outstreamxy(840,325);

    if(ch == 'P')
    {
        outtextxy(940,230,"PLAYER'S TURN");

        bgiout << setw(2) << setfill('0') << randomNumber;
        outstreamxy(960,357);
        bgiout << "\n\nPlayer Position is : " << setw(2) << setfill('0') << Position << endl << endl;
        outstreamxy(840,357);

        if(Position == 10 || Position == 19 || Position == 50 || Position == 78)
        {
            bgiout << "Hurry!! You reached on a ladder" << endl;
            outstreamxy(840,420);
        }
        else if(Position == 44 || Position == 64 || Position == 90 || Position == 99)
        {
            bgiout << "Oops!! You got bitten by a Snake" << endl;
            outstreamxy(840,420);
        }
    }
    else if(ch == 'B')
    {
        outtextxy(955,230,"BOT'S TURN");

        bgiout << setw(2) << setfill('0') << randomNumber;
        outstreamxy(960,357);
        bgiout << "\n\nBot Position is : " << setw(2) << setfill('0') << Position << endl << endl;
        outstreamxy(840,357);

        if(Position == 10 || Position == 19 || Position == 50 || Position == 78)
        {
            bgiout << "Bot reached on a ladder" << endl;
            outstreamxy(840,420);
        }
        else if(Position == 44 || Position == 64 || Position == 90 || Position == 99)
        {
            bgiout << "Bot got bitten by a Snake" << endl;
            outstreamxy(840,420);
        }
    }
} // END OF showUpdate() FUNCTION

// END
