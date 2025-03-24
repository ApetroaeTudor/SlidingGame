# Command-line sliding puzzle game

Implemented in C++. The game consists of a 3x3 board, where tiles numbered from 1 to 8 and an empty space (represented by 0) can be rearranged by the player. The objective is to slide the tiles to recreate the solved configuration.

**Game Features**

1.Randomized Board Generation: The board shuffles the tiles at the beginning of each game to create a unique puzzle configuration.

2.Tile Switching: Players can select a tile to move, which will swap with the adjacent empty space if the move is valid.

3.Victory Check: The game automatically checks if the current configuration matches the solution and ends the game when the puzzle is solved.

4.CLI Output: The board's current state is printed to the console after each move.
