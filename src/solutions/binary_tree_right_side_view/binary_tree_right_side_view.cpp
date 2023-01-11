/*
 * Binary Tree Right Side View
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * For example: Given the following binary tree,
 *
 *       1            <---
 *     /   \
 *    2     3         <---
 *    \      \
 *    5       4       <---
 *
 * You should return [1, 3, 4].
 *
 * Credits: Special thanks to @amrsaqr for adding this problem and creating all
 * test cases.
 *
 * Tags: Tree, Depth-first Search, Breadth-first Search
 */

/**
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> Q({root});
        while (!Q.empty()) {
            result.push_back(Q.back()->val);
            size_t size = Q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left != nullptr)
                    Q.push(node->left);
                if (node->right != nullptr)
                    Q.push(node->right);
            }
        }
        return result;
    }
};
