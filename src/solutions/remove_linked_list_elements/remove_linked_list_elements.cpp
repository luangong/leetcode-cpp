/*
 * Remove Linked List Elements
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 *
 * Given:
 *    1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, val = 6
 *
 * Return:
 *    1 -> 2 -> 3 -> 4 -> 5
 *
 * Credits: Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 *
 * Tags: Linked List
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode *head, int val) {
        ListNode dummy(0), *tail = &dummy;
        for (ListNode *curr = head, curr != nullptr; curr = curr->next) {
            if (curr->val == val)
                continue;
            tail->next = curr;
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
