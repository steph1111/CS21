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
#include "str_record.h"

int main() {
    int choice;
    std::string input_file;
    std::string input_str;
    int input_int;
    
    HashTable table(178000);

    do {
        std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
        std::cin >> choice;
    
        switch (choice) {
            case 1: // Read data from a file
                std::cout << "read hash table - filename? ";
                std::cin >> std::ws;
                std::cin >> input_file;
                {
                    std::ifstream fin(input_file);
                    while (std::getline(fin, input_str)) {
                        table.insert(new StrRecord(input_str));
                    }
                }
                break;

            case 2: // Insert a (single) new record
                std::cout << "input new record:\n";
                std::getline(std::cin, input_str);
                table.insert(new StrRecord(input_str));
                break;

            case 3: // Delete a record
                std::cout << "delete record - key? ";
                std::cin >> std::ws;
                std::cin >> input_int;
                try {
                    table.del(input_int);
                    std::cout << "Delete: aaaaaaaaaaaaaaaaaa\n";
                } catch (std::invalid_argument const&) {
                    std::cerr << "Delete not found: " << input_int << "\n";
                }
                break;
            
            case 4: // Search for a record
                std::cout << "search for record - key? ";
                std::cin >> std::ws;
                std::cin >> input_int;
                try {
                    // std::cout << "Found: " << table.search(input_int)->to_str() << "\n";
                } catch (std::invalid_argument const&) {
                    std::cerr << "Search not found: " << input_int << "\n";
                }
                break;
            
            case 5: // Clear entire hash table
                std::cout << "clearing hash table.";
                table.clear();
                break;
            
            case 6: // Save data to a file
                std::cout << "write hash table - filename?";
                std::cin >> std::ws;
                std::cin >> input_str;
                {
                    std::ofstream fin(input_str);
                    table.write(fin);
                }
                break;
        }
    } while (choice != 7);

    return 0;
}