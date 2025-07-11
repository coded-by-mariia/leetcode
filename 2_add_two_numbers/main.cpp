/**********************************************************************************************
 * Problem 2: Add Two Numbers: Easy
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
**********************************************************************************************/

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

ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy_head = new ListNode(0);
    ListNode* current = dummy_head;
    
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        current->next = new ListNode(sum % 10);
        current = current->next;
        
        carry = sum / 10;
    }

    return dummy_head->next;    
}

int main() {
    std::cout << "\n--- case 1 -----------------\n";

    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    ListNode* list_sum1 = add_two_numbers(list1, list2);

    std::cout << "List 1:      " << list1 << "\n";
    std::cout << "List 2:      " << list2 << "\n";
    std::cout << "Their sum:   " << list_sum1 << "\n";


    std::cout << "\n--- case 2 -----------------\n";
    
    ListNode* list3 = new ListNode(0);
    ListNode* list4 = new ListNode(0);
    ListNode* list_sum2 = add_two_numbers(list3, list4);

    std::cout << "List 3:      " << list3 << "\n";
    std::cout << "List 4:      " << list4 << "\n";
    std::cout << "Their sum:   " << list_sum2 << "\n";

    std::cout << "\n--- case 3 -----------------\n";
    
    return 0;
}