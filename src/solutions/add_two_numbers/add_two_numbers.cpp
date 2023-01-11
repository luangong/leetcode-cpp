/**
 * Add Two Numbers
 *
 * You are given two linked lists representing two non-negative numbers.  The
 * digits are stored in reverse order and each of their nodes contain a single
 * digit.  Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8)
 *
 * Tags: Linked List
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
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        ListNode *p = list1, *q = list2;
        while (p != nullptr || q != nullptr) {
            int pval = (p != nullptr ? p->val : 0);
            int qval = (q != nullptr ? q->val : 0);
            int newval = (pval + qval + carry) % 10;
            carry = (pval + qval + carry) / 10;
            // Create a new node
            tail->next = new ListNode(newval);
            tail = tail->next;
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        // Add an additional node after the loop if carry is 1
        if (carry == 1)
            tail->next = new ListNode(1);
        return dummy.next;
    }
};
