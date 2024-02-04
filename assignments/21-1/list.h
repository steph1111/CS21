/**
 * @file list.h
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Assignment#1
 *
 * Declaration of List class and methods. The List class defines a 
 * simple doubly liked list object
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>

class List {
    // LinkNode will be defined later
    struct LinkNode;

    public:
    /**
     * Default constructor for List object
     */
    List();

    /**
     * Destructor for List object
     */
    ~List();

    /**
     * Size of the list
     * 
     * @returns The number of elements (nodes) in the list
     */
    std::size_t size() const;

    /**
     * Remove element from the back of the list
     * 
     * @returns The data held in the element removed
     */
    std::string pop_back();

    /** 
     * Remove element from the front of the list
     * 
     * @returns The data held in the element removed
     */
    std::string pop_front();

    /** 
     * Appends an element to the back of the list
     * 
     * @param val The data to append
     * @returns The data held in the element appended
     */
    std::string push_back(const std::string val);

    /** 
     * Appends an element to the front of the list
     * 
     * @param val The data to append
     * @returns The data held in the element appended
     */
    std::string push_front(const std::string val);

    private:
    struct LinkNode {
        std::string data;
        LinkNode* prev = nullptr;
        LinkNode* next = nullptr;
    };
    LinkNode* head;
    LinkNode* tail;
    std::size_t size_ = 0;
};
#endif  // LIST_H
