/**************************************************************
 * Problem 876: Middle of the Linked List: Easy
 * 
 * Given the head of a singly linked list, return the 
 * middle node of the linked list
 * 
 * If there are two middle nodes, return the second middle node
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
    os << "]" << std::endl;
    return os;
}

ListNode* middle_node(ListNode* head) {
    ListNode* hare = head;
    ListNode* tortoise = head;

    while (hare != nullptr && hare->next != nullptr) {
        hare = hare->next->next;
        tortoise = tortoise->next;
    }

    return tortoise;
}

int main() {
    unsigned int wigth {20};

    // Test case for odd number of nodes
    ListNode* ll_1 = new ListNode(1);
    ll_1 -> next = new ListNode(2);
    ll_1 -> next -> next = new ListNode(3);

    std::cout << "\nTest case for odd number of nodes" << std::endl;
    std::cout << std::setw(wigth) << std::left << "Linkes List: " << ll_1;

    ListNode* middle_node_1 = middle_node(ll_1);
    std::cout << std::setw(wigth) << std::left << "Middle element: " 
              << middle_node_1->val << std::endl;


    // Test case of even number of nodes
    ListNode* ll_2 = new ListNode(1);
    ll_2 -> next = new ListNode(2);
    ll_2 -> next -> next = new ListNode(3);
    ll_2 -> next -> next -> next = new ListNode(4);

    std::cout << "\nTest case for even number of nodes" << std::endl;
    std::cout << std::setw(wigth) << std::left << "Linked List: " << ll_2;

    ListNode* middle_node_2 = middle_node(ll_2);
    std::cout << std::setw(wigth) << std::left << "Middle element: " 
              << middle_node_2->val << std::endl;

    return 0;
}