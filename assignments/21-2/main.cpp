/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    02/29/24
 * CS21:    Assignment#2
 * Status:  Working/tested
 *
 * Demonstrates functionality of the int_min_heap class
*/

#include <iostream>
#include "int_min_heap.h"

int main() {
    int input;
    intMinHeap heap = intMinHeap(2400000);

    while(std::cin >> input) {
        switch(input) {
            case 0:
                // Print the heap and the size of the heap on a single line 
                // of text (as a comma separated list) 
                std::cout << heap.toString() << std::endl;
                break;
            case -1:
                // Extract the minimum value from your object, and print that value on a single line
                std::cout << "extract min: " << heap.extractmin() << std::endl;
                break;
            case -2:
            {
                // call heapsort, and then print, on a single line, as a comma-separated list the 
                // sorted array returned from heapsort.
                std::pair<int *, int> sorted_pair = heap.heapsort();
                
                std::cout << "sorted array: [";
                if (sorted_pair.second > 0)  {
                    for (int i = 0; i < sorted_pair.second - 1; i++) {
                        std:: cout << sorted_pair.first[i] << ", ";
                    }
                    std::cout << sorted_pair.first[sorted_pair.second - 1];
                }
                std::cout << "]" << std::endl;

                delete [] sorted_pair.first;
                break;
            }
            default:
                // Insert input
                std::cout << "insert: " << input << std::endl;
                heap.heapinsert(input);
        }
    }

    return 0;
}