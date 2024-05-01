/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    05/02/24
 * CS21:    Assignment#7
 * Status:  Working/Tested
 *
 * Demonstrates functionality of the `BinarySearchTree` class.
*/

#include <iostream>
#include "binary_search_tree.h"

std::pair<int, std::string> split_data(std::string str) {
    int i = str.find(' ');
    return std::make_pair(std::stoi(str.substr(0, i)), 
        str.substr(i + 1, str.size() - i));
}

int main() {
    std::string choice;

    try { // Try block to avoid memory leaks for invalid input
        while(std::getline(std::cin, choice)){
        }
    } catch (std::invalid_argument const&){
        std::cerr << "Invalid input. Exiting program.\n";
    }

    return 0;
}
