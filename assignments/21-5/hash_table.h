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

#include <memory>
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
    HashTable(unsigned size);

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

    /**
     * Removes a `Record` from the `HashTable`.
     * 
     * @param key Key of the record to delete.
    */
    void del(int key);

    // return pointer to a copy of found Record, or 0

    /**
     * Finds an Record.
     * 
     * @param key Key at which to search for a `Record` at.
     * @return Pointer to a copy of found `Record`, 0 if not found
    */
    std::unique_ptr<Record> search(int key); 

    /**
     * Clears data from the hash table. Does not modify the size.
    */
    void clear();

    /**
     * Write all hash table data to the specified stream.
     * 
     * @param stream Output file stream to write to.
    */
    void write(std::ofstream& stream) const;

    private:
        
    /**
     * Finds an Record.
     * 
     * @param key Key at which to search for a `Record` at.
     * @return Pointer to a copy of found `Record`, 0 if not found
    */
    std::list<std::unique_ptr<Record>>::iterator find(unsigned key); // helper search fn

    /**
     * Hash a `Record` object.
     * 
     * @param rec `Record` object to hash.
     * @return Has of record oject using the multiplication method.
    */
    int hash(Record* rec);
    
    /**
     * Helper function for `int HashTable::hash(Record* rec)`. Hashes a
     * key of a `Record` object using the multiplication method.
     * 
     * hash(k) = ⌊m(kc-⌊kc⌋)⌋ (where c = 1 / Φ)
     * 
     * @param k Key of the `Record` to hash.
    */
    unsigned hash(unsigned key);  // hash value for key  

    unsigned m; // size of table
    std::list<std::unique_ptr<Record>>* table;  // array of m lists that hold `Record` pointers
};


#endif // HASH_TABLE_H
