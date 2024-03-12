import java.io.Serializable;

class intMinHeap implements Serializable {
    /**
     * Constructor for intMinHeap object. Creates a intMinHeap
     * with capacity `cap`
     * 
     * @param cap Capacity of intMinHeap
     */
    public intMinHeap(int cap){ 
        A = new int [cap];
        capacity = cap;
        size = 0;
    }

    /**
     * Sorts heap into a sorted array 
     * 
     * @return A pair in which the first element is the sorted array
     *         and the second element is the size.
    */
    public int [] heapsort(){
        // Store orig heap in variables
        int[] original = A;
        int orig_size = size;
        A = new int[size];

        
        // int orig_size = this->size;
        // this->A = new int[this->size];
    }

    /**
     * Converts contents of heap to a formatted string
     * 
     * @return Contents of heap as a formatted string
    */
    public String toString(){
        StringBuilder str = new StringBuilder();
        str.append("heap size " + size + ":");
        for (int i = 0; i < size - 1; i++) {
            str.append(A[i] + ", ");
        }
        if (!isEmpty()) str.append(A[size - 1]);

        return str.toString();
    }

    /**
     * Insert a new value into the heap
     * 
     * @param val Value to insert
     * @return True if the insert worked, other false if not
    */
    public boolean heapinsert(int n){
        if (isFull()) return false;

        size++;                     // Increase size
        A[size - 1] = n + 1;        // Add one so the old value in decrease key works
        decreaseKey(size - 1, n);   // Moves to correct position

        return true;
    }  

    /**
     * Returns the minimum value in the heap, A[root].
     * 
     * @return A[root], 0 if empty heap
     */
    public int minimum(){  return (isEmpty()) ? 0 : A[0]; } 
    
    /**
     * Removes and returns the minimum value in the heap, A[root].
     * 
     * @return A[root], 0 if the the size is 0
    */
    public int extractMin(){ 
        if (isEmpty()) return 0;

        int min = A[0];
        A[0] = A[--size];
        heapify(0);
        return min;
    }

    /**
     * Promote value at index `i` to `k`
     * 
     * @param i Index to promote 
     * @param k Value to promote to
    */
    public void decreaseKey(int i, int k){
        if (i < 0 || i >= size || A[i] <= k) return;
        A[i] = k;
        while (i > 0 && A[parent(i)] > A[i]) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    /**
     * Returns if the heap is empty
     * 
     * @return true if the heap is empty, otherwise false
     */
    public boolean isEmpty(){ return size == 0; }

    /**
     * Returns if the heap size is the capacity
     * 
     * @return true if the heap is full, otherwise false
     */
    public boolean isFull(){ return size == capacity; }

    /**
     * Swaps elements in the heap at provided indexes.
     * Assumes indexes provided are valid.
     * 
     * @param i, j Indexes of nodes to swap
     */
    private void swap(int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    /**
     * Converts an array to a integer minimum heap
    */
    private void buildheap(){
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    /**
     * Returns the max minimum of three nodes
     * 
     * @param i, j, k Indexes of nodes to compare
     * @return Index of the minimum value node 
    */
    private int minOf3(int i, int j, int k){ 
        if (j >= size || j < 0) j = i;
        if (k >= size || k < 0) k = i;
        int min_index_i_j = A[i] < A[j] ? i : j;
        return A[min_index_i_j] < A[k] ? min_index_i_j : k;
    }

    /**
     * Returns the right node index
     * 
     * @param i Index of node to find the right node of
     * @return The index of the right node to `i`
     */
    private int left(int i){ return 2 * i + 1; }

    /**
     * Returns the right node index
     * 
     * @param i Index of node to find the right node of
     * @return The index of the right node to `i`
     */
    private int right(int i){ return 2 * i + 2; }

    /**
     * Returns the right node index
     * 
     * @param i Index of node to find the right node of
     * @return The index of the right node to `i`
     */
    private int parent(int i){ return 2 * i + 2; }

    /**
     * Preserve the heap property A[i] >= A[parent(i)]
     *  
     * @param i Index of the node to apply heapify on 
     */
    private void heapify(int i){
        int n = minOf3(i, left(i), right(i));
        if (n != i) {
            swap(i, n);
            heapify(n);
        }
    }

    private int [] A;
    private int capacity;   // size of array A
    private int size;       // size of data in array A
}