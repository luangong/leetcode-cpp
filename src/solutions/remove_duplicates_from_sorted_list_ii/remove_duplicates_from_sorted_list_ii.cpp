/*
 * Remove Duplicates from Sorted List II
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        ListNode *first = head, *last = head;
        while (last != nullptr) {
            // 令 last 指向一片连续相同结点的最后一个结点
            while (last->next != nullptr && last->val == last->next->val)
                last = last->next;
            ListNode *next_group = last->next;
            // 如果 first == last，说明本组元素只有一个，则把它加到最终的链表中去
            if (first == last) {                // distinct values
                tail->next = first;
                tail = tail->next;
            } else {                            // 删除 [first, last] 内所有结点
                ListNode *p = first;
                while (p != next_group) {
                    ListNode *tmp = p;
                    p = p->next;
                    delete tmp;
                }
            }
            first = last = next_group;          // 移动到下一组结点的开头
        }
        tail->next = nullptr;
        return dummy->next;
    }
};
