/************************************************************************************
 * Problem 1290: Convert Binary Number in a Linked List to Integer: Easy
 * 
 * Given head which is a reference node to a singly-linked list. 
 * The value of each node in the linked list is either 0 or 1. 
 * The linked list holds the binary representation of a number.
 * 
 * Return the decimal value of the number in the linked list.
 * 
 * The most significant bit is at the head of the linked list.
************************************************************************************/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// to print SLL clean and nicely 
std::ostream &operator<<(std::ostream &os, const ListNode* head) {
    os << "\t[";
    const ListNode* current = head;
    while (current) {
        os << current->val;
        if (current->next != nullptr) {
            os << " -> ";
        }
        current = current->next;
    }
    os << "]";
    return os;
}


// problem solution
int get_decimal_value(ListNode* head) {
    if (!head) return 0;

    int num {0};
    ListNode* current = head;

    while (current) {
        num = num * 2 + current->val;
        current = current->next;
    }
    
    return num;
}


int main() {
    ListNode* case1 = new ListNode(1);
    case1->next = new ListNode(0);
    case1->next->next = new ListNode(1);

    ListNode* case2 = new ListNode(0);

    std::cout << case1 << "  =>  " << get_decimal_value(case1) << "\n";
    std::cout << case2 << "  =>  " << get_decimal_value(case2) << "\n";

    return 0;
}