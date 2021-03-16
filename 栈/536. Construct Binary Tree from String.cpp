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
        if (s.empty()) return nullptr;
        TreeNode* flag = new TreeNode(0);
        vector<TreeNode*> stk = {flag};
        
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                continue;
            } else if (s[i] == ')') {
                stk.pop_back();
            } else {
                tmp += s[i];
                if (s[i + 1] == '(' || s[i + 1] == ')' || s[i + 1] == '\0') {
                    TreeNode* cur = new TreeNode(stoi(tmp));
                    tmp.clear();

                    if (stk.back()->left) stk.back()->right = cur;
                    else stk.back()->left = cur;

                    stk.push_back(cur);
                }
            }
        }
        
        TreeNode* ans = flag->left;
        delete flag;
        return ans;
    }
};
