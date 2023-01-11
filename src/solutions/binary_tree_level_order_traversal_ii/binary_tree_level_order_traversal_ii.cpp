/**
 * Binary Tree Level Order Traversal II
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes'
 * values. (i.e., from left to right, level by level from leaf to root).
 *
 * For example: given binary tree {3,9,20,#,#,15,7},
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its bottom-up level order traversal as:
 *
 *   [
 *     [15,7]
 *     [9,20],
 *     [3],
 *   ]
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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> Q;
        vector<vector<int>> result;
        if (root != nullptr) Q.push(root);
        // 本层结点总数，初始化为 1，即只有根结点
        int numNodesCurrLevel = 1;
        while (!Q.empty()) {
            // 下一层结点总数等于本层所有结点的子树个数之和
            int numNodesNextLevel = 0;
            // 存储本层结点的值
            vector<int> currLevel;
            // 遍历本层所有结点，如果有左/右子树，则累加起来
            for (int i = 0; i < numNodesCurrLevel; ++i) {
                TreeNode *node = Q.front();
                Q.pop();
                currLevel.push_back(node->val);
                if (node->left != nullptr) {
                    Q.push(node->left);
                    ++numNodesNextLevel;
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                    ++numNodesNextLevel;
                }
            }
            // 本层结点访问结束之后，下一层的结点总数又再次成为「本层」
            // 结点数之和
            numNodesCurrLevel = numNodesNextLevel;
            // 把本层结点的值拷贝到返回值中去
            result.push_back(currLevel);
        }

        // 逆转 result，即返回 bottom-up level order traversal 的结果
        reverse(result.begin(), result.end());
        return result;
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
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
        reverse(result.begin(), result.end());
        return result;
    }
};
