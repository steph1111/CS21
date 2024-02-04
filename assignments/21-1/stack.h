/**
 * @file stack.h
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Assignment#1
 *
 * Declaration of List class and methods. The Stack class implements
 * the functionality of a stack data structure
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "list.h"

class Stack {
    public:

    /**
     * Default constructor for Stack object
    */
    Stack();
    
    /** 
     * Removes an element from the top of the stack
     * 
     * @returns The data removed
     */
    std::string pop();
    
    /** 
     * Appends an element to the top of the stack
     * 
     * @param val The data to append
     * @returns The data appended
     */
    std::string push(const std::string val);

    /**
     * Checks if the stack is empty 
     * 
     * @returns true if the stack is empty, otherwise false
    */
    bool isEmpty() const;

    private:
    List list;
};

#endif  // STACK_H