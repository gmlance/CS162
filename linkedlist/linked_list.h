#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <iostream>
#include <stdexcept>
#include <math.h>

using std::cout;
using std::endl;

// abbreviation
using uint = unsigned int;

// extra credit
template <typename T>
class Linked_List {
private:
    uint length;
    Node<T>* head;

public:
    // constructor
    // uint length, Node<T>* head
    Linked_List() {
        length = 0;
        head = nullptr;
    }

    // getters
    uint get_length() {
        return length;
    }

    // helper functions
    void print() {
        Node<T>* cursor = head;
        // traversing the linked list
        while (cursor != nullptr) {
            cout << cursor->val << ' ';
            // move one node over
            cursor = cursor->next;
        }
        cout << endl;
    }

    void clear() {
        length = 0;

        Node<T>* cursor = head;
        Node<T>* next;

        while (cursor != nullptr) {
            next = cursor->next;
            delete cursor;
            cursor = next;
        }

        head = nullptr;
    }

    // signed 8bits
    // -126 to 125

    // unsigned 8bits
    // 0 to 255

    uint insert(T val, uint index) {
        // precondition for index
        // what is a valid range of numbers for index?
        if (index < 0 || length < index) {
            throw std::invalid_argument("length must be between zero and length of list");
        }

        // new node to add
        Node<T>* node = new Node<T>(val);

        // head is null
        if (head == nullptr) {
            head = node;
        }
        // insert before the head
        else if (index == 0) {
            node->next = head;
            head = node;
        }
        // insert after any given node
        else {
            // because we're inserting after
            index--;
            Node<T>* cursor = head;

            // loop down index until 0
            while(index > 0){
            cursor = cursor->next;
            
            index--;
            }
        
            node->next = cursor->next;
            cursor->next = node;
        }

        // if we did add a node, increment length
        length++;
        return length;
    }

    uint push_front(T val) {
        return insert(val, 0);
    }

    uint push_back(T val) {
        return insert(val, length);
    }

    void sort_ascending() {
        merge_sort(&head, false);
    }

    void sort_descending() {
        selection_sort(head, true);
    }

    int count_primes() {
        int num = 0;
        Node<T>* cursor = head;
        while (cursor != nullptr) {
            // check primality
            num += is_prime(cursor->val);
            // move the cursor
            cursor = cursor->next;
        }
        return num;
    }

private:
    // https://www.geeksforgeeks.org/iterative-selection-sort-for-linked-list/
    void selection_sort(Node<T>* head, bool descending=false) {
        Node<T>* cursor = head;
        // Traverse the List
        while (cursor) {
            Node<T>* min_max = cursor;
            Node<T>* temp = cursor->next;
            // Traverse the unsorted sublist
            while (temp) {
                if ((min_max->val > temp->val) ^ descending) {
                    min_max = temp;
                }
                temp = temp->next;
            }
            // Swap Data
            T val = cursor->val;
            cursor->val = min_max->val;
            min_max->val = val;
            cursor = cursor->next;
        }
        
    }

    // merge sort functions
    void merge_sort(Node<T>** phead, bool descending=false) {
        Node<T>* head = *phead;
        Node<T>* a;
        Node<T>* b;

        // stops at either one or two nodes
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // split nodes so we can eventually compare them
        split(head, &a, &b);

        merge_sort(&a, descending);
        merge_sort(&b, descending);

        // join nodes back to head
        *phead = sorted_merge(a, b, descending);
    }

    Node<T>* sorted_merge(Node<T>* a, Node<T>* b, bool descending) {
        Node<T>* result = nullptr;

        if (a == nullptr) {
            return b;
        } else if (b == nullptr) {
            return a;
        }

        if ((a->val <= b->val) ^ descending) {
            result = a;
            result->next = sorted_merge(a->next, b, descending);
        } else {
            result = b;
            result->next = sorted_merge(a, b->next, descending);
        }

        return result;
    }

    // after splitting up, we merge sublists together back to one
    void split(Node<T>* head, Node<T>** a, Node<T>** b) {
        Node<T>* full;
        Node<T>* half;
        half = head;
        full = head->next;

        while (full != nullptr) {
            // move full
            full = full->next;
            if (full != nullptr) {
                // move half
                half = half->next;
                // move full
                full = full->next;
            }
        }

        *a = head;
        *b = half->next;
        half->next = nullptr;
    }

    // primes
    bool is_prime(long val) {
        if (val < 2) {
            return false;
        }
        for (long factor = 2; factor <= sqrt(val); factor++) {
            if (val % factor == 0) {
                return false;
            }
        }
        return true;
    }

};



#endif  // LINKED_LIST_H
