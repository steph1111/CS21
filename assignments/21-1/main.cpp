/**
 * @file main.cpp
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Assignment#1
 *
 * Demonstrates functionality of the stack class
 */

#include <iostream>
#include "stack.h"

int main() {
    Stack stack;
    std::string input;
    
    // Read an unspecified number of strings (until EOF)
    while (std::cin >> input) {
        // Push each string onto 'stack'
        stack.push(input);
    }

    // Pop each string from 'stack, printing it to STDOUT
    while(!stack.isEmpty()) {
        std::cout << stack.pop() << std::endl;
    }

    return 0;
}