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
#include <fstream>
#include "hash_table.h"
#include "record.h"

// public:
/**
 * Default constructor for `HashTable` object. Creates a `HashTable`
 * with table size 100.
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
HashTable::HashTable(unsigned int size) {
    this->m = size;
    this->table = new std::list<std::unique_ptr<Record>>[this->m];
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
    // Clone so they do not have access
    Record* new_rec = rec->clone();
    // emplace_front uses uniq_ptrs
    this->table[this->hash(new_rec)].emplace_front(new_rec);
}

/**
 * Removes a `Record` from the `HashTable`.
 * 
 * @param key Key of the record to delete.
 * @throw `std::invalid_argument` if key not found.
*/
void HashTable::del(unsigned int key) {
    TableIterator item = this->find(key);
    unsigned int key_hash = this->hash(key);
        // Make sure item exists
        if (item != this->table[key_hash].end()) {
            // .erase() takes in an iterator of the position to remove
            this->table[key_hash].erase(item);
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
std::unique_ptr<Record> HashTable::search(unsigned int key) {
    TableIterator item = this->find(key);
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
        for (TableIterator itr = this->table[i].begin();
                itr != this->table[i].end(); itr++) {
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
TableIterator HashTable::find(unsigned int key) {
    unsigned int key_hash = this->hash(key);

    for(TableIterator itr = this->table[key_hash].begin();
            itr != this->table[key_hash].end(); itr++) {
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
unsigned int HashTable::hash(unsigned int k) {
    double prod = k * this->C ;
    return (unsigned int)(this->m * (prod - (unsigned int)prod));
}
