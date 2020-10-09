/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans.clear();
        _serialize(root);
        return join(ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;
        vector<string> s = split(data);
        return build(s);
    }
private:
    vector<string> ans;
    void _serialize(TreeNode* u) {
        if (u == nullptr) {
            ans.push_back("#");
            return;
        }
        ans.push_back(to_string(u->val));
        _serialize(u->left);
        _serialize(u->right);
    }
    
    int idx = 0;
    TreeNode* build(const vector<string>& s) {
        const string& str = s[idx++];
        if (str == "#") return nullptr;
        
        TreeNode* u = new TreeNode(stoi(str));
        u->left = build(s);
        u->right = build(s);
        return u;
    }
    
    string join(const vector<string>& str) {
        string ans;
        for (int i = 0; i < str.size(); i++) {
            ans += str[i] + ",";
        }
        ans.pop_back();
        return ans;
    }

    vector<string> split(const string& str) {
        vector<string> ans;
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ',') ans.push_back(tmp), tmp.clear();
            else tmp += str[i];
        }
        
        if (!tmp.empty()) ans.push_back(tmp);
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
