/*
 * Insertion Sort List
 *
 * Sort a linked list using insertion sort.
 *
 * Tags: Linked List, Sort
 */

#include <iostream>
#include <random>

using namespace std;

/** Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next=nullptr)
        : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(0);
        for (ListNode *curr = head; curr != nullptr;) {
            ListNode *pos = findInsertPos(&dummy, curr->val);
            ListNode *next = curr->next;
            curr->next = pos->next;
            pos->next = curr;
            curr = next;
        }
        return dummy.next;
    }

    ListNode *findInsertPos(ListNode *head, int x) {
        ListNode *prev = nullptr;
        for (ListNode *curr = head;
                curr != nullptr && curr->val <= x;
                prev = curr, curr = curr->next)
            ;
        return prev;
    }

    void printNode(ListNode *p) {
        cout << "val = " << p->val << endl;
        cout << "next = " << p->next << endl;
    }

    void printList(ListNode *head) {
        for (ListNode *p = head; p != nullptr; p = p->next)
            cout << p->val << ' ';
        cout << endl;
    }
};

int main(int argc, char **argv) {
    default_random_engine dre;
    uniform_int_distribution<> dis(0, 99);
    ListNode *head = nullptr;
    for (int i = 0; i < 10; ++i)
        head = new ListNode(dis(dre), head);
    Solution sln;
    sln.printList(head);
    head = sln.insertionSortList(head);
    sln.printList(head);
    return 0;
}
