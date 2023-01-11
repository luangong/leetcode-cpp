/**
 * Binary Tree Level Order Traversal
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (i.e., from left to right, level by level).
 *
 * For example, given binary tree {3,9,20,#,#,15,7},
 *
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *
 * return its level order traversal as:
 *
 *    [
 *      [3],
 *      [9,20],
 *      [15,7]
 *    ]
 *
 * Tags: Tree, Breadth-first Search
 */
#include <vector>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        int h = height(root);
        for (int level = 1; level <= h; ++level) {
            vector<int> vec;
            DFS(root, level, vec);
            result.push_back(vec);
        }
        return result;
    }

    int height(TreeNode *root) {
        if (root == nullptr)
            return 0;
        else
            return max(height(root->left), height(root->right)) + 1;
    }

    void DFS(TreeNode *root, int level, vector<int>& vec) {
        if (root == nullptr) {
            return;
        } else if (level == 1) {
            vec.push_back(root->val);
        } else {
            DFS(root->left, level-1, vec);
            DFS(root->right, level-1, vec);
        }
    }

    // 方法二：在外层循环中用一个内层循环从队列中取出所有当前层的节点
    vector<int> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            vector<int> level;
            auto size = Q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = Q.front();
                Q.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    Q.push(node->left);
                if (node->right != nullptr)
                    Q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }

    // 方法三：用两个 queue 进行倒换
    vector<int> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> current, next;
        current.push(root);
        while (!current.empty()) {
            vector<int> level;
            while (!current.empty()) {
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != nullptr)
                    next.push(node->left);
                if (node->right != nullptr)
                    next.push(node->right);
            }
            result.push_back(level);
            swap(current, next);
        }
        return result;
    }
};
