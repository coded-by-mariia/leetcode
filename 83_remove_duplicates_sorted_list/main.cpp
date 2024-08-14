/*********************************************************
 * Problem 82: Remove Duplicates From Sorted List: Easy
 * 
 * Given the head of a sorted linked list, delete 
 * all duplicates such that each element appears only once. 
 * Return the linked list sorted as well.
**********************************************************/

#include <iostream>

// definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// easy and elegant way to print the linked list
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

ListNode* delete_duplicates(ListNode* head) {
    // edge case: empty list
    if (!head) return head;

    // general case
    ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) { 
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }   
    }

    return head;
}


int main() {
    // Test case: Empty List
    ListNode* empty_list = nullptr;
    std::cout << "\nEmpty List:" << std::endl;
    std::cout << "\t" << empty_list << std::endl;

    ListNode* new_empty_list = delete_duplicates(empty_list);

    std::cout << "Empty List after attemp:" << std::endl;
    std::cout << "\t" << new_empty_list << std::endl;

    // Test Case: Only One Element in List
    ListNode* one_element_list = new ListNode(10);
    std::cout << "\nList with One Element:" << std::endl;
    std::cout << "\t" << one_element_list << std::endl;

    ListNode* new_one_element_list = delete_duplicates(one_element_list);

    std::cout << "List with one element after attemp:" << std::endl;
    std::cout << "\t" << new_one_element_list << std::endl;
    
    // General Test Case: SLL with duplicates
    ListNode* sorted_ll = new ListNode(1);
    sorted_ll -> next = new ListNode(2);
    sorted_ll -> next -> next = new ListNode(2);
    sorted_ll -> next -> next -> next = new ListNode(3);

    std::cout << "\nSorted singly-linked list with duplicates:" << std::endl;
    std::cout << "\t" << sorted_ll << std::endl;

    ListNode* new_sorted_ll = delete_duplicates(sorted_ll);

    std::cout << "Sorted SLL after removing duplicates:" << std::endl;
    std::cout << "\t" << new_sorted_ll << std::endl;

    // General Test Case: SLL without duplicates
    ListNode* sorted_ll_2 = new ListNode(10);
    sorted_ll_2 -> next = new ListNode(20);
    sorted_ll_2 -> next -> next = new ListNode(30);

    std::cout << "\nSorted singly-linked list with NO duplicates:" << std::endl;
    std::cout << "\t" << sorted_ll_2 << std::endl;

    ListNode* new_sorted_ll_2 = delete_duplicates(sorted_ll_2);

    std::cout << "Sorted SLL after attempt:" << std::endl;
    std::cout << "\t" << new_sorted_ll_2 << std::endl;


    return 0;
}