/**
 * @file main.cpp
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Lab#1
 *
 * Demonstrates functionality of the queue class
 */

#include <iostream>
#include "queue.h"

int main() {
    Queue queue;
    std::string input;
    
    // Read an unspecified number of strings (until EOF)
    while (std::cin >> input) {
        // Push each string onto 'queue'
        queue.enqueue(input);
    }

    // Pop each string from 'queue, printing it to STDOUT
    while(!queue.isEmpty()) {
        std::cout << queue.dequeue() << std::endl;
    }

    return 0;
}