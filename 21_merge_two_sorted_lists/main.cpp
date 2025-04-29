/***************************************************************************************
 * Problem 21: Merge Two Sorted Lists: Easy
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * 
 * Merge the two lists into one sorted list.
 * The list should be made by splicing together the nodes of the first two lists. 
 * 
 * Return the head of the merged linked list.
****************************************************************************************/

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

ListNode* merge_two_lists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val < list2->val) {
        list1->next = merge_two_lists(list1->next, list2);
        return list1;
    } else {
        list2->next = merge_two_lists(list1, list2->next);
        return list2;
    }
}


int main() {

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    std::cout << list1 << std::endl;
    std::cout << list2 << std::endl;

    ListNode* merged_list = merge_two_lists(list1, list2);
    std::cout << merged_list << std::endl;
    
    return 0;
}