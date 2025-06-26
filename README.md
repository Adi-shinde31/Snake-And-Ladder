# Snake and Ladder Game

A classic Snake and Ladder board game implemented in C++ using BGI (Borland Graphics Interface) graphics library. This game features a graphical user interface where a human player competes against a computer bot.

**Note**: This game requires a BGI-compatible C++ compiler and graphics library. Modern systems may need additional setup or compatibility layers to run BGI applications.

## Features

- **Graphical Interface**: Full-screen game board with visual representation
- **Player vs Bot**: Play against an AI opponent
- **Interactive Controls**: Click-based controls for dice rolling and navigation
- **Animated Movement**: Smooth player movement animations across the board
- **Real-time Updates**: Live status updates and turn indicators
- **Classic Rules**: Traditional Snake and Ladder gameplay mechanics

## Game Elements

### Board Layout
- **100-square board** (10x10 grid) numbered from 1 to 100
- **Ladders**: Help players climb up faster
  - Square 10 → 35
  - Square 19 → 74
  - Square 50 → 88
  - Square 78 → 95
- **Snakes**: Make players slide down
  - Square 44 → 6
  - Square 64 → 40
  - Square 90 → 53
  - Square 99 → 28

### Visual Elements
- **Player**: Blue circle representing human player
- **Bot**: Magenta circle representing computer opponent
- **Ladders**: Green lines on the board
- **Snakes**: Red lines on the board

## 📸 Screenshots

![Start Window](https://github.com/Adi-shinde31/Snake-And-Ladder/blob/master/output/startwindow.png)
![Image 1](https://github.com/Adi-shinde31/Snake-And-Ladder/blob/master/output/image1.png)
![Image 2](https://github.com/Adi-shinde31/Snake-And-Ladder/blob/master/output/image2.png)

## Prerequisites

### System Requirements
- Windows operating system
- C++ compiler with BGI graphics support (Turbo C++/Dev-C++ with BGI)
- Graphics.h library
- Windows.h library

### Required Libraries
```cpp
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <iomanip>
```

## Installation and Setup

1. **Install BGI Graphics Library**
   - Download and install a C++ compiler that supports BGI (Turbo C++ or Dev-C++ with BGI package)
   - Ensure graphics.h is properly configured

2. **Compile the Game**
   ```bash
   # Using any BGI-compatible compiler
   gcc -o game.exe game.cpp -lgraph
   ```

3. **Run the Game**
   ```bash
   ./game.exe
   ```

## How to Play

### Main Menu
The game starts with three options:
- **START**: Begin a new game
- **INSTRUCTIONS**: View game rules and controls
- **END GAME**: Exit the application

### Gameplay
1. **Starting**: Click on "START" to begin the game
2. **Taking Turns**: 
   - Player goes first
   - Click "THROW DICE" to roll the dice
   - Your piece moves automatically based on the dice roll
   - Bot takes its turn automatically after a 2-second delay
3. **Special Squares**:
   - Landing on a ladder's bottom moves you to its top
   - Landing on a snake's head slides you down to its tail
4. **Winning**: First player to reach exactly square 100 wins
5. **Quitting**: Click "QUIT" anytime to end the game

### Game Rules
- Players must roll the exact number needed to reach square 100
- If the dice roll would take you beyond 100, you don't move
- Landing on ladders automatically moves you up
- Landing on snakes automatically moves you down
- The game alternates between player and bot turns

## User Interface Elements

### Game Board
- **10x10 grid** with numbers 1-100
- **Turn Indicator**: Shows whose turn it is
- **Update Box**: Displays dice roll results and current positions
- **Throw Dice Button**: Click to roll the dice
- **Quit Button**: Exit the game anytime

### Status Information
- **Player Indicator**: Blue circle with "PLAYER" label
- **Bot Indicator**: Magenta circle with "BOT" label
- **Ladder Indicator**: Green line with "LADDERS" label
- **Snake Indicator**: Red line with "SNAKES" label

## Code Structure

### Main Functions
- `main()`: Entry point with menu system
- `startGame()`: Initializes and draws the game board
- `gameFunction()`: Main game loop handling turns
- `instructions()`: Displays game instructions
- `endGame()`: Handles game termination

### Player Functions
- `playerOne()`: Draws player piece
- `bot()`: Draws bot piece
- `throwDice()`: Generates random dice roll (1-6)

### Movement Functions
- `moveToNextNumber()`: Animates piece movement
- `moveFromLadderAndSnake()`: Handles ladder/snake interactions
- `showUpdate()`: Updates game status display

## Technical Details

### Graphics Implementation
- Uses BGI graphics library for rendering
- Full-screen window creation with system metrics
- Real-time mouse click detection for user interaction
- Smooth animation with delay-based movement

### Game Logic
- Turn-based gameplay with alternating player/bot moves
- Random number generation for dice rolls
- Coordinate-based piece positioning
- Win condition checking

## Controls

- **Mouse Click**: Navigate menus and roll dice
- **Left Mouse Button**: Interact with buttons and options
- **Keyboard**: 
  - 'E' or 'e': Exit game after winning
  - Any key: Exit from quit screen

## 🔗 Connect

- [LinkedIn](https://www.linkedin.com/in/adi-shinde31/)
- [GitHub](https://github.com/Adi-shinde31)
- [Portfolio](https://adityashinde.netlify.app/)