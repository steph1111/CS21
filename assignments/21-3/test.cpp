#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <time.h> 

int LIMIT = 5;


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

int main() {

    int input;
    std::vector<int> numbers(1000000);
    int tests[12] = {1000, 100, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
    double time_taken;
    double sum = 0;

    // Add random numbers to vector
    srand(time(0));
    for (int i = 0; i < numbers.size(); i++) {
        // numbers[i] = i;
        numbers[i] = rand() % numbers.size();
    }

    for (int i = 0; i < 12; i++) {
        LIMIT = tests[i]; // set new limit value
        std::cout << "LIMIT = " << tests[i] << ";\nTimes: ";
        sum = 0;

        for (int j = 0; j < 50; j++) {  // Run the test with the limit 10 times
            // Start and end time to run quicksort with the new limit
            auto start = std::chrono::high_resolution_clock::now();
            std::ios_base::sync_with_stdio(false);
            quicksort(numbers, 0, numbers.size() - 1);
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