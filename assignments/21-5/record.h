/**
 * @file    record.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    04/04/24
 * CS21:    Assignment#5
 *
 * Declaration of abstract data type `Record`.
*/

#ifndef RECORD_H
#define RECORD_H

/**
 * abstract base class for data
 * also overload operator= if necessary
 * and/or copy constructor, destructor 
 * clone method invokes copy constructor
 * to make a copy of the object
*/
class Record {
    protected:
        unsigned int id;
    public:
        Record();
        Record(unsigned int id);
        virtual unsigned int getID()=0;
        virtual Record* clone()=0;
        bool operator==(const Record& that);
        void operator=(const Record& that);
};

#endif  // RECORD_H