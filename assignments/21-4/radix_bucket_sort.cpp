/**
 * @file    radix_bucket_sort.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    03/14/24
 * CS21:    Assignment#4
 * Status:  Working/tested
 *
 * Takes an unspecified number of numeric inputs and sorts them
 * using radix bucket hybrid sort. The sorted numbers are then outputted with
 * leading padded zeros to nine total digits.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

/**
 * Outputs a number with leading padding zeros to nine digits.
 * 
 * @param num Number to output.
*/
inline void format_cout(int num) {
    std::cout << std::right << std::setw(9) << std::setfill('0') << num << std::endl;
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
 * @param k Base of the number system (defaults to 10)
*/
void radix_bucket_sort(std::vector<int>& A, int d = 9, int k = 10) {
    std::vector<int>* bucket = new std::vector<int>[k]; // k buckets, each bucket is a vector. One bucket for each possible number
    int n = A.size(), r;

    for(int i = 1; i <= d; i++) {           // Iterate from least significant digit to most significant digit (position in the number)
        for(int j = 0; j < n; j++) {        // For each number in the vector
            r = _get_digit(A[j], i);        // i-th digit from the current number in the vector
            bucket[r].push_back(A[j]);      // Add entire number to correct bucket based on number at the ith digit
        }
        // Numbers are in correct buckers, put them back in FIFO order
        int index = 0;
        for(int j = 0; j < k; j++) {        // For each bucket
            for (int item : bucket[j]) {    // For each item in each bucket
                A[index] = item;            // Put items back into `A` in FIFO order
                index++;
            }
            bucket[j].clear();              // Clear bucket contents for next iteration
        }
    }
    delete[] bucket;
}

int main() {
    int input;
    std::vector<int> numbers;

    while (std::cin >> input) {
        numbers.push_back(input);
    }

    radix_bucket_sort(numbers);

    for (int number: numbers) {
        format_cout(number);
    }

    return 0;
}