/**
 * Binary Tree Inorder Traversal
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2]
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal, where '#'
 * signifies a path terminator where no node exists below.
 *
 * Here's an example:
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 *
 * Tags: Tree, Hash Table, Stack
 */

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include "binary_tree.h"

class Solution {
public:
    // 递归版本
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode *root, vector<int>& result) {
        if (root == nullptr) return;
        traverse(root->left, result);
        result.push_back(root->val);
        traverse(root->right, result);
    }

    // 非递归版本，借助栈
    vector<int> inorderTraversal2(TreeNode *root) {
        stack<TreeNode*> stk;
        vector<int> result;
        TreeNode *p = root;
        while (p != nullptr || !stk.empty()) {
            while (p != nullptr) {
                stk.push(p);
                p = p->left;
            }
            TreeNode *q = stk.top();
            stk.pop();
            result.push_back(q->val);
            p = q->right;
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while (node != nullptr || !stk.empty()) {
            if (node != nullptr) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};
