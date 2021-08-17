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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    multiset<int> s;
    
    void dfs(TreeNode* u) {
        if (u == nullptr) return;
        
        s.insert(u->val);
        if (s.empty() || u->val >= *s.rbegin()) ans++;
        dfs(u->left);
        dfs(u->right);
        s.erase(s.lower_bound(u->val));
    }
};
