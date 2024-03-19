/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 * Status:  Not working/Not tested. :(
 *
 * Demonstrates functionality of the `HashTable` class.
*/

#include <iostream>
#include <fstream>
#include "hash_table.h"

int main() {
    int choice;
    std::string input_file;
    HashTable(178000);

    do {
        std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
        std::cin >> choice;
    
        switch(choice) {
            case 1:
                std::cout << "read hash table - filename? ";
                std::cin >> input_file;
                {
                    std::ifstream fin(input_file);
                    // read from file
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
        

    } while (choice != 7);


    return 0;
}