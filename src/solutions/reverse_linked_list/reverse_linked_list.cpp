/*
Reverse Linked List

Reverse a singly linked list.

Hint: A linked list can be reversed either iteratively or recursively.  Could
you implement both?

Tags: Linked List
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
public:
    // Iterative
    ListNode *reverseLinkedList(ListNode *head) {
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

    // Recursive
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }

    // Tail recursive
    ListNode *reverseList(ListNode *curr, ListNode *prev=nullptr) {
        if (curr == nullptr)
            return prev;
        ListNode *next = curr->next;
        curr->next = prev;
        return reverseList(next, curr);
    }
}
