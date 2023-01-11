/*
 * Swap Nodes in Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example, given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space.  You may NOT modify the values
 * in the list, only nodes itself can be changed.
 *
 * Tags: Linked List
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *p = head;
        while (p != nullptr && p->next != nullptr) {
            swap(p->val, p->next->val);
            p = p->next->next;
        }
        return head;
    }

    ListNode *swapPairs(ListNode *head) {
        // Edge case
        if (head == nullptr || head->next == nullptr)
            return head;
        // Initialize pointers
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;
        ListNode *next = head->next;
        // Swap all the pairs
        while (next != nullptr) {
            prev->next = next;
            curr->next = next->next;
            next->next = curr;
            // Move pointers to next pair
            prev = curr;
            curr = curr->next;
            next = (curr != nullptr ? curr->next : nullptr);
        }
        return dummy.next;
    }
};
