# Assignment 8: Breadth-First Search

## Program Description
Reading in a graph (a nxn maze), use a BFS to find a shortest path from the start to the exit.


## Input
Your program will load nxn sized mazes from STDIN. The maze will consist of n lines of n (hex) ASCII characters. There will be no other input. The hex characters ('A' through 'F') may appear in either upper or lower case—you'll need to handle both cases. Each square in the maze is bounded by four positions: right(1), bottom(2), left(4) and top(8). Each position may have a wall, or may be open. Each square in the maze can be represented by one hex digit (0, 1, 2 ... F). (For example, 'D' is a square with walls to the left, right and top and 'f' is a square surrounded by walls.) The maze will have a start at the top left (from the left), an exit at the bottom right (to the right). The walls in adjacent squares must match. (For example, the sequence "69" could appear in a legal maze, but not "6D".) In the resulting maze, every square should be 'reachable' from every other square. (For example, "a9D", "C03", "76a" is a legal 3x3 maze.)

When I test your program, I will only use mazes that I've verified have a valid path between the start and end squares. A test maze might not have every square reachable from the start square.

## Output
A list of coordinates (one coordinate per line) describing the path from the start to the exit (starting at (0, 0) for the upper left and increasing in value to the left or down) Print proper-looking coordinates (that is with parenthesis and a comma and space between the row and column.) The first coordinate is the column and the second is the row, so display them as (x, y) not (y, x)

## What you turn in
Put all of the source code files (.cpp, .h, makefile if approprite, .java, etc.) but no executeables, binaries, compiler, or data files (omit .o, "a.out" , .class files etc.) in a folder named as shown above in the home directory of your account on pengo. Please don't include any sub-folders.
