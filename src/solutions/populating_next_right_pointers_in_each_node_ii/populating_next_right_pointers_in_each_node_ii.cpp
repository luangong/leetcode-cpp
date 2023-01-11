/**
 * Populating Next Right Pointers in Each Node II
 *
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous
 * solution still work?
 *
 * Note: You may only use constant extra space.
 *
 * For example, given the following binary tree,
 *
 *        1
 *       /  \
 *      2    3
 *     / \    \
 *    4   5    7
 *
 * After calling your function, the tree should look like:
 *
 *       1 -> null
 *      /  \
 *      2 -> 3 -> null
 *     / \    \
 *    4-> 5 -> 7 -> null
 *
 * Tags: Tree, Depth-first Search
 */

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    TreeLinkNode *getNextSibling(TreeLinkNode *parent, bool isLeft) {
        if (isLeft && parent->right != nullptr)
            return parent->right;
        TreeLinkNode *sibling = parent;
        while (sibling != nullptr) {
            if (sibling->left != nullptr)
                return sibling->left;
            else if (sibling->right != nullptr)
                return sibling->right;
            sibling = sibling->next;
        }
        return nullptr;
    }

    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        TreeLinkNode *leftMost = root;
        while (leftMost != nullptr) {
            TreeLinkNode *curr = leftMost;
            TreeLinkNode *newLeftMost = nullptr;
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    curr->left->next = getNextSibling(curr, true);
                    if (newLeftMost == nullptr)
                        newLeftMost = curr->left;
                }
                if (curr->right != nullptr) {
                    curr->right->next = getNextSibling(curr, false);
                    if (newLeftMost == nullptr)
                        newLeftMost = curr->right;
                }
                curr = curr->next;
            }
            leftMost = newLeftMost;
        }
    }
};
