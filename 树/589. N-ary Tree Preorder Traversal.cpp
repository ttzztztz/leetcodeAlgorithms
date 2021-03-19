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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        
        if (root == nullptr) return ans;
        vector<Node*> stk = {root};
        while (!stk.empty()) {
            auto t = stk.back();
            ans.push_back(t->val);
            stk.pop_back();
            
            for (int i = t->children.size() - 1; i >= 0; i--) {
                stk.push_back(t->children[i]);
            }
        }
        
        return ans;
    }
};
