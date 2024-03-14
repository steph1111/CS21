/**
 * @file    radix_bucket_sort.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    03/14/24
 * CS21:    Assignment#4
 * Status:  Working/tested
 *
 * Takes an unspecified number of numeric inputs and sorts them
 * using radix bucket hybrid sort. The sorted numbers are then 
 * outputted with leading padded zeros to nine total digits.
*/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * Outputs a number with leading padding zeros to nine digits.
 * 
 * @param num Number to output.
*/
inline void format_cout(int num) {
    std::cout << std::right << std::setw(9) 
              << std::setfill('0') << num << std::endl;
}

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
    int input;
    std::vector<int> numbers;

    while (std::cin >> input) {
        numbers.push_back(input);
    }

    radix_bucket_sort(numbers);

    for (unsigned i = 0; i < numbers.size(); i++) {
        format_cout(numbers[i]);
    }

    return 0;
}