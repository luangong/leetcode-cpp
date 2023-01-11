/**
 * Validate Binary Search Tree
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *    - The left subtree of a node contains only nodes with keys less than the
 *      node's key.
 *
 *    - The right subtree of a node contains only nodes with keys greater than
 *      the node's key.
 *
 *    - Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        // BUG: The algorithm fails when the smallest node is INT_MIN or
        // the largest node is INT_MAX
        return isValidBSTImpl(root, numeric_limits<int>::min,
                                    numeric_limits<int>::max);
    }

    bool isValidBSTImpl(TreeNode* root, int min, int max) {
        if (root == nullptr) return true;
        if (min < root->val && root->val < max)
            if (isValidBST(root->left, min, root->val))
                return isValidBST(root->right, root->val, max);
        return false;
    }

    /**
     * 非递归算法，对二叉树进行中序遍历，然后检查每一个结点的值是否大于前一个
     * 结点的值。时间复杂度为 O(n)
     */
    bool isValidBST(TreeNode *root) {
        bool first = true;
        int prev;
        TreeNode *p = root;
        stack<TreeNode*> stk;
        while (p != nullptr || !stk.empty()) {
            while (p != nullptr) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top(); stk.pop();
            if (!first && p->val <= prev)
                return false;
            prev = p->val;
            first = false;
            p = p->right;
        }
        return true;
    }
};
