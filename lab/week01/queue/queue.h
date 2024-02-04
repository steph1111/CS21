/**
 * @file queue.cpp
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Lab#1
 *
 * Declaration of Queue class and methods. The Queue class defines a
 * queue data structure
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "list.h"

class Queue {
    public: 

    /**
     * Default constructor for Queue object
    */
    Queue();

    /**
    * Removes an element from the front of the queue
    * 
    * @returns the element which was removed
    */
    std::string dequeue();
    
    /**
     * Adds an element to the back of the queue
     * 
     * @param val The element to be added
     * @returns the element which was added
    */
    std::string enqueue(const std::string val);

    /**
     * Checks if the queue is empty
     * 
     * @returns true if the stack is empty, otherwise false
    */
    bool isEmpty() const;

    private:
    List list;
};

#endif  // QUEUE_H 