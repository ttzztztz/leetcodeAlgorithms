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
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};

        vector<int> ans;
        vector<pair<Node*, bool>> stk = { {root, false} };
        while (!stk.empty()) {
            auto [cur, visited] = stk.back();
            stk.pop_back();

            if (visited) {
                ans.push_back(cur->val);
            } else {
                stk.emplace_back(cur, true);
                for (int i = cur->children.size() - 1; i >= 0; i--) {
                    stk.emplace_back(cur->children[i], false);
                }
            }
        }
        return ans;
    }
};