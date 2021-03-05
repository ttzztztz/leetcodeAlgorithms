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
    Node* cloneTree(Node* root) {
        if (root == nullptr) return nullptr;
        Node* cur = new Node(root->val);
        for (Node* v : root->children) {
            cur->children.push_back(cloneTree(v));
        }
        return cur;
    }
};
