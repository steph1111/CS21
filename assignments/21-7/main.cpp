/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    05/02/24
 * CS21:    Assignment#7
 * Status:  Untested
 *
 * Demonstrates functionality of the `BinarySearchTree` class.
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
#include "binary_search_tree.h"

void print_vector(const std::vector<int>& keys) {
    for (unsigned i = 0; i < keys.size(); i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    BinarySearchTree bst;
    std::string input, action;
    int num;
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
        {"#",           comment}
    };

    try {   // Try block to avoid memory leaks for invalid input
        while(std::getline(std::cin, input)){
            std::stringstream ss(input);    // Create a new string stream of the input
            ss >> action;   // Extract first token from string stream

            // Check if desired action is in the map of valid choices
            auto data = choice_map.find(action);
            if (data != choice_map.end()) {
                switch ((int) data->second) {

                case search:
                    ss >> num;
                    std::cout << num << (bst.search(num) ? " " : " not ") << "found.\n";
                    break;

                case min: {
                    int* minimum = bst.min();
                    if (minimum) {
                        std::cout << "min is " << minimum << ".\n";
                    } else {
                        std::cout << "tree empty.\n";
                    }
                    delete minimum;
                    break;
                }

                case max: {
                    int* maximum = bst.max();
                    if (maximum) {
                        std::cout << "max is " << maximum << ".\n";
                    } else {
                        std::cout << "tree empty.\n";
                    }
                    delete maximum;
                    break;
                }

                case insert:
                    ss >> num;
                    bst.insert(num);
                    std::cout << "inserted " << num << ".\n";
                    break;

                case successor: {
                    ss << num;
                    int* inherit = bst.successor(num);
                    if (inherit) {
                        std::cout << num << "successor is " << inherit << ".\n";
                    } else {
                        std::cout << "key not in tree.\n";
                    }
                    delete inherit;
                    break;
                }

                case predecessor: {
                    ss << num;
                    int* inherit = bst.predecessor(num);
                    if (inherit) {
                        std::cout << num << "predecessor is " << inherit << ".\n";
                    } else {
                        std::cout << "key not in tree.\n";
                    }
                    delete inherit;
                    break;
                }

                case inorder:
                    std::cout << "inorder traversal: ";
                    print_vector(bst.inorder());
                    break;

                case postorder:
                    std::cout << "postorder traversal: ";
                    print_vector(bst.postorder());
                    break;

                case preorder:
                    std::cout << "preorder traversal: ";
                    print_vector(bst.preorder());
                    break;

                case remove:
                    ss << num;
                    if (bst.remove(num)) {
                        std::cout << "deleted " << num << ".\n";
                    } else {
                        std::cout << "delete " << num << " - not found.\n";
                    }
                    break;
                }

            } else {
                std::cerr << "Enter a valid choice.\n";
            }
        }
    } catch (std::invalid_argument const&){
        std::cerr << "Invalid input. Exiting program.\n";
    }

    return 0;
}
