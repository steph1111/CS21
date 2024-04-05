/**
 * @file    disjoint_set.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/18/24
 * CS21:    Assignment#6
 *
 * Declaration of `DisjointSet` class and methods. The `DisjointSet` class defines a 
 * union-find data structure.
*/

#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

class DisjointSet {
    public:
    /**
     * Constructor for `DisjointSet` object. Creates a `DisjointSet`
     * with table size `size`.
     * 
     * @param size Set size
     */
    DisjointSet(unsigned size);

    /**
     * Destructor for `DisjointSet` object. Clean up allocated memory.
     */
    ~DisjointSet();

    /**
     * Unites to disjoint sets with parents `x` and `y`.
     * Because the sets must be disjoint, the union operation
     * destroys sets S_x and S_y removing them from the collection.
     * 
     * Applies heuristic "union by rank" to improve run time.
     * For each node, a rank is maintained, which is the upper
     * bound of the height of the node. Union by rank makes the
     * root with a smaller rank point to the larger rank.
     * 
     * @param x, y Representative members of the sets to union.
     */
    void unite(int x, int y);

    /**
     * Finds the set `x` belongs to.
     * 
     * Applies heuristic "path compression". Finds the parent and
     * flattens the structure at the same time.
     * 
     * @param x Item to find parent of
     * @return The representative of the set.
    */
    int find(int x); 

    /**
     * Gets the number of elements in the `DisjointSet`
    */
    unsigned get_num_elements() const;

    /**
     * Gets the number of sets in the `DisjointSet`
    */
    unsigned get_num_sets() const;

    /**
     * Determine if two elements apart of the same set.
     * 
     * @param x, y Elements of some set 
     * @return true of `x` and `y` are in the same set, otherwise false.
    */
    bool same_set(int x, int y);

    private:
    void link(int x, int y);
    unsigned num_elements;
    unsigned num_sets;
    // Parallel arrays
    int* p; // parent
    int* r; // rank
};

#endif  // DISJOINT_SET_H