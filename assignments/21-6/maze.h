
#ifndef MAZE_H
#define MAZE_H

#include <cstdint>
#include <iostream>
#include "disjoint_set.h"

class Maze {
    public:
    Maze(unsigned len);
    ~Maze();
    friend std::ostream& operator<<(std::ostream& out, const Maze& maze);
    
    private:
    void shuffle(unsigned* array, int n);
    void create_maze();
    void remove_walls(unsigned i);
    void remove_wall(unsigned i, int wall, uint8_t mask_i, uint8_t mask_j);
    inline int left_index(unsigned i);
    inline int right_index(unsigned i);
    inline int up_index(unsigned i);
    inline int down_index(unsigned i);

    unsigned len;
    unsigned size;
    DisjointSet* maze;
    uint8_t* grid;  // Represents each square in the computer 
    unsigned* indexes;
    enum directions {left, right, up, down};
    enum masks {left_mask=11, right_mask=14, up_mask=7, down_mask=13};
};

#endif  // MAZE_H