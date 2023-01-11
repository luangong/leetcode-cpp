/*
 * Maximum Depth of Binary Tree
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root
 * node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // Non-recursive solution.  Mimics preorder traversal with a stack.
    // Every node in the stack has an associated depth value.  We add the depth
    // by one when push the node' children onto the stack.
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int max_depth = 1;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 1));
        while (!stk.empty()) {
            TreeNode *node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            if (depth > max_depth) max_depth = depth;
            if (node->right != nullptr)
                stk.push(make_pair(node->right, depth + 1));
            if (node->left != nullptr)
                stk.push(make_pair(node->left, depth + 1));
        }
        return max_depth;
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int max_depth = 1;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        while (!Q.empty()) {
            TreeNode *node = Q.top().first;
            int depth = Q.top().second;
            Q.pop();
            if (depth > max_depth)
                max_depth = depth;
            if (node->left != nullptr)
                Q.push(make_pair(node->left, depth + 1));
            if (node->right != nullptr)
                Q.push(make_pair(node->right, depth + 1));
        }
        return max_depth;
    }
};
