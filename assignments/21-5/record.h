/**
 * @file    record.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 *
 * Declaration of abstract data type Record.
*/

#ifndef RECORD_H
#define RECORD_H

#include <iostream>

// Abstract base class for data in HashTable
class Record {
    protected:
        unsigned int id;
    public:
        /**
         * Default constructor for Record object.
        */
        Record() {};
        /**
         * Constructor for Record object with id parameter.
         * 
         * @param id Id of Record
        */
        Record(unsigned int id) { this->id = id; }

        /**
         * VIRTUAL: Destructor for Record object.
        */
        virtual ~Record(){}

        /**
         * VIRTUAL: Get record id.
         * 
         * @return Value of id.
        */
        virtual unsigned int getID() const=0;

        /**
         * VIRTUAL: Creates a new record object clone (invokes copy constructor).
         * 
         * @return Pointer to a copy of the Record object.
        */
        virtual Record* clone() const=0;

        /**
         * Checks if a Record object is equal to another Record object.
         * 
         * @param that Other record object to compare.
         * @return true if the two Records compare equal, otherwise false.
        */
        bool operator==(const Record& that) const { return this->id == that.id; }

        /**
         * Assigns a Record object to another Record object. 
         * 
         * @param that Record object to assign to this. 
        */
        void operator=(const Record& that) { this->id = that.id; }

        /**
         * VIRTUAL: Creates a string representation of the Record.
        */
        virtual std::string to_str() const=0;
};

#endif  // RECORD_H