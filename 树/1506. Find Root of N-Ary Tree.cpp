/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        if (tree.empty()) return nullptr;
        
        unordered_set<Node*> has_parent;
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i] == nullptr) {
                continue;
            }
            
            for (Node* u : tree[i]->children) {
                has_parent.insert(u);
            }
        }
        
        for (Node* u : tree) {
            if (!has_parent.count(u)) return u;
        }
        return nullptr;
    }
};
