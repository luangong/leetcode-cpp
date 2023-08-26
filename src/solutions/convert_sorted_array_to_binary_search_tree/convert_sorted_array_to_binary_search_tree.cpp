/**
 * Convert Sorted Array To Binary Search Tree
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * Tags: Tree, Depth-first Search
 */

#include <vector>
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
    TreeNode *sortedArrayToBST(vector<int>& num) {
        return sortedArrayToBST(num.begin(), num.end());
    }

    TreeNode *sortedArrayToBST(vector<int>::iterator beg, vector<int>::iterator end) {
        if (beg >= end) return nullptr;
        vector<int>::iterator mid = beg + (end - beg) / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(beg, mid);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};
