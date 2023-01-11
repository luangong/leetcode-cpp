/*
 * Binary Tree ZigZag Level Order Traversal
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (i.e., from left to right, then right to left for the next level and
 * alternate between).
 *
 * For example: given binary tree {3,9,20,#,#,15,7},
 *
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *
 * return its zigzag level order traversal as:
 *
 *    [
 *      [3],
 *      [20,9],
 *      [15,7]
 *    ]
 *
 * Tags: Tree, Breadth-first Search, Stack
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 方法一：用两个栈互相倒
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        stack<TreeNode*> stk1, stk2;
        stack<TreeNode*> *thisStack = &stk1;
        stack<TreeNode*> *thatStack = &stk2;
        if (root != nullptr) thisStack->push(root);
        bool left2right = true;
        while (!thisStack->empty()) {
            vector<int> tmp;
            while (!thisStack->empty()) {
                TreeNode *p = thisStack->top();
                thisStack->pop();
                tmp.push_back(p->val);
                if (left2right) {
                    if (p->left != nullptr)
                        thatStack->push(p->left);
                    if (p->right != nullptr)
                        thatStack->push(p->right);
                } else {
                    if (p->right != nullptr)
                        thatStack->push(p->right);
                    if (p->left != nullptr)
                        thatStack->push(p->left);
                }
            }
            result.push_back(tmp);
            left2right = !left2right;
            stack<TreeNode*> *tmpStack = thisStack;
            thisStack = thatStack;
            thatStack = tmpStack;
        }
        return result;
    }

    /**
     * 方法二：先统一处理，最后再每隔一层 reverse 一下
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        if (root != nullptr) Q.push(root);
        int numNodesCurrLevel = 1;
        while (!Q.empty()) {
            vector<int> currLevel;
            int numNodesNextLevel = 0;
            for (int i = 0; i < numNodesCurrLevel; ++i) {
                TreeNode *node = Q.front();
                Q.pop();
                currLevel.push_back(node->val);
                if (node->left != nullptr) {
                    Q.push(node->left);
                    ++numNodesNextLevel;
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                    ++numNodesNextLevel;
                }
            }
            result.push_back(currLevel);
            numNodesCurrLevel = numNodesNextLevel;
        }
        for (int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> current, next;
        current.push(root);
        while (!current.empty()) {
            vector<int> level;
            while (!current.empty()) {
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    next.push(node->left);
                if (node->right != nullptr)
                    next.push(node->right);
            }
            result.push_back(level);
            swap(current, next);
        }
        for (int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }
};
