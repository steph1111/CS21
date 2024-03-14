#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <time.h> 
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdint>

// ----------------function def here----------------
/**
 * Extracts a single digit from a number.
 * 
 * @param num The number to extract a digit from
 * @param i The digit to extract. Indexed as ...54321
 * @return The singular digit from `num` at position `i`
*/
inline int _get_digit(int num, int i) {
    return num % (int)(pow(10, i)) / pow(10, i - 1);
}

/**
 * @param A The vector to sort
 * @param d Number of digits in the numbers to sort (defaults to 9)
*/
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

int main() {
    std::vector<int> numbers;
    int sign[2] = {-1, 1};
    double time_taken;
    double sum = 0;
    int input;
    const int NUM_TESTS = 20;

    srand(time(0));
    {
    std::ofstream fout("orig.txt");

    for (int i = 0; i < 21; i++) {
        numbers.resize(pow(2, i));
        for(int j = 0; j < pow(2, i); j++) {
            numbers[j] = rand() % 1000000;
        }
        for (int j = 0; j < NUM_TESTS; j++) { 
            auto start = std::chrono::high_resolution_clock::now();
            // ----------------function call here---------------- 
            radix_bucket_sort(numbers);
            auto end = std::chrono::high_resolution_clock::now();
            time_taken = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;
            sum += time_taken;
        }
        fout << std::fixed << std::setprecision(8) << sum / NUM_TESTS << "\t" 
             << std::setprecision(0) << pow(2, i) << "\n";
    }
    }
    return 0;
}