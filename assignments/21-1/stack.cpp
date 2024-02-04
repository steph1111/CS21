/**
 * @file stack.cpp
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Assignment#1
 *
 * Implementation of Stack class methods. The Stack class implements
 * the functionality of a stack data structure
 */

#include <iostream>
#include "stack.h"

/**
 * Default constructor for Stack object
*/
Stack::Stack() {}

/** 
 * Removes an element from the top of the stack
 * 
 * @returns The data removed
 */
std::string Stack::pop() {
    return this->list.pop_front();
}

/** 
 * Appends an element to the top of the stack
 * 
 * @param val The data to append
 * @returns The data appended
 */
std::string Stack::push(const std::string val) {
    return this->list.push_front(val);
}

/**
 * Checks if the stack is empty 
 * 
 * @returns true if the stack is empty, otherwise false
*/
bool Stack::isEmpty() const {
    return !this->list.size();
}
