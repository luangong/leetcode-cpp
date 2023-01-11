/*
 * Recover Binary Search Tree
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note: A solution using O(n) space is pretty straight forward.  Could you
 * devise a constant space solution?
 *
 * Tags: Tree, Depth-first Search
 */
#include <iostream>
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
    void recoverTree(TreeNode *root) {
        TreeNode *big = nullptr;
        TreeNode *small = nullptr;
        traverse(root, big, small);
        if (big == nullptr) big = small->left;
        else if (small == nullptr) small = big->right;
        // swap(big->val, small->val);
        int tmp = big->val;
        big->val = small->val;
        small->val = tmp;
    }

    void traverse(TreeNode *root, TreeNode *& big, TreeNode *& small) {
        if (root == nullptr) return;
        if (root->left != nullptr && root->val < root->left->val)
            small = root;
        if (root->right != nullptr && root->val > root->right->val)
            big = root;
        traverse(root->left, big, small);
        traverse(root->right, big, small);
    }
};

int main(int argc, char **argv) {
    TreeNode root(3), left(1), right(2);
    root.left = &left;
    root.right = &right;
    Solution sln;
    sln.recoverTree(&root);
    cout << root.left->val << ' ' << root.val << ' ' << root.right->val << endl;
    return 0;
}
