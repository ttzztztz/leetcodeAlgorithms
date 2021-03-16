/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        this->s = s;
        if (s.empty()) return nullptr;
        return build();
    }
private:
    string s;
    int idx;
    
    TreeNode* build() {
        string tmp;
        while (idx < s.size()) {
            if (s[idx] != '(' && s[idx] != ')') tmp += s[idx++];
            else break;
        }
        
        TreeNode* root = new TreeNode(stoi(tmp));
        if (s[idx] == '(') {
            idx++; // (
            root->left = build();
            idx++; // )
        }
        
        
        if (s[idx] == '(') {
            idx++; // (
            root->right = build();
            idx++;
        }
        return root;
    }
};
