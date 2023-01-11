/**
 * Flatten Binary Tree to Linked List
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 *
 * The flattened tree should look like:
 *
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * Hints: If you notice carefully in the flattened tree, each node's right
 * child points to the next node of a pre-order traversal.
 *
 * Tags: Tree, Depth-first Search
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
class Solution {
public:
    void flatten(TreeNode *root) {
        inorder(root);
    }

    TreeNode *inorder(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode *leftLast = inorder(root->left);
        TreeNode *rightLast = inorder(root->right);
        if (leftLast != nullptr && rightLast != nullptr) {
            leftLast->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            return rightLast;
        } else if (leftLast != nullptr) {
            root->right = root->left;
            root->left = nullptr;
            return leftLast;
        } else {
            root->left = nullptr;
            return rightLast;
        }
    }
};
