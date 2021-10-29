#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<windows.h>
#include <iomanip>
// All required files are included

using namespace std;

#define screenWidth GetSystemMetrics(SM_CXSCREEN)
#define screenHeight GetSystemMetrics(SM_CYSCREEN)
// initialize any constant here if you want

int main()
{
    initwindow(screenWidth+3, screenHeight+1, "",-6,-4);

    int opt;
    cout << "Enter 1: New Game." << endl;
    cout << "Enter 2: Exit Game" << endl;
    cout << "Enter 3: Instructions" << endl;
    cin >> opt;

    if(opt == 1){
        int i = 100;
        int reverseLine = 1;

        // Try background here


        while(i >= 10)
        {
            if(reverseLine % 2 != 0) // odd
            {
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


        //line(292,630,460,485); // example ladder from 4 to 34

        // Create ladders here
        // Green or any suitable colour for Ladders




        // Create Snakes here
        // Red or any suitable colour for Snakes




        // Try Creating a background here with any multi-colour combination.
        // If overlapse or any other problem arising then try doing the same steps at line 29

        // (Read "readme.txt" file if any doubt comes)

    }
    else if(opt == 3) // instructions
    {
        bgiout << "This is a Snake and ladder game" << endl;
        bgiout << "Only 1 player can play this game" << endl;
        bgiout << "Thank you!!" << endl;
        outstreamxy(120, 200);
    }
    else // end game
    {
        bgiout << "You Ended the Game!!" << endl;
        bgiout << "Press any key to exit." << endl;
        outstreamxy(120, 200);
        getch();
        return 0;
    }


    getch();
    closegraph();
    return 0;
}

