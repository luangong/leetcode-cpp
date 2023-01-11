/*
 * Merge Two Sorted Lists
 *
 * Merge two sorted linked lists and return it as a new list.  The new list
 * should be made by splicing together the nodes of the first two lists.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *p, ListNode *q) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }
        tail->next = (p != nullptr ? p : q);    // 剩余结点
        return dummy.next;
    }
};
