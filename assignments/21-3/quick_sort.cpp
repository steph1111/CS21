/**
 * @file    quick_sort.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    03/7/24
 * CS21:    Assignment#3
 * Status:  Working/tested
 *
 * Takes an unspecified number of numeric inputs and sorts them
 * using quicksort. The sorted numbers are then outputted with
 * leading padded zeros to nine total digits.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>


const int LIMIT = 5;
const int LIMIT_HOARE = 10;


/**
 * Swaps two elements in a vector given indices
 * 
 * @param A Vector containing elements to sort
 * @param i, j Indexes of elements to swap
*/
void swap(std::vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


/**
 * Outputs a number with leading padding zeros to nine digits
 * 
 * @param num Number to output
*/
inline void format_cout(int num) {
    std::cout << std::right << std::setw(9) << std::setfill('0') << num << std::endl;
}


/**
 * Median of three helper for quicksort().
 * 
 * Avoids selecting a bad pivot by finding the median element index of 
 * of the left most, right most, and center element of the array.
 * 
 * @param A Vector containing elements to sort 
 * @param p Left index
 * @param r Right index 
 * @return Index of the median element in `A` of indexes `p`, `r` 
 *         and `p + ((r - p) / 2)` (the mid point)
*/
int med_of_3(std::vector<int>& A, int p, int r) {
    int mid = A[p + ((r - p) / 2)], left = A[p], right = A[r];
    if ((left > mid) ^ (left > right)) return p;
    if ((right > mid) ^ (right > left)) return r;
    return p + ((r - p) / 2);
}


/**
 * Lumuto partition helper for `quicksort()`
 * 
 * Rearranges the sub array  A[i...j] in place returning into two regions
 * A[i...k - 1] and  A[k + 1...j] where A[k] is the pivot such that
 * all elements in A[i...k - 1] are <= A[k] and all elements in 
 * A[k + 1...j] >= A[k]
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
 * @return Index on which the array is split such that elements to the 
 *         left of the index are less than the element at that index 
 *         and elements to the right are greater than the element at that index.
*/
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


/**
 * Sorts vector A in place in ascending order with quick sort algo
 * 
 * Time complexity:
 * Average case:                            O(nlgn) (small constants)
 * Worst case (already sorted array):       O(n^2)
 * Worser case (many duplicate elements):   Use hoare
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
*/
void quicksort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r); // Divide 
        quicksort(A, p, q - 1);     // Conquer (recursive call on lower array)
        quicksort(A, q + 1, r);     // Conquer (recursive call on upper array)
    }
}


/**
 * Hoare partition helper for quicksort()
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
 * @return Index on which the array is split such that elements to the 
 *         left of the index are less than the element at that index 
 *         and elements to the right are greater than the element at that index.
*/
int hoare_partition(std::vector<int>& A, int p, int r) {
    // Select a good pivot
    if ((r - p) > LIMIT_HOARE) {
        int med = med_of_3(A, p, r);
        swap(A, med, p);
    }

    int x = A[p];   // Pivot 
    int i = p - 1;
    int j = r + 1;
    while (true) {
        do { i++; } while (A[i] < x);   // Move i to the right until it finds something out of place
        do { j--; } while (A[j] > x);   // Move j to the left until it finds something out of place
        if (i >= j) return j;           // Nothing left to swap, return index of pivot
        swap(A, i, j);          // Swap out of place elements
    }
}


/**
 * Sorts vector A in place in ascending order with quick sort algo.
 * Better for arrays with duplicates
 * 
 * @param A Vector containing elements to sort
 * @param p Left index
 * @param r Right index
*/
void hoare_quicksort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = hoare_partition(A, p, r);   // Divide 
        hoare_quicksort(A, p, q);           // Conquer (recursive call on lower array)
        hoare_quicksort(A, q + 1, r);       // Conquer (recursive call on upper array)
    }
}


int main(int argc, char** argv) {
    int input;
    std::vector<int> numbers;

    while (std::cin >> input) {
        numbers.push_back(input);
    }

    // hoare quicksort 
    if (argc > 1 && !strcmp(argv[1], "-h"))  {
        hoare_quicksort(numbers, 0, numbers.size() - 1);
    } else {  // lumuto quick sort
        quicksort(numbers, 0, numbers.size() - 1);
    }

    for (int number: numbers) {
        format_cout(number);
    }

    return 0;
} 