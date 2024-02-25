# Assignment 2: Integer Minimum Heap and Priority Queue

## Program Description
Using the given class definitions for either C++ or Java, create a minimum heap that stores integers and and implements a minimum priority queue. (Your program can be "hard coded" for integers - it does not need to use templates, generics, or polymorphism.) Note that the test routine will only insert positive integers, but your heap must work with all integers.
Your data structure must always store its internal data as a binary heap.
Your `toString()` function should return a string with the heap values as a comma separated list, also including the size of the heap as well. `toString()` must show the values in the same ordering as they are in the heap.
- Your `heapsort()` function should create a **new array** with the sorted values and **not modify** the heap. That resulting array must be sized to exactly hold the number of elements in the result. Since this is a minimum heap, the heap sort should generate data in descending order. Note that "not modify" means that your data when the function terminates is the same as when you started, not necessarily that it wasn't changed at some time during execution of the function. C++ users should code `heapsort()` to return an STL pair of the array and an array size.
- Your `heapinsert()` function should return false if you try to insert values into a full heap (and return `true` on a successful insert).
- `minimum()` and `extractMinimum()` should return 0 on an empty heap.
- You are required to implement and use `parent(i)`, `left(i)`, and `right(i)` helper functions. I also recommend use of a "minimum of three" helper function as described in class.
Don't forget a bounds checks as needed. (In general, make sure that all of your public functions are robust!)

For this assignment, please create a zero-based heap (where `A[0]` is the root) as described in class, and not a one-based heap (where `A[1]` is the root) as described in the textbook. You may make minor adjustments to the class definitions (for example, adding extra helper functions or overloading the constructor to accept initial values,) but any major changes must have prior approval in writing (do this via email.)

```cpp
// integer minimum heap with PQ 
class intMinHeap{
public:
  intMinHeap(int);  // empty heap wth this capacity
  ~intMinHeap();  // clean up allocated memory  
  std::pair<int *, int> heapsort();  // return sorted array and size from heap
  string toString();  
  bool heapinsert(int); // add element to heap; return success
  // min functions should return 0 in empty heaps 
  int minimum();  // return value of A[root]
  int extractmin(); // return and remove A[root]
  void decreasekey(int i, int k);  // A[i] decreased to k
  bool isEmpty(){return size==0;}
  bool isFull();  
private:
  int minOf3(int, int, int); // with bounds check!
  int left(int);
  int right(int);
  int parent(int);	
  void buildheap();  // convert array to a heap
  void heapify(int i);  // heapify at position i  
  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
 };
```

```java
class intMinHeap implements Serializable{
  public intMinHeap(int cap){ ... }
  public int [] heapsort(){ ... }
  public String toString(){ ... }
  public bool heapinsert(int n){ ... }  
  public int minimum(){ ... } // A[root] or 0 if empty
  public int extractMin(){ ... } // A[root] or 0
  public void decreaseKey(int i, int k){ ... }   	 
  public boolean isEmpty(){ ... }
  public boolean isFull(){ ... }
  private void buildheap(){ ... }
  private int minOf3(int i, int j, int k){ ... }
  private int left(int i){ ... }
  private int right(int i){ ... }
  private int parent(int i){ ... }
  private void heapify(int i){ ... } // at position i    
  private int [] A;
  private int capacity; // size of array A
  private int size; // size of data in array A
}
```

## Program testing

Create a "`main`" to test your data structure. Create a heap/pq with capacity of `2,400,000`. Your `main()` function will have some strange i/o as described below. 
- Your main function should read all input from STDIN (until EOF.) Each line will consist of a single integers.
- If the input value is a positive integer (greater than zero,) insert it into your object. This operation prints "insert" and the value that was added.
- If the input value is a `0`, print the heap and the size of the heap on a single line of text (as a comma separated list.) see the provided example for the exact syntax to follow.
- If the input value is a `-1`, extract the minimum value from your object, and print that value on a single line.
- If the input value is a `-2`, call heapsort, and then print, on a single line, as a comma-separated list the sorted array returned from heapsort.

### Sample input/output
Your output formatting must be identical to the provided sample.

**Input:**
```
2
9
4
7
5
8
6
10
3
1
0
-1
-1
0
1
0
-2
0
```

**Output:**
```
insert: 2
insert: 9
insert: 4
insert: 7
insert: 5
insert: 8
insert: 6
insert: 10
insert: 3
insert: 1
heap size 10: 1, 2, 4, 5, 3, 8, 6, 10, 9, 7
extract min: 1
extract min: 2
heap size 8: 3, 5, 4, 9, 7, 8, 6, 10
insert: 1
heap size 9: 1, 3, 4, 5, 7, 8, 6, 10, 9
sorted array: [10, 9, 8, 7, 6, 5, 4, 3, 1]
heap size 9: 1, 3, 4, 5, 7, 8, 6, 10, 9
```

## What you turn in
Put all of the source code files (.cpp, .h, makefile if C++, .java, etc.) but no executables, binaries, compiler, or data files (omit .o, "a.out" , .class files etc.) in a folder named as shown above in the home directory of your account on pengo. Please don't include any sub-directories.
