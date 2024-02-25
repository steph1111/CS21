/**
 * @file    int_min_heap.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    02/29/24
 * CS21:    Assignment#2
 *
 * Declaration of intMinHeap class and methods. The intMinHeap class defines a 
 * minimum priority heap (queue)
*/

#ifndef INT_MIN_HEAP_H
#define INT_MIN_HEAP_H

#include<iostream>

class intMinHeap{
  public:
  /**
   * Constructor for intMinHeap object. Creates a intMinHeap
   * with capacity `cap`
   * 
   * @param cap Capacity of intMinHeap
  */
  intMinHeap(int);

  /**
   * Destructor for intMinHeap object, clean up allocated memory 
  */
  ~intMinHeap();

  /**
   * Sorts heap into a sorted array 
   * 
   * @return A pair in which the first element is the sorted array
   *         and the second element is the size.
  */
  std::pair<int *, int> heapsort();
  
  /**
   * Converts contents of heap to a formatted string
   * 
   * @return Contents of heap as a formatted string
  */
  std::string toString();  

  /**
   * Insert a new value into the heap
   * 
   * @param val Value to insert
   * @return True if the insert worked, other false if not
  */
  bool heapinsert(int); // add element to heap; return success

  /**
   * Returns the minimum value in the heap, A[root].
   * 
   * @return A[root], 0 if empty heap
  */
  inline int minimum();

  /**
   * Removes and returns the minimum value in the heap, A[root].
   * 
   * @return A[root], 0 if the the size is 0
  */
  int extractmin();
  
  /**
   * "Promote" value at index `i` to `k`
   * 
   * @param i Index to promote 
   * @param k Value to promote to
  */
  void decreasekey(int i, int k);

  /**
   * Returns if the heap is empty
   * 
   * @return true if the heap is empty, otherwise false
  */
  inline bool isEmpty();
  
  /**
   * Returns if the heap size is the capacity
   * 
   * @return true if the heap is full, otherwise false
  */
  inline bool isFull();
  
  private:
  /**
   * Swaps elements in the heap at provided indexes.
   * Assumes indexes provided are valid.
   * 
   * @param i, j Indexes of nodes to swap
  */
  void swap(int i, int j);

  /**
   * Returns the max minimum of three nodes
   * 
   * @param i, j, k Indexes of nodes to compare
   * @return Index of the minimum value node 
  */
  int minOf3(int i, int j, int k);

  /**
   * Returns the right node index
   * 
   * @param i Index of node to find the right node of
   * @return The index of the right node to `i`
  */
  inline int left(int i);

  /**
   * Returns the right node index
   * 
   * @param i Index of node to find the right node of
   * @return The index of the right node to `i`
  */
  inline int right(int i);

  /**
   * Returns the parent node index
   * 
   * @param i Index of node to find the right node of
   * @return The index of the right node to `i`
  */
  inline int parent(int i);

  /**
   * Converts an array to a integer minimum heap
  */
  void buildheap();  // convert array to a heap
  
  /**
   * Preserve the heap property A[i] >= A[parent(i)]
   *  
   * @param i Index of the node to apply heapify on 
  */
  void heapify(int i);

  int *A;         // array of integers - data
  int capacity;   // size of array A
  int size;       // data size in array
};

#endif
