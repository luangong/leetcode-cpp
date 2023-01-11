/*
 * Rotate List
 *
 * Given a list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * For example:
 *
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 * Tags: Linked List, Two Pointers
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) return nullptr;
        k %= getLength(head);
        ListNode *p = head;
        for (int i = 0; i < k; ++i)
            p = p->next;

        // 如果向前移动 k 步之后 p 为 head，说明 k 刚好是链表
        // 长度的整数倍，于是直接返回 head
        if (p == head) return head;

        // 否则两个指针一起前进，直到 p 指向最后一个结点，q 指向
        // 待旋转的第一个结点前的那一个结点
        ListNode *q = head;
        while (p->next != nullptr) {
            p = p->next;
            q = q->next;
        }

        // 令最后一个结点指向原 head，新 head 的前一个结点指向 nullptr
        // 并返回新的 head
        ListNode *newhead = q->next;
        p->next = head;
        q->next = nullptr;
        return newhead;
    }

    int getLength(ListNode *head) {
        int length = 0;
        ListNode *p = head;
        while (p != nullptr) {
            p = p->next;
            ++length;
        }
        return length;
    }
};
