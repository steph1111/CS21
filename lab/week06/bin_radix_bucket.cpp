#include <iostream>
#include <vector>
#include <cstdint>

void bin_radix_bucket_sort(std::vector<std::int32_t>& A) {
    std::vector<std::int32_t> bins[2];
    int index;
    int n = A.size();

    for(int i = 0; i < 31; i++) {  // LSB to most MSB, excluding sign bit.
        for(int j = 0; j < n; j++) {
            bins[(A[j] >> i) & 1].push_back(A[j]);   // `A[j] >> i` shifts the bit were looking for to the end, `&1` removes all but the last bit. This gives the current bit, Add entire number to the correct bit bin.
        }
        index = 0;
        // Put everything back in the vector. Bin 0 then 1, bins emptied in FIFO order.
        for(int j = 0; j < 2; j++) {
            for(std::int32_t bytes : bins[j]) {
                A[index] = bytes;
                index++;
            }
            bins[j].clear();
        }
    }

    // To account for negative numbers, treat the sign bit (MSB) separately.
    // `int32_t` stores negative numbers with twos complement. This means negative numbers will be sorted
    // correctly using the previous algo, except for the last bit--the sign bit. Here the numbers should 
    // be ordered such that numbers with a sign bit of `1` come before those with `0`. This is because 
    // `1` represents a negative number, which should come first in the list.

    // Add to bins, only look at the sign (MSB) bit. All other bits are organized from prev sorting
    for(int j = 0; j < n; j++) {
        bins[(A[j] >> 31) & 1].push_back(A[j]);
    }

    // Bin `1` should go back before bin `0`, iterate the opposite direction.
    index = 0;
    for(int j = 1; j >= 0; j--) {
        for(std::int32_t bytes : bins[j]) {
            A[index] = bytes;
            index++;
        }
        bins[j].clear();
    }
}


int main() {
    int input;
    std::vector<std::int32_t> numbers;

    while (std::cin >> input) {
        numbers.push_back(input);
    }

    bin_radix_bucket_sort(numbers);

    std::cout << "-------------------------------------------\n";

    for (int number: numbers) {
        std::cout << number << std::endl;
    }

    return 0;
}