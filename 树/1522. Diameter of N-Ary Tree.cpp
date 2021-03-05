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
    int diameter(Node* root) {
        dfs1(root, 0);
        ans_dist = 0;
        dfs2(ans_node, 0, nullptr);
        return ans_dist;
    }
private:
    int ans_dist = 0;
    Node* ans_node = nullptr;
    unordered_map<Node*, Node*> parent;
    
    void dfs1(Node* u, int deep) {
        if (u == nullptr) return;
        if (deep > ans_dist) {
            ans_dist = deep;
            ans_node = u;
        }
        
        for (Node* v : u->children) {
            parent[v] = u;
            dfs1(v, deep + 1);
        }
    }
    
    void dfs2(Node* u, int deep, Node* p) {
        if (u == nullptr) return;
        if (deep > ans_dist) {
            ans_dist = deep;
            ans_node = u;
        }
        
        for (Node* v : u->children) {
            if (v != p) dfs2(v, deep + 1, u);
        }
        if (parent[u] != p) dfs2(parent[u], deep + 1, u);
    }
};
