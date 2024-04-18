/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/18/24
 * CS21:    Assignment#6
 * Status:  
 *
 * Demonstrates functionality of the `Maze` class.
*/


#include <iostream>
#include "maze.h"

int main(int argc, char** argv) {
    srand(time(0)); 
    if (argc > 1) {
        int n = std::atoi(argv[1]);
        if (n < 3) {
            std::cerr << "Error: (Argument 1) Maze length must be 3 or greater.\n";
        } else {
            Maze maze(n);
            maze.create_maze();
            std::cout << maze;
        }
    } else {
        std::cerr << "Error: Must provide an argument specifying the maze length.\n";
    }
    return 0;
}