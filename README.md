# NamitGarg-C-Assignment.3
## Maze Escape Game – C Console Project
## About This Project

This is my version of the Maze Escape Game that I developed as part of my C Programming Assignment.

 ## What the Game Has
## Here are the main features I added:

### Difficulty Levels
The game includes three difficulty levels:
Easy → 8×8 maze → 50 seconds
Medium → 12×12 maze → 35 seconds
Hard → 15×15 maze → 25 seconds

Each level becomes harder with bigger maze size and less time.

### Player & Goal System
Player is represented by B
Goal is represented by G
Walls are represented by #
Empty path is represented by space

Your objective is to guide B to G within the time limit.

### Real-Time Player Movement
You can move the player without pressing Enter using:
Arrow Keys
OR W, A, S, D
This gives smooth and fast control.

### Timer System
Each level runs with a countdown timer:
Reach G before time ends → ✅ You Win
Time becomes zero → ❌ Game Over
✅ Restart Option

After winning or losing, you can:
Press R → Restart the game
Press any other key → Exit the game
This allows replay without closing the program.

### Colored Console Output
The game uses Windows console colors:
Player B → Blue
Goal G → Pink
Walls and path → White
This improves both visibility and appearance.

### Smooth Screen Redraw
Instead of clearing the screen repeatedly with cls (which causes blinking), I used:
SetConsoleCursorPosition()
This makes the animation smooth and flicker-free.

### How to Play

 Controls:
Action	Keys
Move Up	Arrow Up / W
Move Down	Arrow Down / S
Move Left	Arrow Left / A
Move Right	Arrow Right / D
Restart Game	R
Exit Game	Any Other Key

Gameplay Steps

1)Start the game and select a difficulty level.
2)The maze appears with player B and goal G.
3)Move through the maze using the control keys.
4)Avoid walls (#).
5)Reach the goal (G) before the timer runs out.
6)If you win, the Success Screen appears with time taken.
7)If time runs out, the Game Over Screen appears.
8)Restart or exit as you wish.

### Functions I Added

Three difficulty levels
Timer-based gameplay
Real-time movement without Enter
Restart option after win or game over
Colored console output
Smooth animation without screen blinking
Clean success and game over screens

### What I Learned
While developing this project, I learned:
Working with 2D arrays
Handling real-time input using _kbhit() and getch()
Using Windows console cursor movement
Implementing a timer using time() and difftime()
Designing game loops
Collision detection with walls
Restarting programs without exiting
Improving console UI using colors
