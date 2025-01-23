/**
 * @file    maze.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * CS21:    Assignment#8
 *
 * Declarations of methods of `Maze` class. The `Maze` class 
 * provides functionality to load in an nxn maze of ASCII characters
 * and prints the solution.
*/

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>
#include <list>
#include <sstream>

class Maze {
    struct Node;
    public:
    /**
     * Loads an nxn maze of ASCII hex characters (0-F) from stdin.
     */
    void load_maze();

    /**
     * Finds the solution to the maze using breadth first search (BFS).
     */
    void solve_maze();

    /**
     * Prints the solution to the maze as a list of  coordinates.
     * 
     * Prints one coordinate per line, describing the path from the
     * start to the exit (starting at (0, 0)). The first coordinate
     * is the column and the second is the row.
     */
    void print_solution();

    /**
     * Clean up dynamically allocated memory.
     */
    ~Maze();

    private:
    /**
     * Given the index of a node (i) and its walls described by a 
     * uint8_t, adds its adjacencies to an internal adjacency list.
     * 
     * @param walls Walls of the node, represented by a uint8.
     * @param i Index of node to find adjacencies of. 
     */
    void add_adj(std::uint8_t walls, int i);
    
    int n;
    int size;
    std::vector<int>* adj;
    Node** grid;

    struct Node {
        int c = -1; // Column
        int r = -1; // Row
        int i = -1; // Index
        bool visited = false;
        Node* parent = nullptr;

        Node(int col, int row, int index) {
            this->c = col;
            this->r = row;
            this->i = index;
        }
    };
};

#endif  // MAZE_H