/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * CS21:    Assignment#8
 * Status:  Working/tested
 *
 * Demonstrates functionality of the `Maze` class.
*/

#include "maze.h"

int main() {
    Maze maze;
    maze.load_maze();
    maze.solve_maze();
    maze.print_solution();
    return 0;
}