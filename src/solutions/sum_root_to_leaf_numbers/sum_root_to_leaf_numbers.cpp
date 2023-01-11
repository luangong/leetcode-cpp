/**
 * Sum Root to Leaf Numbers
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 *
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 *
 * Tags: Tree, Depth-first Search
 */

class Solution {
public:
    // 方法一：用引用作为输出参数，节点信息在进入 backtrack 之后访问
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbers(root, num, sum);
        return sum;
    }

    int sumNumbers(TreeNode *root, int& num, int& sum) {
        if (root == nullptr) return;
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
        } else {
            sumNumbers(root->left, num, sum);
            sumNumbers(root->right, num, sum);
        }
        num /= 10;
    }

    // 方法一：用引用作为输出参数，节点信息在进入 backtrack 之前访问
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) return 0;
        int sum = 0;
        sumNumbers(root, root->val, sum);
        return sum;
    }

    void sumNumbers(TreeNode *root, int num, int& sum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr)
            sum += num;
        else {
            if (root->left != nullptr)
                sumNumbers(root->left, num * 10 + root->left->val, sum);
            if (root->right != nullptr)
                sumNumbers(root->right, num * 10 + root->right->val, sum);
        }
    }

    // 方法二：不通过引用传参数，直接用函数返回值
    int sumNumbers(TreeNode *root, int num=0) {
        if (root == nullptr) return 0;
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return num;
        return (sumNumbers(root->left, num) +
                sumNumbers(root->right, num));
    }
};
