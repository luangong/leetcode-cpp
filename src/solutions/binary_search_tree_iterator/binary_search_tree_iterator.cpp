/*
 * Binary Search Tree Iterator
 *
 * Implement an iterator over a binary search tree (BST).  Your iterator will be
 * initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree.
 *
 * Credits: Special thanks to @ts for adding this problem and creating all test
 * cases.
 *
 * Tags: Tree, Stack
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;

/** Definition for binary tree */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode *> stk;
public:
    BSTIterator(TreeNode *root) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        int value = stk.top()->val;
        TreeNode *node = stk.top()->right;
        stk.pop();
        while (node != nullptr) {
            stk.push(node);
            node = node->left;
        }
        return value;
    }
};

/**
 * Your BSTIterator will be called like this:
 *
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext())
 *     cout << i.next();
 */

int main(int argc, char **argv) {
    return 0;
}
