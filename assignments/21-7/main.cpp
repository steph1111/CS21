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
#include <unordered_map>
#include "binary_search_tree.h"

std::pair<int, std::string> split_data(std::string str) {
    int i = str.find(' ');
    return std::make_pair(std::stoi(str.substr(0, i)), 
        str.substr(i + 1, str.size() - i));
}

int main() {
    std::string input, choice;
    std::pair<std::string, std::string> split_input;
    enum {
        search, min, max, insert, successor, predecessor, inorder, postorder, preorder, remove, comment
    };

    std::unordered_map<std::string, int> choice_map {
        {"search",      search},
        {"min",         min},
        {"max",         max},
        {"insert",      insert},
        {"successor",   successor},
        {"predecessor", predecessor},
        {"inorder",     inorder},
        {"postorder",   postorder},
        {"preorder",    preorder},
        {"delete",      remove},
        {"#",           comment},
    };

    try { // Try block to avoid memory leaks for invalid input
        while(std::getline(std::cin, input)){
            split_input = split_data(input);
            choice = split_input.first;
            auto data = choice_map.find(choice);
            if (data != choice_map.end()) {
                switch ((int) data->second) {
                    case search:
                        break;
                    case min:
                        break;
                    case max:
                        break;
                    case insert:
                        break;
                    case successor:
                        break;
                    case predecessor:
                        break;
                    case inorder:
                        break;
                    case postorder:
                        break;
                    case preorder:
                        break;
                    case remove:
                        break;
                    case comment:
                        break;
                }
            } else {
                std::cerr << "Enter a valid choice\n";
            }
            
        }
    } catch (std::invalid_argument const&){
        std::cerr << "Invalid input. Exiting program.\n";
    }

    return 0;
}
