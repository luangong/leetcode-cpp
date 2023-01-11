/*
 * Remove Nth Node from End of List
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 *
 * For example, given linked list: 1->2->3->4->5, and n = 2.  After removing the
 * second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note: Given n will always be valid.  Try to do this in one pass.
 *
 * Tags: Linked List, Two Pointers
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, const ListNode *n)
        : val(x), next(n) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0, head);
        ListNode *p = &dummy;           // 先让一个指针往前走 n 步
        for (int i = 0; i < n; ++i)
            p = p->next;

        ListNode *q = &dummy;           // 然后让另一个指针从头开始跟 p 同步往前走
        while (p->next != nullptr) {    // 直到先走的那个指针到达最后一个节点
            p = p->next;
            q = q->next;
        }

        ListNode *tmp = q->next;        // q 指向被删除结点的前一个结点
        q->next = q->next->next;
        delete tmp;
        return dummy.next;
    }
};
