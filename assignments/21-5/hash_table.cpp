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
#include <memory>
#include <fstream>
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
    this->table = new std::list<std::unique_ptr<Record>>[this->m];
}

/**
 * Constructor for `HashTable` object. Creates a `HashTable`
 * with table size `size`.
 * 
 * @param size Table size
 */
HashTable::HashTable(unsigned size) {
    this->m = size;
    this->table = new std::list<std::unique_ptr<Record>>[this->m];
}

/**
 * Destructor for `HashTable` object, clean up allocated memory 
*/
HashTable::~HashTable() {
    std::cout << "deleting the shit" << std::endl;
    delete[] this->table;
}

/**
 * Add a new `Record` to the `HashTable`
 * 
 * @param rec Record to add.
*/
// void HashTable::insert(std::unique_ptr<Record> rec) {
//     // emplace_front uses uniq_ptrs
//     this->table[this->hash(rec->getID())].emplace_front(rec.get());
// }


/**
 * Add a new `Record` to the `HashTable`
 * 
 * @param rec Record to add.
*/
void HashTable::insert(Record* rec) {
    // emplace_front uses uniq_ptrs
    this->table[this->hash(rec)].emplace_front(rec);
}

/**
 * Removes a `Record` from the `HashTable`.
 * 
 * @param key Key of the record to delete.
 * @throw `std::invalid_argument` if key not found.
*/
void HashTable::del(int key) {
    std::list<std::unique_ptr<Record>>::iterator item = this->find(key);
        // Make sure item exists
        if (item != this->table[this->hash(key)].end()) {
            // .erase() takes in an iterator of the position to remove
            this->table[this->hash(key)].erase(item);
            return;
        }
    throw std::invalid_argument("Key not found");
}

/**
 * Finds an Record. Returns a newly allocated record pointer
 * 
 * @param key Key at which to search for a `Record` at.
 * @return Pointer to a copy of found `Record`, nullptr if not found
 * @throw `std::invalid_argument` if key not found.
*/
std::unique_ptr<Record> HashTable::search(int key) {
    std::list<std::unique_ptr<Record>>::iterator item = this->find(key);
    // Make sure item exists
    if (item != this->table[this->hash(key)].end()) {
        return std::unique_ptr<Record>((item->get()->clone()));
    }
    throw std::invalid_argument("Key not found");
}

/**
 * Clears data from the hash table. Does not modify the size.
*/
void HashTable::clear() {
    for (unsigned i = 0; i < this->m; i++) {
        this->table[i].clear();
    }
}

/**
 * Write all hash table data to the specified stream.
 * 
 * @param stream Output file stream to write to.
*/
void HashTable::write(std::ofstream& stream) const {
    for (unsigned i = 0; i < this->m; i++) {
        for (std::list<std::unique_ptr<Record>>::iterator itr = this->table[i].begin(); itr != this->table[i].end(); itr++) {
            stream << itr->get()->to_str() << "\n";
        }
    }
}

// private:

/**
 * Finds an `Record`.
 * 
 * @param key Key at which to search for a `Record` at.
 * @return An iterator to the found `Record`, .end() if not found
*/
std::list<std::unique_ptr<Record>>::iterator HashTable::find(unsigned key) {
    unsigned key_hash = this->hash(key);

    for(std::list<std::unique_ptr<Record>>::iterator itr = this->table[key_hash].begin(); itr != this->table[key_hash].end(); itr++) {
        if (itr->get()->getID() == key) {
            return itr;
        }
    }
    return table[key_hash].end();
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