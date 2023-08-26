/**
 * Balanced Bianry Tree
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Tags: Tree, Depth-first Search
 */

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // T(n) = 4T(n/2) + O(1) ==> T(n) = O(n^2)
    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;
        int diff = height(root->left) - height(root->right);
        return isBalanced(root->left) && isBalanced(root->right) && abs(diff) <= 1;
    }

    int height(TreeNode *root) {
        if (root == nullptr)
            return -1;
        else
            return max(height(root->left), height(root->right)) + 1;
    }

    // 若 root 不是平衡的，则返回 -1，否则返回 root 的高度
    // T(n) = 2T(n/2) + O(1) ==> T(n) = O(n)
    int height(TreeNode *root) {
        if (root == nullptr) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        if (leftHeight != -1 && rightHeight != -1 && diff <= 1)
            return 1 + max(leftHeight, rightHeight);
        else
            return -1;
    }

};
