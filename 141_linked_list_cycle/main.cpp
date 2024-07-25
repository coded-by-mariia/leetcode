/**************************************************************
 * Problem 141: Linked List Cycle: Easy
 * 
 * Given head, the head of a linked list, 
 * determine if the linked list has a cycle in it
***************************************************************/

#include <iostream>
#include <iomanip>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::ostream &operator<<(std::ostream &os, const ListNode* head) {
    os << "[ ";
    const ListNode* temp = head;
    while (temp) {
        os << temp->val;
        if (temp->next != nullptr) {
            os << " -> ";
        }
        temp = temp->next;
    }
    os << " ]" << std::endl;
    return os;
}

bool has_cycle(ListNode* head) {
    // checking the edge case to avoid unnessesary computations
    // in the situation with empty LL or LL with one node
    // as it's impossible to have a cycle in this kind of LL
    if (!head || !head->next) return false;
    
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

int main() {
    unsigned int wigth {20};

    // Test case for LL without cycle in it
    ListNode* ll_1 = new ListNode(1);
    ll_1 -> next = new ListNode(2);
    ll_1 -> next -> next = new ListNode(3);

    std::cout << "\nTest case for LL without cycle" << std::endl;
    std::cout << std::setw(wigth) << std::left << "Linkes List: " << ll_1;

    if (has_cycle(ll_1)) {
        std::cout << "The LL has a cycle" << std::endl;
    } else {
        std::cout << "The LL does not have a cycle" << std::endl;
    }

    // Test case for LL with cycle in it
    ListNode* ll_2 = new ListNode(3);
    ll_2->next = new ListNode(2);
    ll_2->next->next = new ListNode(0);
    ll_2->next->next->next = new ListNode(-4);
    ll_2->next->next->next->next = ll_2->next; // make a cycle here

    std::cout << "\nTest case for LL with cycle" << std::endl;
    std::cout << "Obviously it's impossible to print this LL" << std::endl;;

    if (has_cycle(ll_2)) {
        std::cout << "The LL has a cycle" << std::endl;
    } else {
        std::cout << "The LL does not have a cycle" << std::endl;
    }

    // Test case for LL with a single node
    ListNode* ll_3 = new ListNode(5);

    std::cout << "\nTest case for LL withonly one node" << std::endl;
    std::cout << std::setw(wigth) << std::left << "Linkes List: " << ll_3;

    if (has_cycle(ll_3)) {
        std::cout << "The LL has a cycle" << std::endl;
    } else {
        std::cout << "The LL does not have a cycle" << std::endl;
    }

    return 0;
}