/*
 * Reorder List
 *
 * Given a singly linked list:
 *
 *    L0 -> L1 -> L2 -> L3 -> ... -> Ln-1 -> Ln,
 *
 * reorder it to:
 *
 *    L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example, given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return;
        auto halves = split(head);
        ListNode *first_half = halves.first;
        ListNode *second_half = reverse(halves.second);
        interleave(first_half, second_half);
    }

    pair<ListNode*, ListNode*> split(ListNode *head) {
        // Edge cases
        if (head == nullptr || head->next == nullptr)
            return make_pair(head, nullptr);
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second_half = slow->next;
        slow->next = nullptr;
        return make_pair(head, second_half);
    }

    ListNode *reverse(ListNode *head) {
        // Edge cases
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *curr = nullptr;
        ListNode *next = head;
        while (next != nullptr) {
            ListNode *prev = curr;
            curr = next;
            next = next->next;
            curr->next = prev;
        }
        return curr;
    }

    ListNode *interleave(ListNode *first, ListNode *second) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        ListNode *p = first, *q = second;
        int i = 0;
        while (p != nullptr && q != nullptr) {
            if (i % 2 == 0) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
            ++i;
        }
        tail->next = (p != nullptr ? p : q);
        return dummy.next;
    }
};
