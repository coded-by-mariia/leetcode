/*********************************************************************************
 * Problem 24: Swap Nodes in Pairs: Medium
 * 
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 * 
*********************************************************************************/

#include <iostream>
#include <vector>

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

ListNode* swap_pairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* first = prev->next;

    while (first && first->next) {
        ListNode* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
        first = first->next;
    }

    head = dummy->next;
    delete dummy;
    return head;
}


// Helper: create list from vector
ListNode* create_list(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper: delete list to prevent memory leaks
void delete_list(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    std::vector<std::vector<int>> test_cases = {
        {1, 2, 3, 4, 5},   // Odd-length list
        {1, 2, 3, 4},      // Even-length list
        {1},              // Single node
        {},               // Empty list
        {10, 20}          // Just two nodes
    };

    for (size_t i = 0; i < test_cases.size(); ++i) {
        ListNode* head = create_list(test_cases[i]);
        std::cout << "\tCase " << i + 1 << "\n";
        std::cout << "Before: " << head << "\n";
        head = swap_pairs(head);
        std::cout << "After : " << head << "\n\n";
        delete_list(head);
    }

    return 0;
}