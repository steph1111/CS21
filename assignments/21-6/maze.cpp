/**
 * @file    maze.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/18/24
 * CS21:    Assignment#5
 *
 * Definitions of methods of `Maze` class. The `Maze` class 
 * uses a `DisjointSet` to create a randomly generated maze.
*/

#include <cstdlib>
#include <time.h>
#include "maze.h"

// public: 

/**
 * Constructor for `Maze` object. Creates a randomly
 * generated maze of size `len` x `len`
 * 
 * @param len The desired length of one size of the maze
*/
Maze::Maze(unsigned len) {
    srand(time(0)); 
    // Initialize all private variables
    this->len = len;
    this->size = this->len * this->len ;
    this->maze = new DisjointSet(this->size);
    this->grid = new uint8_t[this->size];
    this->indexes = new unsigned[this->size];

    // Initialize the starting configuration of the grid 
    // and make a list of all valid indexes
    for (unsigned i = 0; i < this->size; i++) {
        this->grid[i] = 0xF; // Start all squares at 0xF, □
        this->indexes[i] = i;
    }
    // First and last square are entry points
    this->grid[0] = 0xB;
    this->grid[this->size - 1] = 0xE;

    // Shuffle indexes
    this->shuffle(this->indexes, this->size);

    // Randomly create a maze
    this->create_maze();
}

/**
 * Destructor for `Maze` object. Clean up allocated memory.
*/
Maze::~Maze() {
    delete this->maze;
    delete[] this->grid;
    delete[] this->indexes;
}

/**
 * Overload for `<<` operator. Enables usage of an output stream.
*/
std::ostream& operator<<(std::ostream& out, const Maze& maze) {
    for(unsigned i = 0 ; i < maze.size; i++) {
        out << std::hex << (int)maze.grid[i];
        if (!((i + 1) % maze.len)) out << "\n";
    }
    return out;
}

// private:

/**
 * Fisher–Yates shuffle algorithm. Shuffles elements
 * in the `array` to be arrange in a random order.
 * 
 * @param array An array to shuffle.
 * @param n Size of `array`
*/
void Maze::shuffle(unsigned* array, int n) {
    int j, temp;
    for (unsigned i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * Helper function which creates a randomized maze.
*/
void Maze::create_maze() {
    for (unsigned i = 0; i < this->size; i++) {
        this->remove_walls(this->indexes[i]);
    }
}

/**
 * Given an index, removes all valid walls from the square
 * at that position.
 * 
 * @param i Index to remove walls from 
*/
void Maze::remove_walls(unsigned i) {
    unsigned walls[4] = {left, right, up, down};

    for (unsigned j = 0; j < 4; j++) {
        switch(walls[j]) {
            case left:
                this->remove_wall(i, this->left_index(i), left_mask, right_mask);
                break;
            case right:
                this->remove_wall(i, this->right_index(i), right_mask, left_mask);
                break;
            case up:
                this->remove_wall(i, this->up_index(i), up_mask, down_mask);
                break;
            case down:
                this->remove_wall(i, this->down_index(i), down_mask, up_mask);
                break;
        }
    }
}

/**
 * Removes a single wall.
 * 
 * @param i Index to remove first wall from 
 * @param j Index to remove second wall from
 * @param mask_i Bit mask for hex representation at `i`
 * @param mask_j Bit mask for hex representation at `j`
*/
void Maze::remove_wall(unsigned i, int j, uint8_t mask_i, uint8_t mask_j) {
    // Ensures j is a valid index and the sets are not already united
    if ( j> 0 && !this->maze->same_set(i, j)) {
        this->maze->unite(this->maze->find(i), this->maze->find(j));
        // Update hex representation
        this->grid[i] &= mask_i;
        this->grid[j] &= mask_j;
    }
}

/**
 * Given an index into the grid, get the index to the left
 * 
 * @param i An index n the grid
 * @return The index to the left of `i`, -1 if out of bounds
*/
inline int Maze::left_index(unsigned i) {
    if (!(i % this->len)) return -1;
    return i - 1;
}

/**
 * Given an index into the grid, get the index to the right
 * 
 * @param i An index n the grid
 * @return The index to the right of `i`, -1 if out of bounds
*/
inline int Maze::right_index(unsigned i) {
    if (!((i + 1) % this->len)) return -1;
    return i + 1;
}

/**
 * Given an index into the grid, get the index above
 * 
 * @param i An index n the grid
 * @return The index above`i`, -1 if out of bounds
*/
inline int Maze::up_index(unsigned i) {
    if (i < this->len) return -1;
    return i - this->len;
}

/**
 * Given an index into the grid, get the index below
 * 
 * @param i An index n the grid
 * @return The index below `i`, -1 if out of bounds
*/
inline int Maze::down_index(unsigned i) {
    if (i >= this->size - this->len) return -1;
    return i + this->len;
}