#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <time.h> 

int LIMIT_HOARE = 0;


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


int main() {

    int input;
    std::vector<int> numbers(1000000);
    int tests[14] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
    double time_taken;
    double sum = 0;

    // Add random numbers to vector
    srand(time(0));
    for (int i = 0; i < numbers.size(); i++) {
        // numbers[i] = i;
        numbers[i] = rand() % numbers.size();
    }

    for (int i = 0; i < 14; i++) {
        LIMIT_HOARE = tests[i]; // set new limit value
        std::cout << "LIMIT_HOARE = " << tests[i] << ";\nTimes: ";
        sum = 0;

        for (int j = 0; j < 100; j++) {  // Run the test with the limit 10 times
            // Start and end time to run quicksort with the new limit
            auto start = std::chrono::high_resolution_clock::now();
            std::ios_base::sync_with_stdio(false);
            hoare_quicksort(numbers, 0, numbers.size() - 1);
            auto end = std::chrono::high_resolution_clock::now();

            // Total time taken
            time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

            // Output times
            std::cout <<  time_taken << " " ;
            sum += time_taken;
        }
        std::cout << "\nAverage: " << sum / 50 << std::endl << std::endl;
    }

    return 0;
} 