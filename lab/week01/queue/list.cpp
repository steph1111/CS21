/**
 * @file list.cpp
 * @author Stephanie L'Heureux (slheure)
 * @date 02/08/24
 * CS21: Assignment#1
 *
 * Implementation of Stack class methods. The List class defines a
 * simple doubly linked list object
 */


#include <iostream>
#include "list.h"

/**
 * Default constructor for List object
 */
List::List() {}

/**
 * Destructor for List object
 */
List::~List() {
    // While the head is not null
    while (this->head) {
        LinkNode* old_head = this->head;
        this->head = old_head->next;
        delete old_head;
    }
}

/**
 * Size of the list
 * 
 * @returns The number of elements (nodes) in the list
 */
std::size_t List::size() const {
    return this->size_;
}

/**
 * Remove element from the back of the list
 * 
 * @returns The data held in the element removed
 */
std::string List::pop_back() {
    if (!this->size_) {  // Size is zero (the list is empty)
        throw std::domain_error("Empty list");
    }

    LinkNode* old_tail = this->tail;
    std::string old_data = this->tail->data;
    if (this->size_ == 1) {  // Size is one
        // With no remaining elements in the list, head and tail both point to null
        this->head = this->tail = nullptr;
    } else {  // Size is greater than one
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
    }
    this->size_--;
    delete old_tail;
    return old_data;
}

/** 
 * Remove element from the front of the list
 * 
 * @returns The data held in the element removed
 */
std::string List::pop_front() {
    if (!this->size_) {  // Size is zero (the list is empty)
        throw std::domain_error("Empty list");
    }

    LinkNode* old_head = this->head;
    std::string old_data = this->head->data;
    if (this->size_ == 1) {  // Size is zero
        // With no remaining elements in the list, head and tail both point to null
        this->head = this->tail = nullptr;
    } else {  // Size is greater than one
        this->head = this->head->next;
        this->head->prev = nullptr;
    }
    this->size_--;
    delete old_head;
    return old_data;
}

/** 
 * Appends an element to the back of the list
 * 
 * @param val The data to append
 * @returns The data held in the element appended
 */
std::string List::push_back(const std::string val) {
    LinkNode* new_node = new LinkNode{val};
    if (this->size_) {  // Size is greater than zero
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
    } else {  // Size is zero
        this->head = this->tail = new_node;  // Both head and tail are the new node
    }
    this->size_++;
    return val;
}

/** 
 * Appends an element to the front of the list
 * 
 * @param val The data to append
 * @returns The data held in the element appended
 */
std::string List::push_front(const std::string val) {
    LinkNode* new_node = new LinkNode{val};
    if (this->size_) {  // Size is greater than zero
        this->head->prev = new_node;
        new_node->next = this->head;
        this->head = new_node;
    } else {  // Size is zero
        this->head = this->tail = new_node;  // Both head and tail are the new node
    }
    this->size_++;
    return val;
}
