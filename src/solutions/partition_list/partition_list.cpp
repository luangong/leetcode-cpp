/**
 * Partition List
 *
 * Given a linked list and a value x, partition it such that all nodes less than
 * x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example,
 *
 * Given  1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 *
 * Tags: Linked List, Two Pointers
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct comp {
    bool operator()(const ListNode *node) {
        return node->val < x;
    }
    int x;
    comp(int val) : x(val) {}
};

class Solution {
public:
    /**
     * 设置两个 dummy node，一个用来链接所有值小于 x 的结点，
     * 另一个用来链接所有值大于或等于 x 的结点。遍历原链表，根据当前结点
     * 值的大小将其添加到相应链表的尾部。遍历结束后，再令值较小的链表的
     * 尾部指向值较大的链表的头部，同时令值较大的链表的尾部指向 null
     *（因为此结点不一定是原链表的最后一个结点，其 next 不一定是 null）。
     * 需要 O(n) 时间和 O(1) 空间
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode dummySmaller(0);
        ListNode *tailSmaller = &dummySmaller;
        ListNode dummyBigger(0);
        ListNode *tailBigger = &dummyBigger;
        for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
            if (curr->val < x) {
                tailSmaller->next = curr;
                tailSmaller = tailSmaller->next;
            } else {
                tailBigger->next = curr;
                tailBigger = tailBigger->next;
            }
        }
        tailSmaller->next = dummyBigger.next;
        tailBigger->next = nullptr;
        return dummySmaller.next;
    }
};
