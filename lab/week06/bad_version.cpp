#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

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
 * Computes the maximum number of digits for numbers in an vector.
 * 
 * @return The maximum number of digits for all numbers in the vector.
*/
int _max_digits(std::vector<int>& A) {
    int max = A.at(0);
    for (int n : A) {
        if (n > max) max = n;
    }
    return floor(log10(max) + 1); 
}

/**
 * Partitions a vector into a sections of positive and negative numbers.
 * 
 * @param A The vector to partition
 * @return The index of the last negative number
*/
int _partition(std::vector<int>& A) {
    int i = -1;
    int j = A.size();
    while(true) {
        do { i++; } while(A[i] < 0 && i < j);
        do { j--; } while(A[j] >= 0 && j >= 0);
        if (i >= j) {
            return j;
        }
        std::swap(A[i], A[j]);
    }
}

void _sort_partition_pos(std::vector<int>& A, int l, int r) {
    int base = 10, digit, index;
    std::vector<int> bucket[base];
    // bool neg = A[r] < 0;
    int max_digits = _max_digits(A);
    std::cout << "l: "<< l << " r: " << r << std::endl;

    for(int i = 1; i <= max_digits; i++) {
        for(int j = l; j <= r; j++) {
            digit = _get_digit(A[j], i);
            bucket[digit].push_back(A[j]);
        }
        index = l;
        for(int j = 0; j < base; j++) {
            for (int item : bucket[j]) {
                A[index] = item;
                index++;
            }
            bucket[j].clear();
        }
    }

}

// /**
//  * @param A The vector to sort
//  * @param d Number of digits in the numbers to sort (defaults to 9)
//  * @param k Base of the number system (defaults to 10)
// */
// void radix_bucket_sort(std::vector<int>& A) {
//     int i = _partition(A);
//     for (int number: A) {
//         std::cout << number << std::endl;
//     }
//     // _sort_partition(A, 0, i);                 // Negative partition
//     _sort_partition(A, i + 1, A.size() - 1);  // Positive partition
// }


int main() {
    int input;
    std::vector<int> numbers;

    while (std::cin >> input) {
        numbers.push_back(input);
    }

    std::cout << "--------------------------------" << std::endl;

    std::cout << _max_digits(numbers) << std::endl;

    for (int number: numbers) {
        std::cout << number << std::endl;
    }

    return 0;
}