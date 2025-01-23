/**
 * @file    maze.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * CS21:    Assignment#8
 *
 * Definitions of methods of `Maze` class. The `Maze` class 
 * provides functionality to load in an nxn maze of ASCII characters
 * and prints the solution.
*/

#include "maze.h"

/**
 * Loads an nxn maze of ASCII hex characters (0-F) from stdin.
 */
void Maze::load_maze() {
    std::string row;
    std::cin >> row;  // Input one row of the maze to find out the dimensions
    int r = 0, i = 0; // Row index (r) and grid index (i)

    // Set variables now that the dimensions are known
    this->n     = row.size();
    this->size  = this->n * this->n;
    this->adj   = new std::vector<int>[this->size];
    this->grid  = new Node*[this->size];

    do {
        // For each column in the row
        for (int c = 0; c < this->n; c++, i++) {
            // Add that node to the grid
            this->grid[i] = new Node(c, r, i);
            // Add the neighbors of that node
            this->add_adj(std::stoi(row.substr(c, 1), 0, 16), i);
        }
        r++; // Increment number of rows
    } while(std::cin >> row);
}

/**
 * Finds the solution to the maze using breadth first search (BFS).
 */
void Maze::solve_maze() {
    Node* root = this->grid[0];
    // Label root as explored
    root->visited = true;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* v = q.front(); // Node being explored
        q.pop(); // Remove node being explored from the queue
        // for all neighbors adjacent to v
        for (unsigned j = 0; j < this->adj[v->i].size(); j++) {
            // Current neighbor
            Node* u = this->grid[this->adj[v->i][j]];
            // If we have not visited it yet, mark as visted
            if(!u->visited) {
                u->visited = true;
                u->parent = v;
                q.push(u);
            }
        }
    }
}

/**
 * Prints the solution to the maze as a list of  coordinates.
 * 
 * Prints one coordinate per line, describing the path from the
 * start to the exit (starting at (0, 0)). The first coordinate
 * is the column and the second is the row.
 */
void Maze::print_solution() {
    Node* cur = this->grid[this->size - 1]; // Last node is the end of the maze
    std::list<std::string> path;
    std::stringstream ss;

    while(cur) {
        ss << "(" << cur->c <<  ", " << cur->r << ")";
        path.push_front(ss.str());
        cur = cur->parent;
        ss.str("");
    }
    for (const std::string& cord : path) {
        std::cout << cord << std::endl;
    }
}

/**
 * Clean up dynamically allocated memory.
 */
Maze::~Maze() {
    delete[] this->adj;
    for (int i = 0; i < this->size; ++i) {
        delete this->grid[i];
    }
    delete[] this->grid;
}

// private:

/**
 * Finds the solution to the maze using breadth first search (BFS).
 */
void Maze::add_adj(std::uint8_t walls, int i) {
    // Walls: right(1), down(2), left(4) and up(8)

    // Has right neighbor, add it to adjacency list
    if (!(walls & 0b0001) && i != this->size - 1) this->adj[i].push_back(i + 1);

    // Has down neighbor, add it to adjacency list
    if (!(walls & 0b0010)) this->adj[i].push_back(i + this->n);

    // Has left neighbor, add it to adjacency list
    if (!(walls & 0b0100) && i != 0) this->adj[i].push_back(i - 1);

    // Has up neighbor, add it to adjacency list
    if (!(walls & 0b1000)) this->adj[i].push_back(i - this->n);
}