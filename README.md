# Maze Escape Game (C Programming Project)

## About This Project  
This is my version of the Maze Escape Game that I developed as part of my C Programming Assignment.

## What the Game Has

### Difficulty Levels  
- **Easy** → 8×8 maze → 50 seconds  
- **Medium** → 12×12 maze → 35 seconds  
- **Hard** → 15×15 maze → 25 seconds  

Each level becomes harder with **bigger maze size and less time**.

### Player & Goal System  
- **Player** is represented by `B`  
- **Goal** is represented by `G`  
- **Walls** are represented by `#`  
- **Empty path** is represented by a space  

Your objective is to guide **B to G** within the time limit.

### Real-Time Player Movement  
You can move the player **without pressing Enter**, using:  
- Arrow Keys  
- W / A / S / D  

This gives **smooth and fast control**.

### Timer System  
Each level runs with a **countdown timer**:  
- Reach `G` before time ends → ✅ **You Win**  
- Time becomes zero → ❌ **Game Over**  

### Restart Option after Win or Lose  
After winning or losing:  
- Press **R** → Restart the game  
- Press any other key → Exit the game  

This allows **replay without closing the program**.

### Colored Console Output  
Using Windows console colors:  
- Player `B` → Blue  
- Goal `G` → Pink  
- Walls and path → White  

This improves both **visibility and appearance**.

### Smooth Screen Redraw  
Instead of clearing screen with `cls` (which causes blinking), I used:  
SetConsoleCursorPosition()
This makes animation **smooth and flicker-free**.

## How to Play

**Controls:**  

| Action | Keys |
|--------|------|
| Move Up | Arrow Up / `A` |
| Move Down | Arrow Down / `D` |
| Move Left | Left Arrow / `A` |
| Move Right | Right Arrow / `D` |
| Restart Game (after Game Over) | `R` |
| Exit Game (after Game Over) | Any other key |


**Gameplay Steps:**  
1. Start the game and select a difficulty level.  
2. The maze appears with player `B` and goal `G`.  
3. Move using control keys.  
4. Avoid walls (`#`).  
5. Reach the goal (`G`) before the timer runs out.  
6. If you win, a success screen appears with time taken.  
7. If time ends, a “Game Over” screen appears.  
8. Restart or exit as you wish.

## Functions I Added  
- Three difficulty levels  
- Timer-based gameplay  
- Real-time movement without Enter  
- Restart option after win or game over  
- Colored console output  
- Smooth animation without screen blinking  
- Clean success and game over screens  

## What I Learned  
During this project I gained experience in:  
- Working with 2D arrays  
- Handling real-time input using `_kbhit()` and `getch()`  
- Using Windows console cursor movement  
- Implementing a timer using `time()` and `difftime()`  
- Designing game loops  
- Collision detection with walls  
- Restarting program without exiting  
- Improving console UI using colors

---

### Made by: Namit Garg
### Section: AD
### Roll no.: 12515001002 (38)
### B.Tech CSE – Assignment 3
