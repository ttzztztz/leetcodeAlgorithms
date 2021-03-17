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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";

        string ans = to_string(root->val);
        ans += "(";
        for (Node* t : root->children) {
            ans += serialize(t);
        }
        ans += ")";
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        Node* flag = new Node(0);

        vector<Node*> stk = {flag};
        string cur;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '(') {
                continue;
            } else if (data[i] == ')') {
                stk.pop_back();
            } else {
                cur += data[i];
            }
            
            if (i + 1 < data.size() && !cur.empty() && (data[i + 1] == '(' || data[i + 1] == ')')) {
                Node* t = new Node(stoi(cur));
                cur.clear();
                stk.back()->children.push_back(t);
                stk.push_back(t);
            }
        }
        Node* ans = flag->children[0];
        delete flag;
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
