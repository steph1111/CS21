## Int Min Heap

### Heap sort
**Order:** $O(nlgn)$ 

`heap_sort()` returns a sorted array and its size created from a heap.
```cpp
std::pair<int *, int> intMinHeap::heapsort() {
    // Store orig heap in variables
    int* ptr_to_orig_A = A;
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

## Heap insert
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

## Minimum
**Order:** $O(1)$ 

Returns the minimum of a heap, This will always be at `A[root]`
```cpp
int minimum() {
    return this->is_empty() ? 0 : this->A[0];
}
```

## Extract min
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

## Decrease key
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
## Min of three
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
        swap(med, r);
    }

    int x = A[r];                   // Pivot element
    int i = p - 1;                  // Highest index on the low side
    for (int j = p; j < r; j++) {   // For every element besides the pivot
        if (A[j] < x) {             // If the element belongs on the low side
            i++;                    // Increment low position
            swap(i, j);          // Put that element on the low side
        }
    }
    swap(i + 1, r);      // Move the pivot to its new position

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
void radix_bucket_sort(std::vector<int>& A, int d = 9) {
    const int k = 10;
    int r, index;
    std::vector<int> bucket[k];
    int n = A.size();

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
