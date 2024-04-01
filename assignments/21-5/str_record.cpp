/**
 * @file    str_record.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 *
 * Definitions of StrRecord class. The StrRecord derives
 * from a Record. It contains an integer key and string data;
*/

#include <iostream>
#include <sstream>
#include "record.h"
#include "str_record.h"

/**
 * Create a `StrRecord`from an id and data.
 * 
 * @param id ID of record object.
 * @param data String data to store.
*/
StrRecord::StrRecord(unsigned int id, std::string data) {
    this->id = id;
    this->data = data;
}

/**
 * Create a `StrRecord`from a string. Formatted as
 * ######### text text text...
 * Where the first token is the id and the following tokens are the data.
 * 
 * @param str 
*/
StrRecord::StrRecord(std::string str) {
    std::stringstream sin(str);
    sin >> this->id;
    sin >> std::ws;
    std::getline(sin, this->data);
}

/**
 * Copy constructor for a StrRecord object.
 * 
 * @param that Another StrRecord object to create a new StrRecord object from.
*/
StrRecord::StrRecord(StrRecord& that) : Record(that.id), data(that.data) {};

/**
 * Returns the value of a key for a Record object.
 * 
 * @return The key value.
*/
unsigned int StrRecord::getID() { return this->id; }

/**
 * Clones a string record creating a new heap allocated record object.
 * 
 * @return Newly heap allocated StrRecord.  
*/
Record* StrRecord::clone() {
    return new StrRecord(*this);
}

/**
 * Checks two `StrRecord` objects for equality.
 * 
 * @return true if the contents of the objects are the same, otherwise, false.
*/
bool StrRecord::operator==(const StrRecord& that) {
    return this->id == that.id && that.data == this->data;
}

/**
 * Creates a string representation of the record.
 * 
 * @return String representation.
*/
std::string StrRecord::to_str() const { return std::to_string(this->id) + " " + this->data; }