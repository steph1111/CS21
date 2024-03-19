/**
 * @file    hash_table.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 *
 * Definitions of methods of `HashTable` class. The `HashTable` class 
 * defines a hash table data structure.
*/

#include <list>
#include <sstream>
#include "hash_table.h"
#include "record.h"

const double C = 0.618034; // constant for hash, phi / 1

// public:
/**
 * Default constructor for `HashTable` object. Creates a `HashTable`
 * with table size 100
 */
HashTable::HashTable() {
    this->m = 100;
    this->table = new std::list<Record*>[this->m];
}

/**
 * Constructor for `HashTable` object. Creates a `HashTable`
 * with table size `size`.
 * 
 * @param size Table size
 */
HashTable::HashTable(int size) {
    this->m = size;
    this->table = new std::list<Record*>[this->m];
}

/**
 * Destructor for `HashTable` object, clean up allocated memory 
*/
HashTable::~HashTable() {
    delete[] this->table;
}

/**
 * Add a new `Record` to the `HashTable`
 * 
 * @param rec Record to add.
*/
void HashTable::insert(Record* rec) {
    this->table[this->hash(rec)].push_front(rec);
}

/**
 * Removes a `Record` from the `HashTable`.
 * 
 * @param key Key of the record to delete.
*/
void HashTable::del(int key) {
    this->table[this->hash(key)].remove(this->find(key));
}

/**
 * Finds an Record. Returns a newly allocated record object
 * WHICH MUST BE DELETED.
 * 
 * @param key Key at which to search for a `Record` at.
 * @return Pointer to a copy of found `Record`, nullptr if not found
*/
Record* HashTable::search(int key) {
    return this->find(key)->clone();
}


// private:

/**
 * Finds an Record.
 * 
 * @param key Key at which to search for a `Record` at.
 * @return Pointer to a copy of found `Record`, 0 if not found
*/
Record* HashTable::find(unsigned key) {
    unsigned key_hash = this->hash(key);

    for(auto itr = this->table[key_hash].begin(); itr != this->table[key_hash].end(); itr++) {
        if ((*itr)->getID() == key) {
            return *itr;
        }
    }
    return nullptr;
}

/**
 * Hash a `Record` object.
 * 
 * @param rec `Record` object to hash.
 * @return Has of record oject using the multiplication method.
*/
int HashTable::hash(Record* rec) {
    return this->hash(rec->getID());
}

/**
 * Helper function for `int HashTable::hash(Record* rec)`. Hashes a
 * key of a `Record` object using the multiplication method.
 * 
 * hash(k) = ⌊m(kc-⌊kc⌋)⌋ (where c = 1 / Φ)
 * 
 * @param k Key of the `Record` to hash.
*/
unsigned HashTable::hash(unsigned k) {
    return (unsigned)(this->m * (k * C - (unsigned)(k * C)));
}
