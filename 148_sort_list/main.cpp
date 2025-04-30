/***************************************************************************************
 * Problem 148: Sort List: Medium
 * 
 * Given the head of a linked list, return the list after sorting it in ascending order.
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

// helper function to get the middle of the list
ListNode* get_middle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev; // this is the node BEFORE the start of the right half
}

// helper function to merge two sorted lists
ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (left && right) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // append the remainig elements
    if (left) tail->next = left;
    if (right) tail->next = right;

    return dummy->next;
}

// merge sort function on a linked list
ListNode* sort_list(ListNode* head) {
    // base cases: empty list or single node is already sorted
    if (!head || !head->next) return head;

    // step 1: split the list into two halves
    ListNode* mid = get_middle(head);
    ListNode* right = mid->next;
    mid->next = nullptr; // Actually split the list here

    // step 2: recursively sort each half
    ListNode* left = sort_list(head);
    right = sort_list(right);

    // step 3: merge the two sorted halves
    return merge(left, right);
}

int main() {
    // create an unsorted linked list: 4 -> 2 -> 1 -> 3
    ListNode* node4 = new ListNode(3);
    ListNode* node3 = new ListNode(1, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(4, node2);

    std::cout << "Original list: " << head << std::endl;

    // sort the list
    ListNode* sorted = sort_list(head);

    std::cout << "Sorted list:   " << sorted << std::endl;

    return 0;
}