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
        const int n = s.size();

        vector<TreeNode*> stk = { new TreeNode(0) };
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                TreeNode* new_node = new TreeNode(0);
                if (!stk.empty()) {
                    TreeNode* back = stk.back();

                    if (back->left == nullptr) back->left = new_node;
                    else if (back->right == nullptr) back->right = new_node;
                }
                stk.push_back(new_node);
            } else if (s[i] == ')') {
                stk.pop_back();
            } else {
                bool negative = false;
                int val = 0;

                if (s[i] == '-') negative = true;
                else val = s[i] - '0';

                while (i + 1 < n && '0' <= s[i + 1] && s[i + 1] <= '9') {
                    val = val * 10 + s[i + 1] - '0';
                    i++;
                }

                if (negative) val = -val;
                stk.back()->val = val;
            }
        }
        return stk.back();
    }
};