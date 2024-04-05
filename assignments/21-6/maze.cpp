#include "maze.h"
#include <cstdlib>
#include <time.h>


// public: 

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

Maze::~Maze() {
    delete this->maze;
    delete[] this->grid;
    delete[] this->indexes;
}

std::ostream& operator<<(std::ostream& out, const Maze& maze) {
    for(unsigned i = 0 ; i < maze.size; i++) {
        out << std::hex << (int)maze.grid[i];
        if (!((i + 1) % maze.len)) out << "\n";
    }
    return out;
}

// private:

/**
 *  Fisher–Yates shuffle algorithm.
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

void Maze::create_maze() {
    for (unsigned i = 0; i < this->size; i++) {
        this->remove_walls(this->indexes[i]);
    }
    std::cout << this->maze->get_num_sets() << std::endl;
}

void Maze::remove_walls(unsigned i) {
    unsigned walls[4] = {left, right, up, down};
    this->shuffle(walls, 4);

    for (unsigned j = 0; j < 4; j++) {
        switch(walls[j]) {
            case left:
                // std::cout << i << " " << this->left_index(i) << std::endl;
                this->remove_wall(i, this->left_index(i), left_mask, right_mask);
                break;
            case right:
                // std::cout << i << " " << this->right_index(i) << std::endl;
                this->remove_wall(i, this->right_index(i), right_mask, left_mask);
                break;
            case up:
                // std::cout << i << " " << this->up_index(i) << std::endl;
                this->remove_wall(i, this->up_index(i), up_mask, down_mask);
                break;
            case down:
                // std::cout << i << " " << this->down_index(i) << std::endl;
                this->remove_wall(i, this->down_index(i), down_mask, up_mask);
                break;
        }
    }
    // std::cout << "----------------------" << std::endl;
}

void Maze::remove_wall(unsigned i, int j, uint8_t mask_i, uint8_t mask_j) {
    if (j > 0) {
        int x = this->maze->find(i);
        int y = this->maze->find(j);
        if (x != y) {
            this->maze->unite(x, y);
            this->grid[i] &= mask_i;
            this->grid[j] &= mask_j;
        }
    }
}

inline int Maze::left_index(unsigned i) {
    if (!(i % this->len)) return -1;
    return i - 1;
}

inline int Maze::right_index(unsigned i) {
    if (!((i + 1) % this->len)) return -1;
    return i + 1;
}

inline int Maze::up_index(unsigned i) {
    if (i < this->len) return -1;
    return i - this->len;
}

inline int Maze::down_index(unsigned i) {
    if (i >= this->size - this->len) return -1;
    return i + this->len;
}