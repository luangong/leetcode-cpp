/*
 * Path Sum II
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * For example: given the below binary tree and sum = 22,
 *
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \    / \
 *       7    2  5   1
 *
 * return
 *
 *   [
 *     [5,4,11,2],
 *     [5,8,4,5]
 *   ]
 *
 * Tags: Tree, Depth-first Search
 */

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <numeric>

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
    vector<vector<int>> pathSum2(TreeNode *root, int sum) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<int> path{root->val};
        backtrack(root, path, sum - root->val, result);
        return result;
    }

    void backtrack(TreeNode *root, vector<int>& path, int rest, vector<vector<int>>& result) {
        if (root->left == nullptr && root->right == nullptr) {
            if (rest == 0) result.push_back(sln);
        } else {
            if (root->left != nullptr) {
                path.push_back(root->left->val);
                backtrack(root->left, path, sum - root->left->val, result);
                path.pop_back();
            }
            if (root->right != nullptr) {
                path.push_back(root->right->val);
                backtrack(root->right, path, sum - root->right->val, result);
                path.pop_back();
            }
        }
    }

    // 用二叉树的非递归 preorder traversal 来枚举 root-to-leaf 路径
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        stack<pair<TreeNode*, vector<int>>> stk;
        stk.push(make_pair(root, vector<int>{root->val}));
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            TreeNode *node = p.first;
            vector<int>& path = p.second;
            if (node->left == nullptr && node->right == nullptr)
                if (accumulate(path.begin(), path.end(), 0) == sum)
                    result.push_back(path);
            if (node->left != nullptr) {
                path.push_back(node->left->val);
                stk.push(make_pair(node->left, path));
                path.pop_back();
            }
            if (node->right != nullptr) {
                path.push_back(node->right->val);
                stk.push(make_pair(node->right, path));
                path.pop_back();
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    auto result = Solution().pathSum(new TreeNode(1, new TreeNode(2), new TreeNode(3)), 3);
    for (const auto& vec : result) {
        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}
