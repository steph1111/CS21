#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <fstream>

/**
 * Extracts a single digit from a number.
 * 
 * @param num The number to extract a digit from
 * @param i The digit to extract. Indexed as ...54321
 * @return The singular digit from `num` at position `i`
*/
inline int _get_digit(int num, int i) {
    return abs(num % (int)(pow(10, i)) / pow(10, i - 1));
}

/**
 * Computes the maximum number of digits for numbers in an vector.
 * 
 * @return The maximum number of digits for all numbers in the vector.
*/
int _max_digits(std::vector<int>& A) {
    int max = abs(A.at(0));
    for (int n : A) {
        if (abs(n) > max) max = abs(n);
    }
    return floor(log10(max) + 1); 
}

/**
 * Sorts a vector in place with bucket radix sort in ascending order.
 * This version of bucket radix sort avoids some restrictions of
 * standard radix bucket sort. The user does not have to know the
 * max number of digits which should be expected and the input is not
 * limited to only positive numbers.
 * 
 * @param A The vector to sort.
*/
void radix_bucket_sort(std::vector<std::int32_t>& A) {
    int n = A.size();
    int max_digits = _max_digits(A);
    int index;
    const int BASE = 10;
    std::vector<std::int32_t> bucket[BASE];

    for(int i = 1; i <= max_digits; i++) {
        for(int j = 0; j < n; j++) {
            bucket[_get_digit(A[j], i)].push_back(A[j]);
        }
        index = 0;
        for(int j = 0; j < BASE; j++) { 
            for (int item : bucket[j]) {
                A[index] = item;
                index++;
            }
            bucket[j].clear();
        }
    }

    // Sort by MSB, MSB is `1` for negative numbers and `0` for positive
    for(int j = 0; j < n; j++) {
        // (A[j] >> 31) & 1 gets the bit at the most significant digit, assuming a 32 bit integer.
        bucket[(A[j] >> 31) & 1].push_back(A[j]);
    }

    // Bin `1` should go back before bin `0.
    // Bin `1` contains all negative numbers sorted inversely.
    // Bin 1 should be emptied in LIFO order to inverse the current order..
    index = 0;
    for(int i = bucket[1].size() - 1; i >= 0; i--) {
        A[index] = bucket[1][i];
        index++;
    }
    // Bin `0` contains all positive numbers and 0. Empty with standard algo
    for(int item: bucket[0]) {
        A[index] = item;
        index++;
    }
}

int main() {
    int input;
    const int LEN = 1000000;
    std::vector<int> numbers(LEN);
    int sign[2] = {-1, 1};

    for (int i = 0; i < LEN; i++) {numbers[i] = rand() % LEN * sign[rand() % 2];}

    radix_bucket_sort(numbers);
    
    {
    std::ofstream fout("output.txt");
    for (int number: numbers) {
        fout << number << std::endl;
    }
    }

    return 0;
}