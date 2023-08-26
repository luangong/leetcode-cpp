/**
 * Convert Sorted List to Binary Search Tree
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * Tags: Depth-first Search, Linked List
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // 把链表结点指针复制到 vector 里面然后仿照数组换平衡二叉树的方法
        vector<ListNode*> nodes;
        for (ListNode *p = head; p != nullptr; p = p->next)
            nodes.push_back(p);
        return sortedArray2BST(nodes.begin(), nodes.end());
    }

    TreeNode *sortedArray2BST(vector<ListNode*>::iterator beg, vector<ListNode*>::iterator end) {
        if (beg >= end) return nullptr;
        vector<ListNode*>::iterator mid = beg + (end - beg) / 2;
        TreeNode *root = new TreeNode((*mid)->val);
        root->left = sortedArray2BST(beg, mid);
        root->right = sortedArray2BST(mid + 1, end);
        return root;
    }
};
