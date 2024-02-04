/**
 * @file queue.cpp
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Lab#1
 *
 * Implementation of Queue class methods. The Queue class defines a
 * queue data structure
 */

#include <iostream>
#include "list.h"
#include "queue.h"

/**
 * Default constructor for Queue object
*/
Queue::Queue() {}

/**
* Removes an element from the front of the queue
* 
* @returns the element which was removed
*/
std::string Queue::dequeue() {
    return list.pop_front();
}

/**
 * Adds an element to the back of the queue
 * 
 * @param val The element to be added
 * @returns the element which was added
*/
std::string Queue::enqueue(const std::string val) {
    return list.push_back(val);
}

/**
 * Checks if the queue is empty
 * 
 * @returns true if the stack is empty, otherwise false
*/
bool Queue::isEmpty() const {
    return !list.size();
}
