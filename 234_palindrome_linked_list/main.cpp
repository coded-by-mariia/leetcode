/**************************************************************************************
 * Problem 234: Palindrome Linked List: Easy
 * 
 * Given the head of a singly linked list, return true if it is a palindrome 
 * or false otherwise.
 * 
**************************************************************************************/

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
bool is_palindrome(ListNode* head) {
    // check if we need to do any work at all
    if (!head || !head->next) return true;

    // ok, if we get this far, we need to do something

    // step 1: search the middle of the given SLL
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2: reverse second half of SLL
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // step 3: actual comparison of two halves
    ListNode* left = head;
    ListNode* right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

int main() {
    // palindrome case odd number of nodes
    ListNode* palindrome_odd = new ListNode(1);
    palindrome_odd->next = new ListNode(2);
    palindrome_odd->next->next = new ListNode(3);
    palindrome_odd->next->next->next = new ListNode(2);
    palindrome_odd->next->next->next->next = new ListNode(1);

    // palindrome case even number of nodes
    ListNode* palindrome_even = new ListNode(10);
    palindrome_even->next = new ListNode(20);
    palindrome_even->next->next = new ListNode(20);
    palindrome_even->next->next->next = new ListNode(10);

    // palindrome case as only one node
    ListNode* palindrome_one_node = new ListNode(100);

    // non palindrome
    ListNode* non_palindrome = new ListNode(11);
    non_palindrome->next = new ListNode(22);
    non_palindrome->next->next = new ListNode(33);

    // Run tests
    std::cout << "Testing palindrome_odd:       " << palindrome_odd 
              << " => " << std::boolalpha << is_palindrome(palindrome_odd) << "\n";

    std::cout << "Testing palindrome_even:      " << palindrome_even 
              << " => " << std::boolalpha << is_palindrome(palindrome_even) << "\n";

    std::cout << "Testing palindrome_one_node:  " << palindrome_one_node 
              << " => " << std::boolalpha << is_palindrome(palindrome_one_node) << "\n";

    std::cout << "Testing non_palindrome:       " << non_palindrome 
              << " => " << std::boolalpha << is_palindrome(non_palindrome) << "\n";


    return 0;
}