/**
 * @file    hash_table.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 *
 * Declaration of HashTable class and methods. The HashTable class defines a 
 * hash table data structure
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <list>
#include "record.h"


class HashTable{
    public:
    /**
     * Default constructor for `HashTable` object. Creates a `HashTable`
     * with table size 100
     */
    HashTable();

    /**
     * Constructor for `HashTable` object. Creates a `HashTable`
     * with table size `size`.
     * 
     * @param size Table size
     */
    HashTable(int size);

    /**
     * Destructor for `HashTable` object, clean up allocated memory 
    */
    ~HashTable();

    /**
     * Add a new `Record` to the `HashTable`
     * 
     * @param rec Record to add.
    */
    void insert(Record* rec);

    void del(int); // delete a Record
    // return pointer to a copy of found Record, or 0
    Record *search(int); 
    private:
        // find return value: some type of index
        Record *find(int); // helper search fn
        int hash(Record *); // hash value for Record
        int hash(int); // hash value for key  
        
        int m;                     // size of table
        std::list<Record>* table;  // array of m lists that hold `Records`
};


#endif // HASH_TABLE_H