/**
 * Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note: You may assume that duplicates do not exist in the tree.
 *
 * Tags: Tree, Array, Depth-first Search
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
    typedef vector<int>::iterator Iterator;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        // 建立结点的值到该结点在中序遍历序列中的位置（指针）的映射
        unordered_map<int, Iterator> hashMap;
        for (int i = 0; i < n; ++i)
            hashMap.insert(make_pair(inorder[i], inorder.begin() + i));
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), hashMap);
    }

    // h 和 i 分别表示 preorder 的 start 和 end，j 和 k 分别
    // 表示 inorder 的 start 和 end
    TreeNode *buildTree(Iterator h, Iterator i, Iterator j, Iterator k, unordered_map<int, Iterator>& hashMap) {
        if (h >= i) return nullptr;
        TreeNode *root = new TreeNode(*h);
        // 前序遍历序列的第一个元素就是根结点，然后从中序遍历序列中找到根结点
        // 所在的位置，从而分出左右子树
        Iterator mid = hashMap[*h];
        // int *mid = find(j, k, *h);
        int leftsize = mid - j;
        int rightsize = k - mid;
        root->left = buildTree(h + 1, h + 1 + leftsize, j, mid, hashMap);
        root->right = buildTree(h + 1 + leftsize, i, mid + 1, k, hashMap);
        return root;
};
