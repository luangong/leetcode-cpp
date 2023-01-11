/*
Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list.  Analyze and
describe its complexity.

Tags: Divide and Conquer, Linked List, Heap
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /*
     * 方法一：先把所有结点放到一个 heap（大顶堆）中，然后依次从
     * heap 中弹出一个结点，直到 heap 为空。
     *
     * 时间复杂度 O(nlgn)，空间复杂度 O(n)
     */
    auto comp = [](ListNode *p, ListNode *q) { return p->val < q->val; };

    ListNode *mergeKLists(vector<ListNode*> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> Q(comp);
        for (ListNode *node : lists) {
            while (p != nulptr) {
                Q.push(p);
                p = p->next;
            }
        }
        ListNode *dummy = new ListNode(0);
        while (!Q.empty()) {
            ListNode *node = Q.top(); Q.pop();
            node->next = dummy->next;
            dummy->next = node;
        }
        return dummy->next;
    }

    /**
     * 方法二：每次从 vector 里各个链表头部顺序选出一个最小的结点
     */
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (true) {
            int minIndex = -1;
            ListNode *minNode = nullptr;
            ListNode *virtualNode = new ListNode(numeric_limits<int>::max());
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr && lists[i]->val < virtualNode->val) {
                    virtualNode->val = lists[i]->val;
                    minNode = lists[i];
                    minIndex = i;
                }
            }
            if (minNode != nullptr) {
                if (head == nullptr)
                    head = minNode;
                if (tail != nullptr)
                    tail->next = minNode;
                tail = minNode;
                lists[minIndex] = lists[minIndex]->next;
                minNode->next = nullptr;
            } else {
                break;
            }
        }
        return head;
    }

    /** 方法三：每次 merge 一个链表。时间复杂度 O(...)，空间复杂度 O(1) */
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        for (ListNode *list : lists)
            head = merge(head, list);
        return head;
    }

    /** 方法四：每次合并两个链表，类似于归并排序。时间复杂度 O(n lg k)，空间复杂度 O(1) */
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        return doMergeKLists(lists.begin(), lists.end());
    }

    typedef vector<ListNode*>::iterator Iterator;

    ListNode *doMergeKLists(Iterator beg, Iterator end) {
        if (beg == end) return nullptr;
        if (end - beg == 1) return *beg;
        Iterator mid = beg + (end - beg) / 2;
        ListNode *first_half = doMergeKLists(beg, mid);
        ListNode *second_half = doMergeKLists(mid, end);
        return merge(first_half, second_half);
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
