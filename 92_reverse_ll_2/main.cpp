/**********************************************************************************
 * Problem 92: Reverse Linked List II: Medium
 * 
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position 
 * right, and return the reversed list.
 * 
**********************************************************************************/
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


// task solution
ListNode* reverse_between(ListNode* head, int left, int right) {
    // edges: empty sll, sll with one node or incorrect indexes,
    // then no point to hastle at all 
    if (!head || !head->next || left >= right) return head;

    ListNode* dummy = new ListNode(0); // we need this dummy in case left == 1
    dummy->next = head;
    ListNode* prev = dummy;

    // move prev to the node just before left`
    for (int i = 0; i < (left - 1); i++) {
        prev = prev->next;
    }

    ListNode* start = prev->next;
    ListNode* to_move = start->next;

    for (int i = 0; i < (right - left); i++) {
        start->next = to_move->next;
        to_move->next = prev->next;
        prev->next = to_move;
        to_move = start->next;
    }

    return dummy->next;
}

// definition for singly-linked list
int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    std::cout << "\nGeneral case:" << std::endl;
    std::cout << head1 << std::endl;
    std::cout << reverse_between(head1, 2, 4) << std::endl;

// Edge test case 

    ListNode* empty_sll = nullptr;

    std::cout << "\nEmpty SLL: " << std::endl;
    std::cout << empty_sll << std::endl;
    std::cout << reverse_between(empty_sll, 1, 20) << std::endl;

    return 0;
}