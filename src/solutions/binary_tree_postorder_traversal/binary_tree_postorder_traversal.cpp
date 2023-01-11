/**
 * Binary Tree Postorder Traversal
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example: given binary tree {1,#,2,3},
 *   1
 *    \
 *     2
 *    /
 *   3
 * return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                stk.push(make_pair(node, false));
                node = node->left;
            }
            auto p = stk.top();
            stk.pop();
            if (p.first) {      // should visit?
                result.push_back(p.second->val);
                node = nullptr;
            } else {
                stk.push(make_pair(p.first, true));
                node = p.second->right;
            }
        }
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nullptr) {
            if (node != nullptr) {
                stk.push(make_pair(node, false));
                node = node->left;
            } else {
                auto p = stk.top();
                stk.pop();
                if (p.second) {     // should visit?
                    result.push_back(p.first->val);
                    node = nullptr;
                } else {
                    stk.push(make_pair(p.first, true));
                    node = p.first->right;
                }
            }
        }
        return result;
    }
};
