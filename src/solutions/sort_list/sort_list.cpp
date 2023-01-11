/*
 * Sort List
 *
 * Sort a linked list in O(n lg n) time using constant space complexity.
 *
 * Tags: Linked List, Sort
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
    ListNode *sortList(ListNode *head) {
        // Need to have at least two nodes
        if (head == nullptr || head->next == nullptr)
            return head;

        // Split the list into two equally-sized halves
        auto halves = split(head);

        // Sort the two halves separately
        ListNode *first_half = sortList(halves.first);
        ListNode *second_half = sortList(halves.second);

        // Merge the two halves into one linked list
        return merge(first_half, second_half);
    }

    pair<ListNode*, ListNode*> split(ListNode *head) {
        // Need to have at least two nodes
        if (head == nullptr || head->next == nullptr)
            return make_pair(head, nullptr);

        // Split the linked list into halves
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second_half = slow->next;
        slow->next = nullptr;
        return make_pair(head, second_half);
    }

    ListNode *merge(ListNode *p, ListNode *q) {
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
        tail->next = (p != nullptr ? p : q);
        return dummy.next;
    }
};
