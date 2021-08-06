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
        
        deque<Node*> q = { root };
        while (!q.empty()) {
            const int cnt = q.size();
            ans.push_back(vector<int>{});
            
            for (int _ = 0; _ < cnt; _++) {
                auto u = q.front();
                q.pop_front();
                ans.back().push_back(u->val);
                
                for (auto& v : u->children) {
                    q.push_back(v);
                }
            }
        }
        return ans;
    }
};
