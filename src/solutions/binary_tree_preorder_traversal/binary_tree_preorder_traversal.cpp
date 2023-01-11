/**
 * Binary Tree Preorder Traversal
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *   1
 *    \
 *     2
 *    /
 *   3
 * return [1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 * Tags: Tree, Stack
 */

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode *root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        traverse(root.left, result);
        traverse(root.right, result);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while (p != nullptr || !stk.empty()) {
            while (p != nullptr) {
                result.push_back(p->val);
                stk.push(p);
                p = p->left;
            }
            p = stk.top()->right;
            stk.pop();
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root != nullptr) stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            result.push_back(node->val);
            if (node->right != nullptr)
                stk.push(node->right);
            if (node->left != nullptr)
                stk.push(node->left);
        }
        return result;
    }
};
