/**
 * @file    main.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 * Status:  Working/Tested
 *
 * Demonstrates functionality of the `HashTable` class.
*/

#include <iostream>
#include <fstream>
#include "hash_table.h"
#include "str_record.h"

std::pair<int, std::string> split_data(std::string str) {
    int i = str.find(' ');
    return std::make_pair(std::stoi(str.substr(0, i)), 
        str.substr(i + 1, str.size() - i));
}

int main() {
    std::string choice;
    std::string input_str;
    int input_int;
    std::pair<int, std::string> rec;
    std::unique_ptr<Record> temp_record;
    StrRecord* rec_ptr;
    HashTable table(178000);

    try { // Try block to avoid memory leaks for invalid input
        std::cout << "(1)load (2)insert (3)delete (4)search (5)clear";
        std::cout << " (6)save (7)quit -- Your choice? ";
        while(std::getline(std::cin, choice) && choice != "7") {
            switch (std::stoi(choice)) {
                case 1: // Read data from a file
                    std::cout << "read hash table - filename? ";
                    std::getline(std::cin, input_str);
                    {
                        std::ifstream fin(input_str);
                        while (std::getline(fin, input_str)) {
                            rec = split_data(input_str);
                            rec_ptr = new StrRecord(rec.first, rec.second);
                            table.insert(rec_ptr);
                            delete rec_ptr;
                        }
                    }
                    break;

                case 2: // Insert a (single) new record
                    std::cout << "input new record:\n";
                    std::getline(std::cin, input_str);
                    rec = split_data(input_str);
                    rec_ptr = new StrRecord(rec.first, rec.second);
                    table.insert(rec_ptr);
                    delete rec_ptr;
                    break;

                case 3: // Delete a record
                    std::cout << "delete record - key? ";
                    std::getline(std::cin, input_str);
                    input_int = std::stoi(input_str);
                    try {
                        temp_record = table.search(input_int);
                        table.del(input_int);
                        std::cout << "Delete: " << temp_record->to_str() << "\n";
                    } catch (std::invalid_argument const&) {
                        std::cerr << "Delete not found: " << input_int << "\n";
                    }
                    break;

                case 4: // Search for a record
                    std::cout << "search for record - key? ";
                    std::getline(std::cin, input_str);
                    input_int = std::stoi(input_str);
                    try {
                        temp_record = table.search(input_int);
                        std::cout << "Found: " << temp_record->to_str() << "\n";
                    } catch (std::invalid_argument const&) {
                        std::cerr << "Search not found: " << input_int << "\n";
                    }
                    break;

                case 5: // Clear entire hash table
                    std::cout << "clearing hash table.\n";
                    table.clear();
                    break;

                case 6: // Save data to a file
                    std::cout << "write hash table - filename? ";
                    std::getline(std::cin, input_str);
                    {
                        std::ofstream fin(input_str);
                        table.write(fin);
                    }
                    break;
            }
            std::cout << "(1)load (2)insert (3)delete (4)search (5)clear";
            std::cout << " (6)save (7)quit -- Your choice? ";
        }
    } catch (std::invalid_argument const&){
        std::cerr << "Invalid input. Exiting program.\n";
    }

    return 0;
}
