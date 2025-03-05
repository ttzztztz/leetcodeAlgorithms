/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (node_map.count(node)) return node_map[node];

        Node* cur = new Node(node->val);
        node_map[node] = cur;

        for (auto next : node->neighbors) {
            cur->neighbors.push_back(cloneGraph(next));
        }
        return cur;
    }
private:
    unordered_map<Node*, Node*> node_map;
};