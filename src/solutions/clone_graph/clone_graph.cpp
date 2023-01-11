/**
 * Clone Graph
 *
 * Clone an undirected graph.  Each node in the graph contains a label and a
 * list of its neighbors.
 *
 * OJ's undirected graph serialization:
 *
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 *
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a
 * self-cycle.
 *
 * Visually, the graph looks like the following:
 *
 *       1
 *      / \
 *     /   \
 *    0 --- 2
 *         / \
 *         \_/
 *
 * Tags: Depth-first Search, Breadth-first Search, Graph
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    typedef map<UndirectedGraphNode*, UndirectedGraphNode*> map_type;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *root) {
        if (root == nullptr)
            return nullptr;
        map_type copied;
        return clone_bfs(root, copied);
    }

    // DFS
    UndirectedGraphNode *clone(UndirectedGraphNode *root, map_type& copied) {
        // If this node is already copied, then return the copied one
        if (copied.find(root) != copied.end())
            return copied[root];
        // Copy this node and mark as copied
        UndirectedGraphNode *new_node = new UndirectedGraphNode(root->label);
        copied[root] = new_node;
        // Copy each neighbor recursively
        for (auto neighbor : root->neighbors)
            new_node->neighbors.push_back(clone_dfs(neighbor, copied));
        // Return the new node copied
        return new_node;
    }

    // BFS
    UndirectedGraphNode *clone_bfs(UndirectedGraphNode *root, map_type& copied) {
        // Initialize the mapping and the queue with root node
        copied[root] = new UndirectedGraphNode(root->label);
        queue<UndirectedGraphNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            UndirectedGraphNode *node = Q.front();
            Q.pop();
            for (const auto& neighbor : node->neighbors) {
                if (copied.find(neighbor) == copied.end()) {
                    copied[neighbor] = new UndirectedGraphNode(neighbor->label);
                    Q.push(neighbor);
                }
                copied[node]->neighbors.push_back(copied[neighbor]);
            }
        }
        return copied[root];
    }
};
