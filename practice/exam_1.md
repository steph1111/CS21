# Exam one study guide
## Linked List
### Private variables
```cpp
private:
struct Node {
    std::string data;
    Node* next = nullptr;
    Node* prev = nullptr;
};
Node* head;
Node* tail;
int size_ = 0;
```

### Destructor
```cpp 
~LinkedList() {
    while (this->head) {
        LinkNode* old_head = this->head;
        this->head = old_head->next;
        delete old_head;
    }
}
```

### Pop back
```cpp
std::string pop_back() {
    // Make sure there is elements in the list
    if (!this->size_) {
        throw std::domain_error("Empty list");
    }
    Node* old_tail = this->tail;
    std::string old_data = this->tail->data;
    if (this->size == 1) {
        // If the size is one, removing one element makes the size zero
        // this means the head and tail should both be null
        this->head = this->tail = nullptr;
    } else {
        // The new head becomes the next node from the current head
        this->head = this->head->next;
        this->head->prev = nullptr;
    }
    // Decrease the size because we removed a node
    this->size--;
    // Delete to prevent memory leaks!
    delete old_head;
    return old_data;
}
```

### Pop front
```cpp
std::string pop_front() {
    if (!this->size) {  // Size is zero (the list is empty)
        throw std::domain_error("Empty list");
    }

    Node* old_head = this->head;
    std::string old_data = this->head->data;
    if (this->size == 1) {  // Size is zero
        // With no remaining elements in the list, head and tail both point to null
        this->head = this->tail = nullptr;
    } else {  // Size is greater than one
        this->head = this->head->next;
        this->head->prev = nullptr;
    }
    this->size--;
    delete old_head;
    return old_data;
}
```

### Push back
```cpp
std::string push_back(std::string val) {
    Node* new_node = new Node{val};
    if (this->size) {  // Size is greater than zero
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
    } else {  // Size is zero
        this->head = this->tail = new_node;  // Both head and tail are the new node
    }
    this->size++;
    return val;
}
```

### Push front
```cpp
std::string push_front(std::string val) {
    Node* new_node = new LinkNode{val};
    if (this->size) {  // Size is greater than zero
        this->head->prev = new_node;
        new_node->next = this->head;
        this->head = new_node;
    } else {  // Size is zero
        this->head = this->tail = new_node;  // Both head and tail are the new node
    }
    this->size++;
    return val;
}
```

## Int Min Heap

### Heap sort
**Order:** $O(nlgn)$ 

`heap_sort()` returns a sorted array and its size created from a heap.
```cpp
std::pair<int *, int> intMinHeap::heapsort() {
    // Store orig heap in variables
    int* ptr_to_orig_A = this->A;
    int orig_size = this->size;
    this->A = new int[this->size];

    for (int i = 0; i < this->size; i++) this->A[i] = ptr_to_orig_A[i];
    
    // Heap sort algo
    for(int i = this->size - 1; i > 0; i--) {
        this->swap(0, i);
        this->size--;
        this->heapify(0);
    }
    
    // Create pair to return of sorted array an it size
    std::pair<int *, int> sorted_pair = std::make_pair(this->A, orig_size);

    // Cleanup
    this->size = orig_size;
    this->A = ptr_to_orig_A;

    return sorted_pair;
}
```

### Heap insert
**Order:** $O(lgn)$ 

Inserts a value into the heap. Increases the size then appends the new element (-1 so we can use decrease key) to the end. Moves it to the correct position using `decrease_key()`.
```cpp
bool intMinHeap::heapinsert(int val) {
    if (this->isFull()) return false;

    this->size++;                       // Increase size
    A[size - 1] = val + 1;              // Add one so decrease key works
    this->decreasekey(size - 1, val);   // Moves to correct position

    return true;
}
```

### Minimum
**Order:** $O(1)$ 

Returns the minimum of a heap, This will always be at `A[root]`
```cpp
int minimum() {
    return this->is_empty() ? 0 : this->A[0];
}
```

### Extract min
**Order:** $O(lgn)$ 

```cpp
int extract_min() {
    if (this->is_empty()) return 0;

    int min = this->A[0];
    this->A[0] = this->A[--this->size];
    this->heapify(0);
    return min;
}
```

### Decrease key
**Order:** $O(lgn)$ 

```cpp
void intMinHeap::decreasekey(int i, int k) {
    // Bounds check
    if (i < 0 || i >= this->size || this->A[i] <= k) return;
    A[i] = k; // Promote to k (key) value
    // Move value to the right spot
    while (i > 0 && this->A[this->parent(i)] > this->A[i]) {
        this->swap(i, this->parent(i));
        i = this->parent(i);
    }
}
```
### Min of three
```cpp
int intMinHeap::minOf3(int i, int j, int k) {
    if (j >= this->size) j = i;
    if (k >= this->size) k = i;
    if (this->A[j] < this->A[i]) i = j;
    return this->A[k] < this->A[i] ? k : i;
}
```

## Quick sort
### Quicksort
**Order:** $O(nlgn)$ 
```cpp
void quicksort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
```

### Partition
```cpp
int partition(std::vector<int>& A, int p, int r) {
    // Median of three calculation to select a good pivot 
    // for vectors larger than LIMIT
    if ((r - p) > LIMIT) {
        int med = med_of_3(A, p, r);
        swap(A, med, r);
    }

    int x = A[r];                   // Pivot element
    int i = p - 1;                  // Highest index on the low side
    for (int j = p; j < r; j++) {   // For every element besides the pivot
        if (A[j] < x) {             // If the element belongs on the low side
            i++;                    // Increment low position
            swap(A, i, j);          // Put that element on the low side
        }
    }
    swap(A, i + 1, r);      // Move the pivot to its new position

    // New pivot index aka where the array is split into high and low
    return i + 1;
}

```

### Median of three
```cpp
int mo3(std::vector<int>& A, int p, int r) {
    int mid_index = p + ((r - p) / 2); // Remember the middle formula
    int left = A[p], right = A[r], mid = A[mid_index];

    if ((left > mid) ^ (left > right)) return p; // left first
    else if (right > mid ^ right > left) return r;
    return mid_index;
}
```

## Radix-bucket sort
**Order:** $O(n)$ 

```cpp
void radix_bucket_sort(std::vector<int>& A) {
    int d = 9, k = 10, n = A.size();
    int r, index;
    std::vector<int> bucket[k];

    for(int i = 1; i <= d; i++) {           // From LSD to MSD
        for(int j = 0; j < n; j++) {        // For each number in the vector
            r = _get_digit(A[j], i);        // i-th digit
            bucket[r].push_back(A[j]);      // Add number to ith-bucket
        }
        // Put numbers back in FIFO order
        index = 0;
        for(int j = 0; j < k; j++) {
            for (unsigned l = 0; l < bucket[j].size(); l++) {
                A[index] = bucket[j][l];
                index++;
            }
            bucket[j].clear();
        }
    }
}
```
```cpp
int _get_digit(int num, int i) {
    return num % (int)(pow(10, i)) / pow(10, i - 1);
}
```

## Hash table

