/***********************************************************
 * Problem 206: Reverse Linked List: Easy
 * 
 * Given the head of a singly linked list, reverse the list, 
 * and return the reversed list
***********************************************************/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream &operator<<(std::ostream &os, const ListNode* head) {
    os << "\t[";
    const ListNode* current = head;
    while (current != nullptr) {
    // while (current) {} -- equivalent
        os << current->val;
        if (current->next != nullptr) {
            os << " -> ";
        }
        current = current->next;
    }
    os << "]";
    return os;
}

ListNode* reverse_listnode(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;  
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1 -> next = new ListNode(2);
    head1 -> next -> next = new ListNode(3);
    head1 -> next -> next -> next = new ListNode(4);

    std::cout << "\nGeneral case:" << std::endl;
    std::cout << head1 << std::endl;
    std::cout << reverse_listnode(head1) << std::endl;

// Edge test case 1

    ListNode* head2 = new ListNode(10);
    head2 -> next = new ListNode(20);

    std::cout << "\nTwo values case:" << std::endl;
    std::cout << head2 << std::endl;
    std::cout << reverse_listnode(head2) << std::endl;

// Edge test case 2

    ListNode* head3 = nullptr;

    std::cout << "\nEmpty ListNode case:" << std::endl;
    std::cout << head3 << std::endl;
    std::cout << reverse_listnode(head3) << std::endl;

    return 0;
}