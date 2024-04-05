/**
 * @file    maze.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/18/24
 * CS21:    Assignment#6
 *
 * Declaration of `Maze` class and methods. The `Maze` class 
 * uses a `DisjointSet` to create a randomly generated maze.
*/

#ifndef MAZE_H
#define MAZE_H

#include <cstdint>
#include <iostream>
#include "disjoint_set.h"

class Maze {
    public:
    /**
     * Constructor for `Maze` object. Creates a randomly
     * generated maze of size `len` x `len`
     * 
     * @param len The desired length of one size of the maze
    */
    Maze(unsigned len);

    /**
     * Destructor for `Maze` object. Clean up allocated memory.
    */
    ~Maze();

    /**
     * Overload for `<<` operator. Enables usage of an output stream.
    */
    friend std::ostream& operator<<(std::ostream& out, const Maze& maze);
    
    private:
    /**
     * Fisher–Yates shuffle algorithm. Shuffles elements
     * in the `array` to be arrange in a random order.
     * 
     * @param array An array to shuffle.
     * @param n Size of `array`
    */
    void shuffle(unsigned* array, int n);

    /**
     * Helper function which creates a randomized maze.
    */
    void create_maze();

    /**
     * Given an index, removes all valid walls from the square
     * at that position.
     * 
     * @param i Index to remove walls from 
    */
    void remove_walls(unsigned i);

    /**
     * Removes a single wall.
     * 
     * @param i Index to remove first wall from 
     * @param j Index to remove second wall from
     * @param mask_i Bit mask for hex representation at `i`
     * @param mask_j Bit mask for hex representation at `j`
    */
    void remove_wall(unsigned i, int wall, uint8_t mask_i, uint8_t mask_j);
    
    /**
     * Given an index into the grid, get the index to the left
     * 
     * @param i An index n the grid
     * @return The index to the left of `i`, -1 if out of bounds
    */
    inline int left_index(unsigned i);

    /**
     * Given an index into the grid, get the index to the right
     * 
     * @param i An index n the grid
     * @return The index to the right of `i`, -1 if out of bounds
    */
    inline int right_index(unsigned i);

    /**
     * Given an index into the grid, get the index above
     * 
     * @param i An index n the grid
     * @return The index above`i`, -1 if out of bounds
    */
    inline int up_index(unsigned i);

    /**
     * Given an index into the grid, get the index below
     * 
     * @param i An index n the grid
     * @return The index below `i`, -1 if out of bounds
    */
    inline int down_index(unsigned i);

    unsigned len;
    unsigned size;
    DisjointSet* maze;
    uint8_t* grid;
    unsigned* indexes;
    enum directions {left, right, up, down};
    enum masks {left_mask=11, right_mask=14, up_mask=7, down_mask=13};
};

#endif  // MAZE_H