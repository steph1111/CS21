/**
 * @file    str_record.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 *
 * Declaration of StrRecord class. The StrRecord derives
 * from a Record. It contains an integer key and string data.
*/

#ifndef STR_RECORD_H
#define STR_RECORD_H

#include <iostream>
#include "record.h"

class StrRecord : public Record {
    public:
    /**
     * Create a string record. Default constructor.
    */
    StrRecord() {}

    /**
     * Create a `StrRecord`from an id and data.
     * 
     * @param id ID of record object.
     * @param data String data to store.
    */
    StrRecord(unsigned int id, std::string data);

    /**
     * Copy constructor for a StrRecord object.
     * 
     * @param that Another StrRecord object to create a new StrRecord object from.
    */
    StrRecord(StrRecord& that);

    /**
     * Returns the value of a key for a Record object.
     * 
     * @return The key value.
    */
    unsigned int getID();

    /**
     * Clones a string record creating a new heap allocated record object.
     * 
     * @return Newly heap allocated StrRecord.  
    */
    Record* clone();

    /**
     * Checks two `StrRecord` objects for equality.
     * 
     * @return true if the contents of the objects are the same, otherwise, false.
    */
    bool operator==(const StrRecord& that);

    /**
     * Creates a string representation of the record.
     * 
     * @return String representation.
    */
    std::string to_str() const;

    protected:
    std::string data;
};

#endif  // STR_RECORD_H