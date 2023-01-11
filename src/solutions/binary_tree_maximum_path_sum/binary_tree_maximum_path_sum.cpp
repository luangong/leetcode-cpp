/**
 * Binary Tree Maximum Path Sum
 *
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example: given the below binary tree,
 *
 *       1
 *      / \
 *     2   3
 *
 * Return 6.
 *
 * Tags: Tree, Depth-first Search
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
   int maxPathSum(TreeNode *root) {
        int csum;
        int maxsum = numeric_limits<int>::min();
        helper(root, csum, maxsum);
        return maxsum;
    }

    void helper(TreeNode *root, int &csum, int &maxsum) {
        if (root == nullptr) {
            csum = 0;
            return;
        }
        int lsum = 0, rsum = 0;
        helper(root->left, lsum, maxsum);
        helper(root->right, rsum, maxsum);
        csum = root->val + max({0, lsum, rsum});
        maxsum = max({maxsum, csum, root->val + lsum + rsum});
    }
};
