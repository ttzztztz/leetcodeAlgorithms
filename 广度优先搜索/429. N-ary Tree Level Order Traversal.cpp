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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        int layer = 0;
        deque<Node*> q = {root};
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                Node* u = q.front();
                q.pop_front();
                
                if (ans.size() <= layer) ans.resize(layer + 1);
                ans[layer].push_back(u->val);
                
                for (Node* v : u->children) {
                    q.push_back(v);
                }
            }
            layer++;
        }
        return ans;
    }
};
