/**
 * Construct Binary Tree from Inorder and Postorder Traversal
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Tags: Tree, Array, Depth-first Search
 */
#include <vector>
#include <algorithm>

using std::vector;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(&inorder[0], &inorder[0] + inorder.size(), &postorder[0], &postorder[0] + postorder.size());
    }

    TreeNode *buildTree(int *firstInorder, int *lastInorder, int *firstPostorder, int *lastPostorder) {
        if (firstInorder >= lastInorder)
            return nullptr;
        // 后序遍历序列的最后一个元素就是根节点
        int rootVal = *(lastPostorder - 1);
        // 再从中序遍历序列中找到根节点，从而把序列分为左右两半，即为左右子树
        int *p = find(firstInorder, lastInorder, rootVal);
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(firstInorder, p, firstPostorder, firstPostorder + (p - firstInorder));
        root->right = buildTree(p + 1, lastInorder, firstPostorder + (p - firstInorder), lastPostorder - 1);
        return root;
    }
};
