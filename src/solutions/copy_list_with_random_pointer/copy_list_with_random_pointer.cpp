/*
 * Copy List with Random Pointer
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 * Tags: Hash Table, Linked List
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // 解法一：O(n) 时间，O(n) 空间
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> lookupTable;
        RandomListNode dummy(0);
        RandomListNode *tail = &dummy;
        for (RandomListNode *p = head; p != nullptr; p = p->next) {
            RandomListNode *node = new RandomListNode(p->label);
            lookupTable[p] = node;
            tail->next = node;
            tail = tail->next;
        }

        // Since the [] subscription operation automatically inserts a default
        // value (nullptr) when p->random == nullptr is not found in the map, we
        // don't need to insert the nullptr => nullptr mapping in advance
        for (RandomListNode *p = head; p != nullptr; p = p->next)
            lookupTable[p]->random = lookupTable[p->random];
        return dummy.next;
    }

    /** 解法二：O(n) 时间，O(1) 空间 */
    RandomListNode *copyRandomList(RandomListNode *head) {
        return splitList(copyRandomPointers(copyList(head)));
    }

    /**
     * 复制链表节点，并使新链表和原链表交错连接在一起，例如
     * 1 2 3 变成 1 1 2 2 3 3
     */
    RandomListNode *copyList(RandomListNode *head) {
        for (RandomListNode *p = head; p != nullptr; ) {
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        return head;
    }

    /** 复制 random 指针 */
    RandomListNode *copyRandomPointers(RandomListNode *head) {
        for (RandomListNode *p = head; p != nullptr; ) {
            if (p->random != nullptr)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        return head;
    }

    /** 分拆两个链表，提取第 2, 4, 6, ... 个结点为一个新的链表 */
    RandomListNode *splitList(RandomListNode *head) {
        RandomListNode dummy(0);
        RandomListNode *tail = &dummy;
        for (RandomListNode *p = head; p != nullptr; p = p->next) {
            tail->next = p->next;
            tail = tail->next;
            p->next = tail->next;
        }
        return dummy.next;
    }
};
