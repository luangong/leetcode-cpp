/*
 * Remove Duplicates from Sorted List
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
        if (head == nullptr) return nullptr;
        ListNode *tail = head;
        ListNode *curr = head->next;
        while (curr != nullptr) {
            if (curr->val != tail->val) {   // 如果当前 node 的值跟之前的不同则
                tail->next = curr;          // 加入到 tail
                tail = tail->next;
                curr = curr->next;
            } else {                        // 否则删除当前结点
                ListNode *tmp = curr;
                curr = curr->next;
                delete tmp;
            }
        }
        tail->next = nullptr;
        return head;
    }
};
