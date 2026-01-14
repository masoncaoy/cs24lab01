// intlist.cpp
// Implements class IntList
// Mason Cao 1/13/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    Node* n = source.head;
    while (n) {
        push_back(n->info);
        n = n->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    while (head) {
        Node* n = head;
        head = head->next;
        delete n;
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* n = head;
    int sum = 0;
    while (n) {
        sum += n->info;
        n = n->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* n = head;
    while (n) {
        if (n->info == value) {
            return true;
        }
        n = n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head) {
        return 0;
    }
    Node* n = head;
    int max = n->info;
    while (n) {
        if (n->info>max) {
            max = n->info;
        }
        n = n->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(count() == 0) {
        return 0.0;
    }
    return (double)sum()/count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* n = new Node;
    n->info = value;
    n->next = head;
    head = n;
    if (tail == nullptr) {
        tail = n;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node* n = new Node;
    n->info = value;
    n->next = nullptr;
    if (tail != nullptr) {
        tail->next = n;
    } else {
        head = n;
    }
    tail = n;
 
}

// return count of values
int IntList::count() const {
   Node* n = head;
   int count = 0;
   while (n) {
        count++;
        n = n->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    IntList temp(source);
    head = temp.head;
    tail = temp.tail;
    return *this;
    
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

