/**
 * @file    hash_table.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#6
 *
 * Definitions of methods of `DisjointSet` class. The `DisjointSet` class 
 * defines a union-find data structure.
*/

#include "disjoint_set.h"

// public:

/**
 * Constructor for `DisjointSet` object. Creates a `DisjointSet`
 * with table size `size`.
 * 
 * @param size Set size
 */
DisjointSet::DisjointSet(unsigned size) {
    this->num_elements = size;
    this->num_sets = this->num_elements;
    this->p = new int[this->num_elements];
    this->r = new int[this->num_elements];

    for (unsigned i = 0; i < this->num_elements; i++) {
        this->p[i] = i;  // Parent is itself
        this->r[i] = 0;  // Ranks start at zero
    }
}

/**
 * Destructor for `DisjointSet` object. Clean up allocated memory.
 */
DisjointSet::~DisjointSet() {
    delete[] this->p;
    delete[] this->r;
}

/**
 * Unites two disjoint sets with parents `x` and `y`.
 * Because the sets must be disjoint, the union operation
 * destroys sets S_x and S_y removing them from the collection.
 * 
 * Applies heuristic "union by rank" to improve run time.
 * For each node, a rank is maintained, which is the upper
 * bound of the height of the node. Union by rank makes the
 * root with a smaller rank point to the larger rank.
 * 
 * @param x, y Members of the sets to union.
 */
void DisjointSet::unite(int x, int y) {
    // Bounds check
    if (!this->same_set(x, y) && x >= 0 && x < (int)this->num_elements && 
        y >= 0 && y < (int)this->num_elements) {
        this->link(this->find(x), this->find(y));
    }
}

/**
 * Finds the set `x` belongs to.
 * 
 * Applies heuristic "path compression". Finds the parent and
 * flattens the structure at the same time.
 * 
 * @param x Item to find parent of
 * @return The representative of the set.
*/
int DisjointSet::find(int x) {
    if (x < 0 || x >= (int)this->num_elements) return -1;
    if (this->p[x] == x) return x;
    this->p[x] = this->find(this->p[x]);
    return this->p[x]; 
}

/**
 * Gets the number of elements in the `DisjointSet`
*/
unsigned DisjointSet::get_num_elements() const {
    return this->num_elements;
}

/**
 * Gets the number of sets in the `DisjointSet`
*/
unsigned DisjointSet::get_num_sets() const {
    return this->num_sets;
}

/**
 * Determine if two elements apart of the same set.
 * 
 * @param x, y Elements of some set 
 * @return true of `x` and `y` are in the same set, otherwise false.
*/
bool DisjointSet::same_set(int x, int y) {
    int x_parent = this->find(x);
    int y_parent = this->find(y);
    if (x_parent == -1 or y_parent == -1) return false;
    return x_parent == y_parent;
}

/**
 * Clear contents of the set.
*/
void DisjointSet::clear() {
    this->num_sets = this->num_elements;
    for (unsigned i = 0; i < this->num_elements; i++) {
        this->p[i] = i;  // Parent is itself
        this->r[i] = 0;  // Ranks start at zero
    }
}

// private:

/**
 * Tuck smaller rank "under" larger rank. If same rank, one 
 * rank increases by one
 * 
 * @param x, y Representative members of the sets to union.
 */
void DisjointSet::link(int x, int y) {
    // x has he greater rank, the parent of y becomes x
    if (this->r[x] > this->r[y]) {
        this->p[y] = x;
    } else {
        // y has the greater or equal rank, the parent of x becomes y
        this->p[x] = y;
        // y and x have the same ranking
        if (this->r[x] == this->r[y]) {
            // Increase rank of y
            this->r[y]++;
        }
    }
    // Sets are united, reduce count
    this->num_sets--;
}
