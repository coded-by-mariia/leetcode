#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// definition of a singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// easy and elegant way to print out the linked list
std::ostream& operator<<(std::ostream& os, const ListNode* head) {
    const ListNode* current = head; 
    
    os << "[ ";
    while (current) {
        os << current->val;
        if (current->next) {
            os << " -> ";
        }
        current = current->next;
    }
    os << " ]";
    
    return os;
}


#endif // LISTNODE_H