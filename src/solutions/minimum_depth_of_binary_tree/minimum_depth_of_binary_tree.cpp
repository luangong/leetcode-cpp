/*
 * Minimum Depth of Binary Tree
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Tags: Tree, Depth-first Search
 */

#include <iostream>
#include <queue>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left=nullptr, TreeNode *right=nullptr)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr)
            return 1 + minDepth(root->right);
        else if (root->right == nullptr)
            return 1 + minDepth(root->left);
        else
            return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    int minDepth2(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        while (!Q.empty()) {
            TreeNode *node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            // If we found a leaf node, it must be the shallowest one
            // because we are traversing the tree in level order
            if (node->left == nullptr && node->right == nullptr)
                return depth;
            if (node->left != nullptr)
                Q.push(make_pair(node->left, depth + 1));
            if (node->right != nullptr)
                Q.push(make_pair(node->right, depth + 1));
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5)))));
    cout << Solution().minDepth2(root) << endl;
    return 0;
}
