/***********************************************************************
 * Problem 86: Partition List: Medium
 * 
 * Given the head of a linked list and a value x, partition it such that 
 * all nodes less than x come before nodes greater than or equal to x
 * 
 * You should preserve the original relative order of
 * the nodes in each of the two partitions
***********************************************************************/

#include <iostream>

// definition of linked list
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

// function partitioning a linked list
ListNode* partition_list(ListNode* head, int target) {
    ListNode* current = head; // a helper for iteration through the linked list

    ListNode* before_head = new ListNode(0); // beginning of the list with nodes less than target
    ListNode* after_head = new ListNode(0); // beginning of the list with nodes greater than target

    ListNode* before = before_head; 
    ListNode* after = after_head; 

    while (current) {
        if (current->val < target) {
            before->next = current;
            before = before->next;
        } else {
            after->next = current;
            after = after->next;
        }
        current = current->next;
    }
    after->next = nullptr;
    before->next = after_head->next;

    // Get the new head of the partitioned list
    ListNode* new_head = before_head->next;
    
    // small clean up
    delete before_head;
    delete after_head;

    return new_head;
}


int main() {

    ListNode* ll_1 = new ListNode(10);
    ll_1 -> next = new ListNode(2);
    ll_1 -> next -> next = new ListNode(7);
    ll_1 -> next -> next -> next = new ListNode(3);

    int target {5};

    std::cout << "\nOriginal Linked List: " << ll_1 << std::endl;
    std::cout << "Target value: " << target << std::endl;

    ListNode* new_ll = partition_list(ll_1, target);

    std::cout << "\nPartitioned Linked List: " << new_ll << std::endl;

    // Clean up remaining list nodes
    while (new_ll) {
        ListNode* temp = new_ll;
        new_ll = new_ll->next;
        delete temp;
    }
 
    return 0;
}