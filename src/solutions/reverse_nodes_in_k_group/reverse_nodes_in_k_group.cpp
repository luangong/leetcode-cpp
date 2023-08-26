/*
 * Reverse Nodes in k-Group
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end
 * should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example, given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Tags: Linked List
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        while (true) {
            ListNode *last = prev;
            for (int i = 0; i < k && last != nullptr; ++i)
                last = last->next;
            if (last == nullptr)
                break;
            ListNode *first = prev->next;
            prev->next = last;
            prev = reverse(first, last);
        }
        return dummy.next;
    }

    ListNode *reverse(ListNode *first, ListNode *last) {
        ListNode *curr = last->next;
        ListNode *next = first;
        ListNode *sentinel = last->next;
        while (next != sentinel) {
            ListNode *prev = curr;
            curr = next;
            next = next->next;
            curr->next = prev;
        }
        return first;
    }
};
