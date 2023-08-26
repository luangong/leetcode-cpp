/**
 * Populating Next Right Pointers in Each Node
 *
 * Given a binary tree
 *
 *    struct TreeLinkNode {
 *        TreeLinkNode *left;
 *        TreeLinkNode *right;
 *        TreeLinkNode *next;
 *    }
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 *    - You may only use constant extra space.
 *    - You may assume that it is a perfect binary tree (i.e., all leaves are at
 *      the same level, and every parent has two children).
 *
 * For example, given the following perfect binary tree,
 *
 *        1
 *       /  \
 *      2    3
 *     / \  / \
 *    4  5  6  7
 *
 * After calling your function, the tree should look like:
 *
 *        1 -> NULL
 *       /  \
 *      2 -> 3 -> NULL
 *     / \  / \
 *    4->5->6->7 -> NULL
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
    /**
     * 分层遍历二叉树，在每一层中令当前结点的 next 域指向下一个结点，
     * 如果当前结点是本层的最后一个结点，则令 next 指向 null
     */
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> current, next;
        if (root != nullptr) current.push(root);
        while (!current.empty()) {
            while (!current.empty()) {
                TreeLinkNode *node = current.front();
                Q.pop();
                if (!current.empty())
                    node->next = current.front();
                if (node->left != nullptr)
                    next.push(node->left);
                if (node->right != nullptr)
                    next.push(node->right);
            }
            swap(current, next);
        }
    }

    // DFS
    void connect(TreeLinkNode *root) {
        if (root == nullptr || root->left == nullptr || root->right == nullptr)
            return;
        root->left->next = root->right;
        if (root->next != nullptr)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }

    // BFS (recursive)
    void connect(TreeLinkNode *root) {
        if (root == nullptr || root->left == nullptr || root->right == nullptr)
            return;
        for (TreeLinkNode *curr = root; curr != nullptr; curr = curr->next) {
            curr->left->next = curr->right;
            if (curr->next != nullptr)
                curr->right->next = curr->next->left;
        }
        connect(root->left);
    }

    // BFS (iterative)
    void connect(TreeLinkNode *root) {
        for (TreeLinkNode *leftMost = root;
                leftMost != nullptr && leftMost->left != nullptr;
                leftMost = leftMost->left)  {
            for (TreeLinkNode *curr = leftMost;
                    curr != nullptr; curr = curr->next) {
                curr->left->next = curr->right;
                if (curr->next != nullptr)
                    curr->right->next = curr->next->left;
            }
        }
    }
};
