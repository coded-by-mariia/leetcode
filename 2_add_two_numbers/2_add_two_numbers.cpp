/// ===============================================================
/// Problem # : 2
/// Title     : Add Two Numbers
/// Difficulty: Easy
///
/// Description:
/// You are given two non-empty linked lists representing two non-negative integers.
/// The digits are stored in reverse order, and each of their nodes contains a single digit. 
/// Add the two numbers and return the sum as a linked list.
///
/// Constraints:
/// - The number of nodes in each linked list is in the range [1, 100]
/// - 0 <= Node.val <= 9
/// - It is guaranteed that the list represents a number that does not have leading zeros.
///
/// Approach:
/// The approach iteratively traverses both linked lists, summing corresponding digits 
/// along with any carry, and builds a new linked list to represent the result digit by digit.
///
/// Time Complexity: O(max(m,n))
/// Space Complexity: O(max(m,n))
/// ===============================================================

#include "../utility/ListNode.h"

class Solution {
public:
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
};

/// Driver code for local testing
int main() {
    Solution sol;

    std::cout << "\n--- case 1 -----------------\n";

    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    ListNode* list_sum1 = sol.add_two_numbers(list1, list2);

    std::cout << "List 1:      " << list1 << "\n"; // 342
    std::cout << "List 2:      " << list2 << "\n"; // 465
    std::cout << "Their sum:   " << list_sum1 << "\n"; // 807


    std::cout << "\n--- case 2 -----------------\n";
    
    ListNode* list3 = new ListNode(0);
    ListNode* list4 = new ListNode(0);
    ListNode* list_sum2 = sol.add_two_numbers(list3, list4);

    std::cout << "List 3:      " << list3 << "\n"; // 0
    std::cout << "List 4:      " << list4 << "\n"; // 0
    std::cout << "Their sum:   " << list_sum2 << "\n"; // 0

    
    return 0;
}