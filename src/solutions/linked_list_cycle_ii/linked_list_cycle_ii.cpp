/*
 * Linked List Cycle II
 *
 * Given a linked list, return the node where the cycle begins.  If there is no
 * cycle, return null.
 *
 * Follow up: Can you solve it without using extra space?
*/

#include <iostream>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *chaser = head;
                while (chaser != slow) {
                    chaser = chaser->next;
                    slow = slow->next;
                }
                return chaser;
            }
        }
        return nullptr;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    cout << sln.detectCycle(nullptr) << endl;
    return 0;
}
