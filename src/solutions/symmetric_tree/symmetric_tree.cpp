/*
 * Symmetric Tree
 *
 * Given a binary tree, check whether it is a mirror of itself (i.e., symmetric
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *        1
 *       / \
 *      2   2
 *     / \ / \
 *    3  4 4  3
 *
 * But the following is not:
 *
 *      1
 *     / \
 *    2   2
 *     \   \
 *     3    3
 *
 * Note: Bonus points if you could solve it both recursively and iteratively.
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
    /**
     * 方法一：递归并使用辅助函数
     */
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left != nullptr && right != nullptr
                && left->val == right->val
                && isSymmetric(left->left, right->right)
                && isSymmetric(left->right, right->left))
            return true;
        return false;
    }

    /**
     * 方法二：先中序遍历把结点（可以值存指针）存到一个 vector 中，
     * 然后再判断该 vector 是否是 palindrome
     */
    isSymmetric(TreeNode *root) {
        vector<TreeNode*> vec;
        inorder(root, vec);
        return isPalindrome(vec);
    }
    void inorder(TreeNode *root, vector<TreeNode*>& vec) {
        if (root == nullptr) return;
        if (root->left != nullptr)
            inorder(root->left, vec);
        vec.push_back(root);
        if (root->right != nullptr)
            inorder(root->right, vec);
    }
    bool isPalindrome(const vector<TreeNode*>& vec) {
        auto n = vec.size();
        for (int i = 0; i < n / 2; ++i)
            if (vec[i]->val != vec[n-i-1]->val)
                return false;
        return true;
    }

    /**
     * 方法三：用两个队列同时对二叉树的左、右子树进行层次遍历，左子树从左到右
     * 遍历，右子树从右到左遍历，并在遍历过程的每步判断结点是否相等。
     *
     * 注意：空结点也要 push 到队列中去。
     */
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        queue<TreeNode*> leftQ;
        queue<TreeNode*> rightQ;
        leftQ.push(root->left);
        rightQ.push(root->right);
        while (!leftQ.empty() && !rightQ.empty()) {
            TreeNode *leftNode = leftQ.front();
            leftQ.pop();
            TreeNode *rightNode = rightQ.front();
            rightQ.pop();
            if (leftNode == nullptr && rightNode == nullptr)
                continue;
            if (leftNode == nullptr || rightNode == nullptr)
                return false;
            if (leftNode->val != rightNode->val)
                return false;
            leftQ.push(leftNode->left);
            rightQ.push(rightNode->right);
            leftQ.push(leftNode->right);
            rightQ.push(rightNode->left);
        }
        return leftQ.empty() && rightQ.empty();
    }
};
