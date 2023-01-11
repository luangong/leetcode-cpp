/*
 * Reverse Linked List II
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 *
 * Given  1->2->3->4->5->nullptr, m = 2 and n = 4,
 * return 1->4->3->2->5->nullptr.
 *
 * Note:
 *
 * Given m, n satisfy the following condition:
 * 1 <= m <= n <= length of list.
 */
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;

        // 令 before_mth 指向第 m-1 个节点
        ListNode *before_mth = &dummy;
        for (int i = 0; i < m-1; ++i)
            before_mth = before_mth->next;
        // mth 指向第 m 个节点
        ListNode *mth = before_mth;

        // 逆转链表的第 m 个到第 n 个结点之间的部分
        ListNode *curr = mth->next;
        for (int i = m; i < n; ++i) {
            mth->next = curr->next;
            curr->next = before_mth->next;
            before_mth->next = curr;
            curr = mth->next;
        }
        return dummy.next;
    }
};

int main(int argc, char **argv) {
    ListNode node(123);
    Solution sln;
    sln.reverseBetween(&node, 1, 1);
    return 0;
}
