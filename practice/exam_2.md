# Exam one study guide
## Disjoint Set

## Binary search tree
### Overview
A binary search tree is a data structure in which dynamic set operations operate in $O(h)$ time where $h$ is the height of the tree.

The height of the tree $h$ is $\text{lg}n$ in the best case where the tree is fully balanced. In an unbalanced tree, the height becomes $n$, in the worst case (a linear chain of $n$ nodes).

In a binary search tree, for each node, nodes in the left-subtree are lesser, and nodes in the right-subtree are greater. The sub-trees are also binary search trees. 

**Binary search tree property:** Let $x$ be a node in a binary search tree. If node $y$ is a node in the left subtree of $x$, then $y.key \le x.key$. If a $y$ is in the right subtree of $x$, then $y.key \ge x.key$.

#### In a binary search tree with height n, what is the minimum and maximum number of nodes that can be stored in the tree?
- Minimum $n$ nodes
- Maximum $n^2 - 1$ nodes.

#### In a binary search tree that is built with links, what is the least efficient arrangement of data?
- A linear chain of n nodes.

### Traversals: $O(n)$
For each traversal, print the key of the nodes to STDOUT.  
#### Inorder (prints nodes in sequential order, smallest to largest).
```cpp
void inorder(Node* node) const {
    if (node) {
        inorder(node->left);
        std::cout << node->key << std::endl;
        inorder(node->right);
    }
}
```

#### Preorder (used for destructor)
```cpp
void preorder(Node* node) const {
    if (node) {
        std::cout << node->key << std::endl;
        preorder(node->left);
        preorder(node->right);
    }
}
```

#### Postorder
```cpp
void preorder(Node* node) const {
    if (node) {
        preorder(node->left);
        preorder(node->right);
        std::cout << node->key << std::endl;
    }
}
```

### Search: $O(h)$
Remember that nodes to the left are lesser, and nodes to the right are greater.
```cpp
Node* search(Node* node, int key) const {
    if (node == nullptr || node->key == key) return node;
    if (key < node->key) return search(node->left, key);
    if (key > node->key) return search(node->right, key);
}
```
### Minimum and maximum: $O(h)$
#### Minimum
Go left
```cpp
Node* min(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->left) {
        node = node->left;
    }
    return node;
}
```

#### Maximum
Go right
```cpp
Node* max(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->right) {
        node = node->right;
    }
    return node;
}
```

### Ancestors: $O(h)$
#### Successor
Given a node $x$, its successor $y$ is the smallest node greater than x.

Three cases:
1. No nodes in the tree
2. $x$ has a right subtree: Find the minimum in the right tree.
3. $x$ does not have a right subtree: Go up, until $x$ is a left chile of its parent. Return the parent.

```cpp
Node* successor(Node* node) const {
    // Case 1
    if (node == nullptr) return nullptr;
    // Case 2
    if (node->right) return min(node->right);
    // Case 3
    Node* p = node->parent;
    while(p && p->right == node) {
        node = p;
        p = node->parent;
    }
    return p;
}
```

#### Predecessor
Given a node $x$, its predecessor $y$ is the largest node less than x.
```cpp
Node* predecessor(Node* node) const {
    if (node == nullptr) return nullptr;
    if (node->left) return max(node->left);
    Node* p = node->parent;
    while(p && p->left == node) {
        node = p;
        p = node->parent;
    }
    return p;
}
```

### Insert: $O(h)$
Two variables, one for current node, and one for parent of current node. Starts at the root
```cpp
void insert(int key) {
    Node* cur = root;
    Node* p = nullptr;
    while (cur) {
        p = cur;
        if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    Node* insertion = new Node;
    insertion->key = key;
    if (p == nullptr) {
        root = insertion;
    } else {
        insertion->parent = p;
        if (key < p) {
            p->left = insertion;
        } else {
            p->right = insertion;
        }
    }
}
```