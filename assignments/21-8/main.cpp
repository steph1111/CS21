#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>
#include <list>
#include <sstream>

class Maze {
    struct Node;
    public:
    void load_maze();
    void solve_maze();
    void print_solution();
    ~Maze();

    private:
    void add_edge(std::uint8_t walls, int i);
    int n;
    int size;
    std::vector<int>* adj;
    Node** grid;

    struct Node {
        int r = -1;
        int c = -1;
        int i = -1;
        bool visited = false;
        Node* parent = nullptr;

        Node(int col, int row, int index) {
            this->c = col;
            this->r = row;
            this->i = index;
        }
    };

};

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
            // Add the edges of that node
            this->add_edge(std::stoi(row.substr(c, 1), 0, 16), i);
        }
        r++; // Increment number of rows
    } while(std::cin >> row);
}

void Maze::add_edge(std::uint8_t walls, int i) {
    // Has right edge, add it to adjacency list
    if (!(walls & 0b0001) && i != this->size - 1) this->adj[i].push_back(i + 1);

    // Has up edge, add it to adjacency list
    if (!(walls & 0b0010)) this->adj[i].push_back(i - this->n);

    // Has left edge, add it to adjacency list
    if (!(walls & 0b0100) && i != 0) this->adj[i].push_back(i - 1);

    // Has down edge, add it to adjacency list
    if (!(walls & 0b1000)) this->adj[i].push_back(i + this->n);
}

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
        for (int j = 0; j < this->adj[v->i].size(); j++) {
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

void Maze::print_solution() {
    Node* cur = this->grid[this->size - 1]; // Last node is the end of the maze
    std::list<std::string> path;
    std::stringstream ss;

    while(cur) {
        ss << "(" << cur->c <<  ", " << cur->r << ")";
        path.push_front(ss.str());
        cur = cur->parent;
    }
    for (const std::string& cord : path) {
        std::cout << cord << std::endl;
    }
}

Maze::~Maze() {
    delete[] this->adj;
    for (unsigned i = 0; i < this->size; ++i) {
        delete this->grid[i];
    }
    delete[] this->grid;
}

int main() {
    Maze maze;
    maze.load_maze();
    maze.solve_maze();
    maze.print_solution();

    return 0;
}